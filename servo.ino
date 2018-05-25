#include <ESP32_Servo.h>
Servo servo_poubelle;

int servoPin = 26, pos = 0;

void setup() {
  Serial.begin(9600);
  servo_poubelle.attach(servoPin);
  servo_poubelle.write(pos); // put the servo at 0
}

void loop() {
  for (pos = 0; pos <= 200; pos += 1) { // +
    servo_poubelle.write(pos);
    delay(15);
  }
  delay(2000);
  for (pos = 200; pos >= 0; pos -= 1) { // -
    servo_poubelle.write(pos);
    delay(15);
  }
}
