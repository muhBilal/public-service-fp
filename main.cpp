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
                cout << "Nomor HP: " << daftarLaporan[i].nomorHp << endl;
                cout << "Alamat: " << daftarLaporan[i].alamat << endl;
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
        cout << "Masukkan id laporan yang ingin diedit: ";
        cin >> idLaporan;
        cin.ignore();
        if (idLaporan > 0 && idLaporan <= daftarLaporan.size()) {
            Laporan &laporan = daftarLaporan[idLaporan - 1];
            cout << "Masukkan nama baru: ";
            getline(cin, laporan.nama);
            cout << "Masukkan alamat baru: ";
            getline(cin, laporan.alamat);
            cout << "Masukkan jenis laporan baru: ";
            getline(cin, laporan.jenisLaporan);
            cout << "Masukkan permasalahan baru: ";
            getline(cin, laporan.permasalahan);
            cout << "Masukkan lokasi baru: ";
            getline(cin, laporan.lokasi);
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
            cout << "Data berhasil disimpan ke data.txt.\n";
        } else {
            cout << "Gagal membuka file untuk disimpan.\n";
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
                    cout << "Program selesai.\n";
                    break;
                default:
                    cout << "Pilihan tidak valid. Silakan pilih menu yang benar.\n";
                    break;
            }
        } while (pilihan != 5);

        return 0;
    }
