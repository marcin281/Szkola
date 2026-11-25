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


``` marmaid 
stateDiagram-v2
    state "0: Zamknięty(Brak pojazdu)" as S0
    state "1: Otwieranie(Brak pojazdu)" as S1
    state "1P: Otwieranie + SAMOCHÓD(Wykryto pojazd / Mandat = TAK)" as S1_P
    state "2: Otwarty(Brak pojazdu)" as S2
    state "2P: Otwarty + SAMOCHÓD(Mandat = TAK do następnej akcji)" as S2_P
    state "3: Zamykanie(Brak pojazdu)" as S3
    state "3P: Zamykanie + SAMOCHÓD(Wykryto pojazd / Mandat = TAK)" as S3_P
    state "0P: Zamknięty + SAMOCHÓD(Mandat = TAK do następnej akcji)" as S0_P
    state "4: ALARM(Szlaban zatrzymany)" as S4

    %% Otwieranie
    S0 --> S1 : Przycisk
    S0_P --> S1 : Przycisk (reset flagi pojazd)
    S1 --> S1_P : Klawisz w trakcie 5s/ Wykryto samochód + Mandat
    S1 --> S2 : Upływ 5s (brak samochodu)
    S1_P --> S2_P : Upływ 5s (z samochodem)

    %% Zamykanie
    S2 --> S3 : Przycisk
    S2_P --> S3 : Przycisk (reset flagi pojazd)
    S3 --> S3_P : Klawisz w trakcie 5s/ Wykryto samochód + Mandat
    S3 --> S0 : Upływ 5s (brak samochodu)
    S3_P --> S0_P : Upływ 5s (z samochodem)

    %% Przejścia do ALARMU (ze wszystkich stanów w ruchu)
    S1 --> S4 : Klawisz lub
    S1_P --> S4 : Klawisz lub
    S3 --> S4 : Klawisz lub
    S3_P --> S4 : Klawisz lub

    %% Wyjście z ALARMU
    S4 --> S0 : Przycisk (Reset alarmu)

```
