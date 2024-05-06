using Microsoft.Win32;
using System.Drawing;
using System.Drawing.Imaging;
using System.IO;
using System.Text;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Interop;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;

namespace Tester
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        public MainWindow()
        {
            InitializeComponent();
        }

        Bitmap bm = new Bitmap(100, 100);

        // Bing AI
        // https://stackoverflow.com/a/23831231/16426057
        public BitmapImage ToBitmapImage(Bitmap bitmap)
        {
            using (var memory = new MemoryStream())
            {
                bitmap.Save(memory, ImageFormat.Png);
                memory.Position = 0;

                var bitmapImage = new BitmapImage();
                bitmapImage.BeginInit();
                bitmapImage.StreamSource = memory;
                bitmapImage.CacheOption = BitmapCacheOption.OnLoad;
                bitmapImage.EndInit();
                bitmapImage.Freeze();

                return bitmapImage;
            }
        }

        private void Window_Loaded(object sender, RoutedEventArgs e)
        {
            OpenFileDialog ofd = new OpenFileDialog();
            if (ofd.ShowDialog() == true)
            {
                string file = File.ReadAllText(ofd.FileName);

                string[] split1 = file.Split(";");

                string[] _split2 = split1[0].Split(",");
                bm = new Bitmap(int.Parse(_split2[0]), int.Parse(_split2[1]));

                for (int i = 1; i < split1.Length; i++)
                {
                    try
                    {
                        string[] split2 = split1[i].Split(",");

                        int r = int.Parse(split2[0]);
                        int g = int.Parse(split2[1]);
                        int b = int.Parse(split2[2]);

                        try
                        {
                            bm.SetPixel(i % bm.Width, i / bm.Height, System.Drawing.Color.FromArgb(r, g, b));
                        }
                        catch { }
                    } catch { }
                }

                Img.Source = ToBitmapImage(bm);
            }
            else Close();
        }
    }
}