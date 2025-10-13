#include <Servo.h>
#include <SoftwareSerial.h>

// All motor pins are digital port
#define lBac 2 // IN1
#define lFow 4 // IN2
#define rBac 7 // IN3
#define rFow 8 // IN4

// All servo pins are PWM port
Servo shoulder; // SG5010
Servo elbow;    // SG5010
Servo wrist;    // SG90
Servo gripper;  // SG90
Servo rotate;   // MG996R

SoftwareSerial BT(0, 1);
// Connect RX in 0
// Connect TX in 1

void setup()
{
  Serial.begin(9600);
  BT.begin(9600);
  pinMode(lBac, OUTPUT);
  pinMode(lFow, OUTPUT);
  pinMode(rBac, OUTPUT);
  pinMode(rFow, OUTPUT);
}

void loop()
{
  while (BT.available())
  {
    char comm = BT.read();
    Serial.println(comm);

    switch (comm)
    {
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
  }
  // TryOutServo
  // int pos = 0;
  // int angle = map(pos, 0, 1023, 0, 255);
  // shoulder.write(angle);
}

void foward()
{
  digitalWrite(lBac, LOW);
  digitalWrite(lFow, HIGH);
  digitalWrite(rBac, LOW);
  digitalWrite(rFow, HIGH);
}

void backward()
{
  digitalWrite(lBac, HIGH);
  digitalWrite(lFow, LOW);
  digitalWrite(rBac, HIGH);
  digitalWrite(rFow, LOW);
}

void right()
{
  digitalWrite(lBac, LOW);
  digitalWrite(lFow, LOW);
  digitalWrite(rBac, LOW);
  digitalWrite(rFow, HIGH);
}

void left()
{
  digitalWrite(lBac, LOW);
  digitalWrite(lFow, LOW);
  digitalWrite(rBac, HIGH);
  digitalWrite(rFow, LOW);
}

void stop()
{
  digitalWrite(lBac, LOW);
  digitalWrite(lFow, LOW);
  digitalWrite(rBac, LOW);
  digitalWrite(rFow, LOW);
}