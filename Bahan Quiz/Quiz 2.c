#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct
{
    char nama[100];
    char jenis[50];
    int jumlah;
    char tanggal[20];
} bank;

typedef struct node
{
    bank data;
    struct node *prev;
    struct node *next;
} Node;

Node *top = NULL;

void tambahTransaksi()
{
    Node *baru = (Node *)malloc(sizeof(Node));
    if (baru == NULL)
    {
        printf("Transaksi sudah penuh\n");
        return;
    }

    printf("Nama: ");
    scanf(" %[^\n]", baru->data.nama);
    printf("Jenis transaksi: ");
    scanf(" %[^\n]", baru->data.jenis);
    printf("Jumlah: ");
    scanf("%d", &baru->data.jumlah);
    printf("Tanggal (dd-mm-yyyy): ");
    scanf(" %[^\n]", baru->data.tanggal);

    baru->next = NULL;
    baru->prev = NULL;

    if (top == NULL)
    {
        top = baru;
    }
    else
    {
        baru->prev = top ;
        top->next = baru;
        top = baru;
    }
    printf("Transaksi %s berhasil ditambahkan\n", top->data.nama);
}

void muatData()
{
    FILE *file = fopen("atm_log.txt", "r");
    if (file == NULL)
    {
        printf("File tidak ditemukan\n");
        return;
    }

    while (top != NULL)
    {
        Node *hapus = top;
        top = top->prev;
        free(hapus);
    }

    bank temp;
    int count = 0;

    bank buffer[100];
    while (fscanf(file, "%[^#]#%[^#]#%d#%[^\n]\n", temp.nama, temp.jenis, &temp.jumlah, temp.tanggal) == 4)
    {
        buffer[count++] = temp;
    }
    fclose(file);

    for (int i = count - 1; i >= 0; i--)
    {
        Node *baru = (Node *)malloc(sizeof(Node));
        baru->data = buffer[i];
        baru->next = NULL;
        baru->prev = NULL;

        if (top == NULL)
        {
            top = baru;
        }
        else
        {
            baru->prev = top;
            top->next = baru;
            top = baru;
        }
    }
}

void tampilkanTransaksi()
{
    if (top == NULL)
        printf("Tidak ada riwayat transaksi\n");
    else
    {
        printf("========================================================================================\n");
        printf("|                                 RIWAYAT TRANSAKSI ATM                                |\n");
        printf("========================================================================================\n");
        printf("| Nama                           | Jenis Transaksi      | Jumlah     | Tanggal         |\n");
        Node *curr = top;
        while (curr != NULL && curr->prev != NULL)
        {
            curr = curr->prev;
        }
        while (curr != NULL)
        {
            printf("| %-30s | %-20s | %-10d | %-15s |\n",
                curr->data.nama, curr->data.jenis, curr->data.jumlah, curr->data.tanggal);
            curr = curr->next;
        }
    }
}

void batalkanTransaksi()
{
    if (top == NULL)
        printf("Tidak ada riwayat transaksi\n");
    else
    {
        printf("Transaksi %s dibatalkan\n", top->data.nama);
        Node *hapus = top;
        top = top->prev;
        if (top != NULL)
            top->next = NULL;
        free(hapus);
    }
}

void keluar()
{
    FILE *file = fopen("atm_log.txt", "w");
    if (file == NULL)
    {
        printf("Gagal membuka file\n");
        return;
    }

    Node *curr = top;
    while (curr != NULL)
    {
        fprintf(file, "%s#%s#%d#%s\n", curr->data.nama, curr->data.jenis, curr->data.jumlah, curr->data.tanggal);
        curr = curr->prev;
    }
    fclose(file);
}

int main()
{
    int pilihan;
    muatData();

    do
    {
         printf("\n==================================================\n");
        printf("                ATM TRANSACTION LOG\n");
        printf("==================================================\n");
        printf("1. Tambah transaksi baru\n");
        printf("2. Tampilkan seluruh riwayat transaksi\n");
        printf("3. Batalkan transaksi terakhir\n");
        printf("4. Exit\n");
        printf("Pilih menu: ");
        scanf("%d", &pilihan);

        switch (pilihan)
        {
            case 1:
                tambahTransaksi();
                break;

            case 2:
                tampilkanTransaksi();
                break;

            case 3:
                batalkanTransaksi();
                break;

            case 4:
                keluar();
                break;

            default:
                printf("Pilihan anda tidak ada, Silakan coba lagi\n");
        }
    } while (pilihan != 4);
    
    return 0; 
}