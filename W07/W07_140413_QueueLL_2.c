#include <stdio.h>
#include <stdlib.h>

struct tnode
{
    int data;
    struct tnode *next;
};

struct tqueue
{
    struct tnode *front;
    struct tnode *rear;
};

int isEmpty(struct tqueue *queue)
{
    if (queue->front == NULL)
    {
        return 1;
    }
    return 0;
}

void enqueue(struct tqueue *queue, int number)
{
    struct tnode *node;

    node = (struct tnode *) malloc(sizeof(struct tnode));
    if (node == NULL)
    {
        printf("Alokasi memori gagal!\n");
        return;
    }

    node->data = number;
    node->next = NULL;

    if (isEmpty(queue))
    {
        queue->front = node;
    }
    else
    {
        queue->rear->next = node;
    }

    queue->rear = node;
    printf("Enqueue berhasil: %d\n", number);
}

void dequeue(struct tqueue *queue)
{
    struct tnode *trash;
    int number;

    if (isEmpty(queue))
    {
        printf("Queue kosong (UNDERFLOW)!\n");
        return;
    }

    trash  = queue->front;
    number = trash->data;

    queue->front = queue->front->next;

    if (queue->front == NULL)
    {
        queue->rear = NULL;
    }

    free(trash);
    printf("Dequeue berhasil: %d\n", number);
}

void peek(struct tqueue *queue)
{
    if (isEmpty(queue))
    {
        printf("Queue kosong!\n");
        return;
    }

    printf("Elemen terdepan: %d\n", queue->front->data);
}

void printQueue(struct tqueue *queue)
{
    struct tnode *current;

    if (isEmpty(queue))
    {
        printf("Queue kosong!\n");
        return;
    }

    printf("Isi queue (depan -> belakang): ");
    current = queue->front;
    while (current != NULL)
    {
        printf("%d", current->data);
        if (current->next != NULL)
        {
            printf(" -> ");
        }
        current = current->next;
    }
    printf("\n");
}

void clearQueue(struct tqueue *queue)
{
    struct tnode *current;
    struct tnode *next;

    current = queue->front;
    while (current != NULL)
    {
        next = current->next;
        free(current);
        current = next;
    }

    queue->front = NULL;
    queue->rear  = NULL;
    printf("Queue berhasil dikosongkan.\n");
}

int main(void)
{
    struct tqueue queue;
    int pilihan;
    int number;

    queue.front = NULL;
    queue.rear  = NULL;

    printf("=================================\n");
    printf("  PROGRAM QUEUE - LINKED LIST    \n");
    printf("=================================\n\n");

    do
    {
        printf("Menu:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. IsEmpty\n");
        printf("4. Peek\n");
        printf("5. PrintQueue\n");
        printf("6. Clear Queue\n");
        printf("7. Exit\n");
        printf("Pilihan: ");
        scanf("%d", &pilihan);
        printf("\n");

        switch (pilihan)
        {
            case 1:
                printf("Masukkan bilangan bulat: ");
                scanf("%d", &number);
                enqueue(&queue, number);
                break;

            case 2:
                dequeue(&queue);
                break;

            case 3:
                if (isEmpty(&queue))
                {
                    printf("Queue KOSONG.\n");
                }
                else
                {
                    printf("Queue tidak kosong.\n");
                }
                break;

            case 4:
                peek(&queue);
                break;

            case 5:
                printQueue(&queue);
                break;

            case 6:
                clearQueue(&queue);
                break;

            case 7:
                printf("Keluar dari program.\n");
                break;

            default:
                printf("Pilihan tidak valid!\n");
                break;
        }

        printf("\n");

    } while (pilihan != 7);

    clearQueue(&queue);

    return EXIT_SUCCESS;
}
