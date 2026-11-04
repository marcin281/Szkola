# System Analizy Pomiarów Meteorologicznych

Aplikacja konsolowa w języku C++ służąca do wczytywania, filtrowania oraz analizy danych pomiarowych (temperatury i prędkości wiatru) z pliku tekstowego.

### Główne funkcje

* **Wczytywanie danych z pliku:** Automatyczne pobieranie rekordów z pliku zewnętrznego i parsowanie linii.
* **Obsługa błędów (Try-Catch):** Bezpieczne sprawdzanie poprawności otwarcia pliku i zgłaszanie wyjątków w przypadku jego braku.
* **Analiza minimów:** Automatyczne odnajdywanie i wyświetlanie pełnego rekordu z najniższą zanotowaną temperaturą.
* **Filtrowanie danych:** Dynamiczne wyszukiwanie wszystkich pomiarów, których temperatura przekracza wartość wskazaną przez użytkownika.

### Struktura pliku wejściowego (a.txt)

Program do poprawnego działania wymaga pliku o nazwie `a.txt` umieszczonego w tym samym katalogu co plik wykonywalny. Dane w pliku muszą być oddzielone średnikami według schematu: `ID;DATA;TEMPERATURA;WIATR`.

Przykładowa zawartość pliku:
```text
ST-01;2026-11-01;12.5;4.2
ST-02;2026-11-02;-3.5;12.0
ST-03;2026-11-03;18.2;2.1
```

### Technologia i struktura kodu

Projekt został napisany w standardzie C++11 (lub nowszym) i wykorzystuje programowanie obiektowe oraz bibliotekę STL:
* `struct dane` – Struktura przechowująca pojedynczy rekord pomiarowy.
* `class pomiary` – Klasa zarządzająca logiką aplikacji (`wczytaj`, `min_temp`, `szukaj`).
* `std::vector` – Kontener używany do dynamicznego przechowywania struktur w pamięci.
* `std::stringstream` – Narzędzie wykorzystane do podziału tekstu względem separatora (średnika).

### Instrukcja uruchomienia

1. Skonstruuj plik `a.txt` z danymi pomiarowymi w folderze projektu.
2. Skompiluj program za pomocą g++:
   ```bash
   g++ -std=c++11 main.cpp -o analizator
   ```
3. Uruchom aplikację:
   ```bash
   ./analizator
   ```
