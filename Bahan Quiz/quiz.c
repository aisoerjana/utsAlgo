#include <stdio.h>
#include <string.h>

typedef struct
{
    char judul[100];
    char sutradara[100];
    int tahun;
    int menit;
    float rating;
} film;

film list[100];
int count = 0;

void baca()
{
    count = 0;
    FILE *file = fopen("film.txt", "r");
    if (file != NULL)
    {
        while(fscanf(file, "%[^#]#%[^#]#%d#%d#%f\n",
            list[count].judul, list[count].sutradara, &list[count].tahun, &list[count].menit, &list[count].rating) == 5)
            {
                count++;
            }
            fclose(file);
    }
}

void tampilkan()
{
    int i;
    printf("\n===== Daftar Film =====\n");
    for(i=0; i<count; i++)
    {
        printf("%d. %s - %s (%d) [%d menit] Rating : %.1f\n",
            i+1, list[i].judul, list[i].sutradara, list[i].tahun, list[i].menit, list[i].rating);
    }
}

void tambah()
{
    if (count >= 100)
    {
        printf("Data film sudah penuh!\n");
        return;
    }

    film baru;
    printf("Judul : ");
    scanf(" %[^\n]", baru.judul);
    printf("Sutradara : ");
    scanf(" %[^\n]", baru.sutradara);
    printf("Tahun : ");
    scanf(" %d", &baru.tahun);
    printf("Menit : ");
    scanf(" %d", &baru.menit);
    printf("Rating : ");
    scanf(" %f", &baru.rating);

    list[count] = baru;
    count++;
    
    FILE *file = fopen("film.txt", "a");
    if (file != NULL)
    {
        fprintf(file, "%s#%s#%d#%d#%.1f\n", 
            baru.judul, baru.sutradara, baru.tahun, baru.menit, baru.rating);
    }
    fclose (file);
}

void cari()
{
    int tahun, i, ketemu = 0;
    printf("\nMasukkan tahun film : ");
    scanf("%d", &tahun);

    printf("\n=====Hasil search film tahun %d=====\n", tahun);
    for (i=0; i<count; i++)
    {
        if (list[i].tahun == tahun)
        {
            printf("%s - %s (%d) [%d] Rating : %.1f\n", list[i].judul, list[i].sutradara, list[i].tahun, list[i].menit, list[i].rating);
            ketemu++;
        }
    }
    if (ketemu == 0)
    {
        printf("Tidak ada film dari tahun %d\n", tahun);
    }
}

void update()
{
    int i=0;
    char rateJudul[100];
    printf("Masukkan judul film : ");
    scanf(" %[^\n]", rateJudul);

    
    for(i=0; i<count; i++)
    {
        if (strcmp(rateJudul, list[i].judul) == 0)  
        {
            if(list[i].rating + 0.5 > 10.0)
            {
                list[i].rating = 10.0;
                printf("\nRating berhasil diupdate");
            }
            else if (list[i].rating + 0.5 != 10)
            {
                list[i].rating += 0.5;
                printf("\nRating berhasil diupdate");
            }
        }   
    }

    FILE *file = fopen("film.txt", "w");
    if (file != NULL)
    {
        for (i = 0; i < count; i++)
        {
            fprintf(file, "%s#%s#%d#%d#%.1f\n",
                list[i].judul, list[i].sutradara, list[i].tahun, list[i].menit, list[i].rating);
        }
        fclose(file);
    }
}

int main()
{
    int pilihan;
    baca();

    do
    {
        printf("\n===== Database Film =====\n");
        printf("1. Tampilkan Film\n");
        printf("2. Tambah Film\n");
        printf("3. Cari Film by Tahun\n");
        printf("4. Update Rating\n");
        printf("5. Keluar\n");
        printf("Pilih: ");
        scanf("%d", &pilihan);

        switch (pilihan)
        {
            case 1: 
            tampilkan();   
            break;
            
            case 2: 
            tambah();  
            break;
            
            case 3: 
            cari();    
            break;
            
            case 4: 
            update(); 
            break;
            
            case 5: 
            printf("Keluar\n"); 
            break;
            
            default: 
            printf("Anda salah pilih angka\n");
        }
    } while (pilihan != 5);
    return 0;
}
