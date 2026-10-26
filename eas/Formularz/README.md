Formularz WPF – Rejestracja osób i statystyki
Opis projektu

Aplikacja Formularz WPF to prosta aplikacja desktopowa napisana w języku C# z wykorzystaniem technologii WPF (Windows Presentation Foundation). Umożliwia wprowadzanie danych osób, zapisywanie ich do pliku tekstowego oraz automatyczne generowanie podstawowych statystyk.

Funkcjonalności
Wprowadzanie wieku – użytkownik podaje wiek osoby w zakresie od 1 do 120 lat.
Wybór koloru – możliwość wybrania koloru z listy rozwijanej.
Wybór płci – możliwość określenia płci za pomocą przycisków radiowych:
Mężczyzna (M)
Kobieta (K)
Inne
Zgoda – możliwość zaznaczenia pola wyboru zgody.
Walidacja danych – sprawdzanie poprawności podanego wieku oraz wyboru koloru.
Zapisywanie osób – każda poprawnie dodana osoba jest przechowywana w kolekcji w pamięci aplikacji.
Generowanie statystyk – automatyczne obliczanie:
średniego wieku osób,
najczęściej wybieranego koloru,
liczby mężczyzn,
liczby kobiet,
liczby udzielonych zgód.
Zapis wyników do pliku – dane osób i statystyki są zapisywane w pliku wyniki.txt.
Komunikaty dla użytkownika – aplikacja informuje o poprawnym dodaniu osoby lub występujących błędach.
Czyszczenie formularza – po dodaniu osoby formularz jest przygotowywany do wprowadzenia kolejnych danych.
Wykorzystane technologie
C# – język programowania.
WPF – technologia tworzenia interfejsu graficznego dla systemu Windows.
.NET – platforma uruchomieniowa aplikacji.
LINQ – przetwarzanie kolekcji i obliczanie statystyk.
ObservableCollection – przechowywanie listy osób w pamięci aplikacji.
System.IO – obsługa zapisu danych do pliku.
System.Text – przygotowanie tekstu i kodowanie UTF-8.
Struktura projektu

Przykładowa struktura plików:

text
FormularzWPF/
├── MainWindow.xaml
├── MainWindow.xaml.cs
├── App.xaml
├── App.xaml.cs
├── Person.cs (opcjonalnie)
├── README.md
└── wyniki.txt (tworzony automatycznie)


Klasa Person znajduje się obecnie w pliku MainWindow.xaml.cs. Można ją przenieść do osobnego pliku Person.cs, aby uporządkować kod projektu.

Instrukcja uruchomienia
Zainstaluj Visual Studio z obsługą programowania aplikacji desktopowych .NET.
Otwórz projekt FormularzWPF w Visual Studio.
Upewnij się, że projekt zawiera plik MainWindow.xaml oraz odpowiadający mu plik MainWindow.xaml.cs.
Sprawdź, czy nazwy kontrolek w pliku XAML odpowiadają nazwom użytym w kodzie C#.
Uruchom aplikację za pomocą klawisza F5 lub polecenia Start.
Instrukcja obsługi
Uruchom aplikację.
Wpisz wiek osoby w odpowiednim polu.
Wybierz kolor z listy rozwijanej.
Wybierz płeć.
Opcjonalnie zaznacz pole zgody.
Kliknij przycisk dodawania lub zapisywania osoby.
Odczytaj komunikat o wyniku operacji.
Sprawd
