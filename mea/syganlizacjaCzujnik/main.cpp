const int zielone1 = 3;
const int czerwone1 = 2;

const int zielone2 = 4;
const int czerwone2 = 5;

const int zielone3 = 6;
const int czerwone3 = 7;

const int zielone4 = 8;
const int czerwone4 = 9;

// Czujniki PIR
const int pir1 = 12;
const int pir2 = 13;
const int pir3 = 11;
const int pir4 = 10;

// Czas świecenia zielonego
const unsigned long czasZielonego = 5000;

// Kolejka żądań
bool kolejka[4] = {false, false, false, false};

// Aktualnie obsługiwane światło (-1 = brak)
int aktywneSwiatlo = -1;

unsigned long czasStartu = 0;

// Poprzedni stan czujników
bool poprzedniRuch[4] = {false, false, false, false};

const int zielone[4] = {
  zielone1, zielone2, zielone3, zielone4
};

const int czerwone[4] = {
  czerwone1, czerwone2, czerwone3, czerwone4
};

const int pir[4] = {
  pir1, pir2, pir3, pir4
};

void setup() {
  for (int i = 0; i < 4; i++) {
    pinMode(zielone[i], OUTPUT);
    pinMode(czerwone[i], OUTPUT);
    pinMode(pir[i], INPUT);
  }

  wszystkieCzerwone();
}

void wszystkieCzerwone() {
  for (int i = 0; i < 4; i++) {
    digitalWrite(zielone[i], LOW);
    digitalWrite(czerwone[i], HIGH);
  }
}

void wlaczZielone(int nr) {
  wszystkieCzerwone();

  digitalWrite(czerwone[nr], LOW);
  digitalWrite(zielone[nr], HIGH);

  aktywneSwiatlo = nr;
  czasStartu = millis();
}

void loop() {
  // Sprawdzanie czujników i dodawanie do kolejki
  for (int i = 0; i < 4; i++) {
    bool ruch = digitalRead(pir[i]) == HIGH;

    // Dodaj do kolejki tylko przy nowym wykryciu ruchu
    if (ruch && !poprzedniRuch[i]) {
      kolejka[i] = true;
    }

    poprzedniRuch[i] = ruch;
  }

  // Jeśli zielone świeci już 5 sekund, zakończ obsługę
  if (aktywneSwiatlo != -1 &&
      millis() - czasStartu >= czasZielonego) {

    digitalWrite(zielone[aktywneSwiatlo], LOW);
    digitalWrite(czerwone[aktywneSwiatlo], HIGH);

    aktywneSwiatlo = -1;
  }

  // Jeśli żadne światło nie jest aktywne, obsłuż kolejkę
  if (aktywneSwiatlo == -1) {
    for (int i = 0; i < 4; i++) {
      if (kolejka[i]) {
        kolejka[i] = false;
        wlaczZielone(i);
        break;
      }
    }
  }
}
