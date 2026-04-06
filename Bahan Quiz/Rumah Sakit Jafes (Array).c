#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct tstack
{
    int data[10];
    int size;
    int top;
};

typedef struct
{
    char nama[100];
    char keluhan[100];
    int tanggal;
} pasien;

pasien psn[100];
int idxPasien = 0;

void push(struct tstack *stack)
{
     if (stack->top == stack->size - 1)
        printf("Antrian sudah penuh\n");
    else
    {
        stack->top++;
        printf("Masukkan nama pasien: ");
        scanf(" %[^\n]", psn[idxPasien].nama);
        printf("Masukkan keluhan pasien: ");
        scanf(" %[^\n]", psn[idxPasien].keluhan);
        printf("Masukkan tanggal kunjungan: ");
        scanf("%d", &psn[idxPasien].tanggal);
        stack->data[stack->top] = idxPasien;
        printf("Pasien %s berhasil didaftarkan\n", psn[idxPasien].nama);
        idxPasien++;
    }
}

void pop(struct tstack *stack)
{
    if (stack->top == -1)
        printf("Tidak ada pasien\n");
    else
    {
        int idxPasien = stack->data[stack->top]; 
        printf("Pasien %s dipanggil\n", psn[idxPasien].nama);
        stack->top--;
    }
}

void peek(struct tstack *stack)
{
    if (stack->top == -1)
        printf("Tidak ada pasien dalam antrian\n");
    else
    {
        int idxPasien = stack->data[stack->top];
        printf("Pasien paling atas dalam antrian: %s - %s (Tanggal: %d)\n", psn[idxPasien].nama, psn[idxPasien].keluhan, psn[idxPasien].tanggal);
    }
}

void simpanData(struct tstack *stack)
{
    FILE *file = fopen("Data Pasien.txt", "w");
    if (file == NULL) 
    { 
        printf("Gagal membuka file\n"); 
        return; 
    }
    
    for (int i = 0; i <= stack->top; i++) 
    {
        int idxPasien = stack->data[i];
        fprintf(file, "%s#%s#%d\n", psn[idxPasien].nama, psn[idxPasien].keluhan, psn[idxPasien].tanggal);
    }
    fclose(file);
    printf("Semua data pasien berhasil disimpan\n");
}

void muatData(struct tstack *stack)
{
    FILE *file = fopen("Data Pasien.txt", "r");
    if (file == NULL) 
    { 
        printf("File tidak ditemukan\n"); 
        return; 
    }

    stack->top = -1;
    idxPasien = 0;
    while (fscanf(file, "%[^#]#%[^#]#%d\n", 
        psn[idxPasien].nama, psn[idxPasien].keluhan, &psn[idxPasien].tanggal) == 3)
    {
        stack->top++;
        stack->data[stack->top] = idxPasien;
        idxPasien++;
    }
    fclose(file);
    printf("%d data berhasil dimuat\n", stack->top + 1);
}

void tampilkan(struct tstack *stack)
{
    if (stack->top == -1)
        printf("Tidak ada pasien dalam antrian\n");
    else
    {
        printf("Daftar pasien dalam antrian:\n");
        printf("| Nama                           | Keluhan              | Tanggal |\n");
        for (int i = stack->top; i >= 0; i--)
        {
            int idxPasien = stack->data[i]; 
            printf("| %-30s | %-20s | %-7d |\n", psn[idxPasien].nama, psn[idxPasien].keluhan, psn[idxPasien].tanggal);
        }
    }
}

int main()
{
    struct tstack stack;
    int pilihan;
    stack.size = 10;
    stack.top = -1;

    do
    {
        printf("\n==================================================\n");
        printf("    SISTEM ANTRIAN PASIEN KLINIK BAKPAO JAFES\n");
        printf("==================================================\n");
        printf("1. Daftarkan pasien baru\n");
        printf("2. Panggil pasien terakhir\n");
        printf("3. Lihat pasien paling atas\n");
        printf("4. Tampilkan semua pasien\n");
        printf("5. Simpan data ke file\n");
        printf("6. Muat data dari file\n");
        printf("7. Keluar\n");
        printf("==================================================\n");
        printf("Pilihan: ");
        scanf("%d", &pilihan);

        switch (pilihan)
        {
            case 1:
            push(&stack);
            break;
            
            case 2:
            pop(&stack);
            break;

            case 3:
            peek(&stack);
            break;

            case 4:
            tampilkan(&stack);
            break;

            case 5:
            simpanData(&stack);
            break;

            case 6:
            muatData(&stack);
            break;

            case 7:
            printf("Terima kasih telah datang ke klinik Bakpao Jafes, semoga lekas sembuh, God Bless you\n");
            break;

            default:
            printf("Pilihan anda tidak ada\n");

        }
    } while (pilihan != 7);
   return 0;
}