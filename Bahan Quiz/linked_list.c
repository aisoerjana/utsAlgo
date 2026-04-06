#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* ───────────────────────────────────────────
   Node structure
─────────────────────────────────────────── */
typedef struct Node {
    int num;
    struct Node* next;
} Node;

/* ───────────────────────────────────────────
   Helper: create a new node
─────────────────────────────────────────── */
Node* newNode(int num) {
    Node* node = (Node*) malloc(sizeof(Node));
    node->num  = num;
    node->next = NULL;
    return node;
}

/* ───────────────────────────────────────────
   Insert node at tail
─────────────────────────────────────────── */
void insert(Node** head, Node** tail, int num) {
    Node* node = newNode(num);
    if (*head == NULL) {
        *head = node;
        *tail = node;
    } else {
        (*tail)->next = node;
        *tail = node;
    }
}

/* ───────────────────────────────────────────
   Print list
─────────────────────────────────────────── */
void printList(Node* head) {
    if (head == NULL) { printf("  (list kosong)\n"); return; }
    printf("  List: ");
    while (head != NULL) {
        printf("%d", head->num);
        if (head->next) printf(" -> ");
        head = head->next;
    }
    printf("\n");
}

/* ───────────────────────────────────────────
   Free entire list
─────────────────────────────────────────── */
void freeList(Node** head, Node** tail) {
    Node* temp;
    while (*head != NULL) {
        temp  = *head;
        *head = (*head)->next;
        free(temp);
    }
    *tail = NULL;
}

/* ═══════════════════════════════════════════
   MENU 1 – Sum & Mean
═══════════════════════════════════════════ */
void sumAndMean(Node* head) {
    if (head == NULL) { printf("  List kosong.\n"); return; }
    int sum = 0, count = 0;
    Node* cur = head;
    while (cur) { sum += cur->num; count++; cur = cur->next; }
    printf("  Sum  : %d\n", sum);
    printf("  Mean : %.2f\n", (double)sum / count);
}

/* ═══════════════════════════════════════════
   MENU 2 – Is Sorted (ascending)?
═══════════════════════════════════════════ */
void isSorted(Node* head) {
    if (head == NULL || head->next == NULL) {
        printf("  List terurut (ascending).\n"); return;
    }
    Node* cur = head;
    while (cur->next != NULL) {
        if (cur->num > cur->next->num) {
            printf("  List TIDAK terurut.\n"); return;
        }
        cur = cur->next;
    }
    printf("  List terurut (ascending).\n");
}

/* ═══════════════════════════════════════════
   MENU 3 – Min & Max
═══════════════════════════════════════════ */
void minMax(Node* head) {
    if (head == NULL) { printf("  List kosong.\n"); return; }
    int mn = head->num, mx = head->num;
    Node* cur = head->next;
    while (cur) {
        if (cur->num < mn) mn = cur->num;
        if (cur->num > mx) mx = cur->num;
        cur = cur->next;
    }
    printf("  Minimum : %d\n", mn);
    printf("  Maximum : %d\n", mx);
}

/* ═══════════════════════════════════════════
   MENU 4 – Move first node to last
═══════════════════════════════════════════ */
void firstToLast(Node** head, Node** tail) {
    if (*head == NULL || (*head)->next == NULL) {
        printf("  Tidak perlu dipindah (0 atau 1 node).\n"); return;
    }
    Node* first = *head;
    *head        = (*head)->next;   /* advance head            */
    first->next  = NULL;            /* detach old first        */
    (*tail)->next = first;          /* append to tail          */
    *tail         = first;          /* update tail             */
    printf("  Node pertama dipindah ke akhir.\n");
}

/* ═══════════════════════════════════════════
   MENU 5 – Reverse list (by links, not data)
═══════════════════════════════════════════ */
void reverseList(Node** head, Node** tail) {
    if (*head == NULL || (*head)->next == NULL) {
        printf("  List tidak perlu di-reverse.\n"); return;
    }
    *tail = *head;           /* old head becomes new tail */
    Node* prev = NULL;
    Node* cur  = *head;
    Node* next = NULL;
    while (cur) {
        next      = cur->next;
        cur->next = prev;
        prev      = cur;
        cur       = next;
    }
    *head = prev;
    printf("  List berhasil di-reverse.\n");
}

/* ═══════════════════════════════════════════
   MENU 6 – Delete last occurrence of a value
═══════════════════════════════════════════ */
void deleteLastOccurrence(Node** head, Node** tail, int val) {
    if (*head == NULL) { printf("  List kosong.\n"); return; }

    Node* lastPrev = NULL;   /* node before last occurrence */
    Node* last     = NULL;   /* last occurrence node        */
    Node* prev     = NULL;
    Node* cur      = *head;

    while (cur) {
        if (cur->num == val) { lastPrev = prev; last = cur; }
        prev = cur;
        cur  = cur->next;
    }

    if (last == NULL) { printf("  Nilai %d tidak ditemukan.\n", val); return; }

    if (last == *head) {         /* deleting head */
        *head = (*head)->next;
        if (*head == NULL) *tail = NULL;
    } else {
        lastPrev->next = last->next;
        if (last == *tail) *tail = lastPrev;
    }
    free(last);
    printf("  Kemunculan terakhir %d berhasil dihapus.\n", val);
}

/* ═══════════════════════════════════════════
   MENU 7 – Remove all duplicate nodes
   (keep first occurrence of each value)
═══════════════════════════════════════════ */
void removeDuplicates(Node** head, Node** tail) {
    if (*head == NULL) { printf("  List kosong.\n"); return; }

    Node* cur = *head;
    int removed = 0;

    while (cur != NULL) {
        Node* prev  = cur;
        Node* check = cur->next;
        while (check != NULL) {
            if (check->num == cur->num) {
                prev->next = check->next;
                if (check == *tail) *tail = prev;
                free(check);
                check = prev->next;
                removed++;
            } else {
                prev  = check;
                check = check->next;
            }
        }
        cur = cur->next;
    }
    printf("  %d node duplikat dihapus.\n", removed);
}

/* ═══════════════════════════════════════════
   Read list from user
═══════════════════════════════════════════ */
void inputList(Node** head, Node** tail) {
    freeList(head, tail);
    int num;
    printf("  Masukkan 5 angka:\n");
    for (int i = 1; i <= 5; i++) {
        printf("  Angka ke-%d: ", i);
        scanf("%d", &num);
        insert(head, tail, num);
    }
}

/* ═══════════════════════════════════════════
   MAIN
═══════════════════════════════════════════ */
int main() {
    Node* head = NULL;
    Node* tail = NULL;
    int choice, val;

    printf("╔══════════════════════════════════════╗\n");
    printf("║       PROGRAM LINKED LIST (C)        ║\n");
    printf("╚══════════════════════════════════════╝\n");

    do {
        printf("\n┌─────────────────────────────────────┐\n");
        printf("│  MENU                               │\n");
        printf("├─────────────────────────────────────┤\n");
        printf("│  0. Input / Reset list              │\n");
        printf("│  1. Sum & Mean                      │\n");
        printf("│  2. Cek apakah list terurut         │\n");
        printf("│  3. Nilai Minimum & Maximum         │\n");
        printf("│  4. Pindah node pertama ke terakhir │\n");
        printf("│  5. Reverse list                    │\n");
        printf("│  6. Hapus kemunculan terakhir nilai │\n");
        printf("│  7. Hapus node duplikat             │\n");
        printf("│  8. Tampilkan list                  │\n");
        printf("│  9. Keluar                          │\n");
        printf("└─────────────────────────────────────┘\n");
        printf("  Pilihan: ");
        scanf("%d", &choice);
        printf("\n");

        switch (choice) {
            case 0:
                inputList(&head, &tail);
                break;
            case 1:
                sumAndMean(head);
                break;
            case 2:
                isSorted(head);
                break;
            case 3:
                minMax(head);
                break;
            case 4:
                firstToLast(&head, &tail);
                break;
            case 5:
                reverseList(&head, &tail);
                break;
            case 6:
                printf("  Masukkan nilai yang ingin dihapus (kemunculan terakhir): ");
                scanf("%d", &val);
                deleteLastOccurrence(&head, &tail, val);
                break;
            case 7:
                removeDuplicates(&head, &tail);
                break;
            case 8:
                printList(head);
                break;
            case 9:
                printf("  Keluar program. Sampai jumpa!\n");
                break;
            default:
                printf("  Pilihan tidak valid!\n");
        }
    } while (choice != 9);

    freeList(&head, &tail);
    return 0;
}
