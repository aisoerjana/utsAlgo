#include <stdio.h>

typedef struct 
{
    char judul[100];
    char pengarang[100];
    int  harga;
}buku123;

int main()
{
    buku123 buku;

    printf("Judul : ");
    scanf("%s", buku.judul);
    printf("Pengarang : ");
    scanf("%s", buku.pengarang);
    printf("Harga : ");
    scanf("%d", &buku.harga);

    printf("\nJudul : %s\n", buku.judul);
    printf("Pengarang : %s\n", buku.pengarang);
    printf("Harga : %d\n", buku.harga);

    return 0;
}


#include <stdio.h>

typedef struct
{
    char nama[100];
    char jurusan[100];
    float ipk;
}mahasiswa;

void high(mahasiswa *mhs, int size)
{
    int i;
    int highest = 0;
    for(i=0; i<size; i++)
    {
        if(mhs[i].ipk > mhs[highest].ipk)
        highest = i;
    }
    printf("Nama    : %s\n", mhs[highest].nama);
    printf("Jurusan : %s\n", mhs[highest].jurusan);
    printf("IPK     : %.2f\n", mhs[highest].ipk);
}

int main()
{
    mahasiswa mhs[3];
    int i;
    
    printf("\nInput 3 data mahasiswa : \n");

    for(i=0; i<3; i++)
    {
        printf("Nama : ");
        scanf(" %[^\n]", mhs[i].nama);
        printf("Jurusan : ");
        scanf(" %[^\n]", mhs[i].jurusan);
        printf("IPK : ");
        scanf("%f", &mhs[i].ipk);
    }

    printf("\nData Mahasiswa\n");
    printf("No | Nama | Jurusan | IPK\n");

    for(i=0; i<3; i++)
    {
        printf("%d | %s | %s | %.2f\n", i+1, mhs[i].nama, mhs[i].jurusan, mhs[i].ipk);
    }
    high(mhs, 3);

    return 0;
}


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