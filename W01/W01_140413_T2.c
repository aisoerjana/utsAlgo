#include <stdio.h>

void perkalian(int (*matrix1)[3], int (*matrix2)[3], int (*hasil)[3])
{
    for (int row = 0; row<3; row++)
    {
        for(int col = 0; col<3; col++)
        {
            hasil[row][col] = 0;;
            for (int k=0; k<3; k++)
            {
                hasil[row][col] = hasil[row][col] + matrix1[row][k] * matrix2 [k][col];
            }
        }
    }

    for (int row = 0; row<3; row++)
    {
        for (int col = 0; col<3; col++)
        {
            printf("%d ", hasil[row][col]);
        }
        printf("\n");
    }
    printf("\n");
}

void penjumlahan(int (*matrix1)[3], int (*matrix2)[3], int (*hasil)[3])
{
    for (int row = 0; row<3; row++)
    {
        for(int col = 0; col<3; col++)
        {
            hasil[row][col] = matrix1[row][col] + matrix2[row][col];
        }
    }

    for (int row = 0; row<3; row++)
    {
        for (int col = 0; col<3; col++)
        {
            printf("%d ", hasil[row][col]);
        }
        printf("\n");
    }
    printf("\n");
}

void transpose(int (*matrix1)[3], int (*matrix2)[3], int (*hasil)[3], int (*hasil2)[3])
{
    for (int row = 0; row<3; row++)
    {
        for (int col = 0; col<3; col++)
        {
            hasil[col][row] = matrix1[row][col];
        }
    }

    for (int row = 0; row<3; row++)
    {
        for (int col = 0; col<3; col++)
        {
            hasil2[col][row] = matrix2[row][col];
        }
    }

    printf("Matrix Pertama\n");
    for (int row = 0; row<3; row++)
    {
        for (int col = 0; col<3; col++)
        {
            printf("%d ", hasil[row][col]);
        }
        printf("\n");
    }

    printf("Matrix Kedua\n");
    for (int row = 0; row<3; row++)
    {
        for (int col = 0; col<3; col++)
        {
            printf("%d ", hasil2[row][col]);
        }
        printf("\n");
    }
    printf("\n");
}

int main()
{
    int pilihan, matrix1[3][3], matrix2[3][3], hasil[3][3], hasil2[3][3], row, col;
    
    printf("\nMasukkan Matrix Pertama (3 x 3)\n");
    for (row=0; row<3; row++)
    {
        for (col=0; col<3; col++)
        {
        scanf("%d", &matrix1[row][col]);
        }
    }
    
    printf("Masukkan Matrix Kedua (3 x 3)");
    for (row=0; row<3; row++)
    {
        for (col=0; col<3; col++)
        {
        scanf("%d", &matrix2[row][col]);
        }
    }

    do
    {
        printf("\n1. Perkalian Dua Buah Matrix\n");
        printf("2. Penjumlahan Dua Buah Matrix\n");
        printf("3. Transpose Dua Buah Matrix\n");
        printf("4. Keluar");
        printf("Pilihan: ");
        scanf("%d", &pilihan);

        switch (pilihan)
        {
        case 1:
            perkalian(matrix1, matrix2, hasil);
            break;
        case 2:
            penjumlahan(matrix1, matrix2, hasil);
            break;
        case 3:
            transpose(matrix1, matrix2, hasil, hasil2);
            break;
        default:
        printf("Pilihan anda tidak ada di program kami.");
        }
    }
    while (pilihan != 4);
}