// for uno r3
int j = 0;
void setup() {
  Serial.begin(9600);
  pinMode(13, OUTPUT);
}
void loop() {
  Serial.println(j);
  if(Serial.available())
  {
    int k = Serial.parseInt();
    if (k % 2 == 0)
      digitalWrite(13, LOW);
    else 
      digitalWrite(13,HIGH);
  }
  j++;
  delay(2000);
}

