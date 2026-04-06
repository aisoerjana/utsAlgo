#include <stdio.h>
#define MAXSTUDENT 20

typedef struct {
    char Name[100];
    char Major[30];
    float Gpa;
} mhsStruct;

mhsStruct mhs[MAXSTUDENT];
int jumlah = 0;

void function1 ()
{
    if (jumlah == 0)
            printf("\nYou have not input anything\n");
    else
    {
        printf("               List of Student Information\n");
        printf("--------------------------------------------------------\n");
        printf("|  No.  |          Name         |    Major      | GPA  |\n");
        printf("--------------------------------------------------------\n");
        for (int i=0; i < jumlah; i++)
        {
                printf("| %-2d\t| %-18s\t| %-13s\t| %.2f |\n", i+1, mhs[i].Name, mhs[i].Major, mhs[i].Gpa);
        }
    }
}

void function2 ()
{
    if (jumlah < MAXSTUDENT)
    {
        printf("Insert Student Information\n");
        printf("---------------------------\n");
        printf("Name   : ");
        scanf(" %[^\n]", mhs[jumlah].Name);
        printf("Major  : ");
        scanf(" %[^\n]", mhs[jumlah].Major);
        printf("GPA    : ");
        scanf("%f", &mhs[jumlah].Gpa);
        jumlah++;
        printf("\nInserting data...\n");
        printf("New students added\n");
    }
    else
        printf("Database is full");
}

int main()
{
    int pilihan;
    do
    {
    printf("\nWelcome to simple student database (%d/20) [AB]\n", jumlah);
    printf("1. Show all students\n");
    printf("2. Input new students\n");
    printf("3. Exit\n");
    printf("Choose: ");
    scanf("%d", &pilihan);

    switch (pilihan)
    {
        case 1:
        function1 ();
        break;
    
        case 2:
        function2 ();
        break;
        
        case 3:
        printf("Thank you!\n");
        printf("[AB]");
        break;

        default:
        printf("\nSalah pilih angka!\n");
        break;
    }

    } while (pilihan != 3);
    return 0;
}

// [AB]