#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include "libad.h"
#include "list.h"

#define TRUE 1
#define FALSE 0

//-----------------------Structs---------------------------//

typedef int Tkey;

typedef struct datos
{
    int status;
    Tkey enrollement;

    char name[30];
    char app[50];
    char apm[50];
    char gen[15];

    char JobP[30];
    char state[30];
    int age;

    Tkey phone;
} data;

//----------------------Prototipos-------------------------//
void menu();
void opci();

//-------------------------Main----------------------------//
int main()
{
    opci();
    return 0;
}

//---------------------Funciones---------------------------//

void menu()
{
    printf("MENU\n");
    printf("1.-AGREGAR\n");
    printf("2.-ELIMINAR\n");
    printf("3.-Buscar\n");
    printf("4.-Ordenar\n");
    printf("5.-Imprimir Registros (Archivo Original)\n");
    printf("6.-Imprimir Registros (Archivo Ordenado)\n");
    printf("7.-Generar Archivo De Texto\n");
    printf("8.-Empaquetar\n");
    printf("0.-Salir\n");
}

void opci()
{
    int opci;
    do
    {
        menu();
        opci = valid2("Fuera de rango", 0, 8);
        switch (opci)
        {
            case 1:
            {
            }
            case 0:
            {
                printf("Seguro que quiere salir");
            }
        }
    } while (opci != 0);
}

void new (data reg , int p)
{
    
}