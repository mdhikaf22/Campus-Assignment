#include "FinalTubesAmin.h"

void createlistPenyewa(listPenyewa &Lp){
    Lp.first = NULL;
    Lp.last = NULL;
}

adrPenyewa alokasiPenyewa(infotypePenyewa data){
    adrPenyewa p = new elmPenyewa;
    p->info = data;
    p->next = p->prev = NULL;
    p->FirstListRelasi = NULL;
    return p;
}

void insertfirstPenyewa(listPenyewa &Lp, adrPenyewa p){
    if (Lp.first == NULL){
        Lp.first = p;
        Lp.last = p;
    } else {
        p->next = Lp.first;
        Lp.first->prev = p;
        Lp.first = p;
    }
}

void insertlastPenyewa(listPenyewa &Lp, adrPenyewa p) {
    if (Lp.first == NULL){
        Lp.first = p;
        Lp.last = p;
    }else{
        p->prev = Lp.last;
        Lp.last->next = p;
        Lp.last = p;
    }
}

void insertafterPenyewa(listPenyewa &Lp, adrPenyewa prec, adrPenyewa p){
    if (prec == Lp.last) {
        insertlastPenyewa(Lp, p);
    } else {
        p->next = prec->next;
        p->prev = prec;
        prec->next->prev = p;
        prec->next = p;
    }
}

void deletefirstPenyewa(listPenyewa &Lp, adrPenyewa &p){
    if (Lp.first != NULL) {
        p = Lp.first;
        Lp.first = p->next;
        if (Lp.first != NULL) {
            Lp.first->prev = NULL;
        } else {
            Lp.last = NULL;
        }
    }
}

void deletelastPenyewa(listPenyewa &Lp, adrPenyewa &p){
    if (Lp.last != NULL) {
        p = Lp.last;
        Lp.last = p->prev;
        if (Lp.last != NULL) {
            Lp.last->next = NULL;
        } else {
            Lp.first = NULL;
        }
    }
}

void deleteafterPenyewa(adrPenyewa prec, adrPenyewa &p){
    if (prec != NULL && prec->next != NULL) {
            p = prec->next;
            prec->next = p->next;
            if (p->next != NULL) {
                p->next->prev = prec;
            }
        }
}

adrPenyewa findPenyewa(listPenyewa Lp, string nama){
    adrPenyewa p = Lp.first;
    while (p != NULL) {
        if (p->info.nama == nama) {
            return p;
        }
        p = p->next;
    }
    return NULL;
}

void displayPenyewa(listPenyewa Lp){
    cout << endl;
    cout << "--------------------- Data Informasi Penyewa -----------------------" << endl;
    adrPenyewa penyewa = Lp.first;
    while (penyewa != NULL) {
        cout << "Nama: " << penyewa->info.nama << endl;
        cout << "Jaminan: " << penyewa->info.jaminan << endl;
        int total = countBarangPenyewa(Lp, penyewa->info.nama);
        cout << "Total Transaksi: " << total << endl ;
        cout << endl;
        penyewa = penyewa->next;
    }
    cout << "--------------------------------------------------------------------" << endl;
}

void createlistBarang(listBarang &Lb){
    Lb.first = NULL;
}

adrBarang alokasiBarang(infotypeBarang data){
    adrBarang p = new elmBarang;
    p->info = data;
    p->next = NULL;
    return p;
}

void insertfirstBarang(listBarang &Lb, adrBarang p){
    if (Lb.first == NULL) {
        Lb.first = p;
    } else {
        p->next = Lb.first;
        Lb.first = p;
    }
}

void insertlastBarang(listBarang &Lb, adrBarang p){
    if (Lb.first == NULL) {
        Lb.first = p;
    } else {
        adrBarang temp = Lb.first;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = p;
    }
}

void insertafterBarang(listBarang &Lb, adrBarang prec, adrBarang p){
     if (prec != NULL) {
        p->next = prec->next;
        prec->next = p;
    }
}

void deletefirstBarang(listBarang &Lb, adrBarang &p){
    if (Lb.first != NULL) {
        p = Lb.first;
        Lb.first = p->next;
    }
}

void deletelastBarang(listBarang &Lb, adrBarang &p){
if (Lb.first != NULL) {
        if (Lb.first->next == NULL) {
            p = Lb.first;
            Lb.first = NULL;
        } else {
            adrBarang temp = Lb.first;
            while (temp->next->next != NULL) {
                temp = temp->next;
            }
            p = temp->next;
            temp->next = NULL;
        }
    }
}

void deleteafterBarang(adrBarang prec, adrBarang &p){
    if (prec != NULL && prec->next != NULL) {
        p = prec->next;
        prec->next = p->next;
    }
}

adrBarang findBarang(listBarang Lb, string namaB) {
     adrBarang p = Lb.first;
    while (p != NULL) {
        if (p->info.namaBarang == namaB) {
            return p;
        }
        p = p->next;
    }
    return NULL;
}

void displayBarang(listBarang Lb){
    cout << endl;
    cout << "---------------------------- List Barang ---------------------------" << endl;
    adrBarang currentBarang = Lb.first;
    while (currentBarang != NULL) {
        cout << "Nama: " << currentBarang->info.namaBarang << endl;
        cout << "Jenis: " << currentBarang->info.jenis << endl;
        cout << "Harga: " << currentBarang->info.harga << endl ;
        cout << endl;
        currentBarang = currentBarang->next;
    }
    cout << "--------------------------------------------------------------------" << endl;
}

void addRelasi(listPenyewa &Lp, listBarang &Lb, string namaP, string namaB){
    adrPenyewa penyewa = findPenyewa(Lp, namaP);
    adrBarang barang = findBarang(Lb, namaB);
    if (penyewa != NULL && barang != NULL) {
        adrRelasi relasi = new elmRelasi;
        relasi->nextBarang = barang;
        relasi->prevRelasi = NULL;
        relasi->nextRelasi = penyewa->FirstListRelasi;
        if (penyewa->FirstListRelasi != NULL) {
            penyewa->FirstListRelasi->prevRelasi = relasi;
        }
        penyewa->FirstListRelasi = relasi;
    }
}

void deletePenyewaRelasi(listPenyewa &Lp, string namaP){
    adrPenyewa Penyewa = findPenyewa(Lp, namaP);
    if (Penyewa != NULL) {
        adrRelasi relasi = Penyewa->FirstListRelasi;
        while (relasi != NULL) {
            adrRelasi tempRelasi = relasi;
            relasi = relasi->nextRelasi;
        }
        if (Penyewa == Lp.first) {
            deletefirstPenyewa(Lp, Penyewa);
        } else if (Penyewa == Lp.last) {
            deletelastPenyewa(Lp, Penyewa);
        } else {
            adrPenyewa prec = Lp.first;
            while (prec->next != Penyewa) {
                prec = prec->next;
            }
            deleteafterPenyewa(prec, Penyewa);
        }
    }
}

void deleteBarangPenyewa(listPenyewa &Lp, listBarang &Lb, string namaP, string namaB) {
    adrPenyewa Penyewa = findPenyewa(Lp, namaP);
    if (Penyewa != NULL) {
        adrRelasi relasi = Penyewa->FirstListRelasi;
        adrRelasi precRelasi = NULL;
        while ((relasi != NULL) && (relasi->nextBarang->info.namaBarang != namaB)) {
            precRelasi = relasi;
            relasi = relasi->nextRelasi;
        }
        if (relasi != NULL) {
            if (precRelasi == NULL) {
                Penyewa->FirstListRelasi = relasi->nextRelasi;
            } else {
                precRelasi->nextRelasi = relasi->nextRelasi;
            }
            if (relasi->nextRelasi != NULL) {
                relasi->nextRelasi->prevRelasi = relasi->prevRelasi;
            }
        }
    }
}

void displayPenyewaBarang(listPenyewa Lp){
    cout << endl;
    cout << "--------------------------- Data Penyewaan -------------------------" << endl;
    adrPenyewa penyewa = Lp.first;
    while (penyewa != NULL) {
        cout << "Nama Penyewa: " << penyewa->info.nama << endl;
        cout << "Jaminan: " << penyewa->info.jaminan << endl;
        cout << "Total Transaksi: " << countBarangPenyewa(Lp, penyewa->info.nama) << endl ;
        cout << "Barang yang Disewa: " << endl;
        adrRelasi relasi = penyewa->FirstListRelasi;
        int count = 1;
        while (relasi != NULL) {
            cout << count << ". " << relasi->nextBarang->info.namaBarang << endl;
            count++;
            relasi = relasi->nextRelasi;
        }
        cout << endl;
        penyewa = penyewa->next;
    }
    cout << "--------------------------------------------------------------------" << endl;
}

int countBarangPenyewa(listPenyewa Lp, string namaP){
    adrPenyewa penyewa = findPenyewa(Lp, namaP);
    if (penyewa != NULL) {
        int count = 0;
        adrRelasi relasi = penyewa->FirstListRelasi;
        while (relasi != NULL) {
            count++;
            relasi = relasi->nextRelasi;
        }
        return count;
    } else {
        return 0;
    }
}

void displayPenyewaBarangTertentu(listPenyewa Lp, string namap) {
    cout << endl;
    cout << "--------------------------- Data Penyewaan -------------------------" << endl;
    adrPenyewa penyewa = findPenyewa(Lp, namap);
    if (penyewa != NULL) {
        cout << "Nama Penyewa: " << namap << endl;
        cout << "Jaminan: " << penyewa->info.jaminan << endl;
        cout << "Total Transaksi: " << countBarangPenyewa(Lp, penyewa->info.nama) << endl ;
        cout << "Barang yang Disewa: " << endl;
        adrRelasi relasi = penyewa->FirstListRelasi;
        int count = 1;
        while (relasi != NULL) {
            cout << count << ". " << relasi->nextBarang->info.namaBarang << endl;
            count++;
            relasi = relasi->nextRelasi;
        }
    } else {
        cout << "Penyewa dengan nama " << namap << " tidak ditemukan." << endl;
    }
    cout << "--------------------------------------------------------------------" << endl;
}

void displayPenyewaTertentu(listPenyewa Lp, string namap){
    cout << endl;
    cout << "--------------------- Data Informasi Penyewa -----------------------" << endl;
    adrPenyewa penyewa = findPenyewa(Lp, namap);
    if (penyewa != NULL) {
        cout << "Nama: " << namap << endl;
        cout << "Jaminan: " << penyewa->info.jaminan << endl;
        int total = countBarangPenyewa(Lp, penyewa->info.nama);
        cout << "Total Transaksi: " << total << endl ;
    }
    cout << "--------------------------------------------------------------------" << endl;
}

adrBarang findBarangofPenyewa(listPenyewa Lp, string namap, string namab){
    if (Lp.first == NULL) {
        cout << "Penyewa kosong" << endl;
        return NULL;
    } else {
        adrPenyewa penyewaan = findPenyewa(Lp, namap);
        if (penyewaan != NULL) {
            adrRelasi relasi = penyewaan->FirstListRelasi;
            while (relasi != NULL && relasi->nextBarang->info.namaBarang != namab) {
                relasi = relasi->nextRelasi;
            }
            if (relasi == NULL) {
                return NULL;
            } else {
                return relasi->nextBarang;
            }
        } else {
            return NULL;
        }
    }
}

void deleteAllBarangofPenyewa(listPenyewa &Lp, string namap) {
    adrPenyewa penyewaan = findPenyewa(Lp, namap);
    if (penyewaan != NULL) {
        adrRelasi relasi = penyewaan->FirstListRelasi;
        while (relasi != NULL) {
            adrRelasi temp = relasi;
            relasi = relasi->nextRelasi;
            listBarang Lb;
            deleteBarangPenyewa(Lp, Lb, namap, temp->nextBarang->info.namaBarang);
        }
    }
}

void masukList(listPenyewa &Lp, listBarang &Lb){

    infotypePenyewa penyewa1, penyewa2, penyewa3, penyewa4;

    createlistPenyewa(Lp);
    createlistBarang(Lb);

    penyewa1.nama = "Dika";
    penyewa1.jaminan = "KTP";

    penyewa2.nama = "Maya";
    penyewa2.jaminan = "KK";

    penyewa3.nama = "Putra";
    penyewa3.jaminan = "KTM";

    penyewa4.nama = "Dinda";
    penyewa4.jaminan = "KTP";

    infotypeBarang barang1, barang2, barang3, barang4, barang5;

    barang1.namaBarang = "NIKON";
    barang1.jenis = "Full frame";
    barang1.harga = 100000;

    barang2.namaBarang = "SONY";
    barang2.jenis = "APSC";
    barang2.harga = 170000;

    barang3.namaBarang = "FUJIFILM";
    barang3.jenis = "Body";
    barang3.harga = 160000;

    barang4.namaBarang = "LUMIX";
    barang4.jenis = "Body";
    barang4.harga = 150000;

    barang5.namaBarang = "CANON";
    barang5.jenis = "Lensa";
    barang5.harga = 75000;

    adrPenyewa p1, p2, p3, p4;

    p1 = alokasiPenyewa(penyewa1);
    insertlastPenyewa(Lp, p1);

    p2 = alokasiPenyewa(penyewa2);
    insertlastPenyewa(Lp, p2);

    p3 = alokasiPenyewa(penyewa3);
    insertlastPenyewa(Lp, p3);

    p4 = alokasiPenyewa(penyewa4);
    insertlastPenyewa(Lp, p4);

    adrBarang ch1, ch2, ch3, ch4, ch5;

    ch1 = alokasiBarang(barang1);
    insertlastBarang(Lb, ch1);

    ch2 = alokasiBarang(barang2);
    insertlastBarang(Lb, ch2);

    ch3 = alokasiBarang(barang3);
    insertlastBarang(Lb, ch3);

    ch4 = alokasiBarang(barang4);
    insertlastBarang(Lb, ch4);

    ch5 = alokasiBarang(barang5);
    insertlastBarang(Lb, ch5);
}

void buatRelasi(listPenyewa &Lp, listBarang &Lb){
    addRelasi(Lp, Lb, "Dika", "NIKON");
    addRelasi(Lp, Lb, "Dika", "SONY");
    addRelasi(Lp, Lb, "Dika", "FUJIFILM");
    addRelasi(Lp, Lb, "Maya", "NIKON");
    addRelasi(Lp, Lb, "Putra", "SONY");
    addRelasi(Lp, Lb, "Putra", "FUJIFILM");
    addRelasi(Lp, Lb, "Putra", "LUMIX");
    addRelasi(Lp, Lb, "Putra", "CANON");
    addRelasi(Lp, Lb, "Dinda", "FUJIFILM");
    addRelasi(Lp, Lb, "Dinda", "LUMIX");
}

void menu(listPenyewa &Lp, listBarang &Lb){
    cout << endl;
    cout << "========================== MENU PENYEWAAN ==========================" << endl;
    cout << "1. Masukkan data penyewa baru." << endl; /*1*/
    cout << "2. Melihat semua data informasi penyewa." << endl; /*2*/
    cout << "3. Cari data informasi penyewa." << endl; /*4*/
    cout << "4. Menambah data barang baru." << endl; /*6*/
    cout << "5. Melihat semua data penyewaan." << endl; /*8*/
    cout << "6. Exit" << endl;
    int pilihan;
    cout << "Pilihan >> ";
    cin >> pilihan;
    cout << endl;
    if (pilihan == 1){ // 1. Masukkan data penyewa baru.
        cout << "Masukkan nama penyewa baru >> ";
        string pbaru;
        cin >> pbaru;
        adrPenyewa caripb = findPenyewa(Lp, pbaru);
        if (caripb != NULL){
            cout << "Nama penyewa sudah terdaftar." << endl;
            menu(Lp, Lb);
        } else {
            infotypePenyewa penyewa5;
            penyewa5.nama = pbaru;
            penyewa5.jaminan = "-";
            penyewa5.totalTransaksi = 0;
            adrPenyewa ch;
            ch = alokasiPenyewa(penyewa5);
            insertlastPenyewa(Lp, ch);
            displayPenyewa(Lp);
            menu(Lp, Lb);
        }
    } else if (pilihan == 2){ // 2. Melihat semua data informasi penyewa.
        displayPenyewa(Lp);
        cout << "1. Hapus data informasi penyewa." << endl; /*3*/
        cout << "2. Back" << endl;
        int pdua;
        cout << "Pilihan >> ";
        cin >> pdua;
        cout << endl;
        if (pdua != 1 && pdua != 2){
            while (pdua != 1 && pdua != 2){
                cout << "Input invalid" << endl;
                cout << "Pilihan >> ";
                cin >> pdua;
                cout << endl;
            }
        }
        if (pdua == 1){ // 1. Hapus data informasi penyewa.
            cout << "Masukkan nama penyewa >> ";
            string hapusp;
            cin >> hapusp;
            adrPenyewa carihp = findPenyewa(Lp, hapusp);
            if (carihp == NULL){
                cout << "Nama penyewa tidak ditemukan" << endl;
                menu(Lp, Lb);
            } else {
                deletePenyewaRelasi(Lp, hapusp);
                displayPenyewa(Lp);
                menu(Lp, Lb);
            }
        } else if (pdua == 2){
            menu(Lp, Lb);
        }
    } else if (pilihan == 3){ // 3. Cari data informasi penyewa.
        cout << "Masukkan nama penyewa >> ";
        string namap;
        cin >> namap;
        adrPenyewa carip = findPenyewa(Lp, namap);
        if (carip == NULL){
            cout << "Penyewa tidak ditemukan." << endl;
            menu(Lp, Lb);
        } else {
            displayPenyewaTertentu(Lp, namap);
            cout << "1. Menghapus data barang pada penyewa yang dicari." << endl; /*10*/
            cout << "2. Melihat barang yang disewa penyewa yang dicari." << endl; /*9*/
            cout << "3. Menambah barang sewaan penyewa yang dicari." << endl; /*7*//*6*/
            cout << "4. Back" << endl;
            int ptiga;
            cout << "Pilihan >> ";
            cin >> ptiga;
            if (ptiga != 1 && ptiga != 2 && ptiga != 3 && ptiga != 4){
                while (ptiga != 1 && ptiga != 2 && ptiga != 3 && ptiga != 4){
                    cout << "Input invalid" << endl;
                    cout << "Pilihan >> ";
                    cin >> ptiga;
                }
            }
            cout << endl;
            if (ptiga == 1){ // 1. Menghapus data barang tertentu pada penyewa yang dicari.
                cout << "1. Hapus semua." << endl;
                cout << "2. Cari data barang yang ingin dihapus." << endl; /*5*/
                cout << "3. Back to menu" << endl;
                int tigasatu;
                cout << "Pilihan >> ";
                cin >> tigasatu;
                if (ptiga != 1 && ptiga != 2 && ptiga != 3){
                    while (ptiga != 1 && ptiga != 2 && ptiga != 3){
                        cout << "Input invalid" << endl;
                        cout << "Pilihan >> ";
                        cin >> ptiga;
                    }
                }
                cout << endl;
                if (tigasatu == 1){
                    deleteAllBarangofPenyewa(Lp, namap);
                    displayPenyewaBarangTertentu(Lp, namap);
                    menu(Lp, Lb);
                } else if (tigasatu == 2){
                    cout << "Masukan nama barang >> ";
                    string hapusb;
                    cin >> hapusb;
                    adrBarang carihb = findBarangofPenyewa(Lp, namap, hapusb);
                    if (carihb == NULL){
                        cout << namap << " tidak menyewa " << hapusb << endl;
                        menu(Lp, Lb);
                    }
                    deleteBarangPenyewa(Lp, Lb, namap, hapusb);
                    displayPenyewaBarangTertentu(Lp, namap);
                    menu(Lp, Lb);
                } else if (tigasatu == 3){
                    menu(Lp, Lb);
                }
            } else if (ptiga == 2){ // 2. Melihat barang yang disewa penyewa yang dicari.
                displayPenyewaBarangTertentu(Lp, namap);
                menu(Lp, Lb);
            } else if (ptiga == 3){ // 3. Menambah barang sewaan penyewa yang dicari.
                cout << "Masukkan nama barang >> ";
                string namab;
                cin >> namab;
                adrBarang carib = findBarang(Lb, namab);
                if (carib == NULL){
                    while (carib == NULL){
                        cout << "Barang tidak terdaftar." << endl;
                        cin >> namab;
                    }
                }
                addRelasi(Lp, Lb, namap, namab);
                displayPenyewaBarangTertentu(Lp, namap);
                menu(Lp, Lb);
            } else if (ptiga == 4){
                menu(Lp, Lb);
            }
        }
    } else if (pilihan == 4){ // 4. Menambah data barang baru.
        cout << "Masukkan nama barang baru >> ";
        string bbaru;
        cin >> bbaru;
        adrBarang caribb = findBarang(Lb, bbaru);
        if (caribb != NULL){
            cout << "Barang sudah terdaftar. " << endl;
            menu(Lp, Lb);
        } else {
            cout << "Masukkan jenis >> ";
            string jenisb;
            cin >> jenisb;
            cout << "Masukkan harga >> ";
            int hargab;
            cin >> hargab;
            infotypeBarang barang6;
            barang6.namaBarang = bbaru;
            barang6.jenis = jenisb;
            barang6.harga = hargab;
            adrBarang ch6;
            ch6 = alokasiBarang(barang6);
            insertlastBarang(Lb, ch6);
            displayBarang(Lb);
            menu(Lp, Lb);
        }
    } else if (pilihan == 5){ // 5. Melihat semua data penyewaan.
        displayPenyewaBarang(Lp);
        menu(Lp, Lb);
    } else if (pilihan == 6){
        cout << "Goodbye!" << endl;
    } else {
        cout << "Input invalid" << endl;
        menu(Lp, Lb);
    }
}
