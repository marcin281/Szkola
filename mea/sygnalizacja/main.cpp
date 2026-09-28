const int zielone1 = 3;
const int czerwone1 = 2;

const int zielone2 = 4;
const int czerwone2 = 5;

const int zielone3 = 6;
const int czerwone3 = 7;

const int zielone4 = 8;
const int czerwone4 = 9;


const unsigned long CZERWONE_CZAS = 2000;
const unsigned long ZIELONE_CZAS = 5000;


// 0 - czerwone
// 1 - zielone 1
// 2 - czerwone
// 3 - zielone 2
// 4 - czerwone
// 5 - zielone 3
// 6 - czerwone
// 7 - zielone 4

int stan = 0;

unsigned long czas = 0;


void czerwone() {
  digitalWrite(zielone1, LOW);
  digitalWrite(czerwone1, HIGH);

  digitalWrite(zielone2, LOW);
  digitalWrite(czerwone2, HIGH);

  digitalWrite(zielone3, LOW);
  digitalWrite(czerwone3, HIGH);

  digitalWrite(zielone4, LOW);
  digitalWrite(czerwone4, HIGH);
}


void setup() {

  pinMode(zielone1, OUTPUT);
  pinMode(czerwone1, OUTPUT);

  pinMode(zielone2, OUTPUT);
  pinMode(czerwone2, OUTPUT);

  pinMode(zielone3, OUTPUT);
  pinMode(czerwone3, OUTPUT);

  pinMode(zielone4, OUTPUT);
  pinMode(czerwone4, OUTPUT);

  czerwone();

  czas = millis();
}


void loop() {

  unsigned long teraz = millis();


  // CZERWONE 2 sekundy
  if (stan == 0 && teraz - czas >= CZERWONE_CZAS) {
    stan = 1;
    czas = teraz;

    digitalWrite(czerwone1, LOW);
    digitalWrite(zielone1, HIGH);
  }


  // ZIELONE 1 - 5 sekund
  else if (stan == 1 && teraz - czas >= ZIELONE_CZAS) {
    stan = 2;
    czas = teraz;

    czerwone();
  }


  // CZERWONE 2 sekundy
  else if (stan == 2 && teraz - czas >= CZERWONE_CZAS) {
    stan = 3;
    czas = teraz;

    digitalWrite(czerwone2, LOW);
    digitalWrite(zielone2, HIGH);
  }


  // ZIELONE 2 - 5 sekund
  else if (stan == 3 && teraz - czas >= ZIELONE_CZAS) {
    stan = 4;
    czas = teraz;

    czerwone();
  }


  // CZERWONE 2 sekundy
  else if (stan == 4 && teraz - czas >= CZERWONE_CZAS) {
    stan = 5;
    czas = teraz;

    digitalWrite(czerwone3, LOW);
    digitalWrite(zielone3, HIGH);
  }


  // ZIELONE 3 - 5 sekund
  else if (stan == 5 && teraz - czas >= ZIELONE_CZAS) {
    stan = 6;
    czas = teraz;

    czerwone();
  }


  // CZERWONE 2 sekundy
  else if (stan == 6 && teraz - czas >= CZERWONE_CZAS) {
    stan = 7;
    czas = teraz;

    digitalWrite(czerwone4, LOW);
    digitalWrite(zielone4, HIGH);
  }


  // ZIELONE 4 - 5 sekund
  else if (stan == 7 && teraz - czas >= ZIELONE_CZAS) {
    stan = 0;
    czas = teraz;

    czerwone();
  }
}
