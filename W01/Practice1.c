#include <stdio.h>

void cetak (int *arr, int size)
{
    int i;
    for (i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
}

int main()
{
    int arr[5];
    int i;

    printf("\nInput 5 angka : ");
    for (i = 0; i < 5; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Output : ");
    cetak(arr, 5);
    return 0;
}