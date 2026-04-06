#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include <unistd.h>

typedef struct Node
{
    int angka;
    struct Node* next;
} Node;

void createNewNodes(Node** head, Node** tail, int angka)
{
    Node* newNodes = (Node*) malloc(sizeof(Node));
    newNodes->angka = angka;
    newNodes->next = NULL;

    if (*head == NULL)
    {
        *head = newNodes;
        *tail = newNodes;
    }
    else
    {
        (*tail)->next = newNodes;
        *tail = newNodes;
    }
}

void input(Node** head, Node** tail)
{
    int angka;
    printf("Masukkan 10 angka : \n");
    for (int i = 0; i < 10; i++)
    {
        printf("Angka ke-%d : ", i+1);
        scanf("%d", &angka);
        createNewNodes(head, tail, angka);
    }
}

void sumMean(Node* head)
{
    if (head == NULL)
    {
        printf("List masih kosong\n");
        return;
    }
    int sum = 0; 
    int count = 0;
    Node *current = head;
    while (current != NULL)
    {
        sum = sum + current->angka;
        count++;
        current = current->next;
    }
    printf("Sum : %d\n", sum);
    printf("Mean : %.2f\n", (double)sum / count);
}

void isSorted(Node* head)
{
    if (head == NULL || head->next == NULL)
    {
        printf("List terurut (ascending)\n");
        return;
    }
    Node *current = head;
    while (current->next != NULL)
    {
        if (current->angka > current->next->angka)
        {
            printf("List tidak terurut\n");
            return;
        }
        current = current->next;
    }
    printf("List terurut (ascending)\n");
}

void minMax(Node* head)
{
    if (head == NULL)
    {
        printf("List masih kosong\n");
        return;
    }
    int min = head->angka;
    int max = head->angka;

    Node *current = head->next;
    while (current != NULL)
    {
        if (current-> angka < min)
        min = current->angka;
        if (current->angka > max)
        max = current->angka;
        current = current->next;
    }
    printf("Minimum : %d\n", min);
    printf("Maximum : %d\n", max);
}

void firstToLast(Node** head, Node** tail)
{
    if (*head == NULL || (*head)->next == NULL)
    {
        printf("Tidak bisa dipindah, hanya ada 0 atau 1 node\n");
        return;
    }
    Node *first = *head;
    *head = (*head)->next;
    first->next = NULL;
    (*tail)->next = first;
    *tail = first;
    printf("Node pertama berhasil dipindahkan ke paling akhir\n");
}

void reverse(Node** head, Node** tail)
{
    if (*head == NULL || (*head)->next == NULL)
    {
        printf("List tidak bisa direverse, hanya ada 0 atau 1 node\n");
        return;
    }
    *tail = *head;
    Node* prev = NULL;
    Node* current = *head;
    Node* next = NULL;
    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head = prev;
    printf("List berhasil di reverse\n");
} 

void deleteLast(Node** head, Node** tail, int value)
{
    if (*head == NULL)
    {
        printf("List masih kosong\n");
        return;
    }
    Node* lastPrev = NULL;
    Node* last  = NULL;
    Node* prev = NULL;
    Node* current = *head;

    while (current != NULL)
    {
        if (current->angka == value)
        {
            lastPrev = prev;
            last = current;
        }
        prev = current;
        current = current->next;
    }

    if (last == NULL)
    {
        printf("Nilai %d tidak ditemukan\n", value);
        return;
    }
    if (last == *head)
    {
        *head = (*head)->next;
        if (*head == NULL)
            *tail = NULL;
    }
        else
        {
            lastPrev->next = last->next;
            if (last == *tail)
                *tail = lastPrev;
        }
    free(last);
    printf("Kemunculan terakhir %d berhasil dihapus\n", value);
}

void removeDuplicates(Node**head, Node**tail)
{
    if (*head == NULL) 
    { 
        printf("List masih kosong\n"); 
        return; 
    }
    Node* current = *head;
    int removed = 0;

    while (current != NULL) 
    {
        Node* prev  = current;
        Node* check = current->next;
        while (check != NULL) 
        {
            if (check->angka == current->angka) 
            {
                prev->next = check->next;
                if (check == *tail) *tail = prev;
                free(check);
                check = prev->next;
                removed++;
            } 
            else
            {
                prev  = check;
                check = check->next;
            }
        }
        current = current->next;
    }
    printf("%d Node duplikat sudah dihapus\n", removed);
}

void printList(Node* head)
{
    if (head == NULL)
    {
        printf("List masih kosong\n");
        return;
    }
    printf("List : ");
    while (head != NULL)
    {
        printf("%d ", head->angka);
        head = head->next;
    }
    printf("\n");
}

void freeList(Node** head, Node** tail)
{
    Node* temp;
    while (*head != NULL) {
        temp  = *head;
        *head = (*head)->next;
        free(temp);
    }
    *tail = NULL;
}

int main()
{
    Node *head = NULL;
    Node *tail = NULL;
    int pilihan, value;

    do
    {
        printf("\nMenu:\n");
        printf("1. Masukkan 5 angka\n");
        printf("2. Sum & Mean\n");
        printf("3. Sort checking\n");
        printf("4. Show minimum and maximum\n");
        printf("5. Move first node to last\n");
        printf("6. Reverse the list\n");
        printf("7. Delete last occurence\n");
        printf("8. Remove all duplicate nodes\n");
        printf("9. Show list\n");
        printf("10. Exit\n");
        printf("Pilihan : ");
        scanf("%d", &pilihan);
    
        switch (pilihan)
        {
            case 1:
                input(&head, &tail);
                break;
            case 2:
                sumMean(head);
                break;
            case 3:
                isSorted(head);
                break;
            case 4:
                minMax(head);
                break;
            case 5:
                firstToLast(&head, &tail);
                break;
            case 6:
                reverse(&head, &tail);
                break; 
            case 7:
                printf("  Masukkan nilai yang ingin dihapus (kemunculan terakhir): ");
                scanf("%d", &value);
                
                deleteLast(&head, &tail, value);
                break;
            case 8:
                removeDuplicates(&head, &tail);
                break;
            case 9:
                printList(head);
                break;
            case 10:
                printf("Terima kasih!\n");
                break;
            default:
                printf("Pilihan anda tidak ada di menu\n");
        }
    } while (pilihan != 10);
    freeList(&head, &tail);
    return 0;
} 


