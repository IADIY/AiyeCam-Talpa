# SPI <!--TODO--> 

## `int spi_init(int master_slave, int data_rate, int type, int phase, int cs_gpio, int bus_width)` <!--DONE-->

### Description

Initializes the SPI interface with specified settings.

### Parameters

- **`master_slave`**: Mode (master or slave).
    - ```SPI_MASTER```
    - ```SPI_SLAVE```

- **`data_rate`**: Data rate for SPI.

- **`type`**: SPI type (e.g., mode 0, mode 1).
    - ```SPI_FRAME_FORMAT_MOTORROLA```
    - ```SPI_FRAME_FORMAT_TI```
    - ```SPI_FRAME_FORMAT_NS```

- **`phase`**: Clock phase.
    - ```SPI_MODE_0```
    - ```SPI_MODE_1```
    - ```SPI_MODE_2```
    - ```SPI_MODE_3```

- **`cs_gpio`**: Chip select GPIO pin.
- **`bus_width`**: Bus width (e.g., 8-bit, 16-bit).

### Return

- **`int`**: Status of the initialization.

### Note

- None

---

## `void spi_set_speed(unsigned long speed)` <!--DONE-->

### Description

Sets the speed of the SPI interface.

### Parameters

- **`speed`**: SPI speed in Hz.

### Return

- None

### Note

- None

---

## `void spi_cs_active(int active)` <!--DONE-->

### Description

Activates or deactivates the SPI chip select.

### Parameters

- **`active`**: Chip select active state (1 for active, 0 for inactive).

### Return

- None

### Note

- None

---

## `int spi_polling_xfer(unsigned int bitlen, const void* dout, void* din, unsigned long flags)` <!--DONE-->

### Description

Performs SPI transfer using polling mode.

### Parameters

- **`bitlen`**: Length of the data in bits.
- **`dout`**: Pointer to data to send.
- **`din`**: Pointer to store received data.
- **`flags`**: Transfer flags.

### Return

- **`int`**: Status of the transfer.  Returns 0 on success, non-zero on failure.

### Note

- None

---

## `int spi_xfer(unsigned int bitlen, const void* dout, void* din, unsigned long flags)` <!--DONE-->

### Description

Performs an SPI transfer.

### Parameters

- **`bitlen`**: Length of the data in bits.
- **`dout`**: Pointer to data to send.
- **`din`**: Pointer to store received data.
- **`flags`**: Transfer flags.

### Return

- **`int`**: Status of the transfer.  Returns 0 on success, non-zero on failure.

### Note

- None

---

## `int spi_polling_xfer_write_only(unsigned int bitlen, const void* dout, void* din, unsigned long flags)` <!--DONE-->

### Description

Performs an SPI transfer with write-only mode using polling.

### Parameters

- **`bitlen`**: Length of the data in bits.
- **`dout`**: Pointer to data to send.
- **`din`**: Pointer to store received data (may be unused).
- **`flags`**: Transfer flags.

### Return

- **`int`**: Status of the transfer.

### Note

- Normally unused, only used after playing audio.
