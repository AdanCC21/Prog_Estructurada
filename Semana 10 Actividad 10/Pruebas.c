#include <stdio.h>
#include <string.h>


typedef struct alumn
{
    char nombre[30];
    char app[30];
    char apm[30];
    int mat;
    int age;
    char sex[10];
    int status;
} Taulum;

Taulum ale(Taulum alumno[],int i);

int main() 
{
    int i;
    Taulum registro[20];
    for(i=0;i<10;i++)
    {
        registro[i] = ale(registro,i);
        
    }

}

Taulum ale(Taulum alumno[],int i)
{
    strcpy(alumno[i].nombre,"JUAN");
    printf("%s \n",alumno[i].nombre);
}
