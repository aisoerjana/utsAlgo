#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ============================================================
// STRUCT
// ============================================================
typedef struct Mahasiswa {
    char nim[20];
    char nama[50];
    float ipk;
    struct Mahasiswa *prev, *next;
} Mahasiswa;

// ============================================================
// STACK (menggunakan array)
// ============================================================
#define MAX 100
Mahasiswa *stackArr[MAX];
int top = -1;

void push(Mahasiswa *data) {
    if (top == MAX - 1) {
        printf("Stack penuh!\n");
        return;
    }
    stackArr[++top] = data;
    printf("Push: %s berhasil masuk stack.\n", data->nama);
}

Mahasiswa* pop() {
    if (top == -1) {
        printf("Stack kosong!\n");
        return NULL;
    }
    return stackArr[top--];
}

void peek() {
    if (top == -1) {
        printf("Stack kosong!\n");
        return;
    }
    printf("Top stack: %s (NIM: %s | IPK: %.2f)\n",
           stackArr[top]->nama, stackArr[top]->nim, stackArr[top]->ipk);
}

void displayStack() {
    if (top == -1) {
        printf("Stack kosong!\n");
        return;
    }
    printf("\n--- ISI STACK (top -> bottom) ---\n");
    for (int i = top; i >= 0; i--) {
        printf("[%d] NIM: %-12s | Nama: %-20s | IPK: %.2f\n",
               i, stackArr[i]->nim, stackArr[i]->nama, stackArr[i]->ipk);
    }
}

// ============================================================
// DOUBLE LINKED LIST
// ============================================================
Mahasiswa *head = NULL;
Mahasiswa *tail = NULL;

// INSERT DI BELAKANG
void insertBelakang(char nim[], char nama[], float ipk) {
    Mahasiswa *data = (Mahasiswa*)malloc(sizeof(Mahasiswa));
    strcpy(data->nim, nim);
    strcpy(data->nama, nama);
    data->ipk = ipk;
    data->prev = NULL;
    data->next = NULL;

    if (head == NULL) {
        head = data;
        tail = data;
    } else {
        tail->next = data;
        data->prev = tail;
        tail = data;
    }
}

// INSERT DI DEPAN
void insertDepan(char nim[], char nama[], float ipk) {
    Mahasiswa *data = (Mahasiswa*)malloc(sizeof(Mahasiswa));
    strcpy(data->nim, nim);
    strcpy(data->nama, nama);
    data->ipk = ipk;
    data->prev = NULL;
    data->next = NULL;

    if (head == NULL) {
        head = data;
        tail = data;
    } else {
        data->next = head;
        head->prev = data;
        head = data;
    }
}

// DELETE BY NIM
void deleteByNim(char nim[]) {
    if (head == NULL) {
        printf("List kosong!\n");
        return;
    }

    Mahasiswa *temp = head;
    while (temp != NULL) {
        if (strcmp(temp->nim, nim) == 0) {
            if (temp->prev != NULL) temp->prev->next = temp->next;
            else head = temp->next;
            if (temp->next != NULL) temp->next->prev = temp->prev;
            else tail = temp->prev;
            printf("Data %s berhasil dihapus.\n", temp->nama);
            free(temp);
            return;
        }
        temp = temp->next;
    }
    printf("NIM %s tidak ditemukan.\n", nim);
}

// DELETE TERAKHIR
void deleteTerakhir() {
    if (tail == NULL) {
        printf("List kosong!\n");
        return;
    }
    printf("Data terakhir %s berhasil dihapus.\n", tail->nama);
    if (head == tail) {
        free(tail);
        head = NULL;
        tail = NULL;
    } else {
        Mahasiswa *temp = tail;
        tail = tail->prev;
        tail->next = NULL;
        free(temp);
    }
}

// PRINT MAJU
void printMaju() {
    if (head == NULL) {
        printf("List kosong!\n");
        return;
    }
    printf("\n--- LIST MAHASISWA (maju) ---\n");
    printf("%-15s %-25s %-5s\n", "NIM", "Nama", "IPK");
    printf("%-15s %-25s %-5s\n", "---", "----", "---");
    Mahasiswa *temp = head;
    while (temp != NULL) {
        printf("%-15s %-25s %.2f\n", temp->nim, temp->nama, temp->ipk);
        temp = temp->next;
    }
}

// PRINT MUNDUR
void printMundur() {
    if (tail == NULL) {
        printf("List kosong!\n");
        return;
    }
    printf("\n--- LIST MAHASISWA (mundur) ---\n");
    printf("%-15s %-25s %-5s\n", "NIM", "Nama", "IPK");
    printf("%-15s %-25s %-5s\n", "---", "----", "---");
    Mahasiswa *temp = tail;
    while (temp != NULL) {
        printf("%-15s %-25s %.2f\n", temp->nim, temp->nama, temp->ipk);
        temp = temp->prev;
    }
}

// CARI BY NIM (pointer)
Mahasiswa* cariByNim(char nim[]) {
    Mahasiswa *temp = head;
    while (temp != NULL) {
        if (strcmp(temp->nim, nim) == 0) return temp;
        temp = temp->next;
    }
    return NULL;
}

// ============================================================
// FILE
// ============================================================
void simpanKeFile() {
    FILE *fp = fopen("mahasiswa.txt", "w");
    if (fp == NULL) {
        printf("Gagal membuka file!\n");
        return;
    }
    Mahasiswa *temp = head;
    while (temp != NULL) {
        fprintf(fp, "%s*%s*%.2f\n", temp->nim, temp->nama, temp->ipk);
        temp = temp->next;
    }
    fclose(fp);
    printf("Data berhasil disimpan ke mahasiswa.txt\n");
}

void bacaDariFile() {
    FILE *fp = fopen("mahasiswa.txt", "r");
    if (fp == NULL) {
        printf("File tidak ditemukan!\n");
        return;
    }
    char nim[20], nama[50];
    float ipk;
    while (fscanf(fp, "%[^*]*%[^*]*%f\n", nim, nama, &ipk) == 3) {
        insertBelakang(nim, nama, ipk);
    }
    fclose(fp);
    printf("Data berhasil dibaca dari file.\n");
}

// ============================================================
// POINTER - TUKAR NILAI IPK
// ============================================================
void tukarIPK(float *a, float *b) {
    float temp = *a;
    *a = *b;
    *b = temp;
}

// ============================================================
// FREE MEMORY
// ============================================================
void freeAll() {
    Mahasiswa *temp = head;
    while (temp != NULL) {
        Mahasiswa *next = temp->next;
        free(temp);
        temp = next;
    }
    head = NULL;
    tail = NULL;
}

// ============================================================
// MAIN MENU
// ============================================================
int main() {
    int pil, pilStack;
    char nim[20], nama[50];
    float ipk;

    do {
        printf("\n================================\n");
        printf("   PROGRAM ADS - MAHASISWA\n");
        printf("================================\n");
        printf("1.  Baca dari File\n");
        printf("2.  Simpan ke File\n");
        printf("3.  Insert Belakang\n");
        printf("4.  Insert Depan\n");
        printf("5.  Delete by NIM\n");
        printf("6.  Delete Terakhir\n");
        printf("7.  Print Maju\n");
        printf("8.  Print Mundur\n");
        printf("9.  Cari by NIM\n");
        printf("10. Stack Menu\n");
        printf("0.  Exit\n");
        printf("Pilihan: ");
        scanf("%d", &pil);

        switch (pil) {
            case 1:
                bacaDariFile();
                break;

            case 2:
                simpanKeFile();
                break;

            case 3:
                printf("NIM   : "); scanf(" %[^\n]", nim);
                printf("Nama  : "); scanf(" %[^\n]", nama);
                printf("IPK   : "); scanf("%f", &ipk);
                insertBelakang(nim, nama, ipk);
                printf("Data berhasil ditambahkan di belakang!\n");
                break;

            case 4:
                printf("NIM   : "); scanf(" %[^\n]", nim);
                printf("Nama  : "); scanf(" %[^\n]", nama);
                printf("IPK   : "); scanf("%f", &ipk);
                insertDepan(nim, nama, ipk);
                printf("Data berhasil ditambahkan di depan!\n");
                break;

            case 5:
                printf("Masukkan NIM yang dihapus: ");
                scanf(" %[^\n]", nim);
                deleteByNim(nim);
                break;

            case 6:
                deleteTerakhir();
                break;

            case 7:
                printMaju();
                break;

            case 8:
                printMundur();
                break;

            case 9:
                printf("Masukkan NIM: ");
                scanf(" %[^\n]", nim);
                Mahasiswa *hasil = cariByNim(nim);
                if (hasil != NULL)
                    printf("Ditemukan -> NIM: %s | Nama: %s | IPK: %.2f\n",
                           hasil->nim, hasil->nama, hasil->ipk);
                else
                    printf("NIM %s tidak ditemukan.\n", nim);
                break;

            case 10:
                printf("\n--- STACK MENU ---\n");
                printf("1. Push (dari linked list by NIM)\n");
                printf("2. Pop\n");
                printf("3. Peek\n");
                printf("4. Display Stack\n");
                printf("Pilihan: ");
                scanf("%d", &pilStack);

                if (pilStack == 1) {
                    printf("Masukkan NIM untuk push: ");
                    scanf(" %[^\n]", nim);
                    Mahasiswa *found = cariByNim(nim);
                    if (found != NULL) push(found);
                    else printf("NIM tidak ditemukan.\n");
                } else if (pilStack == 2) {
                    Mahasiswa *popped = pop();
                    if (popped != NULL)
                        printf("Pop: %s (NIM: %s)\n", popped->nama, popped->nim);
                } else if (pilStack == 3) {
                    peek();
                } else if (pilStack == 4) {
                    displayStack();
                }
                break;

            case 0:
                freeAll();
                printf("Program selesai.\n");
                break;

            default:
                printf("Pilihan tidak valid!\n");
        }
    } while (pil != 0);

    return 0;
}
