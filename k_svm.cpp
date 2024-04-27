#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// non-lineer ornek veri seti
vector<vector<double>> egitim_verileri = {{1, 9}, {2, 8}, {2.8, 7.2}, {1.55, 8}, {2, 8}, {1.75, 8.25}, {4.35, 5.65}, {4, 6}, {6, 4}, {4, 6}, {5.55, 4.45}, {5, 5}};
vector<int> egitim_etiketleri = {-1, -1, -1, -1, -1, -1, 1, 1, 1, 1, 1, 1};

// RBF kerneli
// İki vektor arasindaki RBF (Radyal Tabanli Fonksiyon) çekirdeğini hesaplar
double rbf(const vector<double> &egitim_verileri1, const vector<double> &egitim_verileri2, double gamma)
{
    double toplam = 0;
    for (int i = 0; i < egitim_verileri1.size(); ++i)
    {
        toplam += pow(egitim_verileri1[i] - egitim_verileri2[i], 2);
    }
    return exp(-gamma * toplam);
}

class SvmKernel
{
private:
    vector<vector<double>> destek_vektorleri; // Destek vektorlerini saklar
    vector<int> destek_etiketleri; // Destek vektorlerinin etiketlerini saklar
    vector<double> alphas; // Alpha değerlerini saklar
    double yanlilik; // Yanlilik terimini saklar
    double gamma; // RBF kernelinin gamma parametresini saklar

public:
    // Kurucu fonksiyon, gamma değerini alir
    SvmKernel(double g) : gamma(g) {}

    // SVM modelini eğitir
    void eğit(const vector<vector<double>> &egitim_verileri_eğitim, const vector<int> &egitim_etiketleri_eğitim)
    {
        int ornek_sayisi = egitim_verileri_eğitim.size();
        int ozellik_sayisi = egitim_verileri_eğitim[0].size();

        // kernel matrisini hesapla
        vector<vector<double>> kernel_matrisi(ornek_sayisi, vector<double>(ornek_sayisi));
        for (int i = 0; i < ornek_sayisi; ++i)
        {
            for (int j = 0; j < ornek_sayisi; ++j)
            {
                kernel_matrisi[i][j] = rbf(egitim_verileri_eğitim[i], egitim_verileri_eğitim[j], gamma);
            }
        }

        // Düzgün bir şekilde siniflandirmak için alpha'lari hesapla
        alphas = vector<double>(ornek_sayisi, 0);
        double oğrenme_orani = 0.01; // oğrenme orani
        int iterasyon = 1000; // İterasyon sayisi
        for (int donem = 0; donem < iterasyon; ++donem)
        {
            for (int i = 0; i < ornek_sayisi; ++i)
            {
                double hata = 0;
                for (int j = 0; j < ornek_sayisi; ++j)
                {
                    hata += alphas[j] * egitim_etiketleri_eğitim[j] * kernel_matrisi[i][j];
                }
                hata += yanlilik;
                hata *= egitim_etiketleri_eğitim[i];

                // Hata pozitif ise, alpha ve yanliliği güncelle
                if (hata <= 0)
                {
                    alphas[i] += oğrenme_orani;
                    yanlilik += oğrenme_orani * egitim_etiketleri_eğitim[i];
                }
            }
        }

        // Destek vektorlerini ve etiketlerini al
        for (int i = 0; i < ornek_sayisi; ++i)
        {
            if (alphas[i] > 0)
            {
                destek_vektorleri.push_back(egitim_verileri_eğitim[i]);
                destek_etiketleri.push_back(egitim_etiketleri_eğitim[i]);
            }
        }
    }

    // Verilen giriş vektorünü siniflandirir
    int siniflandir(const vector<double> &girdi)
    {
        double sinifla = yanlilik;
        for (int i = 0; i < destek_vektorleri.size(); ++i)
        {
            sinifla += alphas[i] * destek_etiketleri[i] * rbf(girdi, destek_vektorleri[i], gamma);
        }
        return sinifla >= 0 ? 1 : -1;
    }
};

int main()
{
    // SVM modelini oluştur ve eğit
    SvmKernel svm(1); // Gamma değeri alir
    svm.eğit(egitim_verileri, egitim_etiketleri);

    // Eğitilen veri seti ile siniflandirma
    for (const auto &ornek : egitim_verileri)
    {
        int sinif = svm.siniflandir(ornek);
        cout << "ornek: (" << ornek[0] << ", " << ornek[1] << ") siniflandirma sonucu: " << sinif << endl;
    }

    cout << endl;

    // Test veri seti ile siniflandirma
    vector<vector<double>> test_verileri = {{5, 6}, {2, 8}, {5, 5}, {2.9, 7.1}, {8, 2}, {1.86, 8.14}};
    for (const auto &ornek : test_verileri)
    {
        int sinif = svm.siniflandir(ornek);
        cout << "ornek: (" << ornek[0] << ", " << ornek[1] << ") siniflandirma  sonucu: " << sinif << endl;
    }

    return 0;
}
