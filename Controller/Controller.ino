// for switches
const int switch1 = 13;
const int switch2 = 12;
const int switch3 = 14;
const int switch4 = 27;

int sw1 = 0;
int sw2 = 0;
int sw3 = 0;
int sw4 = 0;

// for potetiometer
const int pot_pin = 4;
int pott = 0;

// for joystick 1
const int joysw1 = 33; // for joystick press button
const int joyy1 = 35; // for x direction analog
const int joyx1 = 34; // for y direction analog

int jx1 = 0;
int j_x1 = 0;
int jy1 = 0;
int j_y1 = 0;

// for joystick 2
const int joysw2 = 26; // for joystick press button
const int joyy2 = 25; // for x direction analog
const int joyx2 = 32; // for y direction analog

int jx2 = 0;
int j_x2 = 0;
int jy2 = 0;
int j_y2 = 0;

const int threshold = 10;
const int deadband = 5;

void Switch();  // fun for switches

void Joystick1(); // fun for joystick 1

void Joystick2(); // fun for joystick 2

void Pot(); // fun for Potentiometer

void setup() 
{
  
  Serial.begin(9600);
  pinMode(switch1, INPUT);
  pinMode(switch2, INPUT);
  pinMode(switch3, INPUT);
  pinMode(switch4, INPUT);

  pinMode(joysw1, INPUT_PULLUP);
  pinMode(joysw2, INPUT_PULLUP);

  analogSetAttenuation(ADC_11db); // set for all pins at once; 11db for 3.3V
  // analogSetAttenution(pin, attentuation_value); : to make adc read input voltage directly in particular voltage range, not needed in Arduino Board
}

void loop() 
{
    Switch();

    Joystick1();

    Joystick2();

    Pot();

}

// function for reading 4 push button switches
void Switch()
{
    sw1  = digitalRead(switch1);
    if (sw1>0)
    {
      Serial.println("Switch 1 is pressed");
      sw1=0;
    }

    sw2 = digitalRead(switch2);
    if (sw2>0)
    {
      Serial.println("Switch 2 is pressed");
      sw2=0;
    }
    sw3 = digitalRead(switch3);
    if (sw3>0)
    {
      Serial.println("Switch 3 is pressed");
      sw3=0;
    }

    sw4 = digitalRead(switch4);
    if (sw4>0)
    {
      Serial.println("Switch 4 is pressed");
      sw4=0;
    }
}

// function for reading joystick 1 
void Joystick1()
{
  int jsw1 = 1;   // normally it is close, when pressed it opens
    jsw1 = digitalRead(joysw1);
    if (jsw1 == 0)
      Serial.println("Joystick 1 swithch is pressed");

    jy1 = map(analogRead(joyy1), 0, 4095, -100, 100); // analog in y direction
    if (abs(jy1)<deadband)// if variation due to fluctuation at rest, make to zero again
      jy1 = 0;
    if (jy1-j_y1>threshold || jy1-j_y1<-threshold) // print if value changes
    {
      Serial.print("y = ");
      Serial.println(jy1);
      j_y1 = jy1;
    }

    jx1 = map(analogRead(joyx1), 0, 4095, -100, 100); // analog in x direction
    if (abs(jx1) < deadband) // if variation due to fluctuation at rest, make to zero again
      jx1 = 0;

    if (jx1-j_x1>threshold || jx1-j_x1<-threshold) // print if value changes
    {
      Serial.print("x = ");
      Serial.println(jx1);
      j_x1 = jx1;
    }
}

// funtion for reading joystick 2 
void Joystick2()
{
    int jsw2 = 1;   // normally it is close, when pressed it opens
    jsw2 = digitalRead(joysw2);
    if (jsw2 == 0)
      Serial.println("Joystick 2 swithch is pressed");

    jy2 = map(analogRead(joyy2), 0, 4095, -100, 100); // analog in y direction
    if (abs(jy2)<deadband)// if variation due to fluctuation at rest, make to zero again
      jy2 = 0;
    if (jy2-j_y2>threshold || jy2-j_y2<-threshold) // print if value changes
    {
      Serial.print("y = ");
      Serial.println(jy2);
      j_y2 = jy2;
    }

    jx2 = map(analogRead(joyx2), 0, 4095, -100, 100); // analog in x direction
    if (abs(jx2) < deadband) // if variation due to fluctuation at rest, make to zero again
      jx2 = 0;

    if (jx2-j_x2>threshold || jx2-j_x2<-threshold) // print if value changes
    {
      Serial.print("x = ");
      Serial.println(jx2);
      j_x2 = jx2;
    }
}

// funtion to read potentiometer
void Pot()
{
    int pot = map(analogRead(pot_pin), 0, 4095, 0, 100);
    if (pot!=pott)
      {
        Serial.print("Potentiometer = ");
        Serial.println(pot);
        pott=pot;
      }
}