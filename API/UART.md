
# UART <!--DONE-->

## `void uart_init(uint32_t baudrate, uint8_t line_control, uint8_t div)` <!--DONE-->

### Description

Initializes the UART with specified settings.

### Parameters

- **`baudrate`**: UART baud rate.
- **`line_control`**: Line control settings.
- **`div`**: Divider for baud rate calculation.

### Return

- None

### Note

- None

---

## `void uart_set_baudrate(uint32_t baudrate)` <!--DONE-->

### Description

Sets the UART baud rate.

### Parameters

- **`baudrate`**: Desired baud rate.

### Return

- None

### Note

- None

---

## `void uart_putc(char c)` <!--DONE-->

### Description

Sends a character over UART.

### Parameters

- **`c`**: Character to send.

### Return

- None

### Note

- None

---

## `char uart_getc(void)` <!--DONE-->

### Description

Receives a character from UART.

### Parameters

- None

### Return

- **`char`**: Received character.

### Note

- None

---

## `int uart_tstc(void)`

### Description

Tests if a character is available to read from UART.

### Parameters

- None

### Return

- **`int`**: 1 if a character is available, 0 otherwise.

### Note

- None
