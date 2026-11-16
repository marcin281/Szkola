
#include <Keypad.h>

#define BUZZER 10
#define PIR 9
#define LED 11

const byte ROWS = 4;
const byte COLS = 4;

char keys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

byte rowPins[ROWS] = {1, 2, 3, 4};
byte colPins[COLS] = {5, 6, 7, 8};

Keypad keypad = Keypad(makeKeymap(keys),
                       rowPins, colPins,
                       ROWS, COLS);

int melody[] = {2000, 1000};
int noteDuration = 500;

bool systemON = false;

void setup() {
  pinMode(BUZZER, OUTPUT);
  pinMode(PIR, INPUT);
  pinMode(LED, OUTPUT);

  digitalWrite(LED, LOW);

  Serial.begin(9600);
  Serial.println("Nacisnij # aby wlaczyc system");
}

void loop() {

  if (!systemON) {
    char key = keypad.getKey();

    if (key == '#') {
      delay(5000);
      systemON = true;
      Serial.println("SYSTEM WLACZONY!");
    }

    return;
  }

  if (digitalRead(PIR) == HIGH) {

    Serial.println("WYKRYTO RUCH!");

    for (int i = 0; i < 2; i++) {

      if (digitalRead(PIR) == LOW) {
        noTone(BUZZER);
        digitalWrite(LED, LOW);
        break;
      }

      digitalWrite(LED, HIGH);
      tone(BUZZER, melody[i]);
      delay(noteDuration);

      digitalWrite(LED, LOW);
      noTone(BUZZER);
      delay(30);
    }

  } else {
    noTone(BUZZER);
    digitalWrite(LED, LOW);
  }
}
