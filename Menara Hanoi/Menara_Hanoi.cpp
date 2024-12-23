#include <iostream>
using namespace std;

// Fungsi rekursif untuk memindahkan cakram dari satu tiang ke tiang lainnya
void menaraHanoi(int n, char asal, char tujuan, char bantu)
{
    if (n == 1)
    {
        cout << "Pindahkan cakram 1 dari tiang " << asal << " ke tiang " << tujuan << endl;
        return;
    }
    // Pindahkan n-1 cakram dari asal ke bantu menggunakan tujuan sebagai perantara
    menaraHanoi(n - 1, asal, bantu, tujuan);

    // Pindahkan cakram ke-n dari asal ke tujuan
    cout << "Pindahkan cakram " << n << " dari tiang " << asal << " ke tiang " << tujuan << endl;

    // Pindahkan n-1 cakram dari bantu ke tujuan menggunakan asal sebagai perantara
    menaraHanoi(n - 1, bantu, tujuan, asal);
}

int main()
{
    int n; // Jumlah cakram

    cout << "\nMasukkan jumlah cakram : ";
    cin >> n;

    cout << "\nLangkah-langkah Pemindahan Menara Hanoi :" << endl;
    menaraHanoi(n, 'A', 'C', 'B'); // A: asal, C: tujuan, B: bantu

    return 0;
}