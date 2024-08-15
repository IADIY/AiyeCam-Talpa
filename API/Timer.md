# Timer <!--TODO-->
- ### TIMER_ID_T <!--DONE-->
    - ```TIM0```
    - ```TIM1```
    - ```TIM2```
    - ```TIM3```

- ### TIMER_MODE_T <!--DONE-->
    - ```TIM_MODE_FREERUN```
    - ```TIM_MODE_USERDEF```

## `void timer1_int_handler(void)` <!--DONE-->

### Description

Interrupt handler for Timer 1.

### Parameters

- None

### Return

- None

### Note

- The function can be re-implemented.

---

## `void timer2_int_handler(void)` <!--DONE-->

### Description

Interrupt handler for Timer 2.

### Parameters

- None

### Return

- None

### Note

- The function can be re-implemented.

---

## `void timer_init(TIMER_ID_T tim, TIMER_MODE_T mode, uint8_t div, uint32_t count, void *isr)` <!--DONE-->

### Description

Initializes a timer with specified settings.

### Parameters

- **`tim`**: Timer ID.
- **`mode`**: Timer mode.
- **`div`**: Divider value.
- **`count`**: Initial count value.
- **`isr`**: Interrupt service routine for the timer.

### Return

- None

### Note

- The divider value `div` should be greater than 2.

---

## `void timer_start(TIMER_ID_T tim)` <!--DONE-->

### Description

Starts the specified timer.

### Parameters

- **`tim`**: Timer ID.

### Return

- None

### Note

- None

---

## `void timer_stop(TIMER_ID_T tim)` <!--DONE-->

### Description

Stops the specified timer.

### Parameters

- **`tim`**: Timer ID.

### Return

- None

### Note

- None

---

## `uint32_t timer_get_count(TIMER_ID_T tim)` <!--DONE-->

### Description

Gets the current count value of the specified timer.

### Parameters

- **`tim`**: Timer ID.

### Return

- **`uint32_t`**: Current count value.

### Note

- None

---

## `void timer_enable_int(TIMER_ID_T tim, int en)` <!--DONE-->

### Description

Enables or disables timer interrupts.

### Parameters

- **`tim`**: Timer ID.
- **`en`**: Enable (1) or disable (0) interrupts.

### Return

- None

### Note

- None

---

## `void timer_clear_int(TIMER_ID_T tim)` <!--DONE-->

### Description

Clears the interrupt flag for the specified timer.

### Parameters

- **`tim`**: Timer ID.

### Return

- None

### Note

- None

---

## `uint32_t timer_get_int_status(TIMER_ID_T tim)` <!--DONE-->

### Description

Gets the interrupt status of the specified timer.

### Parameters

- **`tim`**: Timer ID.

### Return

- **`uint32_t`**: Interrupt status.

### Note

- None

---

## `void perf_timer_init(void)` <!--DONE-->

### Description

Initializes the TIMER 3 as performance timer and starts.

### Parameters

- None

### Return

- None

### Note

- None

---

## `unsigned long long perf_get_ticks(void)` <!--DONE-->

### Description

Gets the current performance timer ticks.

### Parameters

- None

### Return

- **`unsigned long long`**: Current performance timer ticks.

### Note

- Accuaracy: 1 / (system_clk / 2) second

---

## `unsigned long perf_get_timer(unsigned long base)` <!--DONE-->

### Description

Gets the performance timer value relative to `base`.

### Parameters

- **`base`**: Base time value.

### Return

- **`unsigned long`**: Performance timer value.

### Note

- None

---


## `void udelay(unsigned long usec)` <!--DONE-->

### Description

Delays execution for a specified number of microseconds.

### Parameters

- **`usec`**: Number of microseconds to delay.

### Return

- None

### Note

- Don't release CPU ownership.

---

## `void mdelay(unsigned long msec)` <!--DONE-->

### Description

Delays execution for a specified number of milliseconds.

### Parameters

- **`msec`**: Number of milliseconds to delay.

### Return

- None

### Note

- Don't release CPU ownership.

---

## `void mdelay_task(unsigned long msec)` <!--DONE-->

### Description

Delays the current task for a specified number of milliseconds.

### Parameters

- **`msec`**: Number of milliseconds to delay.

### Return

- None

### Note

- Release CPU ownership.
