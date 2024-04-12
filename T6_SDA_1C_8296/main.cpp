#include "LinkedList.h"

int main()
{
    std::string namaKota, namaPenduduk, namaPendudukSebelum;
    int usiaPenduduk;
    char opsi, subopsi, triopsi;

    do
    {
        std::cout << "=======================================\n";
        std::cout << "| Pilih operasi yang ingin dilakukan: |\n";
        std::cout << "| 1. Tambah kota                      |\n";
        std::cout << "| 2. Tambah anggota awal ke kota      |\n";
        std::cout << "| 3. Tambah anggota tengah ke kota    |\n";
        std::cout << "| 4. Tambah penduduk akhir ke kota    |\n";
        std::cout << "| 5. Hapus anggota dari kota          |\n";
        std::cout << "| 6. Menu Tampilkan dan cari          |\n";
        std::cout << "| 7. Tampilkan Anggota Tertua         |\n";
        std::cout << "| 8. Tampilkan Anggota Termuda        |\n";
        std::cout << "| 9. Urutkan kota dan usia            |\n";
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
            std::cout << "Masukkan nama anggota sebelumnya: ";
            std::cin >> namaPendudukSebelum;
            std::cout << "Masukkan usia anggota: ";
            std::cin >> usiaPenduduk;
            tambahPendudukTengah(namaKota, namaPenduduk, usiaPenduduk, namaPendudukSebelum);
            std::cout << "Anggota " << namaPenduduk << " (usia " << usiaPenduduk << ") berhasil ditambahkan ke kota " << namaKota << ".\n";
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
                std::cout << "3. Tampilkan Jumlah Kota\n";
                std::cout << "4. Tampilkan Jumlah Anggota \n";
                std::cout << "5. Cari Anggota\n";
                std::cout << "6. Cari Data Kota\n";
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
                    tampilkanJumlahKota();
                    break;
                case '4':
                    tampilkanJumlahAnggotaPerKota(); 
                    break;
                case '5':
                    std::cout << "Masukkan nama kota: ";
                    std::cin >> namaKota;
                    std::cout << "Masukkan nama anggota yang ingin dicari: ";
                    std::cin >> namaPenduduk;
                    std::cout << "Masukkan usia anggota yang ingin dicari: ";
                    std::cin >> usiaPenduduk;
                    cariAnggota(namaKota, namaPenduduk, usiaPenduduk);
                    break;
                case '6':
                    std::cout << "Masukkan nama kota yang ingin dicari: ";
                    std::cin >> namaKota;
                    cariDataKota(namaKota);
                    break;
                }
            } while (subopsi != '0');
            break;
        case '7':
            std::cout << "Anggota tertua di setiap kota:\n";
            tampilkanDaftarKota();
            std::cout << std::endl;
            for (Kota *temp = head; temp != nullptr; temp = temp->next)
            {
                anggotaTertua(temp->nama);
            }
            break;
        case '8':
            std::cout << "Anggota termuda di setiap kota:\n";
            tampilkanDaftarKota();
            std::cout << std::endl;
            for (Kota *temp = head; temp != nullptr; temp = temp->next)
            {
                anggotaTermuda(temp->nama);
            }
            break;
        case '9':
            std::cout << "Pilih jenis pengurutan:\n";
            std::cout << "1. Urutkan anggota kota berdasarkan usia\n";
            std::cout << "2. Urutkan kota berdasarkan nama\n";
            std::cout << "Pilihan: ";
            std::cin >> triopsi;
            switch (triopsi) 
            {
                case '1':
                    urutkanUmurAnggotaPerKota();
                    std::cout << "Anggota kota setelah diurutkan berdasarkan usia:\n";
                    tampilkanDaftarKota();
                    std::cout << "Masukkan nama kota yang ingin ditampilkan anggotanya: ";
                    std::cin >> namaKota;
                    std::cout << "Daftar anggota kota " << namaKota << " setelah diurutkan berdasarkan usia:\n";
                    tampilkanDaftarAnggota(namaKota); 
                    break;
                case '2':
                    urutkanKota();
                    tampilkanDaftarKota(); // Tampilkan daftar kota yang sudah diurutkan
                    break;
                default:
                    std::cout << "Pilihan tidak valid." << std::endl;
                    break;
            }
            break;
        default:
            std::cout << "Pilihan tidak valid." << std::endl;
            break;
        }
        std::cout << std::endl;
    } while (opsi != '0');
    return 0;
}
