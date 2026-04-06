#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

typedef struct Student {
    char name[100];
    char major[30];
    int nim;

    struct Student *next, *prev;
} Student;

void createNewNode(int nim, char *name, char *major, Student **head, Student **tail)
{
    Student *newNode = (Student*) malloc(sizeof(Student));

    newNode->nim = nim;
    strcpy(newNode->name, name);
    strcpy(newNode->major, major);
    newNode->next = NULL;
    newNode->prev = NULL;

    if(*tail == NULL)
    { // first node
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

void headDeletion(Student **head, Student **tail)
{
    if(*head == NULL) return;

    Student *trash = *head;

    if(*head == *tail)
    { // only one node
        *head = NULL;
        *tail = NULL;
    }
    else
    {
        *head = trash->next;
        (*head)->prev = NULL;
    }
    free(trash);
}

void tailDeletion(Student **head, Student **tail)
{
    if(*tail == NULL) return;

    Student *trash = *tail;
    
    if(*head == *tail)
    { // only one node
        *head = NULL;
        *tail = NULL;
    }
    else
    {
        *tail = trash->prev;
        (*tail)->next = NULL;
    }
    free(trash);
}

void middleDeletion(Student **head, Student **tail, int target)
{
    if(*head == NULL) return;

    Student *trash = *head;

    while(trash != NULL && trash->nim != target)
    {
        trash = trash->next;
    }

    if(trash == NULL)
    {
        printf("Student with NIM %d not found\n\n", target);
        return;
    }
    
    if(trash == *head)
    {
        headDeletion(head, tail);
        return;
    }

    if(trash == *tail)
    {
        tailDeletion(head, tail);
        return;
    }

    Student *before = trash->prev;
    Student *after = trash->next;

    before->next = after;
    after->prev = before;

    free(trash);
}

void printLinkedList(Student *head)
{
    if(head == NULL)
    {
        printf("Linked list is empty\n\n");
        return;
    }

    Student *curr = head;
    while(curr != NULL)
    {
        printf("%d | %s | %s\n", curr->nim, curr->name, curr->major);
        curr = curr->next;
    }
    printf("\n");
}

int main()
{
    /*Student *head, *node, *tail;
    head = tail = NULL;

    node = (Student*) malloc(sizeof(Student));
    node->nim = 13531;
    strcopy(node->name, "Febe Febrita");
    strcopy(node->major, "Informatics");
    node->next = node->prev = NULL;
    head = node;
    tail = node;

    node = (Student*) malloc(sizeof(Student));
    node->nim = 11111;
    strcpy(node->name, "Eliel");
    strcpy(node->major, "Information Systems");
    node->next = node->prev = NULL;
    head = node;
    tail = node;

    return 0;*/

    Student *head = NULL;
    Student *tail = NULL;

    createNewNode(11111, "Febe", "Informatics", &head, &tail);
    createNewNode(22222, "Emiliio", "Electrical Engineering", &head, &tail);
    createNewNode(33333, "Valdo", "Information Systems", &head, &tail);
    createNewNode(44444, "Evan", "Engineering Physics", &head, &tail);
    createNewNode(55555, "Rio", "Computer Engineering", &head, &tail);
    createNewNode(66666, "Eliel", "Information Systems", &head, &tail);
    createNewNode(77777, "XXXXX", "Informatics", &head, &tail);
    
    printf("All data inside linked list:\n");
    printLinkedList(head);

    printf("All data after 2x head deletion:\n");
    headDeletion(&head, &tail);
    headDeletion(&head, &tail);
    printLinkedList(head);

    printf("All data after 1x tail deletion:\n");
    tailDeletion(&head, &tail);
    printLinkedList(head);

    printf("All data after middle deletion (NIM 44444):\n");
    middleDeletion(&head, &tail, 44444);
    printLinkedList(head);

    return 0;
}