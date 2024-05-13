#include <iostream>
using namespace std;
#include "FinalTubesAmin.h"

int main(){
    listPenyewa Lp;
    listBarang Lb;

    masukList(Lp, Lb);
    buatRelasi(Lp, Lb);
    /*displayPenyewa(Lp);
    displayBarang(Lb);
    displayPenyewaBarang(Lp);
    displayPenyewaBarangTerbanyak(Lp);*/

    cout << "--------------------------------------------------------------------" << endl;
    cout << "                      Aplikasi Penyewaan Barang                     " << endl;
    cout << "              oleh Mahardhika Fernanda dan Dinda Desfira            " << endl;
    cout << "                               IF 46 03                             " << endl;
    cout << "                          Struktur Data 2023                        " << endl;
    cout << "--------------------------------------------------------------------" << endl;
    menu(Lp, Lb);

    return 0;
}
