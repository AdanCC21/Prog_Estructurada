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
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "libad.h"

//      Prototipos      //

typedef struct alumn
{
    char nombre[30];
    char app[30];
    char apm[30];
    int mat;
    int edad;
    char gen[10];
    int status;
} talum;

int opci ();
int menu ();

talum AgrAL (talum alumno[], int i);
talum AgrMn (talum alumno [],int i);

void elimr ();
void busc ();
void ordenar ();
void imprim (talum alumno[]);

void namesAL (char nombre[], int gen);
void apeAL(char apeido[]);

int validCh(char arreglo[]);

//          Main            //

int main()
{
    srand(time(NULL));
    opci();
    return 0;
}

//      Funciones       //

//  Menu

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

// Opciones

int opci ()
{
    talum alumno[500];
    int op,i;
    i=1;
    do
    {
        op=menu();
        switch(op)
        {
            case 1:
                for(i=0;i<=10;i++)
                {
                    alumno[i] = AgrAL(alumno,i);
                }
                printf("Cadena llena\n");
                system("PAUSE");
                break;
            case 2:
                AgrMn(alumno,i); //falta remplazarlo en la lista a la hora de generar los nombres aleatorios:c
                i++;
                break;
            case 3:
                elimr();
                break;
            case 4:
                busc();
                break;
            case 5:
                ordenar();
                break;
            case 6:
                imprim(alumno);
        }
        
    }
    while(op!=0);
    printf("Que tenga buen dia\n");
    return 0;
}

//  Funciones

void namesAL (char nombre[], int gen)
{
    int c;
    c=rand()%(10-0+1)+0;
    char namesH [20][50] = {"ADAN","IVAN","BRYAN","KEVIN","JOSE","ANTONIO","FERNANDO","ALEJANDO","PACO","HARO","DIEGO"};
    char namesM[20][50] = {"MARIA","ANA","LUPITA","ISABEL","CARMEN","MARYAM","FERNANDA","KARLA","LIZ","DANNA","ANDREA"};
    if(gen==1)
    {
        strcpy(nombre,namesH[c]);
    }
    else
    {
        if(gen==2)
        {
            strcpy(nombre,namesM[c]);
        }
    }
}

void apeAL(char apeidos[])
{
    int c;
    c=rand()%(10-1+1)+1;
    char apeidosL[20][20] = {"RODRIGUEZ", "GONZALEZ", "MARTINEZ", "LOPEZ", "PEREZ", "GOMEZ", "FERNANDEZ", "LOPEZ", "TORRES", "DIAZ",
    "RUIZ", "SANCHEZ", "GIL", "ROMERO", "VAZQUEZ", "MORALES", "JIMENEZ", "ORTEGA", "CASTRO","SUAREZ"};
    strcpy(apeidos,apeidosL[c]);
}

talum AgrAL (talum alumno[], int i)
{
    int gen,mat;
    char tempName [20], tempApeido[20];
    gen=rand()%(2-1+1)+1;

    //Nombre
    namesAL(tempName,gen);//Generar el nombre y almacenarlo en una variable local temporal
    strcpy(alumno[i].nombre,tempName);//Pasar lo almacenado a nuestro registro atravez de la variable alumno de tipo talum(Tipo de nuestro registro), en el arreglo i

    //Apeido Paterno
    apeAL(tempApeido);
    strcpy(alumno[i].app,tempApeido);

    //Apeido materno
    apeAL(tempApeido);
    strcpy(alumno[i].apm,tempApeido);

    //Matricula
    mat = rand()%(399999-300000+1)+300000;
    alumno[i].mat = mat;

    //edad
    alumno[i].edad=rand()%(30-17+1)+17;

    //genero
    if(gen==1)
    {
        strcpy(alumno[i].gen,"H");
    }
    else
    {
        strcpy(alumno[i].gen,"M");
    }

    //Estatus
    alumno[i].status=1; //1 = dado de alta, no creo que el profesor necesite un alumno dado de baja
    
    return alumno[i];
}

talum AgrMn (talum alumno[],int i)
{
    int v;
    char nombre[20], apeidopt[20], apeidomt[20]; 
    printf("A continuacion ingrese todo lo que se le solicite en mayusculas y sin acentos porfavor\n");

    printf("Ingrese el nombre del alumno\n");
    do
    {
        fgets(nombre,sizeof(nombre),stdin);
        v=validCh(nombre);
    }
    while(v==1);
    strcpy(alumno[i].nombre,nombre);

    printf("Ingrese el apeido paterno\n");
    do
    {
        fgets(apeidopt,sizeof(apeidopt),stdin);
        v=validCh(apeidopt);
    }
    while(v==1);
    strcpy(alumno[i].app,apeidopt);
    

    printf("Ingrese el apeido materno\n");
    do
    {
        fgets(apeidomt,sizeof(apeidomt),stdin);
        v=validCh(apeidomt);
    }
    while(v==1);
    strcpy(alumno[i].apm,apeidomt);
    
    //edad
    alumno[i].edad=valid("Ingrese su edad",17,30);
    
    //genero
    v=valid("Ingrese su genero\n1.-Hombre 2.-Mujer",1,2);
    if(v==1)
    {
        strcpy(alumno[i].gen,"H");
    }
    else
    {
        strcpy(alumno[i].gen,"M");
    }

    //matricula
    alumno[i].mat=valid("Ingrese la matricula",300000,399999);

    //estatus
    alumno[i].status=valid("Ingrese su estatus (1 o 0)",0,1);
    
    return alumno[i];
}

void elimr ()
{

}

void busc ()
{

}

void ordenar ()
{

}

void imprim (talum alumno[])
{
    int i;
    printf("%-10s %-10s %-10s %-10s %-4s %-5s %-8s\n","Matricula", "Nombre", "ApP", "ApM", "Edad", "Sexo", "Estatus");
    for(i=0;i<=10;i++)
    {
        //verifique que esta aprobado
        if(alumno[i].status==1)
        {
            printf("%-10d %-10s %-10s %-10s %-4d %-5s %-8d\n", alumno[i].mat, alumno[i].nombre, alumno[i].app, alumno[i].apm, alumno[i].edad, alumno[i].gen,alumno[i].status);
        }
    }
    system("PAUSE");
}

//Validar caracteres
//Corregir con codigo de bryan
int validCh(char arreglo[])
{
    int lon,i;
    lon=longitudDeCh(arreglo);
    
    //Espacio al inicio
    if(arreglo[0]==32)
    {
        printf("Tu texto no puede iniciar con un espacio\n");
        return 1;
    }
    //espacio al final
    if(arreglo[lon-1]==32)
    {
        printf("Tu texto no puede terminar con un espacio\n");
        return 1;
    }
    //Sin ningun caracter
    if(arreglo[0]=='\0')
    {
        printf("No se encontraron caracteres\n");
        return 1;
    }
    //Buscara por toda la cadena y si encuentra x error en alguna parte lo imprimira
    for(i=0;i<=lon;i++)
    {
        //simbolos
        if(arreglo[i]>=33)
        {
            if(arreglo[i]<=47)
            {
                printf("No se aceptan simbolos\n");
                return 1;
            }
        }
        //simbolos 2
        if(arreglo[i]>=58)
        {
            if(arreglo[i]<=64)
            {
                printf("No se aceptan simbolos\n");
                return 1;
            }
        }
        //simbolos 3
        if(arreglo[i]>=91)
        {
            if(arreglo[i]<=96)
            {
                printf("No se aceptan simbolos\n");
                return 1;
            }
        }
        //simbolos 4
        if(arreglo[i]>=123)
        {
            printf("No se aceptan simbolos\n");
            return 1;
        }
        //dobles espacios
        if(arreglo[i]==32)
        {
            if(arreglo[i+1]==32)
            {
                printf("No se permite doble espacio\n");
                return 1;
            }
        }
        //Numeros
        if(arreglo[i]>=48)
        {
            if(arreglo[i]<=57)
            {
                printf("No se permiten numeros\n");
                return 1;
            }
        }
        //Minusculas
        if(arreglo[i]>='a')
        {
            if(arreglo[i]<='z')
            {
                printf("Ingrese solo mayusculas\n");
                return 1;
            }
        }
        //Condicion que hara que solo acepte caracteres entre a y z mayusculas
        if(arreglo[i]>='A')
        {
            if(arreglo[i]<='Z')
            {
                return 0;
            }
            else
            {
                printf("Algun caracter no esta permitido\n");
                return 1;
            }
        }
        else
        {
            printf("Algun caracter no esta permitido\n");
            return 1;
        }
    }
    return 1;
}