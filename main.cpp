#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <ctime>

using namespace std;

struct Laporan {
    string nama;
    string alamat;
    string nomorHp;
    string jenisLaporan;
    string permasalahan;
    string lokasi;
    string tanggal;
};

vector<Laporan> daftarLaporan; // Vektor untuk menyimpan semua laporan

// Fungsi untuk menampilkan menu
void tampilkanMenu() {
    cout << "==================================\n";
    cout << "SIADU PERUMAHAN RUNGKUT ASRI TIMUR\n";
    cout << "==================================\n";
    cout << "Menu: \n";
    cout << "1. Tambah Laporan\n";
    cout << "2. Tampilkan Laporan\n";
    cout << "3. Edit Laporan\n";
    cout << "4. Hapus Laporan\n";
    cout << "5. Keluar dan Simpan\n";
    cout << "Pilih menu: ";
}

// Fungsi untuk menambah laporan baru
void tambahLaporan() {
    Laporan laporanBaru;
    cout << "Masukkan Nama: ";
    cin.ignore();
    getline(cin, laporanBaru.nama);
    cout << "Masukkan Alamat: ";
    getline(cin, laporanBaru.alamat);
    cout << "Masukkan Nomor HP: ";
    getline(cin, laporanBaru.nomorHp);
    cout << "Masukkan Jenis Laporan: ";
    getline(cin, laporanBaru.jenisLaporan);
    cout << "Masukkan Permasalahan: ";
    getline(cin, laporanBaru.permasalahan);
    cout << "Masukkan Lokasi: ";
    getline(cin, laporanBaru.lokasi);
    time_t now = time(0);
    char* dt = ctime(&now);
    laporanBaru.tanggal = dt; 
    daftarLaporan.push_back(laporanBaru);
    cout << "Laporan Kami Terima!\n";
}

// Fungsi untuk menampilkan semua laporan
void tampilkanSemuaLaporan() {
    if (daftarLaporan.empty()) {
        cout << "Belum Ada Laporan Yang Tersedia.\n";
    } else {
        cout << "Daftar Laporan:\n";
        for (size_t i = 0; i < daftarLaporan.size(); ++i) {
            cout << "Laporan " << i + 1 << ":\n";
            cout << "Nama: " << daftarLaporan[i].nama << endl;
            cout << "Alamat: " << daftarLaporan[i].alamat << endl;
            cout << "Nomor HP: " << daftarLaporan[i].nomorHp << endl;
            cout << "Jenis Laporan: " << daftarLaporan[i].jenisLaporan << endl;
            cout << "Permasalahan: " << daftarLaporan[i].permasalahan << endl;
            cout << "Lokasi: " << daftarLaporan[i].lokasi << endl;
            cout << "Tanggal: " << daftarLaporan[i].tanggal << endl;
            cout << "-------------------\n";
        }
    }
}

// Fungsi untuk mengedit laporan
void editLaporan() {
    int idLaporan;
    cout << "Masukkan ID Laporan Yang Ingin Diedit: ";
    cin >> idLaporan;
    cin.ignore();
    if (idLaporan > 0 && idLaporan <= daftarLaporan.size()) {
        Laporan &laporan = daftarLaporan[idLaporan - 1];
        cout << "Masukkan Nama Baru: ";
        getline(cin, laporan.nama);
        cout << "Masukkan Alamat Baru: ";
        getline(cin, laporan.alamat);
        cout << "Masukkan Nomor HP Baru: ";
        getline(cin, laporan.nomorHp);
        cout << "Masukkan Jenis Laporan Baru: ";
        getline(cin, laporan.jenisLaporan);
        cout << "Masukkan Permasalahan Baru: ";
        getline(cin, laporan.permasalahan);
        cout << "Masukkan Lokasi Baru: ";
        getline(cin, laporan.lokasi);
        cout << "Laporan Berhasil Diubah!\n";
    } else {
        cout << "ID Laporan Tidak Valid.\n";
    }
}

// Fungsi untuk menghapus laporan
void hapusLaporan() {
    int idLaporan;
    cout << "Masukkan ID Laporan Yang Ingin Dihapus: ";
    cin >> idLaporan;
    if (idLaporan > 0 && idLaporan <= daftarLaporan.size()) {
        daftarLaporan.erase(daftarLaporan.begin() + idLaporan - 1);
        cout << "Laporan Berhasil Dihapus!\n";
    } else {
        cout << "ID Laporan Tidak Valid.\n";
    }
}

// Fungsi untuk menyimpan laporan ke file
void simpanLaporanKeFile() {
    ofstream file("data.txt");
    if (file.is_open()) {
        for (const auto &laporan : daftarLaporan) {
            file << "Nama: " << laporan.nama << endl;
            file << "Nomor HP: " << laporan.nomorHp << endl;
            file << "Alamat: " << laporan.alamat << endl;
            file << "Jenis Laporan: " << laporan.jenisLaporan << endl;
            file << "Permasalahan: " << laporan.permasalahan << endl;
            file << "Lokasi: " << laporan.lokasi << endl;
            file << "Tanggal: " << laporan.tanggal;
            file << "-------------------\n";
        }
        file.close();
        cout << "Data Berhasil Disimpan Ke data.txt.\n";
    } else {
        cout << "Gagal Membuka File Untuk Disimpan.\n";
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
                simpanLaporanKeFile();
                cout << "Program Aelesai.\n";
                break;
            default:
                cout << "Pilihan Tidak Valid. Silakan Pilih Menu Yang Benar.\n";
                break;
        }
    } while (pilihan != 5);

    return 0;
}
