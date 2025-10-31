#include <Servo.h>
#include <SoftwareSerial.h>

// All motor pins are digital port
#define lBac 4
#define lFow 2
#define rBac 8
#define rFow 7

// All servo pins are PWM port
Servo shoulder;  // SG5010
Servo elbow;     // SG5010
// Servo wrist;     // SG90
// Servo gripper;   // SG90
// Servo rotate;    // MG996R

int shoulderPIN = 3;

// SoftwareSerial BT(0, 1);
// Connect RX in 0
// Connect TX in 1

void setup() {
  Serial.begin(9600);
  // BT.begin(9600);
  pinMode(lBac, OUTPUT);
  pinMode(lFow, OUTPUT);
  pinMode(rBac, OUTPUT);
  pinMode(rFow, OUTPUT);
  shoulder.attach(3);
  elbow.attach(6);
}

void loop() {

  while (Serial.available()) {
    char comm = Serial.read();
    Serial.println(comm);

    switch (comm) {
      case 'w':
        foward();
        break;
      case 's':
        backward();
        break;
      case 'l':
        left();
        break;
      case 'r':
        right();
        break;
      default:
        stop();
        break;
    }

    // if (comm == 1) {
    //   int pos = 180;
    //   int angle = map(pos, 0, 180, 0, 255);
    //   shoulder.write(angle);
    // } else if (comm = 2) {
    //   int pos = 0;
    //   int angle = map(pos, 0, 1023, 0, 255);
    //   shoulder.write(angle);
    // } else {
    //   int pos = 0;
    //   int angle = map(pos, 0, 1023, 0, 255);
    //   shoulder.write(angle);
    // }
  }

  // int pos = 180;
  // int angle = map(pos, 0, 180, 0, 160);
  // elbow.write(angle);

  // elbow.write(90);
  // delay(2000);
  // elbow.write(180);
  // delay(2000);
}

double calculateDistance(double degree) {
  double desiredTime = degree * 150 / 150;
  return desiredTime;
}

void foward() {
  digitalWrite(lBac, LOW);
  digitalWrite(lFow, HIGH);
  digitalWrite(rBac, LOW);
  digitalWrite(rFow, HIGH);
}

void backward() {
  digitalWrite(lBac, HIGH);
  digitalWrite(lFow, LOW);
  digitalWrite(rBac, HIGH);
  digitalWrite(rFow, LOW);
}

void right() {
  digitalWrite(lBac, LOW);
  digitalWrite(lFow, HIGH);
  digitalWrite(rBac, HIGH);
  digitalWrite(rFow, LOW);
}

void left() {
  digitalWrite(lBac, HIGH);
  digitalWrite(lFow, LOW);
  digitalWrite(rBac, LOW);
  digitalWrite(rFow, HIGH);
}

void stop() {
  digitalWrite(lBac, LOW);
  digitalWrite(lFow, LOW);
  digitalWrite(rBac, LOW);
  digitalWrite(rFow, LOW);
}