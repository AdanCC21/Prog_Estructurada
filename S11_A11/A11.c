#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "libad.h"


//      Prototipos      //

void menu ();
void opci();


//        Main          //
int main()
{
    opci();
    return 0;
}

//        Menu          //

void menu ()
{
    printf("\tMENU\n");
    printf("1.-Agregar\n");
    printf("2.-Eliminar Registro\n");
    printf("3.-Buscar\n");
    printf("4.-Ordenar\n");
    printf("5.-Imprimir\n");
    printf("6.-Archivo de texto\n");
    printf("0.-Salir del programa\n");
}

void opci()
{
    int op,op2;
    do
    {
        system("CLS");
        menu();
        op=valid2("Fuera de rango",0,6);
        switch(op)
        {
            case 1:
                system("CLS");
                printf("1.-Agregar Manual\t2.-Agregar Automaticamente\n");
                op2=valid2("Ingrese una opcion valida",1,2);
                
                if(op2==1)
                {
                    CUopci();
                }
                else
                {

                }

                break;
            case 2:
                break;

            case 3:

                break;
            case 4:

                break;
            case 5:

                break;
            case 6:

                break;
            case 0:
                system("CLS");
                printf("Seguro que quieres salir del programa?\n1.-Si, salir\t2.-No, repetir\n");
                op=valid2("Ingrese una opcion valida valida",1,2);
                if(op==1)
                {
                    op=0;
                }
        }
    }
    while(op!=0);
    printf("Buen dia\n");
}

//      Funciones       //


