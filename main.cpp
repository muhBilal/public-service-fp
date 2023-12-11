#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Laporan {
    string nama;
    string permasalahan;
};

vector<Laporan> daftarLaporan; // Vektor untuk menyimpan semua laporan

// Fungsi untuk menampilkan menu
void tampilkanMenu() {
    cout << "Menu: \n";
    cout << "1. Tambah Laporan\n";
    cout << "2. Tampilkan Laporan\n";
    cout << "3. Edit Laporan\n";
    cout << "4. Hapus Laporan\n";
    cout << "5. Keluar\n";
    cout << "Pilih menu: ";
}

// Fungsi untuk menambah laporan baru
void tambahLaporan() {
    Laporan laporanBaru;
    cout << "Masukkan nama: ";
    cin.ignore();
    getline(cin, laporanBaru.nama);
    cout << "Masukkan permasalahan: ";
    getline(cin, laporanBaru.permasalahan);
    daftarLaporan.push_back(laporanBaru);
    cout << "Laporan telah ditambahkan!\n";
}

// Fungsi untuk menampilkan semua laporan
void tampilkanSemuaLaporan() {
    if (daftarLaporan.empty()) {
        cout << "Belum ada laporan yang tersedia.\n";
    } else {
        cout << "Daftar Laporan:\n";
        for (size_t i = 0; i < daftarLaporan.size(); ++i) {
            cout << "Laporan " << i + 1 << ":\n";
            cout << "Nama: " << daftarLaporan[i].nama << endl;
            cout << "Permasalahan: " << daftarLaporan[i].permasalahan << endl;
            cout << "-------------------\n";
        }
    }
}

// Fungsi untuk mengedit laporan
void editLaporan() {
    int idLaporan;
    cout << "Masukkan id laporan yang ingin diedit: ";
    cin >> idLaporan;
    cin.ignore();
    if (idLaporan > 0 && idLaporan <= daftarLaporan.size()) {
        Laporan &laporan = daftarLaporan[idLaporan - 1];
        cout << "Masukkan nama baru: ";
        getline(cin, laporan.nama);
        cout << "Masukkan permasalahan baru: ";
        getline(cin, laporan.permasalahan);
        cout << "Laporan berhasil diubah!\n";
    } else {
        cout << "Id laporan tidak valid.\n";
    }
}

// Fungsi untuk menghapus laporan
void hapusLaporan() {
    int idLaporan;
    cout << "Masukkan id laporan yang ingin dihapus: ";
    cin >> idLaporan;
    if (idLaporan > 0 && idLaporan <= daftarLaporan.size()) {
        daftarLaporan.erase(daftarLaporan.begin() + idLaporan - 1);
        cout << "Laporan berhasil dihapus!\n";
    } else {
        cout << "Id laporan tidak valid.\n";
    }
}

int main() {
    int pilihan;
    do {
        tampilkanMenu();
        cin >> pilihan;
        switch (pilihan) {
            case 1:
                tambahLaporan();
                break;
            case 2:
                tampilkanSemuaLaporan();
                break;
            case 3:
                editLaporan();
                break;
            case 4:
                hapusLaporan();
                break;
            case 5:
                cout << "Program selesai.\n";
                break;
            default:
                cout << "Pilihan tidak valid. Silakan pilih menu yang benar.\n";
                break;
        }
    } while (pilihan != 5);

    return 0;
}
