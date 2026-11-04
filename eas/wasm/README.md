# Stacja Meteorologiczna — Panel WebAssembly

Aplikacja webowa służąca do analizy danych pogodowych. Projekt wykorzystuje technologię **WebAssembly (Wasm)** skompilowaną za pomocą Emscripten, co pozwala na błyskawiczne przetwarzanie pomiarów temperatur bezpośrednio w przeglądarce przy użyciu wydajnego kodu natywnego (C/C++).

### Główne funkcjonalności

* **Wczytywanie danych:** Pobieranie i przetwarzanie bazy pomiarów meteorologicznych za pomocą modułu Wasm.
* **Wyszukiwanie minimum:** Automatyczne wyznaczanie i wyświetlanie najniższej odnotowanej temperatury.
* **Filtrowanie pomiarów:** Wyszukiwanie konkretnych rekordów na podstawie wprowadzonej przez użytkownika temperatury z walidacją danych wejściowych.

### Wymagania systemowe i zależności

* **Przeglądarka internetowa:** Dowolna nowoczesna przeglądarka z obsługą WebAssembly (Chrome, Firefox, Edge, Safari).
* **Pliki aplikacji:** Do poprawnego działania wymagane jest umieszczenie w tym samym katalogu skompilowanego pliku `app.js` (oraz towarzyszącego mu pliku `app.wasm`).
* **Serwer lokalny:** Z powodu zabezpieczeń CORS, pliki muszą być uruchamiane przez serwer HTTP (np. Live Server w VS Code, Python `http.server` lub Node.js), a nie bezpośrednio z dysku jako `file://`.

### Struktura integracji (API WebAssembly)

Aplikacja komunikuje się z modułem C/C++ za pomocą funkcji `Module.ccall`:

* **`wczytaj`**
  * **Typ zwracany:** `string`
  * **Argumenty:** Brak
  * **Opis:** Inicjuje ładowanie bazy danych i zwraca podsumowanie z najniższą temperaturą. Sprawdzane wyrażenie warunkowe: `"najmniejsza temperatura:"`.
* **`szukaj`**
  * **Typ zwracany:** `string`
  * **Argumenty:** `['number']` (temperatura jako liczba zmiennoprzecinkowa)
  * **Opis:** Przeszukuje bazę danych w module Wasm i zwraca sformatowaną listę dopasowanych pomiarów.
