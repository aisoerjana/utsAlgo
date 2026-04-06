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