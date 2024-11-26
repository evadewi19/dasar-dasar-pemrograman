#include <iostream>
#include <iomanip>
using namespace std;

struct penulis
{
    string nama_penulis;
};

struct buku
{
    int id_buku;
    string judul_buku;
    penulis penulis_buku;
    int harga;
};

int jumlah_data;
buku data_buku[1000];

bool cek_ketersediaan_id(int id)
{
    for (int i = 0; i < jumlah_data; i++)
    {
        if (id == data_buku[i].id_buku)
            return false;
    }

    return true;
}

void menu_tambah_buku()
{
    int jumlah_buku_input;

    cout << "\nMasukkan Jumlah Buku yang Ingin Diinput : ";
    cin >> jumlah_buku_input;
    cout << setfill('=') << setw(40) << "" << endl;

    for (int i = 0; i < jumlah_buku_input; i++)
    {
        do
        {
            cout << "Masukkan ID Buku \t: ";
            cin >> data_buku[jumlah_data].id_buku;
        } while (!cek_ketersediaan_id(data_buku[jumlah_data].id_buku));
        cin.ignore();

        cout << "Judul Buku \t\t: ";
        getline(cin, data_buku[jumlah_data].judul_buku);

        cout << "Nama Pengarang \t\t: ";
        getline(cin, data_buku[jumlah_data].penulis_buku.nama_penulis);

        cout << "Harga \t\t\t: ";
        cin >> data_buku[jumlah_data].harga;
        cout << setfill('=') << setw(40) << "" << endl;

        jumlah_data++;
    }

    system("cls");
}

void tampilkan_daftar_buku()
{
    cout << "\nDAFTAR BUKU : " << endl;
    cout << setfill('=') << setw(13) << "" << endl;

    for (int i = 0; i < jumlah_data; i++)
    {
        cout << "ID Buku \t: " << data_buku[i].id_buku << endl;
        cout << "Judul \t\t: " << data_buku[i].judul_buku << endl;
        cout << "Pengarang \t: " << data_buku[i].penulis_buku.nama_penulis << endl;
        cout << "Harga \t\t: " << data_buku[i].harga << endl;
        cout << setfill('=') << setw(30) << "" << endl;
    }
    system("pause");
}

void ubah_data_buku()
{
    int ubah_id_buku;
    bool ditemukan = false;

    cout << "\nMasukkan ID buku yang ingin diubah : ";
    cin >> ubah_id_buku;
    cout << setfill('=') << setw(40) << "" << endl;

    for (int i = 0; i < jumlah_data; i++)
    {
        if (ubah_id_buku == data_buku[i].id_buku)
        {
            cin.ignore();

            cout << "Judul Buku \t\t: ";
            getline(cin, data_buku[i].judul_buku);

            cout << "Nama Pengarang \t\t: ";
            getline(cin, data_buku[i].penulis_buku.nama_penulis);

            cout << "Harga \t\t\t: ";
            cin >> data_buku[i].harga;

            cout << "Data Berhasil Diperbarui" << endl;
            cout << setfill('=') << setw(30) << "" << endl;

            ditemukan = true;
            break;
        }
    }
    if (!ditemukan)
    {
        cout << "Buku dengan ID yang Diubah Tidak Ada" << endl;
    }
}

void hapus_buku()
{
    int hapus_id_buku;

    cout << "Masukkan ID Buku yang Ingin Dihapus : ";
    cin >> hapus_id_buku;
    cout << setfill('=') << setw(40) << "" << endl;

    for (int i = 0; i < jumlah_data; i++)
    {
        if (hapus_id_buku == data_buku[i].id_buku)
        {
            for (int j = i; j < jumlah_data; j++)
            {
                data_buku[j] = data_buku[j + 1];
            }
            jumlah_data--;
            cout << "ID Data Buku Berhasil Dihapus";
            break;
        }
    }
}

void beli_buku()
{
    int beli_buku;
    float total_harga = 0;
    string kode_voucher;
    float diskon = 0;

    cout << "Masukkan Jumlah Buku yang Ingin Dibeli : ";
    cin >> beli_buku;

    int id_buku_beli[beli_buku];

    cout << "Masukkan ID Buku yang Ingin Dibeli : " << endl;
    for (int i = 0; i < beli_buku; i++)
    {
        cin >> id_buku_beli[i];
    }

    int hitung = 0;
    for (int i = 0; i < beli_buku; i++)
    {
        for (int j = 0; j < jumlah_data; j++)
        {
            if (id_buku_beli[i] == data_buku[j].id_buku)
            {
                total_harga += data_buku[j].harga;
                for (int k = i; k < beli_buku; k++)
                {
                    if (data_buku[k].penulis_buku.nama_penulis == data_buku[j].penulis_buku.nama_penulis)
                        hitung++;
                }
            }
        }
    }

    if (hitung >= 2)
    {
        diskon += 0.05f;
    }
    cout << "Masukkan Kode Voucher (Kosongkan jika tidak ada) : ";
    cin.ignore();
    getline(cin, kode_voucher);

    if (kode_voucher == "JPYUM")
    {
        diskon = diskon + 0.1f;
    }

    total_harga = total_harga * (1 - diskon);
    cout << "Total Harga Setelah Diskon (jika ada) : " << total_harga << endl;
    system("pause");
}

int main()
{
    int pilih;

    do
    {
        cout << "\nSELAMAT DATANG !!" << endl;
        cout << "Silahkan Pilih Menu : " << endl;
        cout << "1. Tambah Buku" << endl;
        cout << "2. Tampilkan Daftar Buku" << endl;
        cout << "3. Ubah Data Buku" << endl;
        cout << "4. Hapus Buku" << endl;
        cout << "5. Hitung Total Harga Pembelian dengan Diskon" << endl;
        cout << "6. Keluar " << endl;
        cout << "Pilih Opsi : ";
        cin >> pilih;

        system("cls");

        switch (pilih)
        {
        case 1:
            menu_tambah_buku();
            break;
        case 2:
            tampilkan_daftar_buku();
            break;
        case 3:
            ubah_data_buku();
            break;
        case 4:
            hapus_buku();
            break;
        case 5:
            beli_buku();
            break;
        case 6:
            exit(0);
            break;
        }
    } while (true);
}
