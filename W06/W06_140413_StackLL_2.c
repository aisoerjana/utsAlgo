#include <stdio.h>
#include <stdlib.h>

struct tstack
{
    int data;
    struct tstack *next;
};

void push(struct tstack **top, int angka)
{
    struct tstack *node = (struct tstack *)malloc(sizeof(struct tstack));
    node->data = angka;

    if (*top == NULL)
        node->next = NULL;
    else
        node->next = *top;

    *top = node;
    printf("Push berhasil: %d\n", angka);
}

void pop(struct tstack **top)
{
    if (*top == NULL)
        printf("Stack masih kosong\n");
    else
    {
        struct tstack *node = *top;
        printf("Pop berhasil: %d\n", node->data);
        *top = (*top)->next;
        free(node);
    }
}

void isEmpty (struct tstack *top)
{
    if (top == NULL)
        printf("Stack masih kosong\n");
    else
        printf("Stack tidak kosong\n");
}

void peek(struct tstack *top)
{
    if (top == NULL)
        printf("Stack masih kosong\n");
    else
        printf("Elemen paling atas : %d\n", top->data);
}

void clear(struct tstack **top)
{
    if (*top == NULL)
    {
        printf("Stack sudah kosong\n");
        return;
    }

    struct tstack *current = *top;
    struct tstack *next;
    int count = 0;

    while (current != NULL)
    {
        next = current->next;
        free(current);
        current = next;
        count++;
    }
    *top = NULL;
    printf("Stack sudah kosong, %d element telah dihapus\n", count);
}

int main()
{
    struct tstack *top;
    int angka, pilihan;
    top = NULL;

    do
    {
        printf("\nSTACK PROGRAM - LINKED LIST\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. IsEmpty\n");
        printf("4. Peek\n");
        printf("5. Clear Stack\n");
        printf("6. Exit\n");
        printf("Pilih: ");
        scanf("%d", &pilihan);

        switch (pilihan)
        {
            case 1:
            printf("Masukkan angka untuk push : ");
            scanf("%d", &angka);
            push(&top, angka);
            break;

            case 2:
            pop(&top);
            break;

            case 3:
            isEmpty(top);
            break;

            case 4:
            peek(top);
            break;

            case 5:
            clear(&top);
            break;

            default:
                printf("Pilihan anda tidak ada\n");

        }
    } while (pilihan != 6);
}