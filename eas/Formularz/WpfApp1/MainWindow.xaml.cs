
using System;
using System.Collections.ObjectModel;
using System.Linq;
using System.IO;
using System.Text;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Media;

namespace FormularzWPF
{
    public partial class MainWindow : Window
    {
        private readonly ObservableCollection<Person> people = new();

        public MainWindow()
        {
            InitializeComponent();
            UpdateStatistics();
        }

        private void SaveButton_Click(object sender, RoutedEventArgs e)
        {
            // Sprawdzenie wieku
            if (!int.TryParse(AgeTextBox.Text, out int age)
                || age < 1 || age > 120)
            {
                MessageText.Foreground = Brushes.Red;
                MessageText.Text = "Podaj wiek od 1 do 120.";
                return;
            }

            // Sprawdzenie koloru
            if (ColorComboBox.SelectedItem is not ComboBoxItem selectedColor)
            {
                MessageText.Foreground = Brushes.Red;
                MessageText.Text = "Wybierz kolor.";
                return;
            }

            // Pobranie płci
            string gender;

            if (MaleRadio.IsChecked == true)
                gender = "M";
            else if (FemaleRadio.IsChecked == true)
                gender = "K";
            else
                gender = "Inne";

            // Pobranie pozostałych danych
            string color = selectedColor.Content?.ToString() ?? "";
            bool consent = ConsentCheckBox.IsChecked == true;

            // Utworzenie osoby
            Person person = new Person
            {
                Age = age,
                Color = color,
                Gender = gender,
                Consent = consent
            };

            // Dodanie osoby
            people.Add(person);

            // Aktualizacja statystyk
            UpdateStatistics();

            // Zapis do pliku
            try
            {
                SaveResultsToFile();

                MessageText.Foreground = Brushes.Green;
                MessageText.Text = "Dodano osobę i zapisano wyniki do pliku.";
            }
            catch (Exception ex)
            {
                MessageText.Foreground = Brushes.Red;
                MessageText.Text =
                    "Dodano osobę, ale nie udało się zapisać pliku: "
                    + ex.Message;
            }

            // Czyszczenie formularza
            AgeTextBox.Clear();
            ColorComboBox.SelectedIndex = 0;
            MaleRadio.IsChecked = true;
            ConsentCheckBox.IsChecked = false;
        }

        private void UpdateStatistics()
        {
            if (people.Count == 0)
            {
                AverageAgeText.Text = "Brak danych";
                PopularColorText.Text = "Brak danych";
                MaleCountText.Text = "0";
                FemaleCountText.Text = "0";
                ConsentCountText.Text = "0";
                return;
            }

            // Średnia wieku
            double average = people.Average(p => p.Age);
            AverageAgeText.Text = average.ToString("F2");

            // Najczęściej wybierany kolor
            var popularColor = people
                .GroupBy(p => p.Color)
                .OrderByDescending(g => g.Count())
                .First();

            PopularColorText.Text =
                $"{popularColor.Key} ({popularColor.Count()})";

            // Liczba mężczyzn
            MaleCountText.Text =
                people.Count(p => p.Gender == "M").ToString();

            // Liczba kobiet
            FemaleCountText.Text =
                people.Count(p => p.Gender == "K").ToString();

            // Liczba zgód
            ConsentCountText.Text =
                people.Count(p => p.Consent).ToString();
        }

        private void SaveResultsToFile()
        {
            StringBuilder sb = new StringBuilder();

            sb.AppendLine("WYNIKI FORMULARZA");
            sb.AppendLine("=================");
            sb.AppendLine();

            sb.AppendLine("ZAPISANE OSOBY");
            sb.AppendLine("--------------");

            foreach (Person p in people)
            {
                sb.AppendLine(
                    $"Płeć: {p.Gender}, " +
                    $"Wiek: {p.Age}, " +
                    $"Kolor: {p.Color}, " +
                    $"Zgoda: {(p.Consent ? "Tak" : "Nie")}");
            }

            sb.AppendLine();
            sb.AppendLine("STATYSTYKI");
            sb.AppendLine("==========");

            sb.AppendLine($"Średnia wieku: {AverageAgeText.Text}");
            sb.AppendLine($"Najczęstszy kolor: {PopularColorText.Text}");
            sb.AppendLine($"Liczba mężczyzn: {MaleCountText.Text}");
            sb.AppendLine($"Liczba kobiet: {FemaleCountText.Text}");
            sb.AppendLine($"Liczba zgód: {ConsentCountText.Text}");

            string path = Path.Combine(
                AppDomain.CurrentDomain.BaseDirectory,
                "wyniki.txt");

            File.WriteAllText(path, sb.ToString(), Encoding.UTF8);
        }
    }

    public class Person
    {
        public int Age { get; set; }

        public string Color { get; set; } = "";

        public string Gender { get; set; } = "";

        public bool Consent { get; set; }
    }
}
