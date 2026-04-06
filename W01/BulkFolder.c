#include <stdio.h>

void cetak (int *arr, int size)
{
    int i;
    for (i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
}

int main()
{
    int arr[5];
    int i;

    printf("\nInput 5 angka : ");
    for (i = 0; i < 5; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Output : ");
    cetak(arr, 5);
    return 0;
}


#include <stdio.h>

void cariMaks (int *angka, int size)
{
    int i;
    int maks = angka[i];
    for (i = 0; i < size; i++)
    {
        if (angka[i] > maks)
        {
            maks = angka[i];
        }
    }
    printf("%d", maks);
}

int main()
{
    int angka[5];
    int i;

    printf("\nMasukkan 5 angka : ");
    for (i = 0; i < 5; i++)
    {
        scanf("%d", &angka[i]);
    }

    printf("Angka terbesar : ");
    cariMaks(angka, 5);
    return 0;
}


#include <stdio.h>

void hitung (int *angka, int size)
{
    int total = 0;
    float rata;
    int i;

    for (i = 0; i < size; i++)
    {
        total += angka[i];
    }
    rata = (float)total / size;
    printf("%.2f", rata);
}

int main()
{
    int angka[5];
    int i;

    printf("Masukkan 5 angka : ");
    for (i = 0; i < 5; i++)
    {
        scanf("%d", &angka[i]);
    }

    printf("Rata-rata : ");
    hitung(angka, 5);
}


#include <stdio.h>

void tukar(int *angka, int size)
{
    int *depan, *belakang, temp;
    int i;

    depan = angka;
    belakang = angka + size - 1;


    while (depan < belakang)
    {
        temp = *depan;
        *depan = *belakang;
        *belakang = temp;

        *depan++;
        *belakang--;
    }
    
    for (i = 0; i < size; i++)
    {
        printf("%d", angka[i]);
    }
}

int main()
{
    int angka[5];
    int i;

    printf("Masukkan 5 angka : ");
    for (i = 0; i < 5; i++)
    {
        scanf("%d", &angka[i]);
    }
    printf("Angka setelah ditukar : ");
    tukar(angka, 5);
}


    #include <stdio.h>

    void pemisah(int *angka, int size)
    {
        int i;
        int ganjil[10], genap[10];
        int jmlGanjil = 0, jmlGenap = 0;

        for (i=0; i<size; i++)
        {
            if (angka[i] % 2 == 0)
            {
                genap[jmlGenap] = angka[i];
                jmlGenap++;
            }
        }

        for (i=0; i<size; i++)
        {
            if (angka[i] % 2 == 1)
            {
                ganjil[jmlGanjil] = angka[i];
                jmlGanjil++;
            }
        }

        printf("\nGenap  : ");
        for (i = 0; i < jmlGenap; i++)  // ✅
        printf("%d ", genap[i]);

        printf("\nGanjil : ");
        for (i = 0; i < jmlGanjil; i++)  // ✅
        printf("%d ", ganjil[i]);
    }

    int main()
    {
        int i, angka[10];

        printf("Masukkan 10 angka : ");
        for (i = 0; i < 10; i++)
        {
            scanf("%d", &angka[i]);
        }
        printf("Output : ");
        pemisah(angka, 10);
        return 0;
    }