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
