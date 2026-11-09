# Kompilacja i uruchomienie programu WebAssembly (WASM)

Instrukcja krok po kroku wyjaśniająca, jak przygotować środowisko, skompilować kod źródłowy w C/C++ do formatu WebAssembly za pomocą narzędzia Emscripten oraz jak poprawnie uruchomić przygotowaną aplikację webową.

### 1. Wymagania wstępne (Emscripten SDK)

Aby móc skompilować kod C/C++ do formatu WASM i wygenerować plik integracyjny `main.js`, na komputerze musi być zainstalowany **Emscripten toolchain (emsdk)**. 

Jeśli jeszcze go nie posiadasz, wykonaj w terminalu poniższe polecenia:
```bash
# Pobranie repozytorium emsdk
git clone https://github.com
cd emsdk

# Pobranie i aktywacja najnowszych narzędzi
./emsdk install latest
./emsdk activate latest

# Aktywacja zmiennych środowiskowych w bieżącym terminalu
# (W systemie Windows użyj: emsdk_env.bat)
source ./emsdk_env.sh
```

### 2. Struktura plików w projekcie

Zapewnij, aby w Twoim katalogu roboczym znajdowały się następujące pliki:
*   `main.c` (lub `main.cpp`) – kod źródłowy C/C++ zawierający funkcje `encrypt`, `getResult` oraz `getResultLength`.
*   `index.html` – dostarczony interfejs graficzny użytkownika (HTML/JavaScript).

### 3. Kompilacja kodu C/C++ do WebAssembly

Przed uruchomieniem strony należy skompilować plik z kodem C/C++. Aby wygenerowane środowisko Emscripten współpracowało z kodem JavaScript zawartym w pliku HTML, użyj następującego polecenia kompilacji:

```bash
emcc main.c -o main.js \
  -s EXPORTED_FUNCTIONS="['_encrypt', '_getResult', '_getResultLength', '_malloc', '_free']" \
  -s EXPORTED_RUNTIME_METHODS="['ccall', 'HEAPU8']" \
  -s MODULARIZE=1 \
  -s EXPORT_NAME="Module"
```

**Wyjaśnienie użytych flag:**
*   `-o main.js`: Generuje plik JavaScript odpowiedzialny za ładowanie binarnego pliku `.wasm`.
*   `EXPORTED_FUNCTIONS`: Wskazuje kompilatorowi, które funkcje z języka C nie mogą zostać usunięte i mają być dostępne na zewnątrz (dodanie znaku `_` przed nazwą funkcji jest wymagane przez Emscripten).
*   `EXPORTED_RUNTIME_METHODS`: Udostępnia pomocnicze metody środowiska uruchomieniowego, takie jak `ccall` (do wywoływania funkcji) oraz widok `HEAPU8` (do bezpośredniego odczytu pamięci WASM).
*   `MODULARIZE=1` i `EXPORT_NAME="Module"`: Zamyka kod w obiekcie obietnicy (Promise), co pozwala na bezpieczne asynchroniczne ładowanie za pomocą konstrukcji `Module().then(...)` widocznej w kodzie HTML.

### 4. Uruchomienie aplikacji

Przeglądarki internetowe blokują ładowanie plików `.wasm` bezpośrednio z dysku lokalnego (protokół `file://`) ze względów bezpieczeństwa (polityka CORS). Strona musi być serwowana przez lokalny serwer HTTP.

Możesz uruchomić prosty serwer na kilka sposobów, zależnie od posiadanych narzędzi:

**Opcja A: Python (najprostsza)**
Uruchom w katalogu z plikami:
```bash
python -m http.server 8000
```

**Opcja B: Node.js (http-server)**
Instalacja i uruchomienie:
```bash
npm install -g http-server
http-server -p 8000
```

Po uruchomieniu serwera otwórz przeglądarkę i przejdź pod adres: **`http://localhost:8000`**.

### 5. Instrukcja obsługi interfejsu

1. Poczekaj, aż na dole strony pojawi się komunikat **"WebAssembly załadowany!"**.
2. Wpisz dowolną treść w polu **Tekst**.
3. Wpisz klucz szyfrujący w polu **Klucz**. Pamiętaj, że pole akceptuje wyłącznie ciąg o długości **dokładnie 32 znaków**.
4. Kliknij przycisk **Szyfruj**.
5. W polu **Wynik** wyświetlone zostaną przetworzone przez program WASM dane.
