# SDK Overview

The Talpa SDK requires two operating systems: **Ubuntu 20.04 or later** for building the project, and **Windows 10 or later** for flashing the program into memory.

## Building the Project - Under Linux

### Installing WSL on Windows
It is recommended to use the [Windows Subsystem for Linux (WSL)]() within the Windows environment and to connect to WSL using [Visual Studio Code (VSCode)](https://code.visualstudio.com/) for development purposes.

### Building the Project:
Build the example project by executing the following commands:
 ```bash    
    tar -xzvf Talpa_SDK_package.tar.gz
    cd Talpa_SDK_package
    bash install.sh

    cd Talpa_SDK/project
    bash createNBF.sh
 ```

## Flashing the Program - Under Windows

- Download the `CH341A Driver` from [here]() on your Windows system.
- Download the `SPI Flasher` from [here]() on your Windows system.
- Move the `.nbf` file under `Talpa_SDK/project` to your Windows system.
- Set the CPU to the reset state[*](#note-for-aiyecam-talpa-db-users-simply-press-the-reset-button-on-the-board-see-picture-below), select the `.nbf` file that was moved to your Windows system in the previous step, and click the `Update` icon to flash the program into memory.


###### *Note: For AiyeCam-Talpa-DB users, press the reset button on the board to place the CPU in the reset state. (See the picture below.)
