#include <SoftwareSerial.h>
const int Thumb = A0;
const int INDEX = A1;
const int MIDDLE = A2;
const int RING = A3;
const int PINKY = A4;

int thumbval, indexval, middleval, ringval, pinkyval;
int t, i, m, r, p;

void setup() {
  
    Serial.begin(9600);
    pinMode(Thumb, INPUT);
    pinMode(INDEX, INPUT);
    pinMode(MIDDLE, INPUT);
    pinMode(RING, INPUT);
    pinMode(PINKY, INPUT);
}

void value() {
    t = (analogRead(Thumb) < 300) ? 0 : (analogRead(Thumb) < 600) ? 1 : 2;
    i = (analogRead(INDEX) < 300) ? 0 : (analogRead(INDEX) < 600) ? 1 : 2;
    m = (analogRead(MIDDLE) < 300) ? 0 : (analogRead(MIDDLE) < 600) ? 1 : 2;
    r = (analogRead(RING) < 300) ? 0 : (analogRead(RING) < 600) ? 1 : 2;
    p = (analogRead(PINKY) < 300) ? 0 : (analogRead(PINKY) < 600) ? 1 : 2;
}

void loop() {
    value();  // Call the value function to update t, i, m, r, p

    int sum = t + 10*i + 100*m + 1000*r + 10000*p;  // Calculate sum
    
    Serial.println(sum);  // Correctly capitalized
    SoftwareSerial mySerial(10, 11);
    delay(500);
}
