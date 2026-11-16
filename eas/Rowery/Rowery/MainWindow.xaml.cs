
using System;
using System.Collections.ObjectModel;
using System.Globalization;
using System.IO;
using System.Windows;
using System.Windows.Media.Imaging;

namespace Rowery
{
    public class Rower
    {
        public int Id { get; set; }
        public string Opis { get; set; }
        public string Rodzaj { get; set; }
        public double Cena { get; set; }
        public bool Wypozyczony { get; set; }
        public BitmapImage Obraz { get; set; }

        public string Status
        {
            get { return Wypozyczony ? "Wypozyczony" : "Dostepny"; }
        }
    }

    public partial class MainWindow : Window
    {
        ObservableCollection<Rower> rowery =
            new ObservableCollection<Rower>();

        Random losuj = new Random();

        public MainWindow()
        {
            InitializeComponent();
            dgRowery.ItemsSource = rowery;
        }

        int ZnajdzRower(int id)
        {
            for (int i = 0; i < rowery.Count; i++)
            {
                if (rowery[i].Id == id)
                    return i;
            }

            return -1;
        }

        // Odczytywanie liczb
        bool OdczytajLiczbe(string tekst, out double liczba)
        {
            tekst = tekst.Trim().Replace(',', '.');

            return double.TryParse(
                tekst,
                NumberStyles.Number,
                CultureInfo.InvariantCulture,
                out liczba
            );
        }

        // Losowanie zdjecia
        BitmapImage LosujObraz()
        {
            string[] obrazy = { "img1.jpg", "img2.jpg", "img3.jpg" };

            string nazwa = obrazy[losuj.Next(obrazy.Length)];

            string sciezka = Path.Combine(
                AppDomain.CurrentDomain.BaseDirectory,
                "Obrazy",
                nazwa
            );

            return new BitmapImage(new Uri(sciezka));
        }

        // Dodawanie roweru

        private void DodajRower_Click(object sender, RoutedEventArgs e)
        {
            try
            {
                string tekstId = txtId.Text.Trim();

                int id = 1;

                foreach (Rower rower in rowery)
                {
                    if (rower.Id >= id)
                        id = rower.Id + 1;
                }

                if (txtOpis.Text.Trim() == "" || txtRodzaj.Text.Trim() == "")
                {
                    MessageBox.Show("Uzupelnij wszystkie pola!");
                    return;
                }

                if (!OdczytajLiczbe(txtCena.Text, out double cena))
                {
                    MessageBox.Show("Nieprawidlowa cena!");
                    return;
                }

                if (cena <= 0)
                {
                    MessageBox.Show("Cena musi byc wieksza od 0!");
                    return;
                }

                Rower r = new Rower();

                r.Id = id;
                r.Opis = txtOpis.Text;
                r.Rodzaj = txtRodzaj.Text;
                r.Cena = cena;
                r.Wypozyczony = false;
                r.Obraz = LosujObraz();

                rowery.Add(r);

                txtId.Clear();
                txtOpis.Clear();
                txtRodzaj.Clear();
                txtCena.Clear();

                MessageBox.Show("Dodano rower!");
            }
            catch (Exception ex)
            {
                MessageBox.Show("Blad: " + ex.Message);
            }
        }


        // Wypozyczanie roweru
        private void WypozyczRower_Click(object sender, RoutedEventArgs e)
        {
            Rower r = dgRowery.SelectedItem as Rower;

            if (r == null)
            {
                MessageBox.Show("Wybierz rower!");
                return;
            }

            if (r.Wypozyczony)
            {
                MessageBox.Show("Rower jest juz wypozyczony!");
                return;
            }

            r.Wypozyczony = true;
            dgRowery.Items.Refresh();

            MessageBox.Show("Rower zostal wypozyczony!");
        }

        // Zwracanie roweru
        private void ZwrocRower_Click(object sender, RoutedEventArgs e)
        {
            Rower r = dgRowery.SelectedItem as Rower;

            if (r == null)
            {
                MessageBox.Show("Wybierz rower!");
                return;
            }

            if (!r.Wypozyczony)
            {
                MessageBox.Show("Ten rower nie jest wypozyczony!");
                return;
            }

            if (!OdczytajLiczbe(txtGodziny.Text, out double godziny))
            {
                MessageBox.Show("Nieprawidlowa liczba godzin!");
                return;
            }

            if (godziny <= 0)
            {
                MessageBox.Show("Liczba godzin musi byc wieksza od 0!");
                return;
            }

            double koszt = godziny * r.Cena;

            r.Wypozyczony = false;
            dgRowery.Items.Refresh();

            MessageBox.Show("Rower zostal zwrocony!\nDo zaplaty: "
                + koszt.ToString("0.00") + " zl");

            txtGodziny.Clear();
        }
    }
}
