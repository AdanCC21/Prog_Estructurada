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

void elimr (talum alumno[],int i, int p);
int buscsec(talum alumno[], int n,int num);
int buscbin(talum alumno[],int lef,int rig,int num);
void ordenar (talum alumno[],int n);
void imprim (talum alumno[],int n);

void namesAL (char nombre[], int gen);
void apeAL(char apeido[]);

int validCh(char cadena[]);

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

//      Opciones    //

int opci ()
{
    talum alumno[499];
    int op,i,j,bus;
    int lef, rig, num, n;
    int banO,p;
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
                        banO=0;
                       
                    }
                    printf("Cadena llenada\n");
                }
                else
                {
                    printf("Base de datos llena\n");
                }
                system("PAUSE");
                break;
            case 2:
                if(i<500)
                {
                    alumno[i] = AgrMn(alumno,i);
                    i++;
                    banO=0;
                }
                else
                {
                    printf("Base de datos llena\n");
                }
                system("PAUSE");
                break;
            case 3:
                if(i>0)
                {
                    printf("Que posicion desea eliminar\n");
                    p=valid("Ingrese la posicion",1,i+1);
                    if(p>i)
                    {
                        printf("Fuera de rango\n");
                    }
                    else
                    {
                        elimr(alumno,i,p-1);
                        i--;
                        printf("Listo\n");
                        banO=0;
                    }
                }
                else
                {
                    printf("Lista vacia\n");
                }
                system("PAUSE");
                break;
            case 4:
                printf("Busqueda\n");
                n=i;
                if(banO==0)
                {
                    printf("Metodo de secuencial\n");
                    num=valid("Ingrese la matricula",300000,399999);
                    bus=buscsec(alumno,n,num);
                    if(bus==-1)
                    {
                        printf("No se encontro la matricula\n");
                    }
                    else
                    {
                        printf("La matricula se encuentra en la posicion %d \n", bus);
                        printf("%-10s %-10s %-10s %-10s %-5s %-5s %-3s","Matricula","Nombre","ApPt","ApMt","Edad","Genero","Estatus\n");
                        printf("%-10d %-10s %-10s %-10s %-5d %-5s %-6d\n",alumno[bus].mat, alumno[bus].nombre, alumno[bus].app, alumno[bus].apm, alumno[bus].edad, alumno[bus].gen, alumno[bus].status);
                    }
                }
                else
                {
                    printf("Busqueda binaria\n");
                    num=valid("Ingrese la matricula",300000,399999);
                    lef=0;
                    rig=n;
                    
                    bus=buscbin(alumno,lef, rig, num);
                    if(bus==-1)
                    {
                        printf("No se encontro la matricula\n");
                    }
                    else
                    {
                        printf("La matricula se encuentra en la posicion %d \n", bus);
                        printf("%-10s %-10s %-10s %-10s %-5s %-5s %-3s","Matricula","Nombre","ApPt","ApMt","Edad","Genero","Estatus\n");
                        printf("%-10d %-10s %-10s %-10s %-5d %-5s %-6d\n",alumno[bus].mat, alumno[bus].nombre, alumno[bus].app, alumno[bus].apm, alumno[bus].edad, alumno[bus].gen, alumno[bus].status);
                    }
                }
                system("PAUSE");
                break;
            case 5:
                ordenar(alumno,i);
                banO=1;
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

//      Acciones        //

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

    
    namesAL(tempName,gen);
    strcpy(alumno[i].nombre,tempName);

    apeAL(tempApeido);
    strcpy(alumno[i].app,tempApeido);

    apeAL(tempApeido);
    strcpy(alumno[i].apm,tempApeido);

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
    
    alumno[i].edad=rand()%(50-17+1)+17;

    if(gen==1)
    {
        strcpy(alumno[i].gen,"H");
    }
    else
    {
        strcpy(alumno[i].gen,"M");
    }

    alumno[i].status=1;
    
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

        tempmat=valid("Ingrese la matricula",300000,399999);
        for(int j=0;j<=1;j++)
        {
            for(int k=0;k<=500;k++) 
            {
                if(tempmat==alumno[k].mat)
                {
                    tempmat=valid("Matricula ya ocupada o invalida, intente de nuevo",300000,399999);
                    j=0;
                }
            }
        }
            
        
    alumno[i].mat=tempmat;
 
    alumno[i].edad=valid("Ingrese su edad",17,100);
  
    v=valid("Ingrese su genero\n1.-Hombre 2.-Mujer",1,2);
    if(v==1)
    {
        strcpy(alumno[i].gen,"H");
    }
    else
    {
        strcpy(alumno[i].gen,"M");
    }

    alumno[i].status=valid("Ingrese su estatus (1.- Aun en lista, 2.- dado de baja)",1,2);
    
    return alumno[i];
}

void elimr (talum alumno[],int i,int p)
{
    for(p;p<=i;p++)
    {
        alumno[p]=alumno[p+1];
    }

}

int buscsec(talum alumno[], int n,int num)
{
    int i;
    for(i=0;i<=n;i++)
    {
        if(alumno[i].mat==num)
        {
            return i;
        }
    }
    return -1;
}

int buscbin(talum alumno[],int lef,int rig,int num) 
{
    int med;
    while (lef<=rig)
    {
        med=lef + (rig - lef) / 2;
        
        if(alumno[med].mat==num)
        {
            return med;
            lef=rig+1;
        }
        if(alumno[med].mat< num)
        {
            lef= med+1;
        }
        if(alumno[med].mat > num)
        {
            rig=med-1;
        }

    }
    return -1;

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
        if(alumno[i].status==1)
        {
            printf("%-3d %-10d %-10s %-10s %-10s %-4d %-5s %-8d\n",j, alumno[i].mat, alumno[i].nombre, alumno[i].app, alumno[i].apm, alumno[i].edad, alumno[i].gen,alumno[i].status);
            j++;
        }
    }
    system("PAUSE");
}

int validCh(char cadena[])
{
    int i=0;
    if (cadena[0] == ' ')
    {
        printf("Tu texto no puede iniciar con un espacio\n");
        return 1;
    }
    if (cadena[0] == '\0')
    {
        printf("Texto vacio\n");
        return 1;
    }

    while (cadena[i] != '\0')
    {
        if ((cadena[i] >= 'A' && cadena[i] <= 'Z'))
        {
            
        }
        else
        {
            if ((cadena[i] >= 'a' && cadena[i] <= 'z'))
            {
                printf("Porfavor ingresa solamente letras mayusculas\n");
                return 1;
            }
            else
            {
                if (cadena[i] == ' ')
                {
                    if (cadena[i + 1] == ' ')
                    {
                        printf("Espacios dobles no estan permitidos\n");
                        return 1;
                    }
                }
                else
                {
                    printf("Simbolos no permitidos\n");
                    return 1;
                }
            }
        }
        i++;
    }

    if (cadena[i - 1] == ' ')
    {
        printf("Tu texto no puede terminar con espacio\n");
        return 1;
    }

    return 0; 
}