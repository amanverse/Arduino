//first , you need to insstall the motor driver for L293D motor driver
// Go to Sketch-> Include Librabry-> Manage Library-> Search for Adafruit Motor Shield V1
#include <AFMotor.h>
#include <SoftwareSerial.h>

SoftwareSerial HC05(10,9); //rx, tx

//initial motors pin
AF_DCMotor motor1(1);
AF_DCMotor motor2(2);
AF_DCMotor motor3(3);
AF_DCMotor motor4(4);

char command;

void setup()
{
  // Serial.begin(4800);
  HC05.begin(9600);  //Set the baud rate to your Bluetooth module.
}

void loop() 
{
   if (HC05.available() > 0) 
   {
     command = HC05.read();
     //Stop(); //initialize with motors stoped  
     switch (command)
      {
       case 'F':
        //  Serial.println("forward");
         forward();
         break;
       case 'B':
        //  Serial.println("back");
         back();
         break;
       case 'L':
        //  Serial.println("left");
         left();
         break;
       case 'R':
        //  Serial.println("right");
         right();
         break;
     }
   }
}

void forward()
{
  motor1.setSpeed(255); //Define maximum velocity
  motor1.run(FORWARD);  //rotate the motor clockwise
  motor2.setSpeed(255); //Define maximum velocity
  motor2.run(FORWARD);  //rotate the motor clockwise
  motor3.setSpeed(255); //Define maximum velocity
  motor3.run(FORWARD);  //rotate the motor clockwise
  motor4.setSpeed(255); //Define maximum velocity
  motor4.run(FORWARD);  //rotate the motor clockwise
  delay(50);
  Stop();
}

void back()
{
  motor1.setSpeed(255); //Define maximum velocity
  motor1.run(BACKWARD); //rotate the motor anti-clockwise
  motor2.setSpeed(255); //Define maximum velocity
  motor2.run(BACKWARD); //rotate the motor anti-clockwise
  motor3.setSpeed(255); //Define maximum velocity
  motor3.run(BACKWARD); //rotate the motor anti-clockwise
  motor4.setSpeed(255); //Define maximum velocity
  motor4.run(BACKWARD); //rotate the motor anti-clockwise
  delay(50);
  Stop();
}

void left()
{
  motor1.setSpeed(150); //Define maximum velocity
  motor1.run(BACKWARD); //rotate the motor clockwise
  motor2.setSpeed(150); //Define lower velocity
  motor2.run(BACKWARD); //rotate the motor clockwise
  motor3.setSpeed(255); //Define maximum velocity
  motor3.run(FORWARD);  //rotate the motor clockwise
  motor4.setSpeed(255); // Define lower velocity
  motor4.run(FORWARD);  //rotate the motor clockwise
  delay(50);
  Stop();
}

void right()
{
  motor1.setSpeed(255); //Define lower velocity
  motor1.run(FORWARD);  //rotate the motor clockwise
  motor2.setSpeed(255); //Define maximum velocity
  motor2.run(FORWARD);  //rotate the motor clockwise
  motor3.setSpeed(150); //Define lower velocity
  motor3.run(BACKWARD); //rotate the motor clockwise
  motor4.setSpeed(150); //Define maximum velocity
  motor4.run(BACKWARD); //rotate the motor clockwise
  delay(50);
  Stop();
}

void Stop()
{
  motor1.setSpeed(0);  //Define minimum velocity
  motor1.run(RELEASE); //stop the motor when release the button
  motor2.setSpeed(0);  //Define minimum velocity
  motor2.run(RELEASE); //rotate the motor clockwise
  motor3.setSpeed(0);  //Define minimum velocity
  motor3.run(RELEASE); //stop the motor when release the button
  motor4.setSpeed(0);  //Define minimum velocity
  motor4.run(RELEASE); //stop the motor when release the button
}
