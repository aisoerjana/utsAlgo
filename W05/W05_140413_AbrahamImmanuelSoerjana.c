#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>

typedef struct playlist {
    char singer[100];
    char album[100];
    char title[100];
    int year;

    struct playlist *next, *prev;
} playlist;

void createNewNode(char *singer, char *album, char *title, int year, playlist **head, playlist **tail)
{
    playlist *newNode = (playlist*) malloc(sizeof(playlist));

    strcpy(newNode->singer, singer);
    strcpy(newNode->album, album);
    strcpy(newNode->title, title);
    newNode->year = year;
    newNode->next = NULL;
    newNode->prev = NULL;

    if(*tail == NULL)
    {
        *head = newNode;
        *tail = newNode;
    }
    else
    {
        newNode->prev = *tail;
        (*tail)->next = newNode;
        *tail = newNode;
    }
}

void baca(playlist **head, playlist **tail)
{
    FILE *playlist = fopen ("playlist.txt", "r");
    if(playlist == NULL)
    {
        printf("File playlist.txt tidak ditemukan\n");
        return;
    }
    
    char singer[100], album[100], title[100];
    int year; 

        while(fscanf(playlist, "%[^*]*%[^*]*%[^*]*%d\n", 
        singer, album, title, &year) == 4)
        {
            createNewNode(singer, album, title, year, head, tail);
        }
        fclose(playlist);
}

void tampilkan(playlist **head)
{
    if(*head == NULL)
    {
        printf("Data masih kosong\n");
        return;
    }

    printf("+----+----------------------+-------------------------+----------------------+---------------+\n");
    printf("| No | Singer               | Song Title              | Album                | Released Year |\n");
    printf("+----+----------------------+-------------------------+----------------------+---------------+\n");

    playlist *curr = *head;
    
    int no = 1;
    while(curr != NULL)
    {
        printf("| %-3d| %-21s| %-24s| %-21s| %-14d|\n",
               no, curr->singer, curr->title, curr->album, curr->year);
        curr = curr->next;
        no++;
    }
}

void tambah(playlist **head, playlist **tail)
{
    char singer[100], album[100], title[100];
    int year;

    printf("\n===== Insert new data =====\n");
    printf("Singer : ");
    scanf(" %[^\n]", singer);
    printf("Album : ");
    scanf(" %[^\n]", album);
    printf("Title : ");
    scanf(" %[^\n]", title);
    printf("Year : ");
    scanf("%d", &year);

    createNewNode(singer, album, title, year, head, tail);

    FILE *playlist = fopen("playlist.txt", "a");
    if (playlist != NULL)
    {
        fprintf(playlist, "%s*%s*%s*%d\n", singer, album, title, year); 
    }
    fclose (playlist);

    printf("\nData berhasil ditambahkan\n\n");
}

void hapus(playlist **head, playlist **tail)
{
    if(*tail == NULL) return;

    playlist *sampah = *tail;

    if(*head == *tail)
    {
        *head = NULL;
        *tail = NULL;
    }
    else
    {
        *tail = sampah->prev;
        (*tail)->next = NULL;
    }
    free(sampah);
    printf("\nData terakhir berhasil dihapus\n");

    FILE *file = fopen("playlist.txt", "w");
    playlist *curr = *head;
    if (file != NULL)
    {
        while(curr != NULL)
        {
            fprintf(file, "%s*%s*%s*%d\n", curr->singer, curr->album, curr->title, curr->year);
            curr = curr->next;
        }
        fclose(file);
    }
}

void freeMemory(playlist **head)
{
    playlist *curr = *head;
    playlist *temp;

    while(curr != NULL){
        temp = curr;
        curr = curr->next;
        free(temp);
    }
    *head = NULL;
}
    
int main()
{
    playlist *head = NULL;
    playlist *tail = NULL;
    baca(&head, &tail);
    int pilihan;

    do
    {
        printf("\n===== Playlist Database =====\n");
        printf("1. Tampilkan data\n");
        printf("2. Tambah data\n");
        printf("3. Hapus data\n");
        printf("4. Exit\n");
        printf("Pilihan : ");
        scanf("%d", &pilihan);

        switch(pilihan)
        {
            case 1:
            tampilkan(&head);
            break;

            case 2:
            tambah(&head, &tail);
            break;

            case 3:
            hapus(&head, &tail);
            break;

            case 4:
            printf("\nTerima kasih sudah menggunakan program ini\n");
            freeMemory(&head);
            break;

            default:
            printf("\nAnda salah pilih angka\n");
        }
    } while (pilihan != 4);

    return 0;
}