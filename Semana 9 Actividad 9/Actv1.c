#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "valid.h"

int menu ();
int opci ();
void llenadov (int vect1[], int n);
void llenadom (int mat[][4], int n, int m);
void imprv (int vect1[], int n);
void imprm (int mat[][4], int n, int m);
void ordv ();
void search ();

int main()
{
    srand(time(NULL));
    opci();
    return 0;
}

int menu ()
{
    int op;
    printf("MENU");
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
                llenadov(vect1, n1);
                break;
            case 2:
                lelnadom(mat,n, m);
                break;
            case 3:
                imprv(vect1, n1);
                break;
            case 4:
                imprm(mat, n, m);
                break;
            case 5:
                ordv(vect1, n1);
                break;
            case 6:
                search();
                break;
        }
    }
    while(op!=0);
    printf("Buen dia\n");
    return 0;
}

void llenadov (int vect1[],int n)
{
    int i,num,j,band;
    for(i=0;i<=n;i++)
    {
        do
        {
            band = 0; // Reinicia bandera
            num=rand()%(20-1+1)+1;

            // Validar en cada espacio el numero
            for (j = 0; j <= i; j++)
            {
                if (vect1[j] == num)
                {
                    band = 1;
                }
            }
        } while (band != 0);
        vect1[i] = num;
    }
    printf("Posiciones llenas\n");
    system("pause");
}

void llenadom (int mat[][4], int n, int m)
{
    
}


void imprv (int vect1[], int n);


void imprm (int mat[][4], int n, int m);


void ordv ();


void search ();