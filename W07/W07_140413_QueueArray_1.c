#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 5

struct tqueue
{
    int data[MAX];
    int front;
    int rear;
};

int isEmpty(struct tqueue *queue)
{
    if (queue->front == -1)
    {
        return 1;
    }
    return 0;
}

int isFull(struct tqueue *queue)
{
    if (queue->rear == MAX - 1)
    {
        return 1;
    }
    return 0;
}

void Enqueue(struct tqueue *queue)
{
    int bilangan;
    printf("Masukkan 1 bilangan bulat untuk dimasukkan ke dalam Queue : ");
    scanf("%d", &bilangan);
    
    if (isFull(queue))
    {
        printf("Queue sudah penuh\n");
        return;
    }

    if (isEmpty(queue))
    {
        queue->front = queue->rear = 0;
    }
    else
    {
        queue->rear++;
    }
    queue->data[queue->rear] = bilangan;
    printf("Enqueue berhasil: %d\n", bilangan);
}

void dequeue(struct tqueue *queue)
{
    int bilangan;

    if (isEmpty(queue))
    {
        printf("Queue kosong\n");
        return;
    }

    bilangan = queue->data[queue->front];

    if (queue->front == queue->rear)
    {
        queue->front = queue->rear = -1;
    }
    else
    {
        queue->front++;
    }
    printf("Dequeue berhasil: %d\n", bilangan);
}

void peek(struct tqueue *queue)
{
    if (isEmpty(queue))
    {
        printf("Queue kosong\n");
        return;
    }
    printf("Elemen terdepan: %d\n", queue->data[queue->front]);
}

void printQueue(struct tqueue *queue)
{
    int i;

    if (isEmpty(queue))
    {
        printf("Queue kosong\n");
        return;
    }

    printf("Isis queue (depan -> belakang): ");
    for (i = queue->front; i <= queue->rear; i++)
    {
        printf("%d", queue->data[i]);
        if (i < queue->rear)
        {
            printf(" -> ");
        }
    }
    printf("\n");
}

void clearQueue(struct tqueue *queue)
{
    queue->front = -1;
    queue->rear = -1;
    printf("Queue berhasil dikosongkan\n");
}

int main()
{
    struct tqueue queue;
    int pilihan;

    queue.front = -1;
    queue.rear = -1;

    printf("============================\n");
    printf("   PROGRAM QUEUE - ARRAY    \n");
    printf("============================\n\n");

    do
    {
        printf("Menu:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. isFull\n");
        printf("4. isEmpty\n");
        printf("5. Peek\n");
        printf("6. PrintQueue\n");
        printf("7. Clear Queue\n");
        printf("8. Exit\n");
        printf("Pilihan : ");
        scanf("%d", &pilihan);

        switch (pilihan)
        {
            case 1:
            Enqueue(&queue);
            break;

            case 2:
            dequeue(&queue);
            break;

            case 3:
            if (isFull(&queue))
            {
                printf("Queue penuh\n");
            }
            else
            {
                printf("Queue belum penuh\n");
            }
            break;

            case 4:
            if (isEmpty(&queue))
            {
                printf("Queue kosong\n");
            }
            else
            {
                printf("Queue tidak kosong\n");
            }
            break;

            case 5:
            peek(&queue);
            break;

            case 6:
            printQueue(&queue);
            break;

            case 7:
            clearQueue(&queue);
            break;

            case 8:
            printf("Terima kasih telah menggunakan program ini\n");
            break;

            default:
            printf("Pilihan anda tidak ada\n");
            break;
        }
        printf("\n");
    } while (pilihan != 8);
    
    return 0;
}