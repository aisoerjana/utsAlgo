#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Mahasiswa{
    char nim[15];
    char nama[50];
    char jurusan[50];
    struct Mahasiswa *next;
}Mahasiswa;

Mahasiswa *top = NULL;

int isEmpty(){
    return top == NULL;
}

void push(){

    Mahasiswa *newNode = (Mahasiswa*) malloc(sizeof(Mahasiswa));

    printf("Masukkan NIM: ");
    scanf("%s", newNode->nim);

    printf("Masukkan Nama: ");
    scanf(" %[^\n]", newNode->nama);

    printf("Masukkan Jurusan: ");
    scanf(" %[^\n]", newNode->jurusan);

    newNode->next = top;
    top = newNode;

    printf("Mahasiswa berhasil ditambahkan\n");
}

void pop(){

    if(isEmpty()){
        printf("Stack kosong\n");
        return;
    }

    Mahasiswa *temp = top;

    printf("Mahasiswa yang dihapus:\n");
    printf("%s - %s\n", temp->nim, temp->nama);

    top = top->next;

    free(temp);
}

void peek(){

    if(isEmpty()){
        printf("Stack kosong\n");
        return;
    }

    printf("Mahasiswa paling atas:\n");
    printf("%s - %s - %s\n", top->nim, top->nama, top->jurusan);
}

void display(){

    if(isEmpty()){
        printf("Stack kosong\n");
        return;
    }

    Mahasiswa *temp = top;

    printf("\nData Mahasiswa di Stack:\n");

    while(temp != NULL){
        printf("%s | %s | %s\n",
               temp->nim,
               temp->nama,
               temp->jurusan);

        temp = temp->next;
    }
}

void saveFile(){

    FILE *fp = fopen("mahasiswa.txt","w");

    if(fp == NULL){
        printf("File tidak bisa dibuka\n");
        return;
    }

    Mahasiswa *temp = top;

    while(temp != NULL){
        fprintf(fp,"%s;%s;%s\n",
                temp->nim,
                temp->nama,
                temp->jurusan);

        temp = temp->next;
    }

    fclose(fp);

    printf("Data berhasil disimpan ke file\n");
}

void loadFile(){

    FILE *fp = fopen("mahasiswa.txt","r");

    if(fp == NULL){
        printf("File tidak ditemukan\n");
        return;
    }

    char nim[15], nama[50], jurusan[50];

    while(fscanf(fp,"%[^;];%[^;];%[^\n]\n",
                 nim, nama, jurusan) != EOF){

        Mahasiswa *newNode = malloc(sizeof(Mahasiswa));

        strcpy(newNode->nim, nim);
        strcpy(newNode->nama, nama);
        strcpy(newNode->jurusan, jurusan);

        newNode->next = top;
        top = newNode;
    }

    fclose(fp);

    printf("Data berhasil dibaca dari file\n");
}

int main(){

    int pilihan;

    do{

        printf("\n=== MENU STACK MAHASISWA ===\n");
        printf("1 Push\n");
        printf("2 Pop\n");
        printf("3 Peek\n");
        printf("4 Display\n");
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