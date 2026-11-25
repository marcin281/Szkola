# Symulator Szlabanu (C++)

Prosta aplikacja konsolowa symulująca działanie automatycznego szlabanu oparta na maszynie stanów.

## Funkcjonalności
* **Płynny ruch (5s):** Otwieranie i zamykanie szlabanu trwa 5 sekund z możliwością przerwania w czasie rzeczywistym.
* **System alarmowy:** Naciśnięcie przycisku w trakcie ruchu szlabanu lub wywołanie alarmu natychmiast zatrzymuje mechanizm.
* **Detekcja pojazdów:** Wykrycie auta podczas podnoszenia lub opuszczania zapory skutkuje wystawieniem mandatu.

## Sterowanie
* `1` – Otwórz / Zamknij szlaban (gdy jest w ruchu: wywołuje **ALARM**)
* `3` – Wymuś **ALARM** podczas ruchu
* `4` – Symuluj wykrycie pojazdu (w ruchu = **mandat**)
* `5` – Reset alarmu (przywraca stan *zamknięty*)
* `0` – Wyjście z programu

## Wymagania i kompilacja
Program korzysta z biblioteki `<conio.h>`, dlatego przeznaczony jest dla systemu **Windows**.


```mermaid 
stateDiagram-v2
    state "0: Zamknięty" as S0
    state "1: Otwieranie" as S1
    state "2: Otwarty" as S2
    state "3: Zamykanie" as S3
    state "4: ALARM (Szlaban zatrzymany)" as S4
    state "P: SAMOCHÓD (Wykryto pojazd / Mandat = TAK)" as SP

    %% Otwieranie
    S0 --> S1 : Przycisk
    S1 --> S2 : Upływ 5s (brak samochodu)
    S1 --> SP : Klawisz w trakcie 5s (otwieranie) / Wykryto samochód + Mandat
    SP --> S2 : Upływ 5s (zakończenie otwierania)

    %% Zamykanie
    S2 --> S3 : Przycisk
    S3 --> S0 : Upływ 5s (brak samochodu)
    S3 --> SP : Klawisz w trakcie 5s (zamykanie) / Wykryto samochód + Mandat
    SP --> S0 : Upływ 5s (zakończenie zamykania)

    %% Przejścia do ALARMU (ze wszystkich stanów w ruchu)
    S1 --> S4 : Klawisz lub
    S3 --> S4 : Klawisz lub
    SP --> S4 : Klawisz lub

    %% Wyjście z ALARMU
    S4 --> S0 : Przycisk (Reset alarmu)


```
