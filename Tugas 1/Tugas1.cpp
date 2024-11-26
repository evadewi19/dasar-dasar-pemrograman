#include <iostream>
using namespace std;

int main()
{
    cout << "\nSELAMAT DATANG DI PERMAINAN TEBAK ANGKA !!!" << endl;
    cout << "\nSilahkan Login Terlebih Dahulu!" << endl;

    int angka_tebak;
    int angka_benar = 6;
    string nama, nim;
    cout << "\nMasukkan Nama dan NIM!" << endl;

    for (int i = 0; i <= 2; i++)
    {
        cout << "\nMasukkan Nama \t: ";
        cin >> nama;

        cout << "\nMasukkan NIM \t: ";
        cin >> nim;

        if (nama == "eva" && nim == "156")
        {
            cout << "\nSELAMAT ANDA BERHASIL LOGIN!" << endl;
            do
            {
                cout << "\nTebak Angka (1 - 10) = ";
                cin >> angka_tebak;

                if (angka_tebak > angka_benar)
                {
                    cout << "ANGKA TERLALU BESAR" << endl;
                }

                else if (angka_tebak < angka_benar)
                {
                    cout << "ANGKA TERLALU KECIL" << endl;
                }

                else
                {
                    cout << "\nSELAMAT KAMU BENAR, ANGKANYA ADALAH " << angka_benar << endl;
                    break;
                }

            } while (angka_tebak != angka_benar);
            break;
        }
        else
        {
            cout << "\nMAAF NAMA ATAU NIM YANG ANDA MASUKKAN SALAH, SILAHKAN COBA LAGI!" << endl;
        }
    }
}
