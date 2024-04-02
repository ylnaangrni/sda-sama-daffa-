#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include <string>

using namespace std;

struct Penduduk
{
    string nama;
    int usia;
    Penduduk *next;

    Penduduk(string _nama, int _usia) : nama(_nama), usia(_usia), next(nullptr) {}
};

struct Kota
{
    string nama;
    Penduduk *penduduk;
    Kota *next;

    Kota(string _nama) : nama(_nama), penduduk(nullptr), next(nullptr) {}
};

extern Kota *head;

void tambahKota(string namaKota);
void tambahPenduduk(string namaKota, string namaPenduduk, int usiaPenduduk);
void tambahPendudukTengah(string namaKota, string namaPenduduk, int usiaPenduduk, string namaPendudukSebelum);
void tambahPendudukAkhir(string namaKota, string namaPenduduk, int usiaPenduduk);
void hapusPenduduk(string namaKota, string namaPenduduk, int usiaPenduduk);
void tampilkanDaftarKota();
void tampilkanDaftarAnggota(string namaKota);
void cariDataKota(string namaKota);

#endif
