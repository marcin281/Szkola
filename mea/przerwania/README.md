🚦 Inteligentna sygnalizacja świetlna z czujnikami PIR

Opis projektu



Projekt przedstawia system inteligentnej sygnalizacji świetlnej dla czterech kierunków ruchu, sterowany za pomocą mikrokontrolera Arduino. System wykorzystuje cztery czujniki ruchu PIR do wykrywania obecności obiektów i przydzielania zielonego światła odpowiedniemu kierunkowi.



Po wykryciu ruchu przez czujnik system dodaje dany kierunek do kolejki żądań. Gdy aktualnie aktywny kierunek zakończy swój cykl, sterownik uruchamia kolejny kierunek oczekujący w kolejce.



Każdy kierunek otrzymuje zielone światło na 5 sekund, po czym sygnalizacja wraca do czerwonego światła.



🛠️ Wykorzystane elementy

Arduino UNO z mikrokontrolerem ATmega328P

4 czujniki ruchu PIR

4 zielone diody LED

4 czerwone diody LED

Rezystory ograniczające prąd diod LED

Płytka stykowa i przewody połączeniowe

Przewód USB do programowania Arduino

🔌 Schemat połączeń

Sygnalizacja świetlna

Kierunek	Zielone światło	Czerwone światło

Kierunek 1	Pin 3	Pin 2

Kierunek 2	Pin 4	Pin 5

Kierunek 3	Pin 6	Pin 7

Kierunek 4	Pin 8	Pin 9

Czujniki PIR

Czujnik	Pin Arduino	Kierunek

PIR 1	12	Kierunek 1

PIR 2	13	Kierunek 2

PIR 3	11	Kierunek 3

PIR 4	10	Kierunek 4



Każdy czujnik PIR należy podłączyć zgodnie z oznaczeniami na module: VCC do zasilania, GND do masy oraz OUT do odpowiedniego pinu Arduino.



Diody LED należy podłączyć przez rezystory ograniczające prąd.



⚙️ Zasada działania

Po uruchomieniu Arduino wszystkie kierunki otrzymują czerwone światło.

Sterownik monitoruje sygnały z czterech czujników PIR.

Wykrycie ruchu powoduje dodanie odpowiedniego kierunku do kolejki żądań.

Jeśli dany kierunek jest już aktywny lub znajduje się w kolejce, nie jest dodawany ponownie.

Gdy nie ma aktywnego zielonego światła, sterownik wybiera następny kierunek z kolejki.

Wybrany kierunek otrzymuje zielone światło na 5 sekund, a pozostałe kierunki mają światło czerwone.

Po upływie 5 sekund zielone światło zostaje wyłączone, a sterownik przechodzi do kolejnego oczekującego kierunku.



Jeśli żaden czujnik nie wykryje ruchu i kolejka jest pusta, wszystkie kierunki pozostają na czerwonym świetle.



🧠 Obsługa przerwań



Projekt wykorzystuje przerwania zmiany stanu portu B mikrokontrolera ATmega328P (PCINT0\_vect) do wykrywania zmian sygnałów na pinach 10, 11, 12 i 13.



Dzięki temu mikrokontroler może wykrywać ruch bez konieczności ciągłego odczytywania tych czterech wejść w głównej pętli programu.



W procedurze przerwania zapisywane są jedynie flagi informujące o wykryciu ruchu. Obsługa kolejki i sterowanie światłami odbywają się w funkcji loop().



Dostęp do współdzielonych flag jest na krótko zabezpieczany przez noInterrupts() i interrupts(), aby bezpiecznie przekazać informacje między procedurą przerwania a główną pętlą.



📋 Najważniejsze parametry programu

Parametr	Wartość

Liczba kierunków	4

Liczba czujników PIR	4

Czas zielonego światła	5000 ms

Maksymalna liczba oczekujących kierunków	4

Mikrokontroler docelowy	ATmega328P

Mechanizm wykrywania ruchu	Przerwania PCINT

