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

void gen ();


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
    int op;
    do
    {
        menu();
        op=valid2("Fuera de rango",0,9);
        switch(op)
        {
            case 1:

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
            case 7:
                gen();
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

void read ()
{
    printf("De que archivo quiere leer los registros\n");
}

void agre_al ()
{

}

void gen ()
{
    int i;

}