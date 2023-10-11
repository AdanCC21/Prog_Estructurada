/*Gonzalez Ceseña Adan 372799
Actividad 10
REALICE EL SIGUIENTE PROGRAMA QUE CONTENGA UN MENÚ.
                MENÚ

             1.- AGREGAR (AUTOM 10 REGISTROS)

             2.- AGREGAR MANUAL

             3- ELIMINAR REGISTRO (lógico)

             4.- BUSCAR 

             5- ORDENAR

             6.- IMPRIMIR

             0.- SALIR
UTILIZAR UN ARREGLO DE 500 REGISTROS  
SE DEBERÁ UTILIZAR ESTRUCTURAS CON LOS DATOS BÁSICOS DE UN ALUMNO ( status, Matricula, ApPat, ApMat, Nombre, Edad, Sexo )  
Busqueda y Ordenacion por campo MATRICULA
nota: usar librería propia

10/10/2023 *Creado
Actv_10_932*/

#include <stdio.h>
#include <stdlib.h>
#include "libad.h"

//      Prototipos      //
int opci ();
int menu ();

void agregar ();
void agregm ();
void elimr ();
void busc ();
void ordenar ();
void imprim ();

//No pongas el curp en la libreria jaja ya despues agregala

//          Main            //
int main()
{
    opci();
    return 0;
}

//      Funciones       //

int menu ()
{
    int op;
    printf("    MENU\n");
    printf("1.-Agregar\n");
    printf("2.-Agregar Manual\n");
    printf("3.-Eliminar Registro\n");
    printf("4.-Buscar\n");
    printf("5.-Ordenar\n");
    printf("6.-Imprimir\n");
    printf("0.-Salir\n");
    op=valid("Seleccione una opcion",0,6);
    return op;
}

int opci ()
{
    int op,salid;
    do
    {
        op=menu();
        switch(op)
        {
            case 1:
                agregar();
                break;
            case 2:
                agregm();
                break;
            case 3:
                elimr();
                break;
            case 4:
                busc();
                break;
            case 5:

                break;
            case 6:
        }
        salid=valid("Seleccione 1 para salir, 2 para repetir",1,2);
    }
    while(salid!=1);
}

void agregar ();


void agregm ();


void elimr ();


void busc ();


void ordenar ();


void imprim ();

