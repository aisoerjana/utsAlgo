#include <stdio.h>

void hitung1 (char *word)
{
    for (int i = 0; word[i] != '\0'; i++)
        {
            if (word[i] >= 97 && word [i] <= 122)
            {
                word[i] = word[i] - 32;
            }
        }
        printf("Kata baru = %s", word);
}

void hitung2 (char *word)
{
    for (int i = 0; word[i] != '\0'; i++)
        {
            if (word[i] >= 65 && word [i] <= 90)
            {
                word[i] = word[i] + 32;
            }
        }
        printf("Kata baru = %s", word);
}

void hitung3 (char *word)
{
      for (int i = 0; word[i] != '\0'; i++)
        {
        if (word[i] >= 97 && word[i] <= 122)
            {
            word[i] = word[i] - 32;
            }
        else if (word[i] >= 65 && word[i] <= 90)
            {
            word[i] = word[i] + 32;
            }
    }
    printf("Kata baru = %s", word);
}

int main()
{
    int pilihan;
    char word[100];

    do
    {
        printf("\n1. Uppercase\n");
        printf("2. Lowercase\n");
        printf("3. Switching\n");
        printf("4. Keluar\n");
        
        printf("Pilihan : ");
        scanf("%d", &pilihan);

        if (pilihan == 1)
        {
        printf("Masukkan kata: ");
        scanf(" %[^\n]", word);
        hitung1 (word);
        }

        if (pilihan == 2)
        {
            printf("Masukkan kata: ");
            scanf(" %[^\n]", word);
            hitung2 (word);
        }

        if (pilihan == 3)
        {
            printf("Masukkan kata: ");
            scanf(" %[^\n]", word);
            hitung3 (word);
        }
    } while (pilihan != 4);
    return 0;
}