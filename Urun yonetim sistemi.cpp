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
        cout << "�r�n eklenemiyor! Maksimum �r�n say�s�na ula��ld�.\n";
        return;
    }
    cout << "�r�n ad�: ";
    cin.ignore();
    getline(cin, urunler[urunSayisi].ad);
    cout << "�r�n fiyat�: ";
    cin >> urunler[urunSayisi].fiyat;
    cout << "Stok miktar�: ";
    cin >> urunler[urunSayisi].stok;
    urunSayisi++;
    cout << "�r�n ba�ar�yla eklendi.\n";
}

void urunleriListele(const Urun urunler[], int urunSayisi) {
    if (urunSayisi == 0) {
        cout << "Listelenecek �r�n bulunmamaktad�r.\n";
        return;
    }
    cout << "\n�r�n Listesi:\n";
    for (int i = 0; i < urunSayisi; i++) {
        cout << i + 1 << ". �r�n:\n";
        cout << "Ad: " << urunler[i].ad << "\n";
        cout << "Fiyat: " << urunler[i].fiyat << "\n";
        cout << "Stok: " << urunler[i].stok << "\n\n";
    }
}

void stokMiktariEnFazla(const Urun urunler[], int urunSayisi) {
    if (urunSayisi == 0) {
        cout << "�r�n bulunmamaktad�r.\n";
        return;
    }
    int maxIndex = 0;
    for (int i = 1; i < urunSayisi; i++) {
        if (urunler[i].stok > urunler[maxIndex].stok) {
            maxIndex = i;
        }
    }
    cout << "Stok miktar� en fazla olan �r�n:\n";
    cout << "Ad: " << urunler[maxIndex].ad << "\n";
    cout << "Fiyat: " << urunler[maxIndex].fiyat << "\n";
    cout << "Stok: " << urunler[maxIndex].stok << "\n";
}

void urunAra(const Urun urunler[], int urunSayisi, const string& urunAdi) {
    bool bulundu = false;
    for (int i = 0; i < urunSayisi; i++) {
        if (urunler[i].ad == urunAdi) {
            cout << "�r�n bulundu:\n";
            cout << "Ad: " << urunler[i].ad << "\n";
            cout << "Fiyat: " << urunler[i].fiyat << "\n";
            cout << "Stok: " << urunler[i].stok << "\n";
            bulundu = true;
            break;
        }
    }
    if (!bulundu) {
        cout << "�r�n bulunamad�.\n";
    }
}
int main() {
    Urun urunler[10];
    int urunSayisi = 0;
    int secim;

    do {
        cout << "\n=== �r�n Y�netim Sistemi ===\n";
        cout << "1. �r�n Ekle\n";
        cout << "2. �r�nleri Listele\n";
        cout << "3. Stok Miktar� En Fazla Olan �r�n� Bul\n";
        cout << "4. �r�n Ara\n";
        cout << "5. ��k��\n";
        cout << "Se�iminiz: ";
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
                cout << "Aramak istedi�iniz �r�n�n ad�n� girin: ";
                cin.ignore();
                getline(cin, urunAdi);
                urunAra(urunler, urunSayisi, urunAdi);
                break;
            }
            case 5:
                cout << "Programdan ��k�l�yor...\n";
                break;
            default:
                cout << "Ge�ersiz se�im! Tekrar deneyin.\n";
        }
    } while (secim != 5);

    return 0;
}

