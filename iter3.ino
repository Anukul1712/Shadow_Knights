#include <Wire.h>
#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>
#include <math.h>
#include <SoftwareSerial.h>
SoftwareSerial BTSerial(11, 12);
const int Thumb = A6;
const int INDEX = A3;
const int MIDDLE = A2;

int lastSum = 0, prevSum = 0;

Adafruit_MPU6050 imu;
int thumbval, indexval, middleval, ringval, pinkyval;
int t, i, m, r, p;

void setup() {
  Serial.begin(9600);
  BTSerial.begin(38400);

  if (!imu.begin()) {
    Serial.println("MPU6050 connection failed!");
    while (1);
  }
  pinMode(Thumb, INPUT);
  pinMode(INDEX, INPUT);
  pinMode(MIDDLE, INPUT);

  Serial.println("MPU6050 connected.");
}

int calculateSum() {
    int t = (analogRead(Thumb) < 845) ? 0 : 2;
    int i = (analogRead(INDEX) < 815) ? 0 : 2;
    int m = (analogRead(MIDDLE) < 845) ? 0 : 2;
    return t + 10 * i + 100 * m;
}

void dynamicFunction(int current, int previous) {
    if (current == 2 && previous == 222) {
        Serial.println(" SYSTEM IS ");
    } else if(current == 0 && previous == 222){
        Serial.println("The System is working.");
    } else {
      Serial.println("THE SYSTEM IS WORKING")
    }
}

void loop() {
  sensors_event_t a, g, temp;
  imu.getEvent(&a, &g, &temp);

  float acc[3] = {a.acceleration.x / 9.81, a.acceleration.y / 9.81, a.acceleration.z / 9.81};
  float gyro[3] = {g.gyro.x * 180 / PI, g.gyro.y * 180 / PI, g.gyro.z * 180 / PI};

  float pitch = atan2(acc[0], sqrt(acc[1] * acc[1] + acc[2] * acc[2])) * 180 / PI;
  float roll = atan2(acc[1], sqrt(acc[0] * acc[0] + acc[2] * acc[2])) * 180 / PI;
  int sum = calculateSum();
  Serial.println(sum);
  if (sum == lastSum) {
        switch (sum) {
        case 2: Serial.println("YO !!!"); break;
        case 20: Serial.println("Nicely"); break;
        case 22: Serial.println("F*** YOU!!!!"); break;
        case 200: Serial.println("Smile"); break;
        case 202:  Serial.println("We are Shadow Knights"); break;
        case 220: Serial.println("Objection Killed"); break;
        case 222: Serial.println("Cheers"); break;
        default:
          if (pitch > 45) {
          Serial.println(gyro[1] > 100 ? "Gesture: Tilt Up with Fast Upward Rotation" : "All Hail *");
          } else if (pitch < -45) {
          Serial.println(gyro[1] < -100 ? "Gesture: Tilt Down with Fast Downward Rotation" : "Bhagwan ke naam pe lele re baba, Roboism mai");
          } else if (roll > 45) {
          Serial.println(gyro[0] > 100 ? "Gesture: Tilt Right with Fast Right Rotation" : "Hello");
          } else if (roll < -45) {
          Serial.println(gyro[0] < -100 ? "Gesture: Tilt Left with Fast Left Rotation" : "Come here");
          } else if (gyro[2] > 100) {
          Serial.println("Juice Pila do");
          } else if (gyro[2] < -100) {
          Serial.println("Side hoja be");
          } else {
          Serial.println("Gesture: Neutral");
          }
          break;
          }
    } else {
        dynamicFunction(sum, lastSum);
    }
  prevSum = lastSum;
  lastSum = sum;

  delay(500);

  Serial.println(sum);
  if (Serial.available()) {
        BTSerial.write(Serial.read());
    }
}
