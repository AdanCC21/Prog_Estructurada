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
void manualmente ();
void aleatoriamente ();
void vector1yvector2 ();
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
    //Creo que hay que declarar el vector aqui mero int vect1[n] y enviarsela en la funcion osea (vector)
    int vect1[9],vect2[9],vect3[19];
    int op;
    do
    {
        op=menu();
        switch (op)
        {
            case 1:
                manualmente();
                break;
            case 2:
                aleatoriamente();
                break;
            case 3:
                vector1yvector2();
                break;
            case 4:
                imprimir();
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

void manualmente ()
{
    system("cls");
    int vect1 [9];
    int i,n;
    for(i=0;i<10;i++)
    {
        printf("Posicion numero %d\n",i);
        n=valid("Llenado de vector manualmente\nIngrese numero por numero del 30 al 70",30,70);
        vect1[i] = n;
    }
    printf("Posiciones llenas\n");
    system("pause");
}

void aleatoriamente ()
{
    system("cls");
    int vect2 [9];
    int i,n;
    for(i=0;i<10;i++)
    {
        n=rand()%(70-30+1)+30;
        vect2[i] = n;
    }
    printf("Posiciones llenas\n");
    system("pause");
}
void vector1yvector2 ()
{
    int vect3[19];
    manualmente();
    aleatoriamente();
    for(int i=0;i<20;i++)
    {
        
    }
}
void imprimir ()
{
    int n;
    

}
void llenar4x4 ()
{

}
void imprimirmatriz ()
{

}