#include <iostream>
#include <iomanip>
using namespace std;

// nilai ujian[0] = Matematika
// nilai ujian[1] = IPA
// nilai ujian[2] = Bahasa Indonesia
// nilai ujian[3] = Bahasa Inggris

struct siswa
{
    string nama;
    int no_ujian;
    char kelas;
    float nilai_ujian[4];
};

int jumlah_data;
siswa data_siswa[500];

void menu1();
void menu2();

int main()
{
    int pilih;

    do
    {
        cout << "\nSELAMAT DATANG!" << endl;
        cout << "\nSilahkan Pilih Menu " << endl;
        cout << "1. Masukkan Data Ujian" << endl;
        cout << "2. Hasil Data Ujian" << endl;
        cout << "3. Keluar" << endl;
        cout << "Pilih: ";
        cin >> pilih;

        switch (pilih)
        {
        case 1:
            menu1();
            system("pause");
            system("cls");
            break;

        case 2:
            menu2();
            system("pause");
            system("cls");
            break;

        case 3:
            cout << "\nKELUAR DARI PROGRAM" << endl;
            exit(0);
            break;

        default:
            cout << "\nPILIHAN YANG ANDA MASUKKAN SALAH" << endl;
        }
    } while (true);
}

void menu1()
{
    int jumlah_input_data;

    cout << "\nMasukkan Jumlah Data Siswa Ujian : ";
    cin >> jumlah_input_data;

    for (int i = 0; i < jumlah_input_data; i++)
    {
        cout << "\nSiswa ke " << i + 1 << endl;
        cout << "Nama Siswa \t: ";
        cin >> data_siswa[i].nama;

        cout << "No Ujian \t: ";
        cin >> data_siswa[i].no_ujian;

        cout << "Kelas \t\t: ";
        cin >> data_siswa[i].kelas;

        cout << "\nUjian Matematika" << endl;
        cout << "Nilai Ujian : ";
        cin >> data_siswa[i].nilai_ujian[0];

        cout << "\nUjian IPA" << endl;
        cout << "Nilai Ujian : ";
        cin >> data_siswa[i].nilai_ujian[1];

        cout << "\nUjian Bahasa Indonesia" << endl;
        cout << "Nilai Ujian : ";
        cin >> data_siswa[i].nilai_ujian[2];

        cout << "\nUjian Bahasa Inggris" << endl;
        cout << "Nilai Ujian : ";
        cin >> data_siswa[i].nilai_ujian[3];
    }
    jumlah_data = jumlah_data + jumlah_input_data;
}

void menu2()
{
    cout << "\nDATA UJIAN" << endl;

    for (int i = 0; i < jumlah_data; i++)
    {
        float rata_rata = (data_siswa[i].nilai_ujian[0] + data_siswa[i].nilai_ujian[1] + data_siswa[i].nilai_ujian[2] + data_siswa[i].nilai_ujian[3]) / 10;
        cout << "\nNilai Ujian ke " << i + 1 << endl;

        cout << "Nama Siswa : " << data_siswa[i].nama << endl;
        cout << "No Ujian : " << data_siswa[i].no_ujian << endl;
        cout << "Kelas : " << data_siswa[i].kelas << endl;

        cout << "\nUjian Matematika" << endl;
        cout << "Nilai Ujian : " << data_siswa[i].nilai_ujian[0] << endl;

        cout << "\nUjian IPA" << endl;
        cout << "Nilai Ujian : " << data_siswa[i].nilai_ujian[1] << endl;

        cout << "\nUjian Bahasa Indonesia" << endl;
        cout << "Nilai Ujian : " << data_siswa[i].nilai_ujian[2] << endl;

        cout << "\nUjian Bahasa Inggris" << endl;
        cout << "Nilai Ujian : " << data_siswa[i].nilai_ujian[3] << endl;

        cout << "Rata-Rata Hasil Ujian : " << rata_rata << endl;
    }
}
