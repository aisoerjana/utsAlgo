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

int main()
{
    // #2 Prepare the head (pointer) and a node for Linked list
    Student *head, *node;

    // #3 Always initialize head as NULL
    head = NULL;

    // #4 Allocate memory for a new node
    // Memory must be allowed first before filling the data
    node = (Student*) malloc(sizeof(Student));

    // #5 Insert data into the node
    // There are two ways to insert data;
    // 1. Store data into a temporary variable first, then assign it to the node
    // 2. Directly insert the data into the node

    node->nim = 13531;
    strcpy(node->name, "Febe Febrita");
    strcpy(node->major, "Informatics");

    // #6 IMPORTANT PART
    // Always set node->next to NLL
    // Do this every time you create a new node
    node->next = NULL;

    // #7 After creating the first node, connect it to head
    head = node;

    // The first node in the Linked list has been successfully created
    return 0;
}