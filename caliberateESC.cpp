#include <Arduino.h>
#include <Servo.h>

Servo esc1;
char x = 0; // x is no longer needed globally for calibration

void setup() {
  Serial.begin(9600);
  esc1.attach(9); // attach ESC to pin 9

  Serial.println("--- ESC Calibration Start ---");
  
  // 1. Send Max Throttle Signal (2000µs)
  // This tells the ESC to enter calibration mode.
  esc1.writeMicroseconds(2000); 
  Serial.println("Signal: MAX (2000us) sent.");
  Serial.println("Connect the main battery to the ESC NOW.");
  
  // Wait for ESC to power up and beep the MAX throttle confirmation.
  // The delay time must be longer than the ESC's startup time.
  delay(5000); // 5 seconds to connect battery and hear max confirmation beeps
  
  // 2. Send Min Throttle Signal (1000µs)
  // This tells the ESC to save the range and arm.
  esc1.writeMicroseconds(1000); 
  Serial.println("Signal: MIN (1000us) sent.");
  
  // Wait for ESC to beep the MIN throttle confirmation/arming tone.
  delay(12000); // 12 seconds for ESC to save the setting and arm, bldc takes about 10 sec to caliberate
  
  Serial.println("--- Calibration Complete ---");
  Serial.println("ESC is armed. Loop() will now begin.");
}

void loop() {
  Serial.println("Started. Ramping up motor speed...");

  // Motor Test Sequence (Safe Range: 1000µs to 2000µs)
  for(int speed = 1100; speed <= 2000; speed += 100)
  {
    esc1.writeMicroseconds(speed);
    Serial.print("Setting Pulse Width: ");
    Serial.println(speed);
    delay(1000);
  }
  
  // Stop Motor Sequence
  Serial.println("Sequence Complete. Setting speed to zero.");
  esc1.writeMicroseconds(1000); // 1000µs is the safe zero throttle
  
  delay(5000); // Wait 5 seconds before repeating the speed test
}