README – Sterowanie światłami z czujnikami PIR

Opis projektu



Program steruje czterema zestawami świateł (zielone/czerwone) z wykorzystaniem czterech czujników ruchu PIR. W przypadku wykrycia ruchu światła są sterowane bezpośrednio przez czujniki.



Zasada działania

Tryb normalny: światła zmieniają się kolejno od 1 do 4.

Czerwone światło: świeci przez 2 sekundy przed włączeniem kolejnego zielonego.

Zielone światło: świeci przez 5 sekund.

Wykrycie ruchu: zielone światło włącza się dla kierunków, w których czujniki PIR wykryły ruch, a pozostałe światła pozostają czerwone.

Brak ruchu: po ustaniu ruchu wszystkie światła przechodzą na czerwone, a następnie rozpoczyna się normalna sekwencja od początku.

Przypisanie pinów

Element	Pin Arduino

Zielone 1	3

Czerwone 1	2

Zielone 2	4

Czerwone 2	5

Zielone 3	6

Czerwone 3	7

Zielone 4	8

Czerwone 4	9

Czujnik PIR 1	12

Czujnik PIR 2	13

Czujnik PIR 3	11

Czujnik PIR 4	10

Wykorzystane elementy

Arduino

4 czujniki ruchu PIR

4 zielone diody LED

4 czerwone diody LED

Rezystory do diod LED

Przewody połączeniowe

Technologie

Język programowania: C++ (Arduino)

Funkcje czasu: millis()

Odczyt czujników: digitalRead()

Sterowanie światłami: digitalWrite()
