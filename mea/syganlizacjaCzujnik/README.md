Sterowanie światłami z czujnikami PIR
Opis projektu

Program na Arduino sterujący czterema zestawami świateł za pomocą czterech czujników ruchu PIR.

Zasada działania
Czerwone światło – świeci przez 2 sekundy przed zmianą na zielone.
Zielone światło – świeci przez 5 sekund.
Wykrycie ruchu – zielone światło włącza się dla kierunków, w których czujniki PIR wykryły ruch.
Brak ruchu – wszystkie światła przechodzą na czerwone, a następnie rozpoczyna się normalna sekwencja.
Tryb normalny – światła zmieniają się kolejno od 1 do 4.
Przypisanie pinów
Element	Pin Arduino
Zielone światło 1	3
Czerwone światło 1	2
Zielone światło 2	4
Czerwone światło 2	5
Zielone światło 3	6
Czerwone światło 3	7
Zielone światło 4	8
Czerwone światło 4	9
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
C++ (Arduino)
digitalRead() – odczyt czujników
digitalWrite() – sterowanie światłami
millis() – kontrola czasu bez użycia delay()
