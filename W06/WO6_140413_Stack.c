#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>

typedef struct Student{
    char nim[13];
    char name[50];
    char major[30];

    struct Student *next;
}Student;

int isEmpty(Student *stack){
    if(stack == NULL)
        return 1;
    return 0;
}

Student* top(Student *stack){
    return stack;
}


void push(Student **stack, char nim[], char name[], char major []){
    Student *data = (Student*) malloc(sizeof(Student));
    strcpy(data->nim, nim);
    strcpy(data->name, name);
    strcpy(data->major, major);
    data->next = NULL;

    if(!isEmpty(*stack)) data->next = *stack;
    *stack = data;
    printf("Adding %s to Stack\n", name);
}

void pop(Student **stack){
    printf("Removing Stack's top element\n");

    if(*stack == NULL){
        printf("Nothing to pop. Stack already empty\n");
        return;
    }

    Student *trash = *stack;
    *stack = trash->next;
    free(trash);
    
    printf("Popping Stack Success\n");


}

int main() {
    printf("STACK TUTORIAL\n");
    printf("--------------\n\n");
    printf("Initializing Stack\n\n");

    Student *stackMhs; // stackMhs as the main Stack
    stackMhs = NULL;   // Initialize the Stack as empty

    printf("Is Stack empty? %s\n", isEmpty(stackMhs) ? "Yes" : "No");
    printf("What is the name at the top? %s\n", top(stackMhs) == NULL ? "No one. Stack is empty" : top(stackMhs)->name);

    push(&stackMhs, "11111", "Febe Febrita", "Informatics");
    printf("What is the name at the top? %s\n",
        top(stackMhs) == NULL ? "No one. Stack is empty" : top(stackMhs)->name);

    printf("Is Stack empty? %s\n\n", isEmpty(stackMhs) ? "Yes" : "No");

    pop(&stackMhs);
    printf("Is Stack empty? %s\n", isEmpty(stackMhs) ? "Yes" : "No");
    printf("What is the name at the top? %s\n",
        top(stackMhs) == NULL ? "No one. Stack is empty" : top(stackMhs)->name
    );

    push(&stackMhs, "22222", "Emilio", "Electrical Engineering");
    push(&stackMhs, "33333", "Valdo", "Information Systems");
    push(&stackMhs, "44444", "Evan", "Engineering Physics");

    printf("What is the name at the top? %s\n",
        top(stackMhs) == NULL ? "No one. Stack is empty" : top(stackMhs)->name
    );

    pop(&stackMhs);
    printf("What is the name at the top? %s\n",
        top(stackMhs) == NULL ? "No one. Stack is empty" : top(stackMhs)->name
    );

    pop(&stackMhs);
    printf("What is the name at the top? %s\n",
        top(stackMhs) == NULL ? "No one. Stack is empty" : top(stackMhs)->name
    );

    pop(&stackMhs);
    printf("\n");
    pop(&stackMhs);

    return 0;
}