#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// #1 Prepare the data structure for Linked list
typedef struct Student
{
    char name[100];
    char major[30];
    int nim;

    // "next" is used to point to the next code
    struct Student *next;
} Student;

void printLinkedList(Student *head)
{
    Student *current = head;

    while(current != NULL)
    {
        printf("Student ID  : %d\n", current->nim);
        printf("Name        : %s\n", current->name);
        printf("Major       : %s\n", current->major);
        printf("--------------------------\n");

        current = current->next;

    }
}

Student* createNewNode(int id, char name[], char major[])
{
    Student *newNode = (Student*) malloc(sizeof(Student));

    newNode->nim = id;
    strcpy(newNode->name, name);
    strcpy(newNode->major, major);
    newNode->next = NULL;

    return newNode;
}

int main()
{
    
    Student *head, *node;
    head = NULL;

    node = (Student*) malloc(sizeof(Student));

    node->nim = 13531;
    strcpy(node->name, "Febe Febrita");
    strcpy(node->major, "Informatics");
    node->next = NULL;

    head = node;

    // The code above is from Tutorial 1.1

    // #1 Add "tail" pointer to track the last node
    Student *tail;
    tail = node;

    // #2 Create a new node using createNewNode()
    node = createNewNode(11111, "Eliel", "Information Systems");

    // #3 Insert at BACK
    tail->next = node;  // Connect last node to new node
    tail = node;        // Move tail to the newest node

    // #4 Insert at FRONT
    node = createNewNode(22222, "Devi", "Informatics");
    node->next = head;  // New node points to current head
    head = node;        // Move head to the new node

    printf("Data BEFORE deletion\n");
    printLinkedList(head);

    // The goal is to delete the node with name "Febe Febrita"
    Student*temp, *prev;
    // temp : pointer for deleting memory
    // prev : pointer to reconnect the Linked List

    temp = head;
    
    // Iterate until the node BEFORE the target node
    while(strcmp(temp->next->name, "Febe Febrita") != 0)
    {
        // Stop when temp->next is the target node
        printf("%s\n", temp->name);
        temp = temp->next;
    }
    
    // Check whether the node to delete is head or not
    if(temp->nim == head->nim)
        printf("true\n");
    else   
        printf("false\n");

    prev = temp;            // Save current position
    temp = temp->next;      // Move temp to the node to delete
    prev->next = temp->next; // Connect previous node to node after target
    temp->next = NULL;      // Disconnect target node
    free(temp);             // Free memory

    printf("Data AFTER deletion\n");
    printLinkedList(head);

    return 0;
}