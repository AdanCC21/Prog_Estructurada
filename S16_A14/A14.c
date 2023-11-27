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

typedef struct indice
{
    int indice;
    Tkey llave;
}indi;

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

//----------------------Prototipos-------------------------//
void menu();
void opci();

void new (data reg[] , int p,indi indice[]);
void del (data reg[], int p, indi indice[], int *Band_ord);

void prin (data reg[], int p, indi indice[]);

//--Busqueda--//
int Tbus_sec (indi vect [],int n,int num);
int Tbuscbin(indi reg[], int lef, int rig, int num);

//---Archivos---//
void crear_bin (data reg[],int p);
void carg_bin (data reg[], indi indice [],int *p);
void crear_txt (data reg[],int p);

int cont_reg(char name[]);

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
    printf("9.-Calale\n");
    printf("0.-Salir\n");
}

void opci()
{
    int opci,elim,bus, bpos, p = 0, P;
    int band_ord = FALSE;

    P = cont_reg("datos");
    P *=1.25;
    
    data reg[P];
    indi indice[P];
    //carg_bin(reg,indice,&p);

    system("PAUSE");

    do
    {
        system("CLS");
        menu();
        opci = valid("Fuera de rango", 0, 9);
        switch (opci)
        {
            case 1:
            {
                if(p<P)
                {
                    new(reg, p, indice);
                    p++;
                    printf("Listo\n");
                }
                else
                {
                    printf("Registros llenos\n");
                }
                getch();
                break;
            }
            case 2:
            {
                if(p>0)
                {
                    printf("Seguro de querer eliminar un empleado?\n1.-Si, Eliminar\t2.-No, Salir\n");
                    elim = valid("FUERA DE RANGO",1,2);
                    if(elim==1)
                    {
                        del(reg,p,indice, &band_ord);
                    }
                    else
                    {
                        printf("Arre\n");
                        getch();
                    }
                }
                else
                {
                    printf("Registro vacio\n");
                    getch();
                }
                break;
            }
            case 3: //Modificar para archivo binario //Modificar para archivo binario //Modificar para archivo binario //Modificar para archivo binario
            {
                if(p<0)
                {
                    printf("Registros vacios\n");
                }                
                else
                {
                    printf("Ingrese el No.Empleado que desea buscar\n");
                    bus=valid("FUERA DE RANGO",100000,399999);

                    if(band_ord == TRUE)
                    {
                        bpos = Tbuscbin(indice,0,p-1,bus);
                        if(bpos!=-1)
                        {
                            printf("Su empleado se encuentra en la posicion : %d\n",bpos);
                        }
                        else
                        {
                            printf("Empleado no encontrado\n");
                        }
                    }
                    else
                    {
                        bpos = Tbus_sec(indice,p,bus);
                        if(bpos!=-1)
                        {
                            printf("Su empleado se encuentra en la posicion : %d\n",bpos);
                        }
                        else
                        {
                            printf("Empleado no encontrado\n");
                        }
                    }
                    getch();
                }
                break;
            }
            case 9:
            {
                prin(reg,p,indice);
                break;
            }
            case 0:
            {
                printf("Seguro que quiere salir\n1.-Salir\t2.-Repetir\n");
                opci = valid("FUERA DE RANGO",1,2);
                opci--;
            }
        }
    } while (opci != 0);
}

void new (data reg[] , int p, indi indice[])
{
    char temp[30];
    int c,i,tempN;
    c=rand()%(2-1+1)+1;

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

    tempN = rand() % (1000000 - 3999999 + 1) + 3999999;
    for(i=0;i<p;i++)
    {
        if(reg[i].phone==tempN)
        {
            tempN = rand() % (1000000 - 3999999 + 1) + 3999999;
            i=0;
        }
    }
    reg[i].phone=tempN;

    tempN = rand() % (399999-300000+1)+300000;
    for(i=0;i<p;i++)
    {
        if(reg[i].enrollment==tempN)
        {
            tempN = rand() % (399999-300000+1)+300000;
            i=0;
        }
    }
    reg[p].enrollment=tempN;

    reg[p].status=1;

    indice[p].indice=p;
    indice[p].llave = reg[p].enrollment;

    crear_bin(reg,p);
}

void del (data reg[], int p, indi indice[], int *Band_ord) //Modificar para archivo binario
{
    int num,pos;
    
    printf("Que numero de empleado desea eliminar?\n");
    num=valid("FUERA DE RANGo",100000,399999); //----------------Modificar al data del profe -----------------------//
    
    if(*Band_ord==TRUE)
    {
        pos = Tbuscbin(indice,0,p-1,num);
    }
    else
    {
        pos = Tbus_sec(indice,p,num);
    }
    
    if(pos != -1)
    {
        reg[pos].status=0;
        *Band_ord=FALSE;
        printf("Listo\n");
        getch();
    }
    else
    {
        printf("Empleado no encontrado\n");
        getch();
    }
}

//--------------------------Busquedas--------------------------//

int Tbus_sec (indi vect [],int n,int num)
{
    int i;
    for(i=0;i<n;i++)
    {
        if(vect[i].llave==num)
        {
            return i;
        }
    }
    return -1; 
}

int Tbuscbin(indi reg[], int lef, int rig, int num) 
{
    int med;
    while (lef <= rig)
    {
        med = lef + (rig - lef) / 2;
        
        if (reg[med].llave == num)
        {
            return med;
        }

        if (reg[med].llave < num)
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

//--------------------------Iprimir--------------------------//
void prin (data reg[], int p, indi indice[])
{
    int i;
    printf("%-2s %-15s %-15s %-15s %-15s %-15s %-10s %-10s %-10s\n","Pos.","No.Empleado","Nombre","Ap. PAT","Ap. MAT","Job","Genero","Estado","No.Celular");
    for (i=0;i<p;i++)
    {
        if(reg[i].status==1)
        {
            printf("%-5d %-15d %-15s %-15s %-15s %-15s %-10s %-10s %-10d\n",indice[i].indice, indice[i].llave, reg[i].name,reg[i].app,reg[i].apm,reg[i].job,reg[i].gen,reg[i].state, reg[i].phone);
        }
    }
    system("PAUSE");
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
            temp=reg[i];
            fwrite(&temp,sizeof(data),1,doc);
        }
    }

    fclose(doc);
}

void carg_bin (data reg[], indi indice [], int *p)
{
    int i = 0;
    data temp;
    FILE *doc;

    doc = fopen("datos.dat","rb");
    if(doc)
    {
        while(fread(&temp,sizeof(data), 1 ,doc))
        {
            if(temp.status==1)
            {
                reg[i]=temp;
                indice[i].llave=reg[i].enrollment;
                indice[i].indice=i;
                i++;
                (*p)++;
            }
        }
        fclose(doc);
    }
}

int cont_reg(char name[])
{
    int c;
    char cmd[50];
    
    system("gcc.exe Rcontador.c -o Rcontador");
    sprintf(cmd,"Rcontador.exe %s", name);
    c = system(cmd);

    return c;
}
