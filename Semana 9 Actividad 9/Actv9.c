/*Gonzalez Ceseña Adan 372799

Actividad 9
1.- LLENAR VECTOR .-  Llenar vector con 15 números, los números generados aleatoriamente, los números entre el rango de 100 al 200 (no repetidos)
2.- LLENAR MATRIZ .- Llenar la matriz de 4x4 con con números generados aleatoriamente, números entre el rango de 1 al 16  (no repetidos)
3.- IMPRIMIR VECTOR .- Imprime el vector que se envíe, donde la función recibe como parámetro el vector,tamaño, nombre del vector.
4.- IMPRIMIR MATRIZ.-  Imprime la matriz sin importar el tamaño de la matriz recibiendo como parámetros la matriz, la cantidad de renglones y columnas, así como nombre que se le dará a la matriz
5.- ORDENAR VECTOR.- Usar función que ordene el vector por el método de ordenación de la Burbuja mejorada.  
6.- BUSCAR VALOR EN VECTOR.-  Buscar un valor en el vector usando el método de búsqueda secuencial.
0.- SALIR

05/10/2023
Actv_9_1_932*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "libad.h"

//Prototype
int menu ();
int opci ();
int bus_sec_m (int mat [][4],int n , int m,int num);

void llenado_v(int vect[],int n);
void llenado_m(int mat[][4], int n, int m);
void imprimir_m (int mat[][4], int n, int m);
void imprimir_v (int vect[],int n);
void orden (int vect[], int n);
void search (int vect[], int n);

//Main principal
int main()
{
    srand(time(NULL));
    opci();
    return 0;
}

int menu ()
{
    int op;
    printf("\tMENU\n");
    printf("1.-Llenar vector\n");
    printf("2.-Llenar matriz\n");
    printf("3.-Imprimir vector\n");
    printf("4.-Imprimir matriz\n");
    printf("5.-Ordenar vector\n");
    printf("6.-Buscar valor en vector\n");
    printf("0.-Salir");
    op = valid("Escoja una opcion",0,6);
    return op;
}

int opci()
{
    int n1, n, m;
    n1=15;
    n=4;
    m=4;
    int vect1[n1], mat[n][m];
    int op;
    do
    {
        op=menu();
        switch(op)
        {
            case 1:
                llenado_v(vect1,n1);
                break;
            case 2:
                llenado_m(mat,n,m);
                break;
            case 3:
                imprimir_v(vect1,n1);
                break;
            case 4:
                imprimir_m(mat,n,m);
                break;
            case 5:
                orden(vect1, n1);
                break;
            case 6:
                search(vect1,n);
                break;
        }
    }
    while(op!=0);
    printf("Buen dia\n");
    return 0;
}

void llenado_v (int vect[],int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        num_alea_sr(vect,n,100,200);
    }
    printf("Vector lleno\n");
    system("PAUSE");
}

void llenado_m (int mat[][4], int n, int m)
{
    int i, j,c;
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            do
            {
                c=rand() % (200-100+1)+100;
            }
            while(bus_sec_m(mat,n,m,c)!=-1);
            
            mat[i][j]=c; 
        }
    }
    printf("Matriz llena\n");
    system("PAUSE");
}

int bus_sec_m (int mat [][4],int n , int m,int num)
{
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            if(mat[i][j]==num) 
            {
                return i;
            }
        }
    }
    return -1; 
    
}

void imprimir_v (int vect[],int n)
{
    impr_vect(vect, n);
    system("PAUSE");
}

void imprimir_m (int mat[][4], int n, int m)
{
    int i, j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            printf(" %d ", mat[i][j]);
        }
        printf("\n");
    }
    system("PAUSE");
}

void orden (int vect[],int n)
{
    int i,j, temp;
    for(i=0;i<n;i++) //el que compararemos con todos
    {
        for(j=i+1;j<n;j++) //Comparar i con todos inciando desde una posicion adelante de i
        {
            if(vect[i]>vect[j])
            {
                temp=vect[i];
                vect[i]=vect[j];
                vect[j]=temp;
                //Solo intercambiamos valores
            }
        }
    }
    printf("Ordenado\n");
    system("PAUSE");
}

void search (int vect[], int n)
{
    char cad[50];
    int pos,num; 
    //definimos num como int ya que si lo ponemos con char solo tomara el ultimo digito al poner una secuencia de numeros

    printf("Que numero busca\n");
    fflush(stdin);
    fgets(cad, sizeof(cad),stdin);
    num=atoi(cad);

    pos=bus_sec(vect,n,num);
    printf("\n");

    if(pos!=-1)
    {
        printf("Su posicion es %d \n",pos);
    }
    else
    {
        printf("No se encontro su numero\n");
    }
    system("PAUSE");
}