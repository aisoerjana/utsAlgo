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