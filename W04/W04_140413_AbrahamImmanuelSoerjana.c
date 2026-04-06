#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Student {
    char nama[100];
    char jurusan[100];
    int nim;

    struct Student *next;
} Student;

Student* createNewNode(int nim, char nama[], char jurusan[])
{
    Student *newNode = (Student*) malloc(sizeof(Student));

    newNode->nim = nim;
    strcpy(newNode->nama, nama);
    strcpy(newNode->jurusan, jurusan);
    newNode->next = NULL;

    return newNode;
}

void insert(Student **head, Student **tail)
{
    int nim;
    char nama[100];
    char jurusan[100];

    printf("\n--- Insert new node ---\n");
    printf("NIM : ");
    scanf("%d", &nim);
    printf("Nama : ");
    scanf(" %[^\n]s", nama);
    printf("Jurusan : ");
    scanf(" %[^\n]s", jurusan);

    Student *newNode = createNewNode(nim, nama, jurusan);

    if (*head == NULL)
    {
        *head = newNode;
        *tail = newNode;
    }
    else
    {
        (*tail)->next = newNode;
        *tail = newNode;
    }

    printf("\nData berhasil ditambahkan\n\n");
}

void print(Student *head)
{
    printf("\n--- Print Linked List ---\n");

    if (head == NULL) 
    {
        printf("Linked List kosong\n\n");
        return;
    }

    Student *baru = head;
    int index = 1;

    while (baru != NULL)
    {
        printf("Node ke-%d\n", index);
        printf("NIM : %d\n", baru->nim);
        printf("Nama : %s\n", baru->nama);
        printf("Jurusan : %s\n\n", baru->jurusan);\

        baru = baru->next;
        index++;
    }
}

void deleteAll(Student **head, Student **tail)
{
    if (*head == NULL) {
        printf("\nLinked List sudah kosong!\n");
        return;
    }

    Student *temp;

    while (*head != NULL)
    {
        temp = *head;
        *head = (*head)->next;
        free(temp);
    }
    printf("\nSemua data sudah dihapus\n\n");
}

void deleteFirst(Student **head, Student **tail)
{
    if (*head == NULL) {
        printf("\nLinked List kosong, tidak ada yang dihapus!\n");
        return;
    }

    Student *temp = *head;
    *head = (*head)->next;

    printf("\nData pertama berhasil dihapus\n\n");
    free(temp);
}

void deleteNim(Student **head, Student **tail)
{
    if (*head == NULL)
    {
        printf("\nLinked list kosong\n");
        return;
    }
        

int targetNim;
printf("Masukkan NIM yang akan dihapus : ");
scanf("%d", &targetNim);

Student *temp = *head;
Student *prev = NULL;

    while (temp != NULL && temp->nim != targetNim)
    {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("NIM %d tidak ditemukan\n", targetNim);
        return;
    }

    if (prev == NULL)
    {
        *head = temp->next;
        if (*head == NULL) *tail = NULL;
    }

    else if (temp -> next == NULL)
    {
        prev->next = NULL;
        *tail = prev;
    }

    else 
    {
        prev-> next = temp->next;
    }
printf("Data %s (NIM : %d) berhasil dihapus\n", temp->nama, temp->nim);
free(temp);
}

int main()
{
    int pilihan;
    Student *head = NULL;
    Student *tail = NULL;

    do
    {
        printf("1. Insert new node\n");
        printf("2. Print linked list\n");
        printf("3. Delete all data\n");
        printf("4. Delete first data\n");
        printf("5. Delete data by NIM\n");
        printf("6. Keluar\n");
        printf("Pilihan : ");
        scanf("%d", &pilihan);

        switch (pilihan)
        {
            case 1:
            insert(&head, &tail);
            break;
            case 2:
            print(head);
            //print();
            break;
            case 3:
            deleteAll(&head, &tail);
            break;
            case 4:
            deleteFirst(&head, &tail);
            break;
            case 5:
            deleteNim(&head, &tail);
            case 6:
            printf("\nTerima kasih\n");
            break;
            default:
            printf("\nPilihan anda tidak ada\n\n");
        }
    } while (pilihan != 6);
    
    return 0;
}