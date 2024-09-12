# GPIO <!--DONE-->
- ### pin_no
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

    pin number 8 is not used.

- ### Interrupt Pin
    - ``` IOA0``` or ```0```
    - ``` IOA1``` or ```1```
    - ``` IOA2``` or ```2```
    - ``` IOA3``` or ```3```
    - ``` IOA4``` or ```4```
    - ``` IOA5``` or ```5```
    - ``` IOA6``` or ```6```
    - ``` IOA7``` or ```7```

- ### GPIO_DIRECTION_T
    - ```GPIO_INPUT_DIRECTION```
    - ```GPIO_OUTPUT_DIRECTION```

- ### GPIO_INT_TYPE_T 
    - ```GPIO_INT_HIGH_LEVEL```
    - ```GPIO_INT_LOW_LEVEL```
    - ```GPIO_INT_RISING_EDGE```
    - ```GPIO_INT_FALLING_EDGE``` 
    - ```GPIO_INT_BOTH_EDGE```
    - ```GPIO_INT_TYPE_END```


## `int gpio_init(void)` <!--DONE-->

### Description

Initializes GPIO driver, configs port direction and contrl register, configs interrupt register if needed. All GPIO pins are initialized as input in. 

### Parameters

- None

### Return

- **`int`**: Status of initialization. Returns 0 on success, non-zero on failure.

### Note

- None

---

## `void gpio_set_dir(int pin_no, GPIO_DIRECTION_T dir)` <!--DONE-->

### Description

Sets the direction for a GPIO pin.

### Parameters

- **`pin_no`**: GPIO pin number.
- **`dir`**: Direction (input or output).

### Return

- None

### Note

- None

---

## `int gpio_get_value(int pin_no)` <!--DONE-->

### Description

Gets the value of a GPIO pin.

### Parameters

- **`pin_no`**: GPIO pin number.

### Return

- **`int`**: Value of the GPIO pin. 0 or 1.

### Note

- None

---

## `void gpio_set_value(int pin_no, int val)` <!--DONE-->

### Description

Sets the value of a GPIO pin.

### Parameters

- **`pin_no`**: GPIO pin number.
- **`val`**: Value to set.

### Return

- None

### Note

- None

---

## `void gpio_set_debounce_time(int div)`  <!--DONE-->

### Description

Sets the debounce time for GPIO pins. Requires 2 external clock cycles.

### Parameters

- **`div`**: Debounce time divider.

### Return

- None

### Note

- **`div`** is a 12 bit divider, the debounce time can be calculated by the following formula: 
$$\frac{2 * \text{div}}{\text{core\_clk}}$$

---

## `void gpio_set_int_source(int pin_no, GPIO_INT_TYPE_T inttype, int debounce_en, gpio_isr_callback_fn callback)` <!--DONE-->

### Description

Configures the interrupt source for a GPIO pin.

### Parameters

- **`pin_no`**: GPIO pin number.
- **`inttype`**: Type of interrupt (rising edge, falling edge, etc.).
- **`debounce_en`**: Enable (1) or disable (0) debounce.
- **`callback`**: Interrupt service routine callback function.

### Return

- None

### Note

- None

---

## `void gpio_enable_int(int pin_no, int en)` <!--DONE-->

### Description

Enables or disables interrupts for a GPIO pin.

### Parameters

- **`pin_no`**: GPIO pin number.
- **`en`**: Enable (1) or disable (0) interrupts.

### Return

- None

### Note

- Please refer to [Interrupt Pin](#interrupt-pin)

---
