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

    // Prepare a temporary variable to delete memory
    Student*temp;

    temp = head;            // Store node to be deleted
    head = head->next;      // Move head to the next node
    free(temp);             // Free the old head from memory

    printf("Data AFTER deletion\n");
    printLinkedList(head);

    return 0;
}