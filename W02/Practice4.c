/*### 🔴 Soal 4 — Susah
**Nested Struct + Menu**

Buatlah program dengan menu seperti di modul:
- Menu 1: Tambah mahasiswa (maks 5)
- Menu 2: Tampilkan semua mahasiswa
- Menu 3: Exit

Struct `Mahasiswa` harus punya nested struct `Alamat` yang berisi `kota` dan `provinsi`.
```
=== DATA MAHASISWA ===
Nama       : Budi
Jurusan    : Informatika
IPK        : 3.85
Kota       : Tangerang
Provinsi   : Banten*/

#include <stdio.h>

typedef struct
{
    char nama[100];
    char jurusan[100];
    float ipk;
    char kota[100];
    char provinsi[100];
}mahasiswa;

void tambah(mahasiswa *mhs)
{
    int i;
    
    printf("Nama : ");
    scanf(" %[^\n]", mhs[i].nama);
    printf("Jurusan : ");
    scanf(" %[^\n]", mhs[i].jurusan);
    printf("IPK : ");
    scanf("%f", &mhs[i].ipk);
    printf("Kota : ");
    scanf(" %[^\n]", mhs[i].kota);
    printf("Provinsi : ");
    scanf(" %[^\n]", mhs[i].provinsi);
    
}

void tampilkan(mahasiswa *mhs)
{
    int i;
    
    printf("Nama : %s\n", mhs[i].nama);
    printf("Jurusan : %s\n", mhs[i].jurusan);
    printf("IPK : %.2f\n", mhs[i].ipk);
    printf("Kota : %s\n", mhs[i].kota);
    printf("Provinsi : %s\n", mhs[i].provinsi);
    
}

int main()
{
    int i, pilihan;
    mahasiswa mhs[5];

    do
    {
        printf("\nMenu 1: Tambah mahasiswa (maks 5)\n");
        printf("Menu 2: Tampilkan semua mahasiswa\n");
        printf("Menu 3: Exit\n");
        printf("Pilihan : ");
        scanf("%d", &pilihan);

        switch (pilihan)
        {
        case 1 :
        tambah(mhs);
        break;
        
        case 2 :
        tampilkan(mhs);
        break;

        default :
        printf("Salah pilih!");
        break;
        }
    }
    while(pilihan != 3);
    return 0;
}