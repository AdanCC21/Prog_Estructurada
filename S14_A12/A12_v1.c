/*
    Gonzalez Cesena Adan 372799

    1.- Cargar Archivo : El programa deberá cargar el vector de registros desde el archivo de texto (solo podrá cargarse una sola vez el archivo)
    2.- Agregar : El programa deberá ser capaz de agregar un 10 registros al arreglo y al final del archivo de texto.  (Generar automáticamente los datos).
    3.- Eliminar : El programa deberá buscar una matrícula en el vector por medio del método de búsqueda más óptimo. Utilizar banderas para escoger el método más adecuado., imprimir el registro y preguntar si se quiere eliminar el registro, (al cerrar el programa se deberar agregar al archivo borrados el registro o registros eliminados, asi se debera mantener dos archivos uno con datos validos y otro con los datos que se borraron)
    4.- Buscar : El programa deberá buscar una matrícula en el vector por medio del método de búsqueda más óptimo. Utilizar banderas para escoger el método más adecuado. Mostrar los datos en forma de registro
    5.- Ordenar : El programa deberá ordenar el vector por medio del método de ordenación más óptimo. Utilizar banderas para escoger el método más adecuado se ordenará por el campo llave (matrícula)
    6.- Mostrar Todo: El programa deberá mostrar todos los registros del vector tal y como están en ese momento ordenado o desordenado. (mostrar en forma de tabla, y de 40 en 40)
    7.- Generar Archivo : El programa deberá preguntar al usuario el nombre del archivo,  solo nombre sin extensión, el programa generará un archivo con el nombre proporcionado por el usuario con extensión .txt los datos que pondrá en el archivo de texto serán idénticos a los contenidos en el Vector de registros. (ordenado o desordenado). El programa podrá generar múltiples archivos para comprobar las salidas. 
    
    Actv_12_07/11/2023
    */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "libad.h"
#include "list.h"

#define P 1500

typedef struct alumnos
{
    char name[30];
    char name2[30];
    char app[30];
    char apm[30];

    int stat;
    int mat;
    int gen;
    int edad;

}alu;

//      Prototipos       //
void menu ();
void opci ();

void carg ();

void agr_ale (alu alum[],int p);

int eliminacion (alu dat[],int pu);
int eliminacion_bin (alu dat[],int pu);

int buscsec(alu alumno[], int p, int num);
int buscbin(alu alumno[], int lef, int rig, int num);

void ordenarB (alu alumno[], int n);

void swap(alu students[], int i, int j);
int partition(alu students[], int low, int high);
void quicksort(alu students[], int low, int high);

void print (alu reg[], int p);

void gen (alu reg[], int p);
void cont (alu reg[]);
void genB (alu reg[]);


//          Main        //
int main ()
{
    opci();
    return 0;
}

//      Funciones       //
void menu ()
{
    printf("\tMENU\n");
    printf("1-Cargar Archivo\n");
    printf("2-Agregar\n");
    printf("3-Eliminar\n");
    printf("4-Buscar\n");
    printf("5-Ordenar\n");
    printf("6-Mostrar Todo\n");
    printf("7-Generar Archivo\n");
    printf("8-Cantidad de registros en un archivo\n");
    printf("9-Mostrar Borrados\n");
    printf("0-Salir\n");
}

void opci()
{
    alu reg [P];
    int op,pu,el;
    int ord,num,bus,left,righ;
    int i;
    pu=0;
    do
    {
        system("CLS");
        menu();
        op=valid2("Fuera de rango",0,9);
        switch(op)
        {
            case 1:
                pu++;
                break;
            case 2:
                for(i=0;i<10;i++)
                {
                    agr_ale(reg,pu);
                    pu++;
                }
                ord=1;
                
                printf("10 registros agregados\n");
                system("PAUSE");
                break;
            case 3:
            //  ------Agregar un archivo con los registros eliminados------ //
            
                if(pu>0)
                {
                    printf("Seguro que quiere eliminar un registro?\n1.-Si, Eliminar\t2.-No, Salir\n");
                    el=valid2("Fuera de rango",1,2);
                    if(el==1)
                    {
                        if(pu<500)
                        {
                            pu=eliminacion(reg,pu);
                            printf("Hecho\n");
                            ord=1;
                            system("PAUSE");
                        }
                        else
                        {
                            pu=eliminacion_bin(reg,pu);
                            printf("Hecho\n");
                            ord=1;
                            system("PAUSE");
                        }
                    }
                }
                else
                {
                    printf("Lista vacia\n");
                    system("PAUSE");
                }
                
                break;
            case 4:
                if(pu==0)
                {
                    printf("lista vacia\n");
                }
                else
                {
                    if(ord==0)
                    {
                        printf("Metodo de secuencial\n");
                        num=valid("Ingrese la matricula",300000,399999);
                        bus=buscsec(reg,pu,num);

                        if(bus==-1)
                        {
                            printf("No se encontro la matricula\n");
                        }
                        else
                        {
                            printf("La matricula se encuentra en la posicion %d \n", bus+1);
                            print(reg,bus);
                        }
                    }
                    else
                    {
                        printf("Busqueda binaria\n");
                        num=valid("Ingrese la matricula",300000,399999);
                        left=0;
                        righ=pu;
                        
                        bus=buscbin(reg,left, righ, num);
                        if(bus==-1)
                        {
                            printf("No se encontro la matricula\n");
                        }
                        else
                        {
                            printf("La matricula se encuentra en la posicion %d \n", bus+1);
                            print(reg,bus);
                        }
                    }
                }
                system("PAUSE");

                break;
            case 5:

                break;
            case 6:
                printf("%-5s %-10s %-15s %-15s %-15s %-15s %-10s %-10s %-10s\n","No","Matricula","Nombre","S-Nombre","Ap Pat","Ap Mat","Edad","Gen","Status");
                for(i=0;i<pu;i++)
                {
                    print(reg,i);
                }
                system("PAUSE");
                break;
            case 7:
                break;
            case 8:

                break;
            case 9:

                break;
            case 0:
                printf("Seguro que quiere salir?\n1-Salir 2-Repetir\n");
                op=valid2("Fuera de rango\n",1,2);
                if(op==1)
                {
                    op=0;
                }
        }
    }
    while(op!=0);
    printf("Buen dia\n");
}

void agr_ale (alu alum[],int p)
{
    int c,z,mat,n;
    c=rand()%(2-1+1)+1;
    char name[30],ap[30],apm[30];

        li_nombres(name,c);
        strcpy(alum[p].name,name);

        li_nombres(name,c);
        strcpy(alum[p].name2,name);

        do
        {
            if(alum[p].name==alum[p].name2)
            {
                li_nombres(name,c);
                strcpy(alum[p].name2,name);
                n=1;
            }
            else
            {
                n=0;
            }
        }
        while(n!=0);

        li_apellidos(ap);
        strcpy(alum[p].app,ap);

        li_apellidos(apm);
        strcpy(alum[p].apm,apm);

        alum[p].gen=c;

        int age;
        age=rand()%(30-18+1)+18;
        alum[p].edad=age;

        z=rand()%(1-0+1)+0;
        alum[p].stat=z;

        mat=rand()%(399999-300000+1)+300000;
        alum[p].mat=mat;
}

//  ------ Elimanacion ------- //
int eliminacion (alu dat[],int pu)
{
    int i,pe,po;
    printf("Ingrese la matricula que desea eliminar");
    pe=valid2("Fuera de rango (300000 - 399999)",300000,399999);

    po=buscsec(dat,pu,pe);
    if(po!=-1)
    {
        for(i=po;i<pu;i++)
        {
            dat[i]=dat[i+1];
        }
        pu--;
    }
    else
    {
        printf("Matricula no encontrada\n");
    }
    return pu;
}

int eliminacion_bin (alu dat[],int pu)
{
    int i,pe,po;
    printf("Ingrese la matricula que desea eliminar");
    pe=valid2("Fuera de rango (300000 - 399999)",300000,399999);

    po=buscbin(dat,0,pu,pe);
    if(po!=-1)
    {
        for(i=po;i<pu;i++)
        {
            dat[i]=dat[i+1];
        }
        pu--;
    }
    else
    {
        printf("Matricula no encontrada\n");
    }
    return pu;
}

//  ------  Busqueads ------- //
int buscsec(alu alumno[], int p, int num)
{
    int i;
    for(i=0;i<=p;i++)
    {
        printf("\nA %d %d %d\n",num,i,p);

        if(alumno[i].mat==num)
        {
            return i;
        }
    }
    return -1;
}

int buscbin(alu alumno[], int lef, int rig, int num) 
{
    int med;
    while (lef<=rig)
    {
        med=lef + (rig - lef) / 2;
        
        if(alumno[med].mat==num)
        {
            return med;
            lef=rig+1;
        }
        if(alumno[med].mat< num)
        {
            lef= med+1;
        }
        if(alumno[med].mat > num)
        {
            rig=med-1;
        }
    }
    return -1;
}

//  ------  Ordenar ------- //
void ordenarB (alu alumno[], int n)
{
    int i,j;
    alu temp;
    for(j=0;j<n;j++)
    {
        for(i=j+1;i<n;i++)
        {
            if(alumno[j].mat>alumno[i].mat)
            {
                temp=alumno[i];
                alumno[i]=alumno[j];
                alumno[j]=temp;
            }
        }
    }
}

//  ------Quicksort------- //
void swap(alu students[], int i, int j)
{
    alu temp = students[i];
    students[i] = students[j];
    students[j] = temp;
}

int partition(alu students[], int low, int high)
{
    alu pivot;
    pivot.mat = students[high].mat;
    int i = low - 1;

    for (int j = low; j <= high - 1; j++)
    {
        if (students[j].mat <= pivot.mat)
        {
            i++;
            swap(students, i, j);
        }
    }
    swap(students, i + 1, high);
    return i + 1;
}

void quicksort(alu students[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(students, low, high);

        quicksort(students, low, pi - 1);
        quicksort(students, pi + 1, high);
    }
}

//  ------  Print   ------- //
void print (alu reg[], int p)
{
    char cad[7];
    if(reg[p].gen==1)
    {
        strcpy(cad,"HOMBRE");
    }
    else
    {
        strcpy(cad,"MUJER");
    }
    printf("%-5d %-10d %-15s %-15s %-15s %-15s %-10d %-10s %-10d\n", p+1 , reg[p].mat , reg[p].name , reg[p].name2 , reg[p].app , reg[p].apm , reg[p].edad , cad , reg[p].stat);
}



