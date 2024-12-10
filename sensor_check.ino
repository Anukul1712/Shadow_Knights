// Define the pin for the flex sensor
const int flexSensorPin = A0; // Change to your analog pin

void setup() {
  // Start the serial communication
  Serial.begin(9600);
}

void loop() {
  // Read the value from the flex sensor
  int flexValue = analogRead(flexSensorPin);
  
  // Print the value to the Serial Monitor
  Serial.print("Flex Sensor Reading: ");
  Serial.println(flexValue);
  
  // Wait a bit before the next reading
  delay(500);
}
