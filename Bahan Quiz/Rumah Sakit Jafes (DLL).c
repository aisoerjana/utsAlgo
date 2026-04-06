#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char nama[100];
    char keluhan[100];
    int tanggal;
} pasien;

typedef struct node
{
    pasien data;
    struct node *prev;
    struct node *next;
} Node;

Node *top = NULL;

void push()
{
    Node *baru = (Node *)malloc(sizeof(Node));
    if (baru == NULL)
    {
        printf("Memori tidak cukup\n");
        return;
    }

    printf("Masukkan nama pasien : ");
    scanf(" %[^\n]", baru->data.nama);
    printf("Masukkan keluhan pasien : ");
    scanf(" %[^\n]", baru->data.keluhan);
    printf("Masukkan tanggal kunjungan : ");
    scanf("%d", &baru->data.tanggal);

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

    printf("Pasien %s berhasil didaftarkan\n", top->data.nama);
}

void pop()
{
    if (top == NULL)
        printf("Tidak ada pasien dalam antrian\n");
    else
    {
        printf("Pasien %s dipanggil untuk pemeriksaan, segera masuk\n", top->data.nama);
        Node *hapus = top;
        top = top->prev;
        if (top != NULL)
            top->next = NULL;
        free(hapus);
    }
}

void peek()
{
    if (top == NULL)
        printf("Tidak ada pasien dalam antrian\n");
    else
        printf("Pasien paling atas dalam antrian: %s - %s (Tanggal: %d)\n",
            top->data.nama, top->data.keluhan, top->data.tanggal);
}

void simpanData()
{
    FILE *file = fopen("Data Pasien.txt", "w");
    if (file == NULL)
    {
        printf("Gagal membuka file\n");
        return;
    }

    Node *curr = top;
    while (curr != NULL)
    {
        fprintf(file, "%s#%s#%d\n", curr->data.nama, curr->data.keluhan, curr->data.tanggal);
        curr = curr->prev;
    }
    fclose(file);
    printf("Semua data pasien berhasil disimpan\n");
}

void muatData()
{
    FILE *file = fopen("Data Pasien.txt", "r");
    if (file == NULL)
    {
        printf("File tidak ditemukan\n");
        return;
    }

    // kosongkan stack dulu
    while (top != NULL)
    {
        Node *hapus = top;
        top = top->prev;
        free(hapus);
    }

    pasien temp;
    int count = 0;

    // baca semua ke array sementara dulu (karena file urutan atas ke bawah)
    pasien buffer[100];
    while (fscanf(file, "%[^#]#%[^#]#%d\n", temp.nama, temp.keluhan, &temp.tanggal) == 3)
    {
        buffer[count++] = temp;
    }
    fclose(file);

    // push dari belakang supaya urutan stack tetap benar
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

    printf("%d data berhasil dimuat\n", count);
}

void tampilkan()
{
    if (top == NULL)
        printf("Tidak ada pasien dalam antrian\n");
    else
    {
        printf("Daftar pasien dalam antrian:\n");
        printf("| Nama                           | Keluhan              | Tanggal |\n");
        Node *curr = top;
        while (curr != NULL)
        {
            printf("| %-30s | %-20s | %-7d |\n",
                curr->data.nama, curr->data.keluhan, curr->data.tanggal);
            curr = curr->prev;
        }
    }
}

int main()
{
    int pilihan;

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
            push();
            break;

            case 2:
            pop();
            break;

            case 3:
            peek();
            break;

            case 4:
            tampilkan();
            break;

            case 5:
            simpanData();
            break;

            case 6:
            muatData();
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
