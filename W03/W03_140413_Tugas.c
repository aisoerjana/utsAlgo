#include <stdio.h>
#include <string.h>

typedef struct
{
    char nim[20];
    char nama[100];
    char jurusan[30];
} mahasiswa;

typedef struct
{
    char nim[20];
    int tugas;
    int uts;
    int uas;
    float finalGrade;
    char grade[5];
} nilaiMhs;

mahasiswa mhs[100];
nilaiMhs nilai [100];
int countMhs = 0, countNilai = 0;
int i, pilihan;

float hitung (int tugas, int uts, int uas)
{
    return (tugas * 0.3) + (uts * 0.3) + (uas * 0.4);
}

char* grade (float finalGrade)
{
    if (finalGrade >= 95)      return "A+";
    else if (finalGrade >= 85) return "A";
    else if (finalGrade >= 80) return "A-";
    else if (finalGrade >= 75) return "B+";
    else if (finalGrade >= 70) return "B";
    else if (finalGrade >= 65) return "C";
    else if (finalGrade >= 60) return "C-";
    else if (finalGrade >= 55) return "D";
    else                       return "E";     
}

void baca()
{
    FILE *fpMhs = fopen ("dataMahasiswa.txt", "r");
    if (fpMhs != NULL)
    {
        while(fscanf(fpMhs, "%[^#]#%[^#]#%[^\n]\n", 
            mhs[countMhs].nim, mhs[countMhs].nama, mhs[countMhs].jurusan) == 3)
        {
            countMhs++;
        }
        fclose(fpMhs);
    }

    FILE *fpNilai = fopen ("nilaiMahasiswa.txt", "r");
    if (fpNilai != NULL)
    {
        while(fscanf(fpNilai, "%[^#]#%d#%d#%d#%f#%[^\n]\n", 
            nilai[countNilai].nim, &nilai[countNilai].tugas, &nilai[countNilai].uts, &nilai[countNilai].uas, &nilai[countNilai].finalGrade, nilai[countNilai].grade) == 6)
        {
            countNilai++;
        }    
        fclose(fpNilai);
    }
}

void tampilkanData()
{
    printf("\nDATA MAHASISWA\n\n");
    printf("NIM | NAMA | JURUSAN |\n");
    for (i=0; i<countMhs; i++)
    {
        printf("%s | %s | %s |\n", 
            mhs[i].nim, mhs[i].nama,  mhs[i].jurusan);
    }
}

void tampilkanNilai()
{
    printf("\nNILAI MAHASISWA\n\n");
    printf("NIM | TUGAS | UTS | UAS | FINAL GRADE | GRADE |\n");
    for (i=0; i<countNilai; i++)
    {
        printf("%s | %d | %d | %d | %.2f | %s |\n", 
            nilai[i].nim, nilai[i].tugas, nilai[i].uts, nilai[i].uas, nilai[i].finalGrade, nilai[i].grade);
    }
}

void inputData()
{
    mahasiswa newMhs;
    nilaiMhs newNilai;
    
    printf("\nINPUT DATA BARU\n");

    printf("NIM : ");
    scanf("%s", newMhs.nim);
    strcpy(newNilai.nim, newMhs.nim);

    printf("Nama : ");
    scanf(" %[^\n]", newMhs.nama);
    printf("Jurusan : ");
    scanf(" %[^\n]", newMhs.jurusan);
    printf("Tugas : ");
    scanf("%d", &newNilai.tugas);
    printf("UTS : ");
    scanf("%d", &newNilai.uts);
    printf("UAS : ");
    scanf("%d", &newNilai.uas);

    newNilai.finalGrade = hitung(newNilai.tugas, newNilai.uts, newNilai.uas);
    strcpy(newNilai.grade, grade(newNilai.finalGrade));
    
    // nulis datanya ke file
    FILE *appendMhs = fopen ("dataMahasiswa.txt", "a");
    if (appendMhs != NULL)
    {
        fprintf(appendMhs, "%s#%s#%s\n", 
            newMhs.nim, newMhs.nama, newMhs.jurusan); 
        fclose(appendMhs);
    }

    FILE *appendNilai = fopen ("nilaiMahasiswa.txt", "a");
    if (appendNilai != NULL)
    {
        fprintf(appendNilai, "%s#%d#%d#%d#%.2f#%s\n",
            newNilai.nim, newNilai.tugas, newNilai.uts, newNilai.uas, newNilai.finalGrade, newNilai.grade);
        fclose(appendNilai);    
    }
}

int main()
{
    
    baca();

    do
    {
        printf("\n=====DATABASE MAHASISWA=====\n");
        printf("1. Tampilkan data mahasiswa\n");
        printf("2. Tampilkan nilai mahasiswa\n");
        printf("3. Input data baru\n");
        printf("4. Keluar\n");
        printf("Pilihan : ");
        scanf("%d", &pilihan);

        switch (pilihan)
        {
            case 1:
            tampilkanData();
            break;
            case 2:
            tampilkanNilai();
            break;
            case 3:
            inputData();
            break;
            case 4:
            break;
            default:
            printf("Anda salah pilih angka");
        }
    } while (pilihan != 4);
    return 0;
}
