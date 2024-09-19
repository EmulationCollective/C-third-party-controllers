

# Third-Party Controller Support on Xbox - Project C

## Overview

**Project C** provides a simple framework for testing and demonstrating third-party controller support on Xbox using the Xbox Devstore Helper (`https://xboxdev.store/api/helper/`). This project helps developers understand how to map various third-party controllers (e.g., PS4, PS5, Switch Pro, Stadia, Xbox 360) to their Xbox equivalents using the Universal Windows Platform (UWP) Remote Input API.

This project does not directly include controller mappings or support for every third-party controller but serves as a reference implementation for capturing and handling controller events using the UWP Remote Input API.

## Key Features

- Maps standard Xbox controller buttons to their key codes.
- Supports third-party controllers mapped to Xbox equivalents via Xbox Devstore Helper.
- Captures button press/release events for every button on a standard Xbox controller.
- Provides a framework for developers to implement and test third-party controllers on Xbox.

## Controller Key Mapping

The table below shows the key codes for each button on a standard Xbox controller. These key codes are used to identify the buttons in the code:

| Button              | Key                  | Keycode |
|---------------------|----------------------|---------|
| A                   | GamepadA             | 195     |
| B                   | GamepadB             | 196     |
| X                   | GamepadX             | 197     |
| Y                   | GamepadY             | 198     |
| D-pad Up            | GamepadDpadUp        | 203     |
| D-pad Down          | GamepadDpadDown      | 204     |
| D-pad Left          | GamepadDpadLeft      | 205     |
| D-pad Right         | GamepadDpadRight     | 206     |
| Left Shoulder (L1)  | GamepadLeftShoulder  | 200     |
| Right Shoulder (R1) | GamepadRightShoulder | 199     |
| Left Trigger (L2)   | GamepadLeftTrigger   | 201     |
| Right Trigger (R2)  | GamepadRightTrigger  | 202     |
| Menu                | GamepadMenu          | 207     |
| View                | GamepadView          | 208     |
| Left Stick Up       | GamepadLeftThumbstickUp | 211  |
| Left Stick Down     | GamepadLeftThumbstickDown | 212 |
| Left Stick Left     | GamepadLeftThumbstickLeft | 214 |
| Left Stick Right    | GamepadLeftThumbstickRight | 213 |
| Right Stick Up      | GamepadRightThumbstickUp | 215 |
| Right Stick Down    | GamepadRightThumbstickDown | 216 |
| Right Stick Left    | GamepadRightThumbstickLeft | 218 |
| Right Stick Right   | GamepadRightThumbstickRight | 217 |
| Left Stick Button (L3) | GamepadLeftThumbstickButton | 209 |
| Right Stick Button (R3) | GamepadRightThumbstickButton | 210 |

## Usage

### Prerequisites

- Visual Studio with UWP development tools
- Xbox Development Mode enabled
- Xbox Devstore Helper (`https://xboxdev.store/api/helper/`)

### Running the Project

1. Clone the repository and open the Visual Studio solution file.
2. Ensure you have the necessary dependencies installed.
3. Build and deploy the app to your Xbox development environment.
4. The application will display key codes for button presses on any connected third-party controller mapped using Xbox Devstore Helper.

### Capturing Controller Input

The project captures input events and maps them to the corresponding key codes listed above. These inputs are either pressed, held, or released, providing a simple mechanism to test third-party controllers on Xbox.

### Example Code Usage

The project includes example code for handling controller input events in `MainPage.xaml.cpp` and `MainPage.xaml.h`. These files demonstrate how to register for controller input events and handle them within a UWP application.

### XAML and C++ Example

The project contains a simple XAML and C++ example demonstrating how to capture and display controller input events. Please refer to the source files `MainPage.xaml.cpp` and `MainPage.xaml.h` for detailed implementation.

## Reference Documentation

- [UWP Remote Input API](https://learn.microsoft.com/en-us/windows/uwp/xbox-apps/uwp-remoteinput-api)

## Notes

- This project is designed for use **ONLY** with the Xbox Devstore Helper.
- The project is intended for developers looking to implement third-party controller support in their games on the Xbox platform.
- The key codes are subject to change based on updates to the UWP Remote Input API.
- Joycon sticks (Eg right and left stick) do not return an axis (from 0 to 1) but a key press (Pressed or Released) instead. You will need to emulate gradual axis using this information.

## License

This project is licensed under the MIT License.
