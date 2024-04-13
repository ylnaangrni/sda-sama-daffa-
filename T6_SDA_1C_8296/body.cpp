#include "LinkedList.h"
#include <climits> 

Kota *head = nullptr;
int totalkota = 0;

void tambahKota(string namaKota)
{
    Kota *temp = head;
    while (temp)
    {
        if (temp->nama == namaKota)
        {
            std::cout << "Kota dengan nama tersebut sudah ada." << std::endl;
            return;
        }
        temp = temp->next;
    }
    
    Kota *newKota = new Kota(namaKota);
    newKota->next = head;
    head = newKota;
    totalkota++;

    std::cout << "Kota " << namaKota << " berhasil ditambahkan.\n";
}

void tampilkanJumlahKota() 
{
    std::cout << "Total jumlah kota yang telah diinput: " << totalkota << std::endl;
}

void tambahPenduduk(string namaKota, string namaPenduduk, int usiaPenduduk)
{
    Kota *temp = head;
    while (temp)
    {
        if (temp->nama == namaKota)
        {
            Penduduk *newPenduduk = new Penduduk(namaPenduduk, usiaPenduduk);
            newPenduduk->next = temp->penduduk;
            temp->penduduk = newPenduduk;
            temp->totalPenduduk++; 
            return;
        }
        temp = temp->next;
    }
    std::cout << "Kota tidak ditemukan." << std::endl;
}  


int hitungJumlahPenduduk(string namaKota) {
    Kota *temp = head;
    while (temp) {
        if (temp->nama == namaKota) {
            return temp->totalPenduduk;
        }
        temp = temp->next;
    }
    return 0; // Return 0 if city not found
}

void tambahPendudukAkhir(string namaKota, string namaPenduduk, int usiaPenduduk)
{
    Penduduk *newPenduduk = new Penduduk(namaPenduduk, usiaPenduduk);
    Kota *temp = head;
    while (temp)
    {
        if (temp->nama == namaKota)
        {
            if (temp->penduduk == nullptr)
            {
                temp->penduduk = newPenduduk;
                temp->totalPenduduk++; // Increment jumlah anggota
                return;
            }
            Penduduk *tempPenduduk = temp->penduduk;
            while (tempPenduduk->next != nullptr)
            {
                tempPenduduk = tempPenduduk->next;
            }
            tempPenduduk->next = newPenduduk;
            temp->totalPenduduk++; // Increment jumlah anggota
            return;
        }
        temp = temp->next;
    }
    std::cout << "Kota tidak ditemukan." << std::endl;
}

void tambahPendudukTengah(string namaKota, string namaPenduduk, int usiaPenduduk, string namaPendudukSebelum)
{
    Penduduk *newPenduduk = new Penduduk(namaPenduduk, usiaPenduduk);
    Kota *temp = head;
    while (temp)
    {
        if (temp->nama == namaKota)
        {
            Penduduk *tempPenduduk = temp->penduduk;
            while (tempPenduduk)
            {
                if (tempPenduduk->nama == namaPendudukSebelum)
                {
                    newPenduduk->next = tempPenduduk->next;
                    tempPenduduk->next = newPenduduk;
                    temp->totalPenduduk++; // Increment jumlah anggota
                    return;
                }
                tempPenduduk = tempPenduduk->next;
            }
            std::cout << "Penduduk sebelum tidak ditemukan." << std::endl;
            return;
        }
        temp = temp->next;
    }
    std::cout << "Kota tidak ditemukan." << std::endl;
}



void hapusPenduduk(string namaKota, string namaPenduduk) {
    Kota* temp = head;
    while (temp) {
        if (temp->nama == namaKota) {
            Penduduk* current = temp->penduduk;
            Penduduk* previous = nullptr;
            while (current) {
                if (current->nama == namaPenduduk) {
                    if (previous == nullptr) { // Jika yang akan dihapus adalah elemen pertama
                        temp->penduduk = current->next;
                        delete current;
                        std::cout << "Penduduk dengan nama " << namaPenduduk << " dihapus dari kota " << namaKota << "." << std::endl;
                        return;
                    } else {
                        previous->next = current->next;
                        delete current;
                        std::cout << "Penduduk dengan nama " << namaPenduduk << " dihapus dari kota " << namaKota << "." << std::endl;
                        return;
                    }
                }
                previous = current;
                current = current->next;
            }
            std::cout << "Penduduk dengan nama " << namaPenduduk << " tidak ditemukan di kota " << namaKota << "." << std::endl;
            return;
        }
        temp = temp->next;
    }
    std::cout << "Kota tidak ditemukan." << std::endl;
}


void tampilkanDaftarKota()
{
    Kota *temp = head;
    while (temp)
    {
        std::cout << temp->nama << " (kota)" << std::endl;
        temp = temp->next;
    }
}

void tampilkanDaftarAnggota(string namaKota)
{
    Kota *temp = head;
    while (temp)
    {
        if (temp->nama == namaKota)
        {
            Penduduk *tempPenduduk = temp->penduduk;
            while (tempPenduduk)
            {
                std::cout << "(" << tempPenduduk->nama << ", " << tempPenduduk->usia << ") ";
                tempPenduduk = tempPenduduk->next;
            }
            std::cout << std::endl;
            return;
        }
        temp = temp->next;
    }
    std::cout << "Kota tidak ditemukan." << std::endl;
}

void cariDataKota(string namaKota)
{
    Kota *temp = head;
    while (temp)
    {
        if (temp->nama == namaKota)
        {
            std::cout << "Kota ditemukan: " << temp->nama << std::endl;
            return;
        }
        temp = temp->next;
    }
    std::cout << "Kota tidak ditemukan." << std::endl;
}

void cariAnggota(string namaKota, string namaPenduduk, int usiaPenduduk) {
    Kota* temp = head;
    while (temp) {
        if (temp->nama == namaKota) {
            Penduduk* current = temp->penduduk;
            while (current) {
                if (current->nama == namaPenduduk && current->usia == usiaPenduduk) {
                    std::cout << "Anggota ditemukan di kota " << namaKota << " dengan nama " << namaPenduduk << " dan usia " << usiaPenduduk << std::endl;
                    return;
                }
                current = current->next;
            }
            std::cout << "Anggota tidak ditemukan di kota " << namaKota << " dengan nama " << namaPenduduk << " dan usia " << usiaPenduduk << std::endl;
            return;
        }
        temp = temp->next;
    }
    std::cout << "nama tidak ditemukan." << std::endl;
}

void tampilkanJumlahAnggotaPerKota() {
    Kota *temp = head;
    while (temp) {
        // Periksa apakah node temp masih valid
        if (temp->penduduk) {
            std::cout << "Jumlah anggota kota " << temp->nama << ": " << temp->totalPenduduk << std::endl;
        }
        temp = temp->next;
    }
}

void urutkanUmurAnggotaPerKota() {
    Kota *temp = head;
    while (temp) {
        if (temp->penduduk) {
            // Bubble sort
            Penduduk *current = temp->penduduk;
            Penduduk *nextPenduduk = nullptr;
            bool swapped;
            do {
                swapped = false;
                current = temp->penduduk;
                while (current->next != nextPenduduk) {
                    if (current->usia < current->next->usia) {
                        // Swap data
                        string tempNama = current->nama;
                        int tempUsia = current->usia;
                        current->nama = current->next->nama;
                        current->usia = current->next->usia;
                        current->next->nama = tempNama;
                        current->next->usia = tempUsia;
                        swapped = true;
                    }
                    current = current->next;
                }
                nextPenduduk = current;
            } while (swapped);
        }
        temp = temp->next;
    }
}

void anggotaTertua(string namaKota) {
    Kota *temp = head;
    int maxUsia = INT_MIN;
    string namaAnggotaTertua;

    while (temp) {
        if (temp->nama == namaKota) {
            Penduduk *tempPenduduk = temp->penduduk;
            while (tempPenduduk) {
                if (tempPenduduk->usia > maxUsia) {
                    maxUsia = tempPenduduk->usia;
                    namaAnggotaTertua = tempPenduduk->nama;
                }
                tempPenduduk = tempPenduduk->next;
            }
            std::cout << "Anggota tertua di kota " << namaKota << ": " << namaAnggotaTertua << " (usia " << maxUsia << " tahun)" << std::endl;
            return;
        }
        temp = temp->next;
    }
    std::cout << "Kota tidak ditemukan." << std::endl;
}

void anggotaTermuda(string namaKota) {
    Kota *temp = head;
    int minUsia = INT_MAX;
    string namaAnggotaTermuda;

    while (temp) {
        if (temp->nama == namaKota) {
            Penduduk *tempPenduduk = temp->penduduk;
            while (tempPenduduk) {
                if (tempPenduduk->usia < minUsia) {
                    minUsia = tempPenduduk->usia;
                    namaAnggotaTermuda = tempPenduduk->nama;
                }
                tempPenduduk = tempPenduduk->next;
            }
            std::cout << "Anggota termuda di kota " << namaKota << ": " << namaAnggotaTermuda << " (usia " << minUsia << " tahun)" << std::endl;
            return;
        }
        temp = temp->next;
    }
    std::cout << "Kota tidak ditemukan." << std::endl;
}


void urutkanKota() {
    Kota *current = head;
    Kota *index = nullptr;
    string tempNama;

    if (head == nullptr) {
        std::cout << "Tidak ada data kota yang perlu diurutkan." << std::endl;
        return;
    }
    else {
        while (current != nullptr) {
            index = current->next;

            while (index != nullptr) {
                // Membandingkan nama kotanya dan menukar jika perlu
                if (current->nama > index->nama) {
                    tempNama = current->nama;
                    current->nama = index->nama;
                    index->nama = tempNama;
                }
                index = index->next;
            }
            current = current->next;
        }
        std::cout << "Data kota berhasil diurutkan secara ascending berdasarkan nama." << std::endl;
    }
}
