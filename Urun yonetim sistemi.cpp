#include <iostream>
#include <string>
using namespace std;

struct Urun {
    string ad;
    float fiyat;
    int stok;
};

void urunEkle(Urun urunler[], int& urunSayisi) {
    if (urunSayisi >= 10) {
        cout << "Ürün eklenemiyor! Maksimum ürün sayýsýna ulaþýldý.\n";
        return;
    }
    cout << "Ürün adý: ";
    cin.ignore();
    getline(cin, urunler[urunSayisi].ad);
    cout << "Ürün fiyatý: ";
    cin >> urunler[urunSayisi].fiyat;
    cout << "Stok miktarý: ";
    cin >> urunler[urunSayisi].stok;
    urunSayisi++;
    cout << "Ürün baþarýyla eklendi.\n";
}

void urunleriListele(const Urun urunler[], int urunSayisi) {
    if (urunSayisi == 0) {
        cout << "Listelenecek ürün bulunmamaktadýr.\n";
        return;
    }
    cout << "\nÜrün Listesi:\n";
    for (int i = 0; i < urunSayisi; i++) {
        cout << i + 1 << ". Ürün:\n";
        cout << "Ad: " << urunler[i].ad << "\n";
        cout << "Fiyat: " << urunler[i].fiyat << "\n";
        cout << "Stok: " << urunler[i].stok << "\n\n";
    }
}

void stokMiktariEnFazla(const Urun urunler[], int urunSayisi) {
    if (urunSayisi == 0) {
        cout << "Ürün bulunmamaktadýr.\n";
        return;
    }
    int maxIndex = 0;
    for (int i = 1; i < urunSayisi; i++) {
        if (urunler[i].stok > urunler[maxIndex].stok) {
            maxIndex = i;
        }
    }
    cout << "Stok miktarý en fazla olan ürün:\n";
    cout << "Ad: " << urunler[maxIndex].ad << "\n";
    cout << "Fiyat: " << urunler[maxIndex].fiyat << "\n";
    cout << "Stok: " << urunler[maxIndex].stok << "\n";
}

void urunAra(const Urun urunler[], int urunSayisi, const string& urunAdi) {
    bool bulundu = false;
    for (int i = 0; i < urunSayisi; i++) {
        if (urunler[i].ad == urunAdi) {
            cout << "Ürün bulundu:\n";
            cout << "Ad: " << urunler[i].ad << "\n";
            cout << "Fiyat: " << urunler[i].fiyat << "\n";
            cout << "Stok: " << urunler[i].stok << "\n";
            bulundu = true;
            break;
        }
    }
    if (!bulundu) {
        cout << "Ürün bulunamadý.\n";
    }
}
int main() {
    Urun urunler[10];
    int urunSayisi = 0;
    int secim;

    do {
        cout << "\n=== Ürün Yönetim Sistemi ===\n";
        cout << "1. Ürün Ekle\n";
        cout << "2. Ürünleri Listele\n";
        cout << "3. Stok Miktarý En Fazla Olan Ürünü Bul\n";
        cout << "4. Ürün Ara\n";
        cout << "5. Çýkýþ\n";
        cout << "Seçiminiz: ";
        cin >> secim;

        switch (secim) {
            case 1:
                urunEkle(urunler, urunSayisi);
                break;
            case 2:
                urunleriListele(urunler, urunSayisi);
                break;
            case 3:
                stokMiktariEnFazla(urunler, urunSayisi);
                break;
            case 4: {
                string urunAdi;
                cout << "Aramak istediðiniz ürünün adýný girin: ";
                cin.ignore();
                getline(cin, urunAdi);
                urunAra(urunler, urunSayisi, urunAdi);
                break;
            }
            case 5:
                cout << "Programdan çýkýlýyor...\n";
                break;
            default:
                cout << "Geçersiz seçim! Tekrar deneyin.\n";
        }
    } while (secim != 5);

    return 0;
}

