/*### 🟡 Soal 3 — Menengah
**Struct dengan Function**

Dari soal 2, tambahkan function `cariIPKTertinggi()` yang menerima array struct dan mengembalikan mahasiswa dengan IPK tertinggi.
```
Output :
Mahasiswa dengan IPK tertinggi :
Nama    : Ani
Jurusan : DKV
IPK     : 3.90
```

> 💡 Hint: parameter functionnya `struct Mahasiswa *mhs, int size`
*/

/*### 🟡 Soal 2 — Menengah
**Array of Struct**

Buatlah struct `Mahasiswa` dengan member `nama`, `jurusan`, dan `ipk`. Input data **3 mahasiswa** lalu tampilkan semuanya.
```
Output :
No | Nama      | Jurusan     | IPK
1  | Budi      | Informatika | 3.85
2  | Ani       | DKV         | 3.90
3  | Riko      | Teknik      | 3.75
```

> 💡 Hint: gunakan `struct Mahasiswa mhs[3]` lalu loop untuk input dan output
*/

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