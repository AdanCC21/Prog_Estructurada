/*Gonzalez Ceseña Adan 372799
Parte 1
09/26/2023
Actv_8_1_932*/
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

//Prototipo
int menu ();
int opciones ();
int valid (char msj[],int ri, int rf);
void manualmente (int vect1[], int n);
void aleatoriamente (int vect2[], int m);
void vector1yvector2 (int vect1[], int vect2[], int vect3[], int p);
void imprimir ();
void llenar4x4 ();
void imprimirmatriz ();


    /*int aleatorio = rand() %(10-0+1)+0;*/

//Main
int main ()
{
    srand(time(NULL));
    opciones();
}

//Funciones
int menu ()
{
    int op;
    system("CLS");
    printf("\t Menu\n");
    printf("1.-Llenar vector manualmente\n");
    printf("2.-Llenar vector Aleatorio\n");
    printf("3.-Llenar vector con vector 1 y 2\n");
    printf("4.-Imprimir vectores\n");
    printf("5.-Llenar matriz 4x4\n");
    printf("6.-Imprimir matriz\n");
    printf("0.-Salir\n");
    op=valid("Ingrese una opcion",0,6);
    return op;
}

int opciones ()
{
    //Definir vectores
    int vect1[9],vect2[9],vect3[19];
    int op;
    do
    {
        op=menu();
        switch (op)
        {
            case 1:
                manualmente(vect1, 9);
                break;
            case 2:
                aleatoriamente(vect2, 9);
                break;
            case 3:
                vector1yvector2(vect1, vect2, vect3, 19);
                break;
            case 4:
                imprimir(vect1, 9, vect2, 9, vect3, 19);;
                break;
            case 5:
                llenar4x4();
                break;
            case 6:
                imprimirmatriz();
                break;
        }
    }
    while(op!=0);
    system("cls");
    printf("Buen dia\n");
}

int valid (char msj[],int ri, int rf)
{
    int n;
    do
    {
        printf("%s\n",msj);
        scanf("%d",&n);
        if(n>rf)
        {
            printf("Opcion invalida, intente de nuevo\n");
        }
        else
        {
            if(n<ri)
            {
                printf("Opcion invalida, intente de nuevo\n");
            }
        }
    }
    while(n>rf || n<ri);
    return n;
}

void manualmente (int vect1[], int n)
{
    int i,ny;
    for(i=0;i<=n;i++)
    {
        printf("Posicion numero %d\n",i);
        ny=valid("Ingrese numero por numero del 30 al 70",30,70);
        vect1[i] = ny;
    }
    printf("Posiciones llenas\n");
    system("pause");
}

void aleatoriamente (int vect2[], int m)
{
    int i,n;
    for(i=0;i<=m;i++)
    {
        n=rand()%(20-1+1)+1; //Falta poner que no se reptian
        vect2[i] = n;
    }
    printf("Posiciones llenas\n");
    system("pause");
}

void vector1yvector2 (int vect1[], int vect2[], int vect3[], int p)
{
    int i;
    p++; //Normalmente 20 posiciones serian 19 contando el 0, asi que para que p/2 de un numero entero sin decimales lo incrementamos a 20

    //llenamos la 1ra mitad con el vector 1
    for(i=0;i<p/2;i++)
    {
        vect3[i]=vect1[i]; 
    }

    //llenamos la 2da mitad con el vector 2
    for(i=p/2;i<p;i++)
    {
        //Al vector 2 le restamos la mitad de p para que inicialize en 0
        vect3[i]=vect2[i-p/2];
    }
    p--; //Lo regresamos a 19

    printf("El vector se a llenado\n");
    system("PAUSE");
}
void imprimir (int vect1[], int n, int vect2[], int m, int vect3[], int p)
{
    int i,op,sal;
    do
    {
        printf("Que vector desea imprimir?\n");
        op=valid("1.-Vector 1, 2.-Vector 2, 3.-Vector 3", 1, 3);
        if(op==1)
        {
            printf("Vector 1\n");
            for(i=0;i<=n;i++)
            {
                printf(" %d ",vect1[i]);
            }
        }
        if(op==2)
        {
            printf("Vector 2\n");
            for(i=0;i<=m;i++)
            {
                printf(" %d ",vect2[i]);
            }
        }
        if(op==3)
        {
            printf("Vector 3\n");
            for(i=0;i<=p;i++)
            {
                printf(" %d ",vect3[i]);
            }
        }
        printf("Desea repeitr?\n");
        sal=valid("1.-Salir 2.-Repetir",1,2);
    }
    while(sal==2);

}
void llenar4x4 ()
{
    int i;
    //restarle 2 a cada vector 1 y 2, y para llenarlo hace de que, matriz[i][j], los primeros 8 osea 7 posiciones llenarlos con vect1 matriz[3][2] y las ultimas 8 llenarlas con vect2
}
void imprimirmatriz ()
{

}