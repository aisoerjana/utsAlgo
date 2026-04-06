#include <stdio.h>

typedef struct
{
    char judul[100];
    int five;
    int four;
    int three;
    int two;
    int one;
    float rate;
    int total;
} film;

film list[3];

float hitungRate(int five, int four, int three, int two, int one)
{   
    return (float)((five * 5) + (four * 4) + (three * 3) + (two * 2) + (one * 1)) / (five + four + three + two + one);
}

float hitungTotal(int five, int four, int three, int two, int one)
{
    return (five + four + three + two + one);
}

int main()
{
    int i;
    int count = 0;

    FILE *file = fopen ("reviews.txt", "r");
    if (file != NULL)
    {
        while(fscanf(file, "%[^#]#%d#%d#%d#%d#%d\n",
            list[i].judul, &list[i].five, &list[i].four, &list[i].three, &list[i].two, &list[i].one) == 6)
        {
            i++;
        }
        fclose(file);
    }
    
    for(i=0; i<3; i++)
    {
        list[i].total = hitungTotal(list[i].five, list[i].four, list[i].three, list[i].two, list[i].one);
        list[i].rate = hitungRate(list[i].five, list[i].four, list[i].three, list[i].two, list[i].one);
        printf("\n%s\n%.2f out of 5\n%d global ratings\n", list[i].judul, list[i].rate, list[i].total);
    }
    return 0;
}