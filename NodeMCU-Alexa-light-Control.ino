#include <ESP8266WiFi.h>
#include <fauxmoESP.h>

// WiFi credentials
const char* ssid = "YOUR_SSID";
const char* password = "YOUR_PASSWORD";

// Define GPIO pin for the relay
#define RELAY_PIN 4  // Change this to D2 pin on NodeMCU to avoid potential GPIO conflicts

// FauxmoESP instance
fauxmoESP fauxmo;

void setup() 
{
  // Initialize the serial port
  Serial.begin(115200);

  // Set up the relay pin
  pinMode(RELAY_PIN, OUTPUT);
  digitalWrite(RELAY_PIN, HIGH); // Relay off

  // Connect to WiFi
  Serial.printf("Connecting to %s ", ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) 
  {
    Serial.print(".");
    delay(1000);
  }
  Serial.println();
  Serial.printf("Connected to WiFi! IP address: %s\n", WiFi.localIP().toString().c_str());

  // Initialize Fauxmo
  fauxmo.createServer(true);  // Allow remote control of your device
  fauxmo.setPort(80);         // Set web server port
  fauxmo.enable(true);        // Enable fauxmoESP

  fauxmo.addDevice("Kitchen lights"); // This is the name that Alexa will recognize

  fauxmo.onSetState([](unsigned char device_id, const char * device_name, bool state, unsigned char value) 
  {
    Serial.printf("[MAIN] Device #%d (%s) state: %s\n", device_id, device_name, state ? "ON" : "OFF");

    if (state) 
    {
      digitalWrite(RELAY_PIN, LOW); // Turn the light on
    }
    else 
    {
      digitalWrite(RELAY_PIN, HIGH); // Turn the light off
    }
  });
}

void loop() 
{
  fauxmo.handle(); // Let Fauxmo process Alexa requests
  delay(10);       // Adding a small delay improves stability
}
