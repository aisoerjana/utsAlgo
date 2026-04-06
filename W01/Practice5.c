    #include <stdio.h>

    void pemisah(int *angka, int size)
    {
        int i;
        int ganjil[10], genap[10];
        int jmlGanjil = 0, jmlGenap = 0;

        for (i=0; i<size; i++)
        {
            if (angka[i] % 2 == 0)
            {
                genap[jmlGenap] = angka[i];
                jmlGenap++;
            }
        }

        for (i=0; i<size; i++)
        {
            if (angka[i] % 2 == 1)
            {
                ganjil[jmlGanjil] = angka[i];
                jmlGanjil++;
            }
        }

        printf("\nGenap  : ");
        for (i = 0; i < jmlGenap; i++)  // ✅
        printf("%d ", genap[i]);

        printf("\nGanjil : ");
        for (i = 0; i < jmlGanjil; i++)  // ✅
        printf("%d ", ganjil[i]);
    }

    int main()
    {
        int i, angka[10];

        printf("Masukkan 10 angka : ");
        for (i = 0; i < 10; i++)
        {
            scanf("%d", &angka[i]);
        }
        printf("Output : ");
        pemisah(angka, 10);
        return 0;
    }