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