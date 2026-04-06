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

    return 0;
}