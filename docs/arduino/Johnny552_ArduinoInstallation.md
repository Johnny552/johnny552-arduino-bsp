# Johnny552 Arduino Installation Guide

## Overview

This guide provides step-by-step instructions for installing and setting up the Johnny552 development board in the Arduino IDE. The Johnny552 is based on the CH552 microcontroller, which requires specific board support packages to work with Arduino.

## Prerequisites

- Arduino IDE (version 1.8.x or later) installed on your computer
- Internet connection for downloading packages
- USB cable (USB-C) for connecting the Johnny552 board to your computer

## Installation Process

### Step 1: Install the CH55x Core

The CH55x core provides basic support for the CH552 microcontroller family:

1. Open Arduino IDE
2. Go to `File > Preferences`
3. In the "Additional Boards Manager URLs" field, add the following URL:
   ```
   https://raw.githubusercontent.com/DeqingSun/ch55xduino/ch55xduino/package_ch55xduino_mcs51_index.json
   ```
   If you already have URLs in this field, separate them with commas.
4. Click "OK" to save the preferences
5. Go to `Tools > Board > Boards Manager`
6. In the Boards Manager, search for "ch55x"
7. Find the "CH55x MCS51 Boards" package and click "Install"
8. Wait for the installation to complete

### Step 2: Install Johnny552 Board Support

To add specific support for the Johnny552 board:

1. Locate your Arduino hardware folder:
   - **Windows**: `%USERPROFILE%\Documents\Arduino\hardware`
   - **macOS**: `~/Documents/Arduino/hardware`
   - **Linux**: `~/Arduino/hardware`

2. Create a folder structure for the Johnny552 board support:
   - **Windows**: Open File Explorer, navigate to the Arduino hardware folder, and create a new folder named "johnny552"
   - **macOS/Linux**: Open Terminal and run:
     ```bash
     mkdir -p ~/Documents/Arduino/hardware/johnny552
     ```

3. Copy the ch55xduino folder from this repository to the johnny552 folder:
   - **Method 1 - Clone the repository and copy the folder**:
     ```bash
     # Clone the repository to a temporary location
     git clone https://github.com/jeroenvanzwam/johnny552-arduino-bsp.git /tmp/johnny552-temp
     
     # Copy the ch55xduino folder to the Arduino hardware folder
     cp -r /tmp/johnny552-temp/ch55xduino ~/Documents/Arduino/hardware/johnny552/
     ```
   
   - **Method 2 - Download and extract**:
     - Download the repository as a ZIP file from https://github.com/jeroenvanzwam/johnny552-arduino-bsp
     - Extract the ZIP file
     - Copy the "ch55xduino" folder from the extracted files to your Arduino hardware/johnny552 folder

4. Verify the folder structure. The path to the pins_arduino.h file should be:
   ```
   Arduino/hardware/johnny552/ch55xduino/ch55x/variants/johnny552/pins_arduino.h
   ```

5. Restart the Arduino IDE

### Step 3: Select the Johnny552 Board

1. Open Arduino IDE
2. Go to `Tools > Board`
3. You should see a new section called "Johnny552 Boards"
4. Select `Johnny552 Boards > Johnny552`

### Step 4: Configure Board Settings

Configure the appropriate settings for the Johnny552 board:

1. Go to `Tools > Upload Method` and select `USB`
2. Go to `Tools > Clock Source` and select the appropriate clock source (typically `16MHz Internal`)

## Programming the Johnny552

### Entering Programming Mode

To upload code to the Johnny552 board, you need to put it in programming mode:

1. Connect the Johnny552 board to your computer using a USB-C cable
2. Hold down the BOOT button on the board
3. While holding the BOOT button, press and release the RESET button
4. Release the BOOT button
5. The board is now in programming mode and ready to receive code

### Uploading Your First Sketch

1. Open the Blink example: `File > Examples > 01.Basics > Blink`
2. Modify the pin number if necessary (the Johnny552 has an LED connected to PIN_BUTTON)
3. Click the Upload button (right arrow icon) in the Arduino IDE
4. Wait for the upload to complete
5. The LED on your Johnny552 board should start blinking

## Troubleshooting

### Common Issues

1. **Board Not Found**
   - Ensure the board is properly connected
   - Check that you've entered programming mode correctly
   - Verify that the correct drivers are installed

2. **Upload Fails**
   - Try entering programming mode again
   - Check the selected port in `Tools > Port`
   - Restart the Arduino IDE
   - Try a different USB cable or port

3. **Board Not Listed**
   - Verify that the Johnny552 board support is installed correctly
   - Check the folder structure as described in Step 2.4
   - Restart the Arduino IDE

### Driver Installation

On some systems, you may need to install additional drivers:

- **Windows**: Windows might automatically install the required drivers. If not, you may need to install WCH CH55x drivers
- **macOS**: No additional drivers should be needed
- **Linux**: You may need to add udev rules to access the USB device without root privileges

## Additional Resources

- [Johnny552 Hardware Documentation](../hardware/johnny522_HardwareDocumentation.md)
- [CH55xduino Documentation](CH55xduino_Documentation.md)
- [Johnny552 GitHub Repository](https://github.com/YourUsername/johnny552-arduino-bsp)

## Support

If you encounter issues not covered in this guide, please:

- Check the [GitHub Issues](https://github.com/YourUsername/johnny552-arduino-bsp/issues) page
- Create a new issue with detailed information about your problem

---

Happy coding with your Johnny552 board!
