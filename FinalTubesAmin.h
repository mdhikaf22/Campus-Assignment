#ifndef FINALTUBESAMIN_H_INCLUDED
#define FINALTUBESAMIN_H_INCLUDED
#include <iostream>
using namespace std;

typedef struct elmPenyewa *adrPenyewa;
typedef struct elmBarang *adrBarang;
typedef struct elmRelasi *adrRelasi;

struct Penyewa {
    string nama;
    string jaminan;
    int totalTransaksi;
};

struct Barang {
    string namaBarang;
    string jenis;
    int harga;
};

typedef struct Penyewa infotypePenyewa;
typedef struct Barang infotypeBarang;

struct listPenyewa {
    adrPenyewa first;
    adrPenyewa last;
};

struct listBarang {
    adrBarang first;
};

struct elmPenyewa {
    infotypePenyewa info;
    adrPenyewa next;
    adrPenyewa prev;
    adrRelasi FirstListRelasi;
};

struct elmBarang {
    infotypeBarang info;
    adrBarang next;
};

struct elmRelasi{
    adrBarang nextBarang ;
    adrRelasi nextRelasi ;
    adrRelasi prevRelasi ;
};

void createlistPenyewa(listPenyewa &Lp);
adrPenyewa alokasiPenyewa(infotypePenyewa);
void insertfirstPenyewa(listPenyewa &Lp, adrPenyewa p) ;
void insertlastPenyewa(listPenyewa &Lp, adrPenyewa p) ;
void insertafterPenyewa(listPenyewa &Lp, adrPenyewa prec, adrPenyewa p);
void deletefirstPenyewa(listPenyewa &Lp, adrPenyewa &p);
void deletelastPenyewa(listPenyewa &Lp, adrPenyewa &p);
void deleteafterPenyewa(adrPenyewa prec, adrPenyewa &p);
adrPenyewa findPenyewa(listPenyewa Lp, string namaP);
void displayPenyewa(listPenyewa Lp);
void displayPenyewaTertentu(listPenyewa Lp, string namap);

void createlistBarang(listBarang &Lb) ;
adrBarang alokasiBarang(infotypeBarang data);
void insertfirstBarang(listBarang &Lb, adrBarang p) ;
void insertlastBarang(listBarang &Lb, adrBarang p);
void insertafterBarang(listBarang &Lb, adrBarang prec, adrBarang p) ;
void deletefirstBarang(listBarang &Lb, adrBarang &p);
void deletelastBarang(listBarang &Lb, adrBarang &p) ;
void deleteafterBarang(adrBarang prec, adrBarang &p) ;
void deleteAllBarangofPenyewa(listPenyewa &Lp, string namap);
adrBarang findBarang(listBarang Lb, string namaB) ;
void displayBarang(listBarang Lb);

adrBarang findBarangofPenyewa(listPenyewa Lp, string namap, string namab);
void addRelasi(listPenyewa &Lp, listBarang &Lb, string namaP, string namaB) ;
void deletePenyewaRelasi(listPenyewa &Lp, string namaP);
void deleteBarangPenyewa(listPenyewa &Lp, listBarang &Lb, string namaP, string namaB);
void displayPenyewaBarang(listPenyewa Lp);
void displayPenyewaBarangTertentu(listPenyewa Lp, string namap);
int countBarangPenyewa(listPenyewa Lp, string namaP);

void masukList(listPenyewa &Lp, listBarang &Lb);
void buatRelasi(listPenyewa &Lp, listBarang &Lb);
void menu(listPenyewa &Lp, listBarang &Lb);

#endif // FINALTUBESAMIN_H_INCLUDED
