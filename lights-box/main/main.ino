#include "pitches.h"

// constants won't change. They're used here to set pin numbers:
const int ledPin4 =  5;
const int ledPin3 =  4;
const int ledPin1 =  2;
const int ledPin2 =  3;
const int ledPin5 =  6;
const int ledPin6 =  7;
const int ledPin7 =  8;
const int ledPin8 =  9;

const int buttonPin1 = A0;
const int buttonPin2 = A1;

const int buzzerPin = A5;

int stateButton = 0;
int counter = 0;

int stateSong = 0;

void setup() {
  // initialize the LED pin as an output:
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);
  pinMode(ledPin4, OUTPUT);
  pinMode(ledPin5, OUTPUT);
  pinMode(ledPin6, OUTPUT);
  pinMode(ledPin7, OUTPUT);
  pinMode(ledPin8, OUTPUT);

  // initialize the BUZZER as an outout:
  pinMode(buzzerPin, OUTPUT);

  // initialize the pushbutton pin as an input:
  pinMode(buttonPin1, INPUT);
  pinMode(buttonPin2, INPUT);
  pinMode(buttonPin3, INPUT);

  Serial.begin(9600);
}

void beep(int note, int duration)
{
  //Play tone on buzzerPin
  tone(buzzerPin, note, duration);

  if(counter % 2 == 0) {
    digitalWrite(ledPin1, HIGH);
    delay(duration);
    digitalWrite(ledPin1, LOW);
  }
  else {
    digitalWrite(ledPin8, HIGH);
    delay(duration);
    digitalWrite(ledPin8, LOW);
  }

  //Stop tone on buzzerPin
  noTone(buzzerPin);

  delay(50);

  //Increment counter
  counter++;
}

void loop() {
  // read the state of the pushbutton value:
  int buttonPin1State = digitalRead(buttonPin1);
  int buttonPin2State = digitalRead(buttonPin2);
  int buttonPin3State = digitalRead(buttonPin3);

  Serial.print("Button1: ");
  Serial.print(buttonPin1State);
  Serial.print(" / Button2: ");
  Serial.print(buttonPin2State);
  Serial.print(" / Button3: ");
  Serial.println(buttonPin3State);
  Serial.print("State:");
  Serial.println(stateButton);
  if (buttonPin1State == LOW) {
    stateButton = 1;
  } else if (buttonPin2State == LOW) {
    if (stateButton == 2) {
      stateButton = 0;
    } else {
      stateButton = 2;
    }
  } else if (buttonPin3State == LOW) {
    if (stateButton == 3) {
      stateButton = 0;
    } else {
      stateButton = 3;
    }
  }

  if (stateButton == 1) {
    Serial.println(" 'Song'");
    if (stateSong == 1) {
      singMario(2);
    }
    if (stateSong == 2) {
      singNoel(1);
    }
    if (stateSong == 3) {
      singNoel(2);
    }
    if (stateSong == 4) {
      singNoel(3);
    }
    if (stateSong == 5) {
       starWarsIntro();
    }
    if (stateSong == 6) {
      stateSong = 0;
    } else {
      stateSong++;
    }

    stateButton = 0;
  }


  if (stateButton == 0) {
    Serial.println(" 'Serpent LED'");
    digitalWrite(ledPin1, HIGH);

    delay(100);

    digitalWrite(ledPin1, LOW);
    digitalWrite(ledPin2, HIGH);

    delay(100);

    digitalWrite(ledPin2, LOW);
    digitalWrite(ledPin3, HIGH);

    delay(100);

    digitalWrite(ledPin3, LOW);
    digitalWrite(ledPin4, HIGH);

    delay(100);

    digitalWrite(ledPin4, LOW);
    digitalWrite(ledPin5, HIGH);

    delay(100);

    digitalWrite(ledPin5, LOW);
    digitalWrite(ledPin6, HIGH);

    delay(100);

    digitalWrite(ledPin6, LOW);
    digitalWrite(ledPin7, HIGH);

    delay(100);

    digitalWrite(ledPin7, LOW);
    digitalWrite(ledPin8, HIGH);

    delay(100);

    digitalWrite(ledPin8, LOW);
  }

  if (stateButton == 2) {
    Serial.println(" 'Blink LED'");
    digitalWrite(ledPin1, HIGH);
    digitalWrite(ledPin3, HIGH);
    digitalWrite(ledPin5, HIGH);
    digitalWrite(ledPin7, HIGH);

    delay(300);

    digitalWrite(ledPin1, LOW);
    digitalWrite(ledPin3, LOW);
    digitalWrite(ledPin5, LOW);
    digitalWrite(ledPin7, LOW);

    digitalWrite(ledPin2, HIGH);
    digitalWrite(ledPin4, HIGH);
    digitalWrite(ledPin6, HIGH);
    digitalWrite(ledPin8, HIGH);

    delay(300);
    digitalWrite(ledPin2, LOW);
    digitalWrite(ledPin4, LOW);
    digitalWrite(ledPin6, LOW);
    digitalWrite(ledPin8, LOW);
  }

  if (stateButton == 3) {
    Serial.println(" 'Duo Blink LED'");
    digitalWrite(ledPin1, HIGH);
    digitalWrite(ledPin2, HIGH);

    delay(300);

    digitalWrite(ledPin1, LOW);
    digitalWrite(ledPin2, LOW);
    digitalWrite(ledPin5, HIGH);
    digitalWrite(ledPin6, HIGH);

    delay(300);

    digitalWrite(ledPin5, LOW);
    digitalWrite(ledPin6, LOW);
    digitalWrite(ledPin3, HIGH);
    digitalWrite(ledPin4, HIGH);

    delay(300);

    digitalWrite(ledPin3, LOW);
    digitalWrite(ledPin4, LOW);
    digitalWrite(ledPin7, HIGH);
    digitalWrite(ledPin8, HIGH);

    delay(300);

    digitalWrite(ledPin7, LOW);
    digitalWrite(ledPin8, LOW);
  }
}
