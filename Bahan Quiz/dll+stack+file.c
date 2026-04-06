#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Pesanan{
    int id;
    char menu[50];
    int jumlah;
    int harga;
    struct Pesanan *next;
    struct Pesanan *prev;
}Pesanan;

Pesanan *top = NULL;

int isEmpty(){
    return top == NULL;
}

void push(){

    Pesanan *newNode = (Pesanan*) malloc(sizeof(Pesanan));

    printf("Masukkan ID Pesanan: ");
    scanf("%d",&newNode->id);

    printf("Masukkan Nama Menu: ");
    scanf(" %[^\n]", newNode->menu);

    printf("Masukkan Jumlah: ");
    scanf("%d",&newNode->jumlah);

    printf("Masukkan Harga: ");
    scanf("%d",&newNode->harga);

    newNode->prev = NULL;
    newNode->next = top;

    if(top != NULL){
        top->prev = newNode;
    }

    top = newNode;

    printf("Pesanan berhasil ditambahkan\n");
}

void pop(){

    if(isEmpty()){
        printf("Stack kosong\n");
        return;
    }

    Pesanan *temp = top;

    printf("Pesanan yang dihapus: %s\n", temp->menu);

    top = top->next;

    if(top != NULL){
        top->prev = NULL;
    }

    free(temp);
}

void peek(){

    if(isEmpty()){
        printf("Stack kosong\n");
        return;
    }

    printf("Pesanan terakhir:\n");
    printf("ID: %d\n", top->id);
    printf("Menu: %s\n", top->menu);
    printf("Jumlah: %d\n", top->jumlah);
    printf("Harga: %d\n", top->harga);
}

void display(){

    if(isEmpty()){
        printf("Stack kosong\n");
        return;
    }

    Pesanan *temp = top;

    printf("\nDaftar Pesanan:\n");

    while(temp != NULL){

        printf("ID:%d | %s | Jumlah:%d | Harga:%d\n",
               temp->id,
               temp->menu,
               temp->jumlah,
               temp->harga);

        temp = temp->next;
    }
}

void saveFile(){

    FILE *fp = fopen("pesanan.txt","w");

    if(fp == NULL){
        printf("File tidak bisa dibuka\n");
        return;
    }

    Pesanan *temp = top;

    while(temp != NULL){

        fprintf(fp,"%d;%s;%d;%d\n",
                temp->id,
                temp->menu,
                temp->jumlah,
                temp->harga);

        temp = temp->next;
    }

    fclose(fp);

    printf("Data berhasil disimpan ke file\n");
}

void loadFile(){

    FILE *fp = fopen("pesanan.txt","r");

    if(fp == NULL){
        printf("File tidak ditemukan\n");
        return;
    }

    int id, jumlah, harga;
    char menu[50];

    while(fscanf(fp,"%d;%[^;];%d;%d\n",
                 &id, menu, &jumlah, &harga) != EOF){

        Pesanan *newNode = malloc(sizeof(Pesanan));

        newNode->id = id;
        strcpy(newNode->menu, menu);
        newNode->jumlah = jumlah;
        newNode->harga = harga;

        newNode->prev = NULL;
        newNode->next = top;

        if(top != NULL){
            top->prev = newNode;
        }

        top = newNode;
    }

    fclose(fp);

    printf("Data berhasil dibaca dari file\n");
}

int main(){

    int pilihan;

    do{

        printf("\n=== SISTEM STACK PESANAN ===\n");
        printf("1 Push Pesanan\n");
        printf("2 Pop Pesanan\n");
        printf("3 Peek Pesanan\n");
        printf("4 Display Pesanan\n");
        printf("5 Save ke File\n");
        printf("6 Load dari File\n");
        printf("7 Exit\n");
        printf("Pilih: ");
        scanf("%d",&pilihan);

        switch(pilihan){

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
                display();
                break;

            case 5:
                saveFile();
                break;

            case 6:
                loadFile();
                break;

            case 7:
                printf("Program selesai\n");
                break;

            default:
                printf("Menu tidak valid\n");
        }

    }while(pilihan != 7);

    return 0;
}