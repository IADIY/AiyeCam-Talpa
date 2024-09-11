# I2C <!--TODO-->

## `int i2c_init(void)` <!--DONE-->

### Description

Initializes the I2C subsystem.

### Parameters

- None

### Return

- **`int`**: Status of initialization. Returns 0 on success, non-zero on failure.

### Note

- Note

---

## `int i2c_set_speed_mode(int mode)` <!--DONE-->

### Description

Sets the I2C speed mode.

### Parameters

- **`mode`**:
    ```0```: Standard mode.
    ```1```: Fast Speed mode.
    

### Return

- **`int`**: Returns 0 on success, non-zero on failure.

### Note

- Note

---

## `int i2c_xfer(uint32_t dev, uint32_t addr, int alen, uint8_t *buffer, int len, int flags)` <!--DONE-->

### Description

Performs an I2C transfer.

### Parameters

- **`dev`**: I2C device address.
- **`addr`**: Register address or data address.
- **`alen`**: Address length.
- **`buffer`**: Pointer to data buffer.
- **`len`**: Length of data to transfer.
- **`flags`**: Transfer flags.

### Return

- **`int`**: Length of transfer data when success. <0 when failed. 

### Note

- Note

---

## `int i2c_write_reg(unsigned int slave_addr, uint32_t reg, uint32_t addr_len, uint32_t val, uint32_t data_len)` <!--DONE-->

### Description

Writes a value to an I2C register.

### Parameters

- **`slave_addr`**: I2C slave address.
- **`reg`**: Register address.
- **`addr_len`**: Address length.
- **`val`**: Value to write.
- **`data_len`**: Length of data.

### Return

- **`int`**: Returns 0 on success, non-zero on failure.

### Note

- Note

---

## `int i2c_write_group(unsigned int slave_addr, unsigned char *cfg, int size, int addr_len, int data_len)` <!--DONE-->

### Description

Writes a group of registers on an I2C device.

### Parameters

- **`slave_addr`**: I2C slave address.
- **`cfg`**: Pointer to configuration data.
- **`size`**: Size of the configuration data.
- **`addr_len`**: Address length.
- **`data_len`**: Length of data.

### Return

- **`int`**: Returns 0 on success, non-zero on failure.

### Note

- Note

---

## `int i2c_read_reg(slave, reg, 1, (uint32_t *)pval, 1)` <!--DONE-->

### Description

Reads a single byte from an I2C register.

### Parameters

- **`slave`**: I2C slave address.
- **`reg`**: Register address.
- **`pval`**: Pointer to store the read value.

### Return

- **`int`**: Returns 0 on success, non-zero on failure.

### Note

- Note

---

