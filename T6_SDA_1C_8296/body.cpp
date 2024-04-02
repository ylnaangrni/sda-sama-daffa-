#include "LinkedList.h"

Kota *head = nullptr;

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

    std::cout << "Kota " << namaKota << " berhasil ditambahkan.\n";
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
            return;
        }
        temp = temp->next;
    }
    std::cout << "Kota tidak ditemukan." << endl;
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
                return;
            }
            Penduduk *tempPenduduk = temp->penduduk;
            while (tempPenduduk->next != nullptr)
            {
                tempPenduduk = tempPenduduk->next;
            }
            tempPenduduk->next = newPenduduk;
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


void hapusPenduduk(string namaKota, string namaPenduduk)
{
    Kota *temp = head;
    while (temp)
    {
        if (temp->nama == namaKota)
        {
            Penduduk *prev = nullptr;
            Penduduk *current = temp->penduduk;
            while (current)
            {
                if (current->nama == namaPenduduk)
                {
                    if (prev)
                        prev->next = current->next;
                    else
                        temp->penduduk = current->next;
                    delete current;
                    return;
                }
                prev = current;
                current = current->next;
            }
            cout << "Penduduk tidak ditemukan." << std::endl;
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

void tampilkanDaftarAnggota(std::string namaKota)
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

void cariDataKota(std::string namaKota)
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
