// Nama Anggota      : - Muhammad Daffa Tridya Atha (231511082)
//                     - Yulina Anggraeni           (231511096)
// Tanggal Pembuatan : 02/04/2024

#include "LinkedList.h"

int main()
{
    std::string namaKota, namaPenduduk, namaPendudukSebelum;
    int usiaPenduduk;
    char opsi,subopsi;

    do
    {
        std::cout << "=======================================\n";
        std::cout << "| Pilih operasi yang ingin dilakukan: |\n";
        std::cout << "| 1. Tambah kota                      |\n";
        std::cout << "| 2. Tambah anggota awal ke kota      |\n";
        std::cout << "| 3. Tambah anggota tengah ke kota    |\n";
        std::cout << "| 4. tambah penduduk akhir ke kota    |\n";
        std::cout << "| 5. Hapus anggota dari kota          |\n";
        std::cout << "| 6. Menu Tampilkan dan cari          |\n";
        std::cout << "| 7. Tampilkan Jumlah Kota            |\n";
        std::cout << "| 8. Jumlah anggota tiap kota         |\n";
        std::cout << "| 9. urutkan umur                     |\n";
        std::cout << "| 0. Keluar                           |\n";
        std::cout << "=======================================\n";
        std::cout << "Pilihan: ";

        std::cin >> opsi;

        switch (opsi)
        {
        case '0':
            std::cout << "Terima kasih, program selesai.\n";
            break;
        case '1':
            std::cout << "Masukkan nama kota: ";
            std::cin >> namaKota;
            tambahKota(namaKota);
            break;
        case '2':
            std::cout << "Masukkan nama kota: ";
            std::cin >> namaKota;
            std::cout << "Masukkan nama anggota: ";
            std::cin >> namaPenduduk;
            std::cout << "Masukkan usia anggota: ";
            std::cin >> usiaPenduduk;
            tambahPenduduk(namaKota, namaPenduduk, usiaPenduduk);
            std::cout << "Anggota " << namaPenduduk << " (usia " << usiaPenduduk << ") berhasil ditambahkan ke kota " << namaKota << ".\n";
            break;
        case '3':
            std::cout << "Masukkan nama kota: ";
            std::cin >> namaKota;
            std::cout << "Masukkan nama anggota: ";
            std::cin >> namaPenduduk;
            std::cout << "Masukan setelah siapa? : ";
            std::cin >> namaPendudukSebelum;
            std::cout << "Masukkan usia anggota: ";
            std::cin >> usiaPenduduk;
            tambahPendudukTengah(namaKota, namaPenduduk, usiaPenduduk, namaPendudukSebelum);
            std::cout <<  "Anggota " << namaPenduduk << " (usia " << usiaPenduduk << ") berhasil ditambahkan ke kota " << namaKota << ".\n";
            break;  
        case '4':
            std::cout << "Masukkan nama kota: ";
            std::cin >> namaKota;
            std::cout << "Masukkan nama anggota: ";
            std::cin >> namaPenduduk;
            std::cout << "Masukkan usia anggota: ";
            std::cin >> usiaPenduduk;
            tambahPendudukAkhir(namaKota, namaPenduduk, usiaPenduduk);
            std::cout << "Anggota " << namaPenduduk << " (usia " << usiaPenduduk << ") berhasil ditambahkan ke kota " << namaKota << ".\n";
            break;
        case '5':
            std::cout << "Masukkan nama kota: ";
            std::cin >> namaKota;
            std::cout << "Masukkan nama anggota yang ingin dihapus: ";
            std::cin >> namaPenduduk;
            hapusPenduduk(namaKota, namaPenduduk);
            std::cout << "Anggota " << namaPenduduk << " berhasil dihapus dari kota " << namaKota << ".\n";
            break;
        case '6':
        do
        {
            std::cout << "1. Tampilkan daftar kota\n";
            std::cout << "2. Tampilkan daftar anggota kota\n";
            std::cout << "3. Cari Data Kota\n";
            std::cout << "4. Cari Anggota\n";
            std::cout << "0. Kembali ke menu utama\n";

            std::cin >> subopsi;
            switch (subopsi)
            {
            case '1':

                std::cout << "Daftar kota:\n";
                tampilkanDaftarKota();
                break;
            case '2':

                std::cout << "Masukkan nama kota: ";
                std::cin >> namaKota;
                std::cout << "Daftar anggota kota " << namaKota << ":\n";
                tampilkanDaftarAnggota(namaKota);
                break;
            case '3':

                std::cout << "Masukkan nama kota yang ingin dicari: ";
                std::cin >> namaKota;
                cariDataKota(namaKota);
                break;

            case '4':
                std::cout << "Masukkan nama kota: ";
                std::cin >> namaKota;
                std::cout << "Masukkan nama anggota yang ingin dicari: ";
                std::cin >> namaPenduduk;
                std::cout << "Masukkan usia anggota yang ingin dicari: ";
                std::cin >> usiaPenduduk;
                cariAnggota(namaKota, namaPenduduk, usiaPenduduk);
                break;
            }
        } while (subopsi != '0');
        break;

        case '7':
            tampilkanJumlahKota();
        break;


        case '8':
            tampilkanJumlahAnggotaPerKota(); 
        break;

        case '9':
            urutkanUmurAnggotaPerKota();
            std::cout << "Daftar anggota tiap kota setelah diurutkan berdasarkan umur:\n";
         tampilkanDaftarKota();
        break;     
        }
        std::cout << std::endl;
    } while (opsi != '0');
    return 0;
}
