const int in1Pin = 2;
const int in2Pin = 3;
const int in3Pin = 8;
const int in4Pin = 9;

void setup() {
  pinMode(in1Pin, OUTPUT);
  pinMode(in2Pin, OUTPUT);
  pinMode(in3Pin, OUTPUT);
  pinMode(in4Pin, OUTPUT);
}

void loop() {
  // Rotate the motor forward
  digitalWrite(in1Pin, HIGH);
  digitalWrite(in2Pin, LOW);
  digitalWrite(in3Pin, HIGH);
  digitalWrite(in4Pin, LOW);
  delay(2000);

  // Rotate the motor backward
  digitalWrite(in1Pin, LOW);
  digitalWrite(in2Pin, HIGH);
  digitalWrite(in3Pin, LOW);
  digitalWrite(in4Pin, HIGH);
  delay(2000);

  // Stop the motor
  digitalWrite(in1Pin, LOW);
  digitalWrite(in2Pin, LOW);
  digitalWrite(in3Pin, LOW);
  digitalWrite(in4Pin, LOW);
  delay(2000);
}