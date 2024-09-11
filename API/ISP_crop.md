# Crop <!--DONE-->

## `void crop_init(void)` <!--DONE-->

### Description

Initializes the ISP cropping module.

### Parameters

- None

### Return

- None

### Note

- None

---

## `void crop_config_win(uint16_t sx, uint16_t sy, uint16_t width, uint16_t height)` <!--DONE-->

### Description

Configures the cropping window.

### Parameters

- **`sx`**: Starting X coordinate.
- **`sy`**: Starting Y coordinate.
- **`width`**: Width of the cropping window.
- **`height`**: Height of the cropping window.

### Return

- None

### Note

- None

---

## `void crop_enable(int module_en, int crop_en)` <!--DONE-->

### Description

Enables or disables the cropping module and cropping functionality.

### Parameters

- **`module_en`**: Enable(1) or disable(0) the cropping module.
- **`crop_en`**: Enable(1) or disable(0) cropping.

### Return

- None

### Note

- None

---

## `int crop_get_output_width(void)` <!--DONE-->

### Description

Gets the output width after cropping.

### Parameters

- None

### Return

- **`int`**: Output width.

### Note

- None

---

## `int crop_get_output_height(void)` <!--DONE-->

### Description

Gets the output height after cropping.

### Parameters

- None

### Return

- **`int`**: Output height.

### Note

- None
