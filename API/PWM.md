
# PWM <!--DONE-->
- ### PWM_CH_T
    - ```PWM0```
    - ```PWM1```
    - ```PWM2```
    - ```PWM3```
    - ```PWM4```
    - ```PWM5```
    - ```PWM6```
    - ```PWM7```

## `int pwm_init(int pin_no, int out_cfg)` <!--DONE-->

### Description

Initializes PWM on a specified pin with a given configuration.

### Parameters

- **`pin_no`**: PWM pin number.
- **`out_cfg`**: Output configuration.
    - ```0```: Initial level is 0.
    - ```1```: Initial level is 1.

### Return

- None

### Note

- None

---

## `void pwm_enable(int pin_no, int enable)` <!--DONE-->

### Description

Enables or disables PWM on a specified pin.

### Parameters

- **`pin_no`**: PWM pin number.
- **`enable`**: Enable (1) or disable (0) PWM.

### Return

- None

### Note

- None

---

## `void pwm_set_peroid(int pin_no, uint32_t period)` <!--DONE-->

### Description

Sets the PWM period for a specified pin.

### Parameters

- **`pin_no`**: PWM pin number.
- **`period`**: PWM period value.

### Return

- None

### Note

- The PWM period can be calculated by dividing the system clock frequency by the PWM frequency:
  $$
  \frac{SYSTEM~CLK}{pwm~frequency} = pwm~period~[clock~cycles]
  $$
---

## `void pwm_set_sample(int pin_no, uint16_t sample)` <!--DONE-->

### Description

Sets the PWM sample value to determine the duty cycles for a specified pin.

### Parameters

- **`pin_no`**: PWM pin number.
- **`sample`**: PWM sample value which indicates the duty cycles.

### Return

- None

### Note

- `sample` is in units of $[clock~cycles]$.
