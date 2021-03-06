#define CUSTOM_SETTINGS
#define INCLUDE_GAMEPAD_MODULE
#include <Dabble.h>

int EN_right = 7;
int rMP1 = 11;
int rMP2 = 12;

int EN_left = 8;
int lMP1 = 9;
int lMP2 = 10;

void setup() {
  // put your setup code here, to run once:

  pinMode(EN_right, OUTPUT);
  pinMode(rMP1, OUTPUT);
  pinMode(rMP2, OUTPUT);

  pinMode(EN_left, OUTPUT);
  pinMode(lMP1, OUTPUT);
  pinMode(lMP2, OUTPUT);


  Dabble.begin(9600, 2, 3);
 
}

void loop() {
  // put your main code here, to run repeatedly:
  int rMP_speed = 0;
  int lMP_speed = 0;

  Dabble.processInput();

  if (GamePad.isUpPressed()){
    rMP_speed = -255;
    lMP_speed = -255;

    digitalWrite(rMP1, HIGH);
    digitalWrite(rMP2, LOW);
    digitalWrite(lMP1, LOW);
    digitalWrite(lMP2, HIGH);

  } else if (GamePad.isDownPressed()){
    rMP_speed = 255;
    lMP_speed = 255;

    digitalWrite(rMP1, LOW);
    digitalWrite(rMP2, HIGH);
    digitalWrite(lMP1, HIGH);
    digitalWrite(lMP2, LOW);
  
  } else if (GamePad.isLeftPressed()){
    rMP_speed = 255;
    lMP_speed = -255;

    digitalWrite(rMP1, HIGH);
    digitalWrite(rMP2, LOW);
    digitalWrite(lMP1, HIGH);
    digitalWrite(lMP2, LOW);

  } else if (GamePad.isRightPressed()){
    rMP_speed = -255;
    lMP_speed = 255;    
    
    digitalWrite(rMP1, LOW);
    digitalWrite(rMP2, HIGH);
    digitalWrite(lMP1, LOW);
    digitalWrite(lMP2, HIGH);

  }

  analogWrite(EN_right, abs(rMP_speed));
  analogWrite(EN_left, abs(lMP_speed));


}

