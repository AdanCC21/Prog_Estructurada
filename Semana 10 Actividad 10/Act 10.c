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

int menu ();
int opci ();

talum AgrAL (talum alumno[], int i);
talum AgrMn (talum alumno [],int i);

void elimr ();
void busc ();
void ordenar (talum alumno[],int n);
void imprim (talum alumno[],int n);

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
    printf("7.-Salir\n");
    op=valid("Seleccione una opcion",1,7);
    return op;
}

// Opciones

int opci ()
{
    talum alumno[500];
    int op,i,j;
    i=0;
    do
    {
        system("CLS");
        op=menu();
        switch(op)
        {
            case 1:
                if(i<500)
                {
                    for(j=0;j<10;j++)
                    {
                        alumno[i] = AgrAL(alumno,i);
                        i++;
                        //Usamos j para generar unicamente 10 nombres e i para cambiar de posiciones de la cadena
                        //osea que no se esten remplazando siempre las mismas 10 primeras posiciones
                    }
                    printf("Cadena llenada\n");
                    system("PAUSE");
                }
                else
                {
                    printf("Base de datos llena\n");
                }
                break;
            case 2:
                if(i<500)
                {
                    alumno[i] = AgrMn(alumno,i);
                    i++;
                }
                else
                {
                    printf("Base de datos llena\n");
                }
                break;
            case 3:
                elimr();
                break;
            case 4:
                busc();
                break;
            case 5:
                ordenar(alumno,i);
                break;
            case 6:
            if(i==0)
            {
                printf("Lista vaica\n");
                system("PAUSE");
            }
            else
            {
                imprim(alumno,i);
            }
        }
    }
    while(op!=7);
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
    int gen,mat,lon,j;
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

    //Matricula sin repetir matriculas
    lon=longitudDeIn(alumno[i].mat);
    mat = rand()%(399999-300000+1)+300000;

    for(j=0; j<=lon;j++)
    {
        if(mat==alumno[j].mat)
        {
            mat = rand()%(399999-300000+1)+300000;
        }
    }
    alumno[i].mat = mat;
    

    //edad
    alumno[i].edad=rand()%(50-17+1)+17;

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
    int tempmat;
    printf("A continuacion ingrese todo lo que se le solicite en mayusculas y sin acentos porfavor\n");

    printf("Ingrese el nombre del alumno\n");
    do
    {
        gets(alumno[i].nombre);
        v=validCh(alumno[i].nombre);
    }
    while(v==1);

    printf("Ingrese el apeido paterno\n");
    do
    {
        gets(alumno[i].app);
        v=validCh(alumno[i].app);
    }
    while(v==1);

    printf("Ingrese el apeido materno\n");
    do
    {
        gets(alumno[i].apm);
        v=validCh(alumno[i].apm);
    }
    while(v==1);

    //matricula

        tempmat=valid("Ingrese la matricula",300000,399999);
        for(int j=0;j<=1;j++)
        {
            for(int k=0;k<=500;k++) //Buscara en todos los registros
            {
                if(tempmat==alumno[k].mat)
                {
                    tempmat=valid("Matricula ya ocupada o invalida, intente de nuevo",300000,399999);
                    j=0;//Regresa el valor de j  a 0 para que se reinicie el for del inicio y vuelva a analizar los 500 campos desde el campo 0
                }
            }
        }
            
        
    alumno[i].mat=tempmat;
    
    //edad
    alumno[i].edad=valid("Ingrese su edad",17,100);
    
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

    //estatus
    alumno[i].status=valid("Ingrese su estatus (1.- Aun en lista, 2.- dado de baja)",1,2);
    
    return alumno[i];
}

void elimr ()
{
    int i;

}

void busc ()
{

}

void ordenar (talum alumno[], int n)
{
    int i,j;
    talum temp;
    for(j=0;j<=n;j++)
    {
        for(i=j+1;i<=n;i++)
        {
            if(alumno[j].mat>alumno[i].mat)
            {
                temp=alumno[i];
                alumno[i]=alumno[j];
                alumno[j]=temp;
            }
        }

    }
    printf("Ordenada\n");
    system("PAUSE");

}

void imprim (talum alumno[],int n)
{
    int i,j;
    j=1;
    printf("%-3s %-10s %-10s %-10s %-10s %-4s %-5s %-8s\n","Num","Matricula", "Nombre", "ApP", "ApM", "Edad", "Sexo", "Estatus");
    for(i=0;i<=n;i++)
    {
        //verifique que esta aprobado
        if(alumno[i].status==1)
        {
            printf("%-3d %-10d %-10s %-10s %-10s %-4d %-5s %-8d\n",j, alumno[i].mat, alumno[i].nombre, alumno[i].app, alumno[i].apm, alumno[i].edad, alumno[i].gen,alumno[i].status);
            j++;
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