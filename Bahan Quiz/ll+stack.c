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

    printf("Mahasiswa berhasil ditambahkan ke stack\n");
}

void pop(){

    if(isEmpty()){
        printf("Stack kosong\n");
        return;
    }

    Mahasiswa *temp = top;

    printf("Mahasiswa yang dihapus:\n");
    printf("NIM: %s\n", temp->nim);
    printf("Nama: %s\n", temp->nama);

    top = top->next;

    free(temp);
}

void peek(){

    if(isEmpty()){
        printf("Stack kosong\n");
        return;
    }

    printf("Mahasiswa paling atas:\n");
    printf("NIM: %s\n", top->nim);
    printf("Nama: %s\n", top->nama);
    printf("Jurusan: %s\n", top->jurusan);
}

void display(){

    if(isEmpty()){
        printf("Stack kosong\n");
        return;
    }

    Mahasiswa *temp = top;

    printf("\nDaftar Mahasiswa di Stack:\n");

    while(temp != NULL){
        printf("NIM: %s | Nama: %s | Jurusan: %s\n",
               temp->nim,
               temp->nama,
               temp->jurusan);
        temp = temp->next;
    }
}

int main(){

    int pilihan;

    do{

        printf("\n=== MENU STACK MAHASISWA ===\n");
        printf("1. Push Mahasiswa\n");
        printf("2. Pop Mahasiswa\n");
        printf("3. Peek Mahasiswa\n");
        printf("4. IsEmpty\n");
        printf("5. Display Semua Mahasiswa\n");
        printf("6. Exit\n");
        printf("Pilih menu: ");
        scanf("%d", &pilihan);

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
                if(isEmpty())
                    printf("Stack kosong\n");
                else
                    printf("Stack tidak kosong\n");
                break;

            case 5:
                display();
                break;

            case 6:
                printf("Program selesai\n");
                break;

            default:
                printf("Pilihan tidak valid\n");
        }

    }while(pilihan != 6);

    return 0;
}