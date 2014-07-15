/*

  Trivial Arduino Click-Bot.
  You will need a Arduino with HID-Support (Leonardo, Micro, Due or patched Uno)
  
 
 */
 
 
// Define Button & LED Pins
const unsigned int Button = 2;

// How often i should click
const unsigned int ClickCNT = 90;

// How long should be waited between mouse clicks (milsecs)
const unsigned int minCNT = 3030;
const unsigned int maxCNT = 3140;

// How long the mousebutton should be pressed (milsecs)
// (time between button click and button release)
const unsigned int pressedMin = 3;
const unsigned int pressedMax = 34;

// How long should be waited after button press to start the Bot (ATM unused)
const unsigned int waittime = 15000; 

void setup() {
  Serial.begin(9600);
  pinMode(Button, INPUT);

  Mouse.begin();
}

void loop() {

  int ButtonState = digitalRead(Button);
  int ClickDelay = 0;
  int PressDelay = 0;

  int delaytime = 3000;
  
  if (ButtonState == HIGH)
  {

    for(int i = 0; i < ClickCNT ; i++)
    {
      ClickDelay = random(minCNT, maxCNT);
      PressDelay = random(pressedMin, pressedMax);
      Mouse.press();
      delay(PressDelay);
      Mouse.release();
      delay(ClickDelay);
    }
  }
  delay(250);
}
