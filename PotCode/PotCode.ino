#include <Servo.h>

const int potPin = A0;

int previousValue = 0;
int currentValue = 0;
int servoPin = 2;

Servo myservo;

void setup() {
  Serial.begin(9600);
  myservo.attach(servoPin);
  pinMode(potPin, INPUT);
}

void loop() {
  // currentValue = analogRead(potPin);

  // if (currentValue != previousValue) {
  //   Serial.println(currentValue);
  //   previousValue = currentValue;
  //   int output = map(currentValue, 0, 1023, 0, 120);
  //   myservo.write(output);
  // }

  myservo.write(45);
  delay(2000);
  myservo.write(90);
  delay(2000);
  myservo.write(180);
  delay(2000);
}