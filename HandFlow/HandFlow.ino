// Library Importing
#include <WiFi.h>
#include <WiFiClient.h>
#include <FirebaseESP32.h>

// Firebase Credentials
#define FIREBASE_HOST "handflow2-c9fc1-default-rtdb.asia-southeast1.firebasedatabase.app/"
#define FIREBASE_AUTH "rHamjnzIl2kZQxFXyIW5AeILsO4IgMqpqm4MKHY0"

// WiFi Credentials
#define WIFI_SSID "HandFlow"
#define WIFI_PASSWORD "Thenaman8@"

// Define FirebaseESP32 data object
FirebaseData firebaseData;
FirebaseJson json;

// Define Pins
#define D1 13  // Device Relay for other devices
#define R1 12  // Low Speed Relay
#define R2 14  // Medium Speed Relay
#define R3 27  // High Speed Relay

void setup() {
  // Initialize Serial and WiFi
  Serial.begin(115200);
  pinMode(D1, OUTPUT); // Device relay pin
  pinMode(R1, OUTPUT); // Low Speed Relay pin
  pinMode(R2, OUTPUT); // Medium Speed Relay pin
  pinMode(R3, OUTPUT); // High Speed Relay pin
  
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
  Firebase.reconnectWiFi(true);

  Serial.println("Ready");  

  // Initialize all relays to off
  turnOffAll();
}

void loop() {
  // Fetch the gestureData from Firebase
  if (Firebase.getString(firebaseData, "/gestureData")) {
    String gestureData = firebaseData.dataPath();
    
    // Read the actual values
    String deviceValue = firebaseData.dataPath() + "/device"; // Path to device
    String commandValue = firebaseData.dataPath() + "/command"; // Path to command
    String levelValue = firebaseData.dataPath() + "/level"; // Path to level

    // Handle the command based on the device
    handleDeviceControl(deviceValue, commandValue, levelValue);
  } else {
    Serial.println("Failed to get data from Firebase");
  }

  delay(1000); // Wait for 1 second before checking again
}

// Function to turn off all device
void turnOffAll() {
  digitalWrite(R1, LOW);
  digitalWrite(R2, LOW);
  digitalWrite(R3, LOW);
  digitalWrite(D1, LOW); // Turn off the device
}

// Function to turn off all fan relays
void turnOffFanRelays() {
  digitalWrite(R1, LOW);
  digitalWrite(R2, LOW);
  digitalWrite(R3, LOW);
}

// Function for Low Speed
void fanLow() {
  turnOffFanRelays();  // Ensure all fan relays are off
  digitalWrite(R1, HIGH); // Activate low speed relay
}

// Function for Medium Speed
void fanMedium() {
  turnOffFanRelays();  // Ensure all fan relays are off
  digitalWrite(R2, HIGH); // Activate medium speed relay
}

// Function for High Speed
void fanHigh() {
  turnOffFanRelays();  // Ensure all fan relays are off
  digitalWrite(R3, HIGH); // Activate high speed relay
}

// Function to control fan based on input level
void controlFanSpeed(int level) {
  if (level < 0 || level > 5) {
    turnOffFanRelays(); // Turn off the fan if level is invalid
    return;
  }
  
  switch (level) {
    case 0:
      turnOffFanRelays(); // Turn off the fan
      break;
    case 1:
      fanLow(); // Low speed
      break;
    case 2:
      fanMedium(); // Medium speed
      break;
    case 3:
      fanHigh(); // High speed
      break;
    case 4:
    case 5:
      fanHigh(); // Use high speed for levels 4 and 5
      break;
    default:
      turnOffFanRelays(); // Default to off
      break;
  }
}

// Function to handle device control based on commands
void handleDeviceControl(String device, String command, String level) {
    int levelInt = level.toInt(); // Convert level from string to integer

    if (device == "device_fan") {
        if (command == "on") {
            // If level is empty or invalid, set it to medium speed
            if (level == "" || levelInt < 0 || levelInt > 5) {
                levelInt = 2; // Default to medium speed
            }
            controlFanSpeed(levelInt); // Control fan speed based on level
        } else if (command == "off") {
            turnOffFanRelays(); // Turn off the fan
        }
    } else if (device == "device_1") { // Example for another device
        controlDevice(command == "on"); // Turn on or off the device
    }
}


// Function to control the device connected to D1
void controlDevice(bool state) {
  digitalWrite(D1, state ? HIGH : LOW); // Turn on or off the device
}
