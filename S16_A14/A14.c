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

typedef struct indice
{
    int indice;
    Tkey llave;
}indi;

typedef struct datos
{
    int status;

    char name[30];
    char app[50];
    char apm[50];
    
    char gen[15];
    char job[30];
    char state[30];
    
    int age;
    Tkey phone;
    indi key;
} data;

//----------------------Prototipos-------------------------//
void menu();
void opci();

void new (data reg[] , int p);

//--Busqueda--//
int Tbus_sec (data vect [],int n,int num);
int Tbuscbin(data reg[], int lef, int rig, int num);

//---Archivos---//
void crear_bin (data reg[],int p);
void carg_bin (data reg[], int *p);
void crear_txt (data reg[],int p);

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
    int opci, p = 0;
    int band_ord = FALSE;
    data reg[P];
    do
    {
        menu();
        opci = valid2("Fuera de rango", 0, 8);
        switch (opci)
        {
            case 1:
            {
                if(p<P)
                {
                    new(reg,p);
                    printf("Listo\n");
                }
                else
                {
                    printf("Registros llenos\n");
                }
                getch();
            }
            case 2:
            {
                if(p>0)
                {

                }
                else
                {
                    printf("Registro vacio\n");
                    getch();
                }
            }
            case 0:
            {
                printf("Seguro que quiere salir");
            }
        }
    } while (opci != 0);
}

void new (data reg[] , int p){
    int c,i,temp;
    c=rand()%(2-1+1)+1;
    char temp[30];
    
    reg[p].key.indice = p;

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

    temp = rand() % (1000000 - 3999999 + 1) + 3999999;
    for(i=0;i<p;i++)
    {
        if(reg[i].phone==temp)
        {
            temp = rand() % (1000000 - 3999999 + 1) + 3999999;
            i=0;
        }
    }
    reg[i].phone=temp;

    temp = rand() % (399999-100000+1)+100000;
    for(i=0;i<p;i++)
    {
        if(reg[i].key.llave==temp)
        {
            temp = rand() % (399999-100000+1)+100000;
            i=0;
        }
    }
    reg[p].key.llave=temp;

    reg[p].status=1;
    crear_bin(reg, p);
}

void del (data reg[], int p, int Band_ord)
{
    int i,num,pos;
    printf("Que numero de empleado desea eliminar?\n");
    num=valid("FUERA DE RANGo",100000,399999);
    if(Band_ord==TRUE)
    {
        pos = Tbuscbin(reg,0,p-1,num);
    }
    else
    {
        pos = Tbus_sec(reg,p,num);
    }
    
    if(pos != -1)
    {

    }
    else
    {
        printf("Empleado no encontrado\n");
        getch();
    }
}

//--------------------------Busquedas--------------------------//

int Tbus_sec (data vect [],int n,int num)
{
    int i;
    for(i=0;i<n;i++)
    {
        if(vect[i].key.llave==num)
        {
            return i;
        }
    }
    return -1; 
}

int Tbuscbin(data reg[], int lef, int rig, int num) 
{
    int med;
    while (lef <= rig)
    {
        med = lef + (rig - lef) / 2;
        
        if (reg[med].key.llave == num)
        {
            return med;
        }

        if (reg[med].key.llave < num)
        {
            lef = med + 1;
        }
        else
        {
            rig = med - 1;
        }
    }
    return -1;
}

//--------------------------Archivos--------------------------//

void crear_bin (data reg[],int p)
{
    //-----------Archivo Base--------------

    int i; data temp;
    FILE *doc = fopen("base.dll","ab");
    if(doc == NULL)
    {
        printf("ERROR 404, Archivo no encontrado\n");
        getch();
    }
    else
    {
        for(i = 0;i < p ;i++)
        {
            temp=reg[p];
            fwrite(&temp,sizeof(data),1,doc);
        }
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