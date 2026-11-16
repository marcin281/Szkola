# System Alarmowy z Czujnikiem Ruchu PIR (Arduino)

Prosty system alarmowy oparty na mikrokontrolerze Arduino. Wykorzystuje czujnik ruchu (PIR), klawiaturę membranową 4x4 do uzbrajania systemu oraz sygnalizację świetlno-dźwiękową (dioda LED i buzzer).

## Funkcjonalności

* **Uzbrajanie z opóźnieniem:** System uruchamia się po wciśnięciu przycisku `#` na klawiaturze. Posiada 5-sekundowe opóźnienie (czas na opuszczenie pomieszczenia).
* **Detekcja ruchu:** Ciągłe monitorowanie otoczenia za pomocą czujnika PIR po uzbrojeniu systemu.
* **Alarm dźwiękowy i wizualny:** W przypadku wykrycia ruchu buzzer emituje dwutonowy sygnał alarmowy (2000 Hz i 1000 Hz), a dioda LED miga synchronicznie z dźwiękiem.
* **Podgląd w Serial Monitorze:** Komunikaty o stanie systemu (oczekiwanie, uzbrojenie, wykrycie ruchu) są przesyłane przez port szeregowy (9600 bps).

## Wymagane komponenty

* Płytka rozwojowa **Arduino** (np. Uno, Nano, Mega)
* **Czujnik ruchu PIR** (np. HC-SR501)
* **Klawiatura membranowa 4x4**
* **Buzzer pasywny** (wymagany do generowania różnych częstotliwości za pomocą funkcji `tone()`)
* **Dioda LED** + rezystor ograniczający prąd (np. 220 Ω)
* Przewody połączeniowe i płytka stykowa

## Schemat podłączenia (Pinout)

| Komponent | Pin na komponencie | Pin Arduino |
| :--- | :--- | :--- |
| **Czujnik PIR** | OUT (Sygnał) | `D9` |
| **Buzzer** | `+` (Sygnał) | `D10` |
| **Dioda LED** | Anoda (`+`) przez rezystor | `D11` |
| **Klawiatura 4x4** | Wiersze (R1 - R4) | `D1`, `D2`, `D3`, `D4` |
| **Klawiatura 4x4** | Kolumny (C1 - C4) | `D5`, `D6`, `D7`, `D8` |

> **Uwaga dotycząca pinu D1:** W kodzie wiersz R1 klawiatury podłączony jest do pinu `D1` (TX). Może to powodować zakłócenia w komunikacji przez Serial Monitor lub problemy z wgrywaniem kodu. W razie trudności zaleca się odłączenie przewodu z pinu `D1` na czas programowania płytki lub przeniesienie go na inny wolny pin (np. `D12` lub piny analogowe `A0`-`A5`).

## Instalacja i uruchomienie

1. **Biblioteki:** Upewnij się, że masz zainstalowaną bibliotekę `Keypad` autorstwa Marka Stanleya i Alexandra Breviga w swoim środowisku Arduino IDE (*Szkic -> Dołącz bibliotekę -> Zarządzaj bibliotekami -> wyszukaj "Keypad"*).
2. **Połączenie:** Złóż układ zgodnie z powyższą tabelą połączeń.
3. **Wgranie kodu:** Otwórz kod źródłowy w Arduino IDE, wybierz odpowiednią płytkę oraz port COM, a następnie kliknij **Wgraj**.
4. **Obsługa:**
   * Otwórz **Monitor Portu Szeregowego** (prędkość `9600`).
   * Naciśnij `#` na klawiaturze, aby uzbroić alarm.
   * Odczekaj 5 sekund, aż pojawi się komunikat `SYSTEM WLACZONY!`.
   * Przetestuj działanie, wykonując ruch przed czujnikiem PIR.

## Możliwości rozwoju projektu

* Dodanie funkcji **rozbrajania alarmu** po wpisaniu 4-cyfrowego kodu PIN z klawiatury.
* Zastosowanie wyświetlacza **LCD** (np. 16x2 z konwerterem I2C) do wyświetlania komunikatów bez konieczności podłączania komputera.
* Zmiana pinu `D1` na inny wolny pin cyfrowy lub analogowy, aby uniknąć konfliktu z interfejsem UART (Serial).
