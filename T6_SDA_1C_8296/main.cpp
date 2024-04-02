#include "LinkedList.h"

int main()
{
    std::string namaKota, namaPenduduk, namaPendudukSebelum;
    int usiaPenduduk;
    char opsi;

    do
    {
        std::cout << "Pilih operasi yang ingin dilakukan:\n";
        std::cout << "1. Tambah kota\n";
        std::cout << "2. Tambah anggota awal ke kota\n";
        std::cout << "3. Tambah anggota tengah ke kota\n";
        std::cout << "4. Hapus anggota dari kota\n";
        std::cout << "5. Tampilkan daftar kota\n";
        std::cout << "6. Tampilkan daftar anggota kota\n";
        std::cout << "7. Cari data kota\n";
        std::cout << "8. tambah penduduk akhir ke kota\n";
        std::cout << "0. Keluar\n";
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
            std::cout << "Kota " << namaKota << " berhasil ditambahkan.\n";
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
            std::cout << "Masukkan nama anggota yang ingin dihapus: ";
            std::cin >> namaPenduduk;
            hapusPenduduk(namaKota, namaPenduduk);
            std::cout << "Anggota " << namaPenduduk << " berhasil dihapus dari kota " << namaKota << ".\n";
            break;
        case '5':
            std::cout << "Daftar kota:\n";
            tampilkanDaftarKota();
            break;
        case '6':
            std::cout << "Masukkan nama kota: ";
            std::cin >> namaKota;
            std::cout << "Daftar anggota kota " << namaKota << ":\n";
            tampilkanDaftarAnggota(namaKota);
            break;
        case '7':
            std::cout << "Masukkan nama kota yang ingin dicari: ";
            std::cin >> namaKota;
            cariDataKota(namaKota);
            break;
        case '8':
        std::cout << "Masukkan nama kota: ";
            std::cin >> namaKota;
            std::cout << "Masukkan nama anggota: ";
            std::cin >> namaPenduduk;
            std::cout << "Masukkan usia anggota: ";
            std::cin >> usiaPenduduk;
            tambahPendudukAkhir(namaKota, namaPenduduk, usiaPenduduk);
            std::cout << "Anggota " << namaPenduduk << " (usia " << usiaPenduduk << ") berhasil ditambahkan ke kota " << namaKota << ".\n";
    
        default:
            std::cout << "Pilihan tidak valid. Silakan pilih lagi.\n";
        }

       
        std::cout << std::endl;
    } while (opsi != '0');

    return 0;
}
