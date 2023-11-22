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

void AutoGen(data alu[], int p)
{
    int c, mat;
    c = rand() % (2 - 1 + 1) + 1;
    char name[30], ap[30], apm[30], gen[15], puest[30];

    li_nombres(name, c);
    strcpy(alu[p].name, name);

    li_apellidos(ap);
    strcpy(alu[p].app, ap);

    li_apellidos(apm);
    strcpy(alu[p].apm, apm);

    li_generos(gen);
    strcpy(alu[p].gen, gen);

    alu[p].age = rand() % (50 - 17 + 1) + 17;

    li_puestos(puest);
    strcpy(alu[p].JobP, puest);

    mat = rand() % (399999 - 300000 + 1) + 300000;
    alu[p].enrollement = mat;

    alu[p].status = 1;
}
