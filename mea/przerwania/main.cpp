
#include <avr/interrupt.h>

// Sygnalizacja świetlna
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

const unsigned long czasZielonego = 5000;

// Kolejka kierunków
int kolejka[4];
int poczatek = 0;
int koniec = 0;
int liczbaWKolejce = 0;

int aktywnyKierunek = -1;
unsigned long czasStartu = 0;

// Poprzednie stany czujników
volatile uint8_t poprzedniStan = 0;

// Flagi ustawiane przez przerwania
volatile bool wykrytoPir[4] = {false, false, false, false};

const int pinyZielone[4] = {
  zielone1, zielone2, zielone3, zielone4
};

const int pinyCzerwone[4] = {
  czerwone1, czerwone2, czerwone3, czerwone4
};

const int pinyPIR[4] = {
  pir1, pir2, pir3, pir4
};

void ustawCzerwone() {
  for (int i = 0; i < 4; i++) {
    digitalWrite(pinyZielone[i], LOW);
    digitalWrite(pinyCzerwone[i], HIGH);
  }
}

bool jestWKolejceLubAktywny(int kierunek) {
  if (aktywnyKierunek == kierunek) {
    return true;
  }

  for (int i = 0; i < liczbaWKolejce; i++) {
    int indeks = (poczatek + i) % 4;

    if (kolejka[indeks] == kierunek) {
      return true;
    }
  }

  return false;
}

void dodajDoKolejki(int kierunek) {
  if (jestWKolejceLubAktywny(kierunek)) {
    return;
  }

  if (liczbaWKolejce < 4) {
    kolejka[koniec] = kierunek;
    koniec = (koniec + 1) % 4;
    liczbaWKolejce++;

    Serial.print("Dodano do kolejki kierunek: ");
    Serial.println(kierunek + 1);
  }
}

void rozpocznijKierunek(int kierunek) {
  aktywnyKierunek = kierunek;
  czasStartu = millis();

  ustawCzerwone();

  digitalWrite(pinyCzerwone[kierunek], LOW);
  digitalWrite(pinyZielone[kierunek], HIGH);

  Serial.print("Zielone dla kierunku: ");
  Serial.println(kierunek + 1);
}

void setup() {
  Serial.begin(9600);

  for (int i = 0; i < 4; i++) {
    pinMode(pinyZielone[i], OUTPUT);
    pinMode(pinyCzerwone[i], OUTPUT);
    pinMode(pinyPIR[i], INPUT);
  }

  ustawCzerwone();

  // Zapamiętaj początkowy stan czujników na porcie B
  poprzedniStan = PINB & 0b00111100;

  // Włącz przerwania zmiany stanu portu B
  PCICR |= (1 << PCIE0);

  // Piny 10, 11, 12, 13
  PCMSK0 |= (1 << PCINT2); // PIR4, pin 10
  PCMSK0 |= (1 << PCINT3); // PIR3, pin 11
  PCMSK0 |= (1 << PCINT4); // PIR1, pin 12
  PCMSK0 |= (1 << PCINT5); // PIR2, pin 13
}

// Przerwanie dla czujników PIR na pinach 10–13
ISR(PCINT0_vect) {
  uint8_t stan = PINB & 0b00111100;
  uint8_t zmiana = stan ^ poprzedniStan;

  // PIR1: pin 12, PB4
  if ((zmiana & (1 << PB4)) && (stan & (1 << PB4))) {
    wykrytoPir[0] = true;
  }

  // PIR2: pin 13, PB5
  if ((zmiana & (1 << PB5)) && (stan & (1 << PB5))) {
    wykrytoPir[1] = true;
  }

  // PIR3: pin 11, PB3
  if ((zmiana & (1 << PB3)) && (stan & (1 << PB3))) {
    wykrytoPir[2] = true;
  }

  // PIR4: pin 10, PB2
  if ((zmiana & (1 << PB2)) && (stan & (1 << PB2))) {
    wykrytoPir[3] = true;
  }

  poprzedniStan = stan;
}

void loop() {
  // Pobierz flagi z przerwań
  bool ruchPir[4];

  noInterrupts();

  for (int i = 0; i < 4; i++) {
    ruchPir[i] = wykrytoPir[i];
    wykrytoPir[i] = false;
  }

  interrupts();

  // Dodaj wykryte kierunki do kolejki
  for (int i = 0; i < 4; i++) {
    if (ruchPir[i]) {
      dodajDoKolejki(i);
    }
  }

  // Zakończenie zielonego światła po 5 sekundach
  if (aktywnyKierunek != -1 &&
      millis() - czasStartu >= czasZielonego) {

    digitalWrite(pinyZielone[aktywnyKierunek], LOW);
    digitalWrite(pinyCzerwone[aktywnyKierunek], HIGH);

    Serial.print("Koniec zielonego kierunku: ");
    Serial.println(aktywnyKierunek + 1);

    aktywnyKierunek = -1;
  }

  // Uruchomienie następnego kierunku z kolejki
  if (aktywnyKierunek == -1 && liczbaWKolejce > 0) {
    int nastepny = kolejka[poczatek];

    poczatek = (poczatek + 1) % 4;
    liczbaWKolejce--;

    rozpocznijKierunek(nastepny);
  }
}
