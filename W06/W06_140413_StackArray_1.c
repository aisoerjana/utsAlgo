#include <stdio.h>
#include <stdlib.h>

struct tstack
{
    int data[100];
    int size;
    int top;
};

void push(struct tstack *stack, int angka)
{
    if (stack->top == stack->size - 1)
        printf("Stack sudah penuh, tidak bisa push\n");
    else
    {
        stack->top++;
        stack->data[stack->top] = angka;
        printf("Push berhasil: %d\n", angka);
    }
}

void pop(struct tstack *stack)
{
    if (stack->top == -1)
        printf("Stack masih kosong\n");
    else
    {
        int angka = stack->data[stack->top];
        stack->top--;
        printf("Pop berhasil: %d\n", angka);
    }
}

void isFull(struct tstack *stack)
{
    if (stack->top == stack->size - 1)
        printf("Stack sudah penuh - %d/%d\n", stack->top + 1, stack->size);
    else
        printf("Stack masih bisa diisi - %d/%d\n", stack->top + 1, stack->size);
}

void isEmpty(struct tstack *stack)
{
    if (stack->top == -1)
        printf("Stack masih kosong\n");
    else
        printf("Stack tidak kosong - ada %d elemen\n", stack->top + 1);
}

void peek(struct tstack *stack)
{
    if (stack->top == -1)
        printf("Stack masih kosong, tidak ada elemen untuk peek\n");
    else
        printf("Elemen paling atas : %d\n", stack->data[stack->top]);
}

void clear(struct tstack *stack)
{
    stack->top = -1;
    printf("Stack sudah kosong\n");
}

int main()
{
    struct tstack stack;
    int angka, pilihan;
    stack.size = 100;
    stack.top = -1;

    do {
        printf("\nSTACK PROGRAM - ARRAY\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. IsFull\n");
        printf("4. IsEmpty\n");
        printf("5. Peek\n");
        printf("6. Clear Stack\n");
        printf("7. Exit\n");
        printf("Pilihan: ");
        scanf("%d", &pilihan);

        switch (pilihan)
        {
            case 1:
            printf("Masukkan angka untuk push : ");
            scanf("%d", &angka);
            push(&stack, angka);
            break;

            case 2:
            pop(&stack);
            break;

            case 3:
            isFull(&stack);
            break;

            case 4:
            isEmpty(&stack);
            break;

            case 5:
            peek(&stack);
            break;

            case 6:
            clear(&stack);
            break;

            default:
            printf("Pilihan anda tidak ada\n");
        }
    } while (pilihan != 7);
}