#include <stdio.h>
#include <string.h>

typedef int Tkey;

typedef struct datos
{
    int status;
    Tkey enrollment;

    char name[30];
    char app[50];
    char apm[50];
    
    char gen[15];
    char job[30];
    char state[30];
    
    int age;
    Tkey phone;
} data;

int main(int arg, char *args[])
{
    FILE *fa;
    char archivo[50];
    int num;
    

    strcpy(archivo, args[1]);
    strcat(archivo, ".dat");

    fa = fopen(archivo, "r");
    if(fa)
    {
        fseek(fa, 0, SEEK_END);
        int tamano = ftell(fa);
        num = tamano / sizeof(data);
        fclose(fa);
        
        return num;
    }
    else
    {
        printf("no se encontro el archivo %s.dat\n", args[1]);
    }

    return 0;
}