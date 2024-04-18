#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "nbsdk.h"
#include "bsp.h"
#include "nbsdk_api.h"
#include "User_Config.h"
#include "include/sensor_aeg.h"
#include "include/Basic.h"
#include "Token.h"

/**************************************************************************
 *	System Constants
 **************************************************************************/
#define HOST_SECTION __attribute__((section(".ver_host")))
#define TASK_DELAY_TIME 2
#define TRUE 1
#define FALSE 0

/**************************************************************************
 *	External Function
 **************************************************************************/
extern void debug_enable_box(int id, int en, int sx, int sy, int ex, int ey);
extern void debug_set_color(int color); // change word color black 0, white 255
extern void debug_enable_label(int id, int en, int value, int sx, int sy);
extern unsigned long intToBcd(int input);
/**************************************************************************
 *	Debug Configuration
 **************************************************************************/

//#define image_viewer

/**************************************************************************
 *	Image Processing constant
 **************************************************************************/
#define ROI_X 100
#define ROI_Y 0
#define ROI_W 120
#define ROI_H 320
#define Binary_threshold 128
/**************************************************************************
 *	Global Data
 **************************************************************************/
static const char HOST_SECTION host_ver[] = "HOST-"__DATE__"-"__TIME__;

static TaskHandle_t xHandle_Win = NULL;
static TaskHandle_t xHandle_User = NULL;
static TaskHandle_t xHandle_Feature = NULL;
static TaskHandle_t xHandle_Result = NULL;

unsigned long int win_flow = 0;
unsigned long int detected_flow = 0;
unsigned long int frame_id = 0;

u32 Sys_Tick = 0;
u8 task_init = FALSE;
u8 process_done = 1;


/**************************************************************************
 *	Function
 **************************************************************************/

static void custom_gpio_2(void){
	sys_set_padshare(IOA3, PAD_FUNC5, PAD_PULL_NO_PULL, PAD_STRENGTH_DIS);
	gpio_set_dir(IOA3, GPIO_INPUT_DIRECTION);
	
	// Flash
	sys_set_padshare(IOB1, PAD_FUNC0, PAD_PULL_NO_PULL, PAD_STRENGTH_DIS);
	sys_set_padshare(IOB2, PAD_FUNC0, PAD_PULL_NO_PULL, PAD_STRENGTH_DIS);
	sys_set_padshare(IOB3, PAD_FUNC0, PAD_PULL_NO_PULL, PAD_STRENGTH_DIS);
	sys_set_padshare(IOB4, PAD_FUNC0, PAD_PULL_NO_PULL, PAD_STRENGTH_DIS);
	sys_set_padshare(IOB5, PAD_FUNC0, PAD_PULL_NO_PULL, PAD_STRENGTH_DIS);
	sys_set_padshare(IOB6, PAD_FUNC0, PAD_PULL_NO_PULL, PAD_STRENGTH_DIS);

	sys_set_padshare(IOA6, PAD_FUNC0, PAD_PULL_NO_PULL, PAD_STRENGTH_DIS);
	gpio_set_dir(IOA6, GPIO_OUTPUT_DIRECTION);
	sys_set_padshare(IOA5, PAD_FUNC0, PAD_PULL_NO_PULL, PAD_STRENGTH_DIS);
	gpio_set_dir(IOA5, GPIO_INPUT_DIRECTION);
	uart_init(115200,UART_LCR_8N1,2);
	
	sys_set_padshare(IOA0, PAD_FUNC5, PAD_PULL_NO_PULL, PAD_STRENGTH_DIS);
	gpio_set_dir(IOA0, GPIO_INPUT_DIRECTION);

	sys_set_padshare(IOA1, PAD_FUNC5, PAD_PULL_NO_PULL, PAD_STRENGTH_DIS);
	gpio_set_dir(IOA1, GPIO_INPUT_DIRECTION);

	sys_set_padshare(IOA2, PAD_FUNC5, PAD_PULL_NO_PULL, PAD_STRENGTH_DIS);
	gpio_set_dir(IOA2, GPIO_INPUT_DIRECTION);

	sys_set_padshare(IOB7, PAD_FUNC5, PAD_PULL_NO_PULL, PAD_STRENGTH_DIS);
	gpio_set_dir(IOB7, GPIO_INPUT_DIRECTION);

	sys_set_padshare(IOC0, PAD_FUNC5, PAD_PULL_NO_PULL, PAD_STRENGTH_DIS);
	gpio_set_dir(IOC0, GPIO_INPUT_DIRECTION);

	sys_set_padshare(IOC1, PAD_FUNC5, PAD_PULL_NO_PULL, PAD_STRENGTH_DIS);
	gpio_set_dir(IOC1, GPIO_INPUT_DIRECTION);

	sys_set_padshare(IOC2, PAD_FUNC5, PAD_PULL_NO_PULL, PAD_STRENGTH_DIS);
	gpio_set_dir(IOC2, GPIO_INPUT_DIRECTION);

	sys_set_padshare(IOC3, PAD_FUNC5, PAD_PULL_NO_PULL, PAD_STRENGTH_DIS);
	gpio_set_dir(IOC3, GPIO_INPUT_DIRECTION);

	sys_set_padshare(IOC4, PAD_FUNC5, PAD_PULL_NO_PULL, PAD_STRENGTH_DIS);
	gpio_set_dir(IOC4, GPIO_INPUT_DIRECTION);

	sys_set_padshare(IOC5, PAD_FUNC5, PAD_PULL_NO_PULL, PAD_STRENGTH_DIS);
	gpio_set_dir(IOC5, GPIO_INPUT_DIRECTION);
}

static int sensor_setup(void)
{
	uint8_t *pinfo = nb_malloc(64);
	ASSERT(pinfo);
	verNbsdkGet(pinfo);
	DEBUG(DEBUG_INFO, "NBSDK_VERSION:%s", pinfo);
	DEBUG(DEBUG_INFO, "Build @%s", host_ver);
	osMemInfoDump(0);
	unsigned int aeg_ver_len;
	aeg_ver_len = sensor_aeg_get_version(pinfo, 64);

	if (aeg_ver_len > 0){
		DEBUG(DEBUG_INFO, "AEG Version: %s", pinfo);
	}
	else{
		DEBUG(DEBUG_ERROR, "AEG Version is Error!!!");
	}
	nb_free(pinfo);
	//token.h
	sensor_aeg_init(AEG_MODE, AEG_AC_POWER_FREQ, AEG_GAMMA_MODE);
	sensor_aeg_video_debug_label_enable(TRUE);

	return FALSE;
}

static void User_Task(void *parameters){
    u32 now_tick = 0;
    for (;;){
        if (task_init){
		uart_ctrl(2);
		uart_ctrl(1);
		printf("loop:%ld\n", now_tick);
		int tstc = uart_tstc();
		if(tstc){
			char data = uart_getc();
			printf("data = %c\n", data);	
		}
		uart_ctrl(0);
        }
	now_tick += 1;
        vTaskDelay(pdMS_TO_TICKS(1000));
    }
    vTaskDelete(NULL);
}

static void userTaskInit(void)
{
	BaseType_t xTask_User;
	xTask_User = xTaskCreate(
		User_Task,
		"User_Task",
		configMINIMAL_STACK_SIZE * 5,
		NULL,
		tskIDLE_PRIORITY + 5,
		&xHandle_User);
	if (xTask_User != pdPASS)
	{
		DEBUG(DEBUG_ERROR, "User_Task is NULL!");
		exit(FALSE);
	}
}

int main(void)
{
	SetDebugLevel(DEBUG_LEVEL, DETAIL_INFO_SUPPORT);
	struct Init_Config *BasicInitConfig = get_init_config();
	BasicInitConfig->BaudRate = UART_DEFAULT_BAUD_RATE_INDEX;
	BasicInitConfig->SPISpeed = FLASH_SPI_SPEED;
	BasicInitConfig->CISWorkFreq = SYS_WORK_FREQ;
	BasicInitConfig->SystemInfoDump = SYS_INFO_DUMP_SW;
	//save system data
	BasicInitConfig->IOPortingMode = IO_PORTING_MODE;
	BasicInitConfig->DebugMode = DEBUG_MODE;
	BasicInitConfig->BLCEnable = BLC_SW;
	//BLC(Back Light Control)
	InitializeBase(BasicInitConfig);
#ifndef image_viewer
	custom_gpio_2();
#endif
	userTaskInit();
	task_init = TRUE;
	return 0;
}
