# NodeMCU-Alexa-Light-Control
To control a light using Alexa with a NodeMCU, you can utilize the FauxmoESP library, which simulates a Philips Hue device, allowing Alexa to discover and control the NodeMCU as a smart device.
This project allows you to control a relay module connected to an ESP8266 (NodeMCU) using Amazon Alexa voice commands. The ESP8266 is programmed to act as a simulated Philips Hue device using the FauxmoESP library, enabling Alexa to discover and control it as a smart light.

## Components Needed
- ESP8266 NodeMCU
- Relay module
- Light or any other device connected to the relay
- Amazon Alexa-enabled device (e.g., Echo Dot, Echo Show)
- Arduino IDE

## Wiring Diagram
- **Relay VCC** → NodeMCU 3.3V
- **Relay GND** → NodeMCU GND
- **Relay IN** → NodeMCU GPIO 4 (D2)

**Note:** This code uses GPIO 4 (D2) to control the relay. Make sure your relay module and connected device match the wiring.

## Getting Started

### 1. Prerequisites
- Install the [Arduino IDE](https://www.arduino.cc/en/software)
- Install the ESP8266 board in the Arduino IDE:
  1. Open Arduino IDE
  2. Go to `File > Preferences`
  3. Add the following URL in "Additional Board Manager URLs":
     ```
     http://arduino.esp8266.com/stable/package_esp8266com_index.json
     ```
  4. Go to `Tools > Board > Boards Manager` and search for "ESP8266" to install it.

- Install the FauxmoESP library:
  1. Go to `Sketch > Include Library > Manage Libraries`
  2. Search for "FauxmoESP" and install it

### 2. Upload the Code
1. Open the `alexa_control.ino` file in the Arduino IDE.
2. Replace the `ssid` and `password` variables with your WiFi network credentials.
3. Connect the ESP8266 to your computer via USB.
4. Select the correct board and port:
   - **Board:** `NodeMCU 1.0 (ESP-12E Module)`
   - **Port:** Select the appropriate COM port
5. Upload the code to the ESP8266.

### 3. Usage

- Once the code is uploaded, the ESP8266 will connect to your WiFi network.
- Alexa will recognize the device as "Kitchen lights."
- Open the Alexa app on your phone, go to **Devices > Add Device > Light > Other > Discover Devices**, or say "Alexa, discover devices."
- After discovery, you can control the relay by saying:
  - "Alexa, turn on the kitchen lights."
  - "Alexa, turn off the kitchen lights."

### 4. Notes
- Ensure your WiFi network and Alexa device are on the same network.
- The relay module can control any device connected to it (ensure it's within the relay's voltage/current specifications).
  
### 5. Troubleshooting
If Alexa doesn't discover the device, make sure:
- Both the ESP8266 and Alexa are on the same WiFi network.
- Multicast is enabled on your router.
- Your SSID doesn't contain special characters (especially commas or spaces).
### 6. License
This project is licensed under the MIT License.
