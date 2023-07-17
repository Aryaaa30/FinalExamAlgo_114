#include <iostream>
#include <string>
using namespace std;

const int MAX_MAHASISWA = 100;

int NIM[MAX_MAHASISWA];
string nama[MAX_MAHASISWA];
string jurusan[MAX_MAHASISWA];
int tahunMasuk[MAX_MAHASISWA];

int jumlahMahasiswa = 0;

void tambahMahasiswa() {
    if (jumlahMahasiswa < MAX_MAHASISWA) {
        cout << "========== TAMBAH MAHASISWA ==========" << endl;
        cout << "NIM : ";
        cin >> NIM[jumlahMahasiswa];
        cin.ignore();
        cout << "Nama : ";
        getline(cin, nama[jumlahMahasiswa]);
        cout << "Jurusan : ";
        getline(cin, jurusan[jumlahMahasiswa]);
        cout << "Tahun Masuk: ";
        cin >> tahunMasuk[jumlahMahasiswa];
        cin.ignore();
        jumlahMahasiswa++;
        cout << "Mahasiswa berhasil ditambahkan!" << endl;
    }
    else {
        cout << "Kapasitas maksimum mahasiswa telah tercapai." << endl;
    }
}

void tampilkanSemuaMahasiswa() {
    if (jumlahMahasiswa == 0) {
        cout << "Tidak ada data mahasiswa." << endl;
    }
    else {
        cout << "========== SEMUA MAHASISWA ==========" << endl;
        for (int i = 0; i < jumlahMahasiswa; i++) {
            cout << "NIM       : " << NIM[i] << endl;
            cout << "Nama      : " << nama[i] << endl;
            cout << "Jurusan   : " << jurusan[i] << endl;
            cout << "Tahun Masuk: " << tahunMasuk[i] << endl;
            cout << endl;
        }
    }
}

void algoritmacariMahasiswaByNIM() {
    int cariNIM;
    cout << "Masukkan NIM yang ingin dicari: ";
    cin >> cariNIM;
    cin.ignore();

    bool found = false;
    for (int i = 0; i < jumlahMahasiswa; i++) {
        if (NIM[i] == cariNIM) {
            cout << "========== DATA MAHASISWA ==========" << endl;
            cout << "NIM       : " << NIM[i] << endl;
            cout << "Nama      : " << nama[i] << endl;
            cout << "Jurusan   : " << jurusan[i] << endl;
            cout << "Tahun Masuk: " << tahunMasuk[i] << endl;
            cout << endl;
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Mahasiswa dengan NIM " << cariNIM << " tidak ditemukan." << endl;
    }
}

void algoritmaSortByTahunMasuk() {
    for (int i = 0; i < jumlahMahasiswa - 1; i++) {
        for (int j = 0; j < jumlahMahasiswa - i - 1; j++) {
            if (tahunMasuk[j] > tahunMasuk[j + 1]) {
                swap(NIM[j], NIM[j + 1]);
                swap(nama[j], nama[j + 1]);
                swap(jurusan[j], jurusan[j + 1]);
                swap(tahunMasuk[j], tahunMasuk[j + 1]);
            }
        }
    }
    cout << "Data mahasiswa telah diurutkan berdasarkan tahun masuk." << endl;
}

int main() {
    int pilihan;
    do {
        cout << "========== MENU MANAJEMEN DATA MAHASISWA ==========" << endl;
        cout << "1. Tambah Mahasiswa" << endl;
        cout << "2. Tampilkan Semua Mahasiswa" << endl;
        cout << "3. Cari Mahasiswa berdasarkan NIM" << endl;
        cout << "4. Tampilkan Mahasiswa berdasarkan Tahun Masuk" << endl;
        cout << "5. Keluar" << endl;
        cout << "Pilihan: ";
        cin >> pilihan;
        cin.ignore();
        switch (pilihan) {
        case 1:
            tambahMahasiswa();
            break;
        case 2:
            tampilkanSemuaMahasiswa();
            break;
        case 3:
            algoritmacariMahasiswaByNIM();
            break;
        case 4:
            algoritmaSortByTahunMasuk();
            tampilkanSemuaMahasiswa();
            break;
        case 5:
            cout << "Terima kasih! Program selesai." << endl;
            break;
        default:
            cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
        }
        cout << endl;
    } while (pilihan != 5);

    return 0;
}

// 2. Algoritma yang digunakan dalam program di atas adalah :
//    - Bubble Sort
//    - Quick Sort
//    - Linear Search

// 3. Perbedaan mendasar antara algoritma stack dan queue adalah :
//    - Stack adalah struktur data linear yang mengikuti prinsip Last - in - first - out (LIFO), 
//      yang berarti elemen terakhir yang dimaksukkan adalah elemen yang pertama keluar.
//      Operasi yang umum dilakukan pada stack adalah push (menambahkan elemen) dan pop (menghapus elemen). 
//    - Queue adalah struktur data linear yang mengikuti prinsip First - in - First - out (FIFO), 
//      yang berarti elemen pertama yang dimasukkan adalah elemen pertama yang keluar.
//      Operasi yang umum dilakukan pada queue adalah enqueue(menambahkan elemen) dan dequeue(menghapus elemen).

// 4. Algoritma stack digunakan pada saat kita ingin mengimplementasikan operasi Last - In - First - Out(LIFO).
//    Contoh situasi di mana algoritma stack digunakan adalah :
//    - Melakukan operasi undo / redo pada aplikasi pengolah teks atau desain grafis.

// 5. a. Kedalaman struktur pada gambar tersebut adalah 5.
//    b. Cara membaca struktur pohon dapat dilakukan dengan menggunakan metode Preorder Traversal.
//       In = 1 5 8 12 15 10 20 22 25 28 30 36 38 40 45 48 50 ( Salah )
//       Preorder = 25 20 10 5 1 8 12 15 22 36 30 28 40 38 48 45 50 ( Benar )
//       Post = 1 8 5 15 12 10 22 20 28 38 45 50 48 30 40 36 25 ( Salah )