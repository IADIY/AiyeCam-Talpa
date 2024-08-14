
# System <!--DONE-->

## `void sys_reset(unsigned int modules)` <!--DONE-->

### Description

Sets hardware module to reset state then back to normal state. Delay about 300 cycles.

### Parameters

- **`modules`**: ID of Module to reset.
    - ```SYS_RSTN_UART```
    - ```SYS_RSTN_I2S```
    - ```SYS_RSTN_SSP```
    - ```SYS_RSTN_KPD```
    - ```SYS_RSTN_GPIO```
    - ```SYS_RSTN_TIMER```
    - ```SYS_RSTN_TIM0```
    - ```SYS_RSTN_TIM1```
    - ```SYS_RSTN_TIM2```
    - ```SYS_RSTN_TIM3```
    - ```SYS_RSTN_WDT```
    - ```SYS_RSTN_SPI```
    - ```SYS_RSTN_DMAC```
    - ```SYS_RSTN_ISP_BINSKIP```
    - ```SYS_RSTN_ISP_MD```
    - ```SYS_RSTN_ISP_DBG```
    - ```SYS_RSTN_ISP_SCALER```
    - ```SYS_RSTN_ISP_FE```
    - ```SYS_RSTN_SENSOR_MEM```
    - ```SYS_RSTN_SENSOR_SPI```
    - ```SYS_RSTN_PWM0```
    - ```SYS_RSTN_PWM1```
    - ```SYS_RSTN_PWM2```
    - ```SYS_RSTN_PWM3```
    - ```SYS_RSTN_PWM4```
    - ```SYS_RSTN_PWM5```
    - ```SYS_RSTN_PWM6```
    - ```SYS_RSTN_PWM7```
    - ```SYS_RSTN_GAMMA```
    - ```SYS_RSTN_PSEUDO```
    - ```SYS_RSTN_SENSOR```

### Return

- None

### Note

- ```sys_reset``` does not support reseting I2C or RTC hardware module.

---

## `void sys_reset2(unsigned int modules)` <!--DONE-->

### Description

Set I2C or RTC hardware module to reset state then back to normal state. Delay about 300 cycles.

### Parameters

- **`modules`**: ID of Module to reset.
    - ```SYS_RSTN_RTC```
    - ```SYS_RSTN_I2C```

### Return

- None

### Note

- ```sys_reset2``` only supports reseting I2C or RTC hardware module.

---

## `void sys_set_div(unsigned int module, unsigned char div)` <!--DONE-->

### Description

Sets the divisor for hardware module.

### Parameters

- **`module`**: The hardware module to set the divisor.
    - ```SYS_DIV_UART```
    - ```SYS_DIV_I2S_MCLK```
    - ```SYS_DIV_I2S_SCLK```
    - ```SYS_DIV_SPI```
    - ```SYS_DIV_KPD```
    - ```SYS_DIV_TIM0```
    - ```SYS_DIV_TIM1```
    - ```SYS_DIV_TIM2```
    - ```SYS_DIV_TIM3```
    - ```SYS_DIV_WDT```
    - ```SYS_DIV_QSPI```
    - ```SYS_DIV_GPIO_DB```
- **`div`**: The divisor value.

### Return

- None

### Note

- Except I2C Module.

---

## `void sys_set_padshare(int pin_no, SYSCON_PAD_FUNC func, int pull_on, int strength)` <!--DONE-->

### Description

Configures the operating mode for a specific pin.

### Parameters

- **`pin_no`**: The pin number to configure.
    - ``` IOA0``` or ```0```
    - ``` IOA1``` or ```1```
    - ``` IOA2``` or ```2```
    - ``` IOA3``` or ```3```
    - ``` IOA4``` or ```4```
    - ``` IOA5``` or ```5```
    - ``` IOA6``` or ```6```
    - ``` IOA7``` or ```7```
    - ``` IOB1``` or ```9```
    - ``` IOB2``` or ```10```
    - ``` IOB3``` or ```11```
    - ``` IOB4``` or ```12```
    - ``` IOB5``` or ```13```
    - ``` IOB6``` or ```14```
    - ``` IOB7``` or ```15```
    - ``` IOC0``` or ```16```
    - ``` IOC1``` or ```17```
    - ``` IOC2``` or ```18```
    - ``` IOC3``` or ```19```
    - ``` IOC4``` or ```20```
    - ``` IOC5``` or ```21```
    - ``` IOC6``` or ```22```
- **`func`**: The function to assign to the pin.
    - ```PAD_FUNC0```
    - ```PAD_FUNC1```
    - ```PAD_FUNC2```
    - ```PAD_FUNC3```
    - ```PAD_FUNC4```
    - ```PAD_FUNC5```
- **`pull_on`**: hether to enable the pull-up/pull-down resistor.
    - ```PAD_PULL_UP```
    - ```PAD_PULL_NO_PULL```
- **`strength`**: The drive strength of the pin.
    - ```PAD_STRENGTH_EN```
    - ```PAD_STRENGTH_DIS```

### Return

- None

### Note

- None

---

## `void sys_pclk_ctrl(SYSCON_PCLK pclk, int enable)` <!--DONE-->

### Description

Controls the peripheral clock.

### Parameters

- **`pclk`**: The peripheral clock to control.
	- ```UART_PCLK```
	- ```I2S_PCLK```
	- ```SSP_PCLK```
	- ```KPD_PCLK```
	- ```GPIO_PCLK```
	- ```TIMER_PCLK```
	- ```WDT_PCLK```
	- ```SSI_HCL```
	- ```DMAC_HCLK```
	- ```ISP_PCLK```
	- ```SENSOR2MEM_PCLK```
	- ```SENSOR_SPI_PCLK```
	- ```AES_PCLK```
	- ```PWM0_PCLK```
	- ```PWM1_PCLK```
	- ```PWM2_PCLK```
	- ```PWM3_PCLK```
	- ```PWM4_PCLK```
	- ```PWM5_PCLK```
	- ```PWM6_PCLK```
	- ```PWM7_PCLK```
	- ```RTC_PCLK```
	- ```I2C_PCLK```
- **`enable`**: Whether to enable or disable the clock.

### Return

- None

### Note

- None



## `void system_config_stack(int stack_size)` <!--DONE-->

### Description

Configures the main task stack size for the system.

### Parameters

- **`stack_size`**: Stack size, unit in 4 bytes.

### Return

- None

---

## `int system_clock(void)` <!--DONE-->

### Description

Gets the current system clock frequency.

### Parameters

- None

### Return

- **`int`**: Current system clock frequency.

---

## `int system_get_error(void)` <!--DONE-->

### Description

Gets the last error code from the system.

### Parameters

- None

### Return

- **`int`**: Last error code.

---

## `int switch_firmware(int id)` <!--DONE-->

### Description

Switches the firmware to the specified ID.

### Parameters

- **`id`**: Firmware ID.

### Return

- **`int`**: Status of the firmware switch. Returns non-zero on failure, otherwise the system will reboot.

---

## `void switch_next_firmware(void)` <!--DONE-->

### Description

Switches to the next firmware.

### Parameters

- None

### Return

- If there is only one valid firmware, it will reset and rerun this firmware.

---

## `int bsp_init(void)` <!--DONE-->

### Description

Initializes the core BSP (Board Support Package) components.

### Parameters

- None

### Return

- Status of initialization. Returns 0 on success, non-zero on failure.

### Note

- None

---

## `void bsp_init_core(void)` <!--DONE-->

### Description

Initializes the core CPU internal configuration.

### Parameters

- None

### Return

- None

### Note

- None

---

## `void bsp_init_clock(int pll_clk, int core_clk)` <!--DONE-->

### Description

Initializes the BSP clock settings.

### Parameters

- **`pll_clk`**: PLL clock setting.
    - ```576``` Mhz
    - ```480``` Mhz
- **`core_clk`**: Core clock setting.
    - ```96``` Mhz
    - ```60``` Mhz
    - ```48``` Mhz
    - ```36``` Mhz
    - ```24``` Mhz
### Return

- None

### Note

- `core_clk` should be the exact division of `pll_clk`

---

## `void bsp_enable_pclk(void)` <!--DONE-->

### Description

Enables all the peripheral clocks (PCLK) for the BSP.

### Parameters

- None

### Return

- None

### Note

- None
