🚦 Sygnalizacja świetlna Arduino

Projekt przedstawia prostą symulację sygnalizacji świetlnej z wykorzystaniem Arduino i 4 zestawów diod LED.

Każdy sygnalizator posiada:

🔴 diodę czerwoną,

🟢 diodę zieloną.

Program uruchamia sygnalizatory po kolei od 1 do 4. Zielone światło świeci przez 5 sekund, a pomiędzy kolejnymi sygnalizatorami wszystkie światła pozostają czerwone przez 2 sekundy.

Do odmierzania czasu wykorzystano funkcję millis(), dzięki czemu program działa bez blokowania pętli przez delay().

Po przejściu wszystkich czterech sygnalizatorów cykl rozpoczyna się ponownie.
