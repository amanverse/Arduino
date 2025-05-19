const int DIR = 12; // direction pin
const int STEP = 14; // step pin
const int  steps_per_rev = 2000; // no of step to complete 1 revolution 

void setup()
{
  Serial.begin(115200);
  pinMode(STEP, OUTPUT);
  pinMode(DIR, OUTPUT);
}
void loop()
{
  digitalWrite(DIR, HIGH); // direction = high = clockwise
  Serial.println("Spinning Clockwise...");
  
  for(int i = 0; i<steps_per_rev; i++)
  {
    digitalWrite(STEP, HIGH);
    delayMicroseconds(500); // controlling this delay adjust the speed
    digitalWrite(STEP, LOW); // faster high to low & low to high = faster the step = faster it moves
    delayMicroseconds(500);
  }
  // delay(1000); 
  
  // digitalWrite(DIR, LOW); // direction = low = anti-clockwise
  // Serial.println("Spinning Anti-Clockwise...");

  // for(int i = 0; i<steps_per_rev; i++)
  // {
  //   digitalWrite(STEP, HIGH);
  //   delayMicroseconds(1000);
  //   digitalWrite(STEP, LOW);
  //   delayMicroseconds(1000);
  // }
  // delay(1000);
}