/*
 * =====================================================
 *  SISTEM MANAJEMEN NILAI MAHASISWA
 *  Mencakup: Array, Pointer, Struct, Linked List,
 *            Double Linked List, Stack, Queue,
 *            File Processing
 * =====================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100
#define MAX_MK 5

/* =====================================================
 *  BAGIAN A — STRUCT & ARRAY
 * ===================================================== */

typedef struct {
    char nim[12];
    char nama[50];
    float nilai[MAX_MK];
    float ipk;
} Mahasiswa;

Mahasiswa db[MAX];
int totalMhs = 0;

/* Hitung IPK via pointer */
void hitungIPK(Mahasiswa *m) {
    float total = 0;
    for (int i = 0; i < MAX_MK; i++)
        total += m->nilai[i];
    m->ipk = total / MAX_MK;
}

/* Input data mahasiswa via pointer */
void inputMahasiswa(Mahasiswa *m) {
    printf("  NIM       : "); scanf("%s", m->nim);
    printf("  Nama      : "); getchar();
    fgets(m->nama, 50, stdin);
    m->nama[strcspn(m->nama, "\n")] = 0;
    printf("  Masukkan %d nilai mata kuliah:\n", MAX_MK);
    for (int i = 0; i < MAX_MK; i++) {
        printf("    MK-%d: ", i + 1);
        scanf("%f", &m->nilai[i]);
    }
    hitungIPK(m);
}

/* Tampilkan semua dengan pointer arithmetic */
void tampilSemuaMhs() {
    if (totalMhs == 0) { printf("  [!] Data kosong.\n"); return; }
    printf("\n  %-12s %-25s %-8s %s\n", "NIM", "NAMA", "IPK", "NILAI MK");
    printf("  -----------------------------------------------------------\n");
    Mahasiswa *ptr = db;
    for (int i = 0; i < totalMhs; i++, ptr++) {
        printf("  %-12s %-25s %-8.2f", ptr->nim, ptr->nama, ptr->ipk);
        for (int j = 0; j < MAX_MK; j++)
            printf(" %.0f", ptr->nilai[j]);
        printf("\n");
    }
}

/* Cari mahasiswa by NIM, return index atau -1 */
int cariIndexNIM(char *nim) {
    for (int i = 0; i < totalMhs; i++)
        if (strcmp(db[i].nim, nim) == 0) return i;
    return -1;
}

/* =====================================================
 *  BAGIAN B — SINGLE LINKED LIST (Mahasiswa Aktif)
 * ===================================================== */

typedef struct NodeLL {
    char nim[12];
    struct NodeLL *next;
} NodeLL;

NodeLL *headLL = NULL;

NodeLL *buatNodeLL(char *nim) {
    NodeLL *baru = (NodeLL *)malloc(sizeof(NodeLL));
    strcpy(baru->nim, nim);
    baru->next = NULL;
    return baru;
}

void insertHead(char *nim) {
    NodeLL *baru = buatNodeLL(nim);
    baru->next = headLL;
    headLL = baru;
}

void insertTail(char *nim) {
    NodeLL *baru = buatNodeLL(nim);
    if (headLL == NULL) { headLL = baru; return; }
    NodeLL *temp = headLL;
    while (temp->next != NULL) temp = temp->next;
    temp->next = baru;
}

void deleteByNIM(char *nim) {
    NodeLL *curr = headLL, *prev = NULL;
    while (curr != NULL && strcmp(curr->nim, nim) != 0) {
        prev = curr; curr = curr->next;
    }
    if (curr == NULL) { printf("  [!] NIM tidak ditemukan di linked list.\n"); return; }
    if (prev == NULL) headLL = curr->next;
    else prev->next = curr->next;
    free(curr);
    printf("  [OK] NIM %s dihapus dari daftar aktif.\n", nim);
}

NodeLL *searchNIM(char *nim) {
    NodeLL *temp = headLL;
    while (temp != NULL) {
        if (strcmp(temp->nim, nim) == 0) return temp;
        temp = temp->next;
    }
    return NULL;
}

void printLinkedList() {
    if (headLL == NULL) { printf("  [!] Daftar aktif kosong.\n"); return; }
    printf("  Mahasiswa Aktif: ");
    NodeLL *temp = headLL;
    while (temp != NULL) {
        printf("[%s]", temp->nim);
        if (temp->next) printf(" -> ");
        temp = temp->next;
    }
    printf(" -> NULL\n");
}

/* =====================================================
 *  BAGIAN C — DOUBLE LINKED LIST (Riwayat Perubahan)
 * ===================================================== */

typedef struct NodeDLL {
    char nim[12];
    int mk;           /* index mata kuliah 0-4 */
    float nilaiLama;
    float nilaiBaru;
    struct NodeDLL *prev;
    struct NodeDLL *next;
} NodeDLL;

NodeDLL *headDLL = NULL;
NodeDLL *tailDLL = NULL;

void insertDLL(char *nim, int mk, float lama, float baru) {
    NodeDLL *node = (NodeDLL *)malloc(sizeof(NodeDLL));
    strcpy(node->nim, nim);
    node->mk = mk;
    node->nilaiLama = lama;
    node->nilaiBaru = baru;
    node->prev = tailDLL;
    node->next = NULL;
    if (tailDLL != NULL) tailDLL->next = node;
    else headDLL = node;
    tailDLL = node;
}

void printForward() {
    if (headDLL == NULL) { printf("  [!] Riwayat kosong.\n"); return; }
    printf("  Riwayat (terlama -> terbaru):\n");
    NodeDLL *temp = headDLL;
    int i = 1;
    while (temp != NULL) {
        printf("  %d. NIM %-10s | MK-%d | %.0f -> %.0f\n",
               i++, temp->nim, temp->mk + 1, temp->nilaiLama, temp->nilaiBaru);
        temp = temp->next;
    }
}

void printBackward() {
    if (tailDLL == NULL) { printf("  [!] Riwayat kosong.\n"); return; }
    printf("  Riwayat (terbaru -> terlama):\n");
    NodeDLL *temp = tailDLL;
    int i = 1;
    while (temp != NULL) {
        printf("  %d. NIM %-10s | MK-%d | %.0f -> %.0f\n",
               i++, temp->nim, temp->mk + 1, temp->nilaiLama, temp->nilaiBaru);
        temp = temp->prev;
    }
}

void deleteNodeDLL(NodeDLL *target) {
    if (target == NULL) return;
    if (target->prev != NULL) target->prev->next = target->next;
    else headDLL = target->next;
    if (target->next != NULL) target->next->prev = target->prev;
    else tailDLL = target->prev;
    free(target);
}

/* =====================================================
 *  BAGIAN D — STACK (Undo Perubahan Nilai)
 * ===================================================== */

typedef struct NodeStack {
    char nim[12];
    int mk;
    float nilaiLama;
    float nilaiBaru;
    struct NodeStack *next;
} NodeStack;

NodeStack *topStack = NULL;

void push(char *nim, int mk, float lama, float baru) {
    NodeStack *node = (NodeStack *)malloc(sizeof(NodeStack));
    strcpy(node->nim, nim);
    node->mk = mk;
    node->nilaiLama = lama;
    node->nilaiBaru = baru;
    node->next = topStack;
    topStack = node;
    printf("  [Stack] Push: NIM %s MK-%d (%.0f -> %.0f)\n", nim, mk+1, lama, baru);
}

int pop(char *nimOut, int *mkOut, float *lamaOut, float *baruOut) {
    if (topStack == NULL) return 0;
    NodeStack *temp = topStack;
    strcpy(nimOut, temp->nim);
    *mkOut = temp->mk;
    *lamaOut = temp->nilaiLama;
    *baruOut = temp->nilaiBaru;
    topStack = temp->next;
    free(temp);
    return 1;
}

void peekAll() {
    if (topStack == NULL) { printf("  [!] Stack kosong.\n"); return; }
    printf("  Isi Stack (top -> bottom):\n");
    NodeStack *temp = topStack;
    int i = 1;
    while (temp != NULL) {
        printf("  %d. NIM %-10s | MK-%d | %.0f -> %.0f\n",
               i++, temp->nim, temp->mk + 1, temp->nilaiLama, temp->nilaiBaru);
        temp = temp->next;
    }
}

void undoNilai() {
    char nim[12]; int mk; float lama, baru;
    if (!pop(nim, &mk, &lama, &baru)) {
        printf("  [!] Tidak ada operasi yang bisa di-undo.\n");
        return;
    }
    int idx = cariIndexNIM(nim);
    if (idx == -1) { printf("  [!] Mahasiswa tidak ditemukan.\n"); return; }
    db[idx].nilai[mk] = lama;
    hitungIPK(&db[idx]);
    printf("  [Undo] NIM %s MK-%d dikembalikan ke %.0f\n", nim, mk+1, lama);
}

/* =====================================================
 *  BAGIAN E — QUEUE (Antrian Konsultasi)
 * ===================================================== */

#define QMAX 50

typedef struct {
    char nim[12];
    float ipk;
    int prioritas; /* 1 = prioritas tinggi (IPK < 2.0) */
} ItemQueue;

ItemQueue antrian[QMAX];
int qFront = 0, qRear = 0;

int queueEmpty() { return qFront == qRear; }
int queueFull()  { return (qRear + 1) % QMAX == qFront; }

void enqueue(char *nim) {
    if (queueFull()) { printf("  [!] Antrian penuh.\n"); return; }
    int idx = cariIndexNIM(nim);
    if (idx == -1) { printf("  [!] NIM tidak ditemukan di database.\n"); return; }

    ItemQueue item;
    strcpy(item.nim, nim);
    item.ipk = db[idx].ipk;
    item.prioritas = (db[idx].ipk < 2.0f) ? 1 : 0;

    /* Priority queue: IPK < 2.0 masuk di depan */
    if (item.prioritas && !queueEmpty()) {
        /* Geser semua ke belakang satu posisi dari front */
        int pos = qRear;
        antrian[qRear] = antrian[(qFront + (qRear - qFront + QMAX) % QMAX - 1 + QMAX) % QMAX];
        /* Insert setelah semua prioritas yang sudah ada */
        int insertPos = qFront;
        while (insertPos != qRear && antrian[insertPos].prioritas == 1)
            insertPos = (insertPos + 1) % QMAX;
        /* Geser dari insertPos ke qRear satu langkah ke kanan */
        int j = qRear;
        while (j != insertPos) {
            int prev = (j - 1 + QMAX) % QMAX;
            antrian[j] = antrian[prev];
            j = prev;
        }
        antrian[insertPos] = item;
        qRear = (qRear + 1) % QMAX;
    } else {
        antrian[qRear] = item;
        qRear = (qRear + 1) % QMAX;
    }
    printf("  [Queue] %s (IPK %.2f)%s masuk antrian.\n",
           nim, item.ipk, item.prioritas ? " [PRIORITAS]" : "");
}

void dequeue() {
    if (queueEmpty()) { printf("  [!] Antrian kosong.\n"); return; }
    ItemQueue item = antrian[qFront];
    qFront = (qFront + 1) % QMAX;
    printf("  [Layani] NIM %s (IPK %.2f) sedang dilayani.\n", item.nim, item.ipk);
}

void displayQueue() {
    if (queueEmpty()) { printf("  [!] Antrian kosong.\n"); return; }
    printf("  Antrian Konsultasi:\n");
    int i = qFront, pos = 1;
    while (i != qRear) {
        printf("  %d. NIM %-10s IPK %.2f%s\n",
               pos++, antrian[i].nim, antrian[i].ipk,
               antrian[i].prioritas ? " [PRIORITAS]" : "");
        i = (i + 1) % QMAX;
    }
}

/* =====================================================
 *  BAGIAN F — FILE PROCESSING
 * ===================================================== */

void saveToFile(char *filename) {
    FILE *f = fopen(filename, "w");
    if (!f) { printf("  [!] Gagal membuka file.\n"); return; }
    for (int i = 0; i < totalMhs; i++) {
        fprintf(f, "%s,%s", db[i].nim, db[i].nama);
        for (int j = 0; j < MAX_MK; j++)
            fprintf(f, ",%.0f", db[i].nilai[j]);
        fprintf(f, ",%.2f\n", db[i].ipk);
    }
    fclose(f);
    printf("  [OK] Data disimpan ke '%s' (%d mahasiswa).\n", filename, totalMhs);
}

void loadFromFile(char *filename) {
    FILE *f = fopen(filename, "r");
    if (!f) { printf("  [!] File '%s' tidak ditemukan.\n", filename); return; }
    totalMhs = 0;
    headLL = NULL; /* reset linked list */
    char line[200];
    while (fgets(line, sizeof(line), f) && totalMhs < MAX) {
        Mahasiswa *m = &db[totalMhs];
        char *tok = strtok(line, ",");
        if (!tok) continue;
        strcpy(m->nim, tok);
        tok = strtok(NULL, ","); strcpy(m->nama, tok);
        for (int j = 0; j < MAX_MK; j++) {
            tok = strtok(NULL, ",");
            m->nilai[j] = atof(tok);
        }
        tok = strtok(NULL, ",\n");
        m->ipk = atof(tok);
        insertTail(m->nim);
        totalMhs++;
    }
    fclose(f);
    printf("  [OK] Loaded %d mahasiswa dari '%s'.\n", totalMhs, filename);
}

void saveLog(char *nim, int mk, float lama, float baru) {
    FILE *f = fopen("log.txt", "a");
    if (!f) return;
    fprintf(f, "UBAH | NIM: %s | MK-%d | %.0f -> %.0f\n", nim, mk+1, lama, baru);
    fclose(f);
}

/* =====================================================
 *  BAGIAN G — MENU UTAMA
 * ===================================================== */

void ubahNilai() {
    char nim[12];
    int mk;
    float nilaiBaru;
    printf("  NIM mahasiswa : "); scanf("%s", nim);
    int idx = cariIndexNIM(nim);
    if (idx == -1) { printf("  [!] NIM tidak ditemukan.\n"); return; }
    printf("  Pilih MK (1-%d): ", MAX_MK); scanf("%d", &mk);
    if (mk < 1 || mk > MAX_MK) { printf("  [!] Input tidak valid.\n"); return; }
    mk--;
    float nilaiLama = db[idx].nilai[mk];
    printf("  Nilai baru MK-%d (saat ini %.0f): ", mk+1, nilaiLama);
    scanf("%f", &nilaiBaru);

    push(nim, mk, nilaiLama, nilaiBaru);
    insertDLL(nim, mk, nilaiLama, nilaiBaru);
    saveLog(nim, mk, nilaiLama, nilaiBaru);

    db[idx].nilai[mk] = nilaiBaru;
    hitungIPK(&db[idx]);
    printf("  [OK] Nilai diperbarui. IPK baru: %.2f\n", db[idx].ipk);
}

void cariMahasiswa() {
    char nim[12];
    printf("  Masukkan NIM: "); scanf("%s", nim);
    NodeLL *node = searchNIM(nim);
    if (node == NULL) {
        printf("  [!] NIM %s tidak ada di daftar aktif.\n", nim);
        return;
    }
    int idx = cariIndexNIM(nim);
    if (idx == -1) { printf("  [?] Ada di linked list tapi tidak di DB.\n"); return; }
    Mahasiswa *m = &db[idx];
    printf("\n  NIM   : %s\n  Nama  : %s\n  IPK   : %.2f\n  Nilai :", m->nim, m->nama, m->ipk);
    for (int i = 0; i < MAX_MK; i++) printf(" MK%d=%.0f", i+1, m->nilai[i]);
    printf("\n");
}

void tampilMenu() {
    printf("\n");
    printf("  +------------------------------------------------+\n");
    printf("  |     SISTEM MANAJEMEN NILAI MAHASISWA           |\n");
    printf("  +------------------------------------------------+\n");
    printf("  |  1. Tambah Mahasiswa Baru                      |\n");
    printf("  |  2. Tampilkan Semua Mahasiswa                  |\n");
    printf("  |  3. Cari Mahasiswa (Linked List)               |\n");
    printf("  |  4. Ubah Nilai (+ Push Stack + DLL)            |\n");
    printf("  |  5. Undo Perubahan Nilai (Pop Stack)           |\n");
    printf("  |  6. Lihat Stack (peekAll)                      |\n");
    printf("  |  7. Riwayat Perubahan - Maju  (DLL)           |\n");
    printf("  |  8. Riwayat Perubahan - Mundur (DLL)          |\n");
    printf("  |  9. Masuk Antrian Konsultasi (Enqueue)         |\n");
    printf("  | 10. Layani Konsultasi (Dequeue)                |\n");
    printf("  | 11. Tampilkan Antrian                          |\n");
    printf("  | 12. Tampilkan Daftar Aktif (Linked List)       |\n");
    printf("  | 13. Hapus dari Daftar Aktif                    |\n");
    printf("  | 14. Simpan Data ke File (data.txt)             |\n");
    printf("  | 15. Muat Data dari File (data.txt)             |\n");
    printf("  |  0. Keluar                                     |\n");
    printf("  +------------------------------------------------+\n");
    printf("  Pilihan: ");
}

int main() {
    int pilih;
    char nim[12];

    printf("\n  [INFO] Program dimulai. Mencoba load data.txt...\n");
    loadFromFile("data.txt");

    do {
        tampilMenu();
        scanf("%d", &pilih);
        printf("\n");

        switch (pilih) {
            case 1:
                if (totalMhs >= MAX) { printf("  [!] Database penuh.\n"); break; }
                inputMahasiswa(&db[totalMhs]);
                insertTail(db[totalMhs].nim);
                totalMhs++;
                printf("  [OK] Mahasiswa ditambahkan.\n");
                break;

            case 2:
                tampilSemuaMhs();
                break;

            case 3:
                cariMahasiswa();
                break;

            case 4:
                ubahNilai();
                break;

            case 5:
                undoNilai();
                break;

            case 6:
                peekAll();
                break;

            case 7:
                printForward();
                break;

            case 8:
                printBackward();
                break;

            case 9:
                printf("  NIM untuk antrian: "); scanf("%s", nim);
                enqueue(nim);
                break;

            case 10:
                dequeue();
                break;

            case 11:
                displayQueue();
                break;

            case 12:
                printLinkedList();
                break;

            case 13:
                printf("  NIM yang dihapus: "); scanf("%s", nim);
                deleteByNIM(nim);
                break;

            case 14:
                saveToFile("data.txt");
                break;

            case 15:
                loadFromFile("data.txt");
                break;

            case 0:
                printf("  Menyimpan data sebelum keluar...\n");
                saveToFile("data.txt");
                printf("  Sampai jumpa!\n\n");
                break;

            default:
                printf("  [!] Pilihan tidak valid.\n");
        }
    } while (pilih != 0);

    return 0;
}
