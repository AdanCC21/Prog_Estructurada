#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

#include "libad.h"
#include "list.h"

#define P 5000

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
    char job[30];
    char state[30];
    
    int age;
    Tkey phone;
} data;

//----------------------Prototipos-------------------------//
void menu();
void opci();

void new (data reg[], int p);

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

void new (data reg[] , int p)
{
    int c;
    c=rand()%(2-1+1)+1;
    char temp[30];
    
    li_nombres(temp,c);
    strcpy(reg[p].name,temp);

    li_apellidos(temp);
    strcpy(reg[p].app,temp);

    li_apellidos(temp);
    strcpy(reg[p].apm,temp);

    li_generos(temp);
    strcpy(reg[p].gen,temp);

    li_puestos(temp);
    strcpy(reg[p].job,temp);

    li_estados(temp);
    strcpy(reg[p].state, temp);

    reg[p].age = rand()%(30-17+1)+17;

    reg[p].phone = rand() % (1000000 - 3999999 + 1) + 3999999;

    reg[p].enrollement = rand() % (399999-300000+1)+300000;;

    reg[p].status=1;
    crear_bin(reg, p);
}

void crear_bin (data reg[],int p)
{
    //-----------Archivo Base--------------

    int i; data temp;
    FILE *doc = fopen("base.dll","ab");
    for(i = 0;i < p ;i++)
    {
        temp=reg[p];
        fwrite(&temp,sizeof(data),1,doc);
    }
    fclose(doc);
}

void carg_bin (data reg[], int *p)
{
    int i,op;
    FILE *doc;
    printf("Desea importar el archivo ordenado o el archivo base\n1.-Ordenaro\t2.-Base");
    op = valid("FUERA DE RANGO",1,2);

    if(op==1)
    {
        fopen("bin_ordenado.dll","rb");
        if(doc)
        {
            data temp;
            while(fread(&temp,sizeof(data), 1 ,doc))
            {
                if(((*p)+1) <= P)
                {
                    reg[(*p)++]=temp;
                }
            }
            printf("Registros cargado\n");
            system("PAUSE");
        }
        else
        {
            printf("Archivno no econtrado o no generado\n");
        }
    }
    else
    {
        fopen("bin_base.dll","rb");
        if(doc)
        {
            data temp;
            while(fread(&temp,sizeof(data), 1 ,doc))
            {
                if(((*p)+1) <= P)
                {
                    reg[(*p)++]=temp;
                }
            }
            printf("Registros cargado\n");
            system("PAUSE");
            
        }
        else
        {
            printf("Archivno no econtrado o no generado\n");
        }
    }
}

void crear_txt (data reg[],int p)
{
    int i;
    FILE *doc;
}