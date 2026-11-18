using System;
using System.Collections.Generic;
using System.Globalization;
using System.IO;
using System.Linq;
using System.Windows;

namespace StacjaPogodowa
{
    public class Pomiar
    {
        public string Id { get; set; } = "";
        public DateTime Data { get; set; }
        public double Temperatura { get; set; }
        public double Wiatr { get; set; }
        public bool IsMax { get; set; }   // podświetlenie wiersza (czerwony)
        public bool IsMin { get; set; }   // podświetlenie wiersza (niebieski)
    }

    public partial class MainWindow : Window
    {
        private const char Separator = ';';
        private static readonly CultureInfo Inv = CultureInfo.InvariantCulture;

        private readonly List<Pomiar> pomiary = new List<Pomiar>();

        public MainWindow()
        {
            InitializeComponent();
            WczytajDane();
            Pokaz(pomiary);
        }

        // wczytanie zawsze z pliku dane.txt (obok programu)
        private void WczytajDane()
        {
            string sciezka = Path.Combine(AppContext.BaseDirectory, "dane.txt");
            if (!File.Exists(sciezka))
            {
                TbStatus.Text = "Nie znaleziono pliku dane.txt.";
                return;
            }

            int bledy = 0;
            foreach (string linia in File.ReadAllLines(sciezka))
            {
                if (string.IsNullOrWhiteSpace(linia)) continue;

                string[] c = linia.Split(Separator);   // końcowy ';' daje pusty ostatni element
                if (c.Length >= 4
                    && DateTime.TryParse(c[1], Inv, DateTimeStyles.None, out DateTime data)
                    && TryDouble(c[2], out double temp)
                    && TryDouble(c[3], out double wiatr))
                {
                    pomiary.Add(new Pomiar { Id = c[0].Trim(), Data = data, Temperatura = temp, Wiatr = wiatr });
                }
                else bledy++;
            }

            TbStatus.Text = "Wczytano " + pomiary.Count + " rekordów"
                            + (bledy > 0 ? ", pominięto błędnych: " + bledy : "") + ".";
        }

        // wyszukiwanie: temperatura > podana ORAZ wiatr > podany (puste pole = brak warunku)
        private void Szukaj_Click(object sender, RoutedEventArgs e)
        {
            double progTemp = double.NegativeInfinity;
            double progWiatr = double.NegativeInfinity;

            if (TbTemp.Text.Trim().Length > 0 && !TryDouble(TbTemp.Text, out progTemp))
            {
                MessageBox.Show("Temperatura musi być liczbą.", "Błąd");
                return;
            }
            if (TbWiatr.Text.Trim().Length > 0 && !TryDouble(TbWiatr.Text, out progWiatr))
            {
                MessageBox.Show("Wiatr musi być liczbą.", "Błąd");
                return;
            }

            var znalezione = pomiary
                .Where(p => p.Temperatura > progTemp && p.Wiatr > progWiatr)
                .ToList();

            Pokaz(znalezione);
            TbStatus.Text = znalezione.Count > 0
                ? "Znaleziono rekordów: " + znalezione.Count + "."
                : "Brak pomiarów spełniających kryterium.";
        }

        private void Wszystkie_Click(object sender, RoutedEventArgs e)
        {
            TbTemp.Clear();
            TbWiatr.Clear();
            Pokaz(pomiary);
            TbStatus.Text = "Wszystkie rekordy: " + pomiary.Count + ".";
        }

        // wyświetla listę i podświetla MAX (czerwony) i MIN (niebieski) temperatury
        private void Pokaz(List<Pomiar> lista)
        {
            foreach (var p in pomiary) { p.IsMax = false; p.IsMin = false; }

            if (lista.Count > 0)
            {
                double max = lista.Max(p => p.Temperatura);
                double min = lista.Min(p => p.Temperatura);
                foreach (var p in lista)
                {
                    p.IsMax = p.Temperatura == max;
                    p.IsMin = p.Temperatura == min;
                }
            }

            DgPomiary.ItemsSource = null;
            DgPomiary.ItemsSource = lista;
        }

        private static bool TryDouble(string s, out double v)
        {
            return double.TryParse((s ?? "").Trim().Replace(',', '.'), NumberStyles.Float, Inv, out v);
        }
    }
}