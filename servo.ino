#include <ESP32_Servo.h>
Servo servo_poubelle;

int servoPin = 26;

void setup() {
  servo_poubelle.attach(servoPin);
}

void loop() {
  servo_poubelle.write(90);
  delay(2000);
  servo_poubelle.write(0);
}
