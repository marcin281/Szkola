Pomiary temperatury i wiatru
Opis projektu

Program napisany w języku C++, który odczytuje dane pomiarowe z pliku tekstowego a.txt, analizuje temperatury oraz umożliwia wyszukiwanie pomiarów przekraczających podaną wartość temperatury.

Funkcjonalności
Wczytywanie danych – odczytywanie pomiarów z pliku a.txt.
Wyszukiwanie minimalnej temperatury – odnajdywanie pomiaru z najniższą temperaturą i wyświetlanie jego identyfikatora, daty, temperatury oraz prędkości wiatru.
Filtrowanie pomiarów – wyświetlanie wszystkich pomiarów, w których temperatura jest większa od wartości podanej przez użytkownika.
Format pliku wejściowego

Dane powinny znajdować się w pliku a.txt.

Każdy wiersz powinien zawierać następujące informacje oddzielone średnikami:

text
id;data;temperatura;wiatr


Przykład:

text
1;2024-01-01;12.5;5.2
2;2024-01-02;-3.4;7.1
3;2024-01-03;8.2;4.5
4;2024-01-04;-7.1;6.3

Wykorzystane technologie
C++
Biblioteka <iostream> – obsługa wejścia i wyjścia.
Biblioteka <fstream> – odczyt danych z pliku.
Biblioteka <vector> – przechowywanie pomiarów.
Biblioteka <sstream> – przetwarzanie danych tekstowych.
Struktura programu
struct dane – przechowuje identyfikator, datę, temperaturę i wiatr.
class pomiary – zawiera metody odpowiedzialne za obsługę i analizę danych.
wczytaj() – odczytuje dane z pliku i zapisuje je w wektorze.
min_temp() – wyszukuje i wyświetla pomiar o najniższej temperaturze.
szukaj() – wyszukuje pomiary z temperaturą większą od podanej przez użytkownika.

Program:

Wczytuje dane z pliku.
Wyświetla pomiar z najniższą temperaturą.
Pobiera od użytkownika wartość temperatury.
Wyświetla wszystkie pomiary, których temperatura jest większa od podanej wartości.
Autor

Projekt wykonany w języku C++.
