#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

typedef struct Hotel{
    char id[1000];
    char nama[101];
    char status[100];
    char waktu[10];
    struct Hotel *next;
}Hotel;

Hotel *front = NULL;
Hotel *rear = NULL;


void loadFromFile(){
    FILE *fp = fopen("pelanggan.txt", "r");

    if(fp == NULL){
        printf("File tidak ditemukan!!\n");
        return;
    }

    char id[100], nama[101], status[100], waktu[10];

    while(fscanf(fp, " %[^*]*%[^*]*%[^*]*%[^\n]\n", id, nama, status, waktu) == 4 ){
        Hotel *newNode = (Hotel*)malloc(sizeof(Hotel));

        strcpy(newNode->id, id);
        strcpy(newNode->nama, nama);
        strcpy(newNode->status, status);
        strcpy(newNode->waktu, waktu);
        newNode->next = NULL;

        if(front == NULL){
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
    }
    fclose(fp);
}

void saveToFile(){
    FILE *fp = fopen("pelanggan.txt", "w");

    if(fp == NULL){
        printf("Gagal membuka file!\n");
        return;
    }

    Hotel *temp = front;
    while(temp != NULL){
        fprintf(fp, "%s*%s*%s*%s\n", 
            temp->id,
            temp->nama,
            temp->status,
            temp->waktu);
        temp = temp->next;
    }
    fclose(fp);
}

void addAntrian(){
    Hotel *newNode = (Hotel*)malloc(sizeof(Hotel));

    if(newNode == NULL){
        printf("Gagal alokasi memori!\n");
        return;
    }

    printf("Masukkan ID : ");
    scanf(" %[^\n]", newNode->id);
    printf("Masukkan Nama : ");
    scanf(" %[^\n]", newNode->nama);
    printf("Masukkan Status : ");
    scanf(" %[^\n]", newNode->status);
    printf("Masukkan Waktu : ");
    scanf(" %[^\n]", newNode->waktu);

    newNode->next = NULL;

    if(front == NULL){
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }

    saveToFile();
    printf("Antrian berhasil ditambahkan!\n\n");
}

void outAntrian(){
    if(front == NULL){
        printf("Queue is empty\n\n");
        return;
    }

    Hotel *trash = front;
    

    printf("Removing %s from queue\n\n", trash->id);
    
    front = front->next;

    if(front == NULL){
        rear = NULL;
    }

    free(trash);
    saveToFile();
}

void printAll(){
    if(front == NULL){
        printf("Queue is empty\n");
        return;
    }

    Hotel *temp = front;
    while(temp != NULL){
        printf("%s - %s - %s - %s\n", temp->id, temp->nama, temp->status, temp->waktu);
        temp = temp->next;
    }
}

void peekFirst(){
    if(front == NULL){
        printf("Queue is empty\n\n");
        return;
    }

    printf("%s - %s - %s - %s\n", front->id, front->nama, front->status, front->waktu);
}

int main(){
    int pilihan;
    loadFromFile();

    do{
        printf("===== MENU ANTRIAN DRAFT =====\n");
        printf("1. Check In (Tambah Antrian)\n");
        printf("2. Check Out (Layani Antrian)\n");
        printf("3. Tampilkan Semua Antrian\n");
        printf("4. Lihat Antrian Pertama\n");
        printf("5. Keluar\n");
        printf("Pilih Menu: ");
        scanf("%d", &pilihan);

        switch (pilihan)
        {
        case 1:
            addAntrian();
            break;
        case 2:
            outAntrian();
            break;
        case 3:
            printAll();
            break;
        case 4:
            peekFirst();
            break;
        case 5:
            break;
        default:
            break;
        }
    }while(pilihan != 5);
}