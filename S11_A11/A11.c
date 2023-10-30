#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "libad.h"

//       Structs        //

typedef struct alumno
{
    char name [30];
    char name2 [30];
    char app [30];
    char apm[30];

    int zone;
    
    char curp[18];
    int mat;
}alum;

typedef struct fecha
{
    int day;
    int month;
    int year;
}birth;

typedef struct datos
{
    alum dalum;
    birth dbirth;
}data;

//      Prototipos      //

void menu ();
void opci();

void gencurp (data ine,int n2, int ap1, int ap2, char nombre[], char nombre2[],char app[], char apm[], int day, int month, int year, int gen, int estado);


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
    data estudiante;
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
                printf("1.-Agregar Manual\t2.-Agregar Automaticamente\n3.-Salir\n");
                op2=valid2("Ingrese una opcion valida",1,2);
                
                if(op2==1)
                {
                    
                }
                else
                {
                    if(op2==2)
                    {

                    }
                    else
                    {
                        //No Hace Nada
                    }

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

void gencurp (data ine,int n2, int ap1, int ap2, char nombre[], char nombre2[],char app[], char apm[], int day, int month, int year, int gen, int estado)
{
    char TempCurp[18];
    //CU_Auto_Gen(TempCurp,n2,ap2,ap1,nombre,nombre2,app,apm,day,month,year,gen,estado);
    CU_Auto_Gen(TempCurp,n2,ap2,ap1,nombre,nombre2,app,apm,day,month,year,gen,estado);
    strcpy(ine.dalum.curp,TempCurp);
    printf("Curp generada");
    system("PAUSE");
}

