#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>

// create struct for the base of queue
typedef struct Student
{
    char nim[13];
    char name[13];
    char major[30];

    struct Student *next;
} Student;

// #2 Create four functions for basic queue operations
// The order of functions: isEmpty, enqueue, dequeue, front

// #2.1 Create function isEmpty
int isEmpty(Student *queue)
{
    // Check whether the queue has elements
    if(queue == NULL) return 1; // if queue is empty
    return 0; // if queue is not empty
}

// #2.2 Create function enqueu
// Used to insert data into the queue
void enqueue(Student **head, Student **tail, char nim[], char name[], char major[])
{
    Student *data = (Student*) malloc(sizeof(Student));

    strcpy(data->nim, nim);
    strcpy(data->name, name);
    strcpy(data->major, major);
    data->next = NULL;

    if(isEmpty(*head)) *head = data;
    else (*tail)->next = data;

    *tail = data;

    printf("Adding %s to queue\n", name);
}

// #2.3 Create function dequeue
// Used to remove data from the queue
void dequeue(Student **head)
{
    printf("Removing queue's front element\n");

    if(isEmpty(*head)) // Check if queue is empty
    {
        // if empty, nothing can be dequeued
        printf("Nothing to dequeue. Queue already empty\n");
        return;
    }

    // trash is used to store the data that will be removed
    Student *trash = *head;
    *head = trash->next;
    free(trash);

    printf("Dequeuing success\n");
}

// #2.4 Create function front
// Returns the first data in the queue
Student *front(Student *queue)
{
    if(queue == NULL) return NULL; // if queue is empty
    return queue; // if queue is not empty
}

int main()
{
    printf("QUEUE TUTORIAL\n");
    printf("--------------\n");

    printf("Initializing Queue\n\n");

    Student *headQueue, *tailQueue; // headQueue = start of queue, tailQueue = end of queue
    headQueue = tailQueue = NULL; // Intialize empty queue

    printf("Is Queue empty? %s\n", isEmpty(headQueue) ? "Yes" : "No");
    printf("What is the name at the front? %s\n\n",
        front(headQueue) == NULL ? "No one. Queue is empty" : front(headQueue)->name);

    enqueue(&headQueue, &tailQueue, "L12312", "Febe", "Informatics");

    printf("What is the name at the front? %s\n",
        front(headQueue) == NULL ? "No one. Queue is empty" : front(headQueue)->name);

    printf("Is Queue empty? %s\n", isEmpty(headQueue) ? "Yes" : "No");

    dequeue(&headQueue);

    printf("is Queue empty? %s\n", isEmpty(headQueue) ? "Yes" : "No");
    printf("What is the name at the front? %s\n\n",
        front(headQueue) == NULL ? "No one. Queue is empty" : front(headQueue)->name);

    return 0;
}