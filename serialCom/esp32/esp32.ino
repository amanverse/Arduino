// for doit esp32 devkit v1

#define RXp2 16
#define TXp2 17
int i = 0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial2.begin(9600, SERIAL_8N1, RXp2, TXp2);
  pinMode(2, OUTPUT);
}
void loop() {
    Serial2.println(i);
    int k = Serial2.readString().toInt();
    Serial.println(k);
    Serial.print(i);
    if (k % 2 ==0)
      digitalWrite(2, LOW);
    else
      digitalWrite(2, HIGH);
    i++;
    delay(1000);
}