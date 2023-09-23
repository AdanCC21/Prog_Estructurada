#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Prototipos
int menu ();
int longitud();
void salida1 ();
void salida2 ();
void salida3 ();
void salida4 ();
void salida5 ();
void salida6 ();
void salida7 ();
void salida8 ();

int main()
{
    int op;
    op=menu();
    switch(op)
    {
        case 1:
            salida1();
            break;
        case 2:
            salida2();
            break;
        case 3:
            salida3();
            break;
        case 4:
            salida4();
            break;
        case 5:
            salida5();
            break;
        case 6:
            salida6();
            break;
        case 7:
            salida7();
            break;
        case 8:
            salida8();
            break;
        default :
            printf("Seleccione una opcion valida\n");
    }
}

int menu ()
{
    int op;
    printf("Bienvenido");
    printf("Porfavor selecione una opcion\n");
    printf("1.-Salida1\n");
    printf("2.-Salida2\n");
    printf("3.-Salida3\n");
    printf("4.-Salida4\n");
    printf("5.-Salida5\n");
    printf("6.-Salida6\n");
    printf("7.-Salida7\n");
    printf("8.-Salida8\n");
    scanf("%d",&op);
    return op;
}


int longitud ()
{
    int i=0;
    char msj[100];
    strcpy(msj,"ENSENADA");
    while(msj[i]!='\0')
    {
        i++;
    }
    return i;
}

void salida1()
{
    char msj[100];
    strcpy(msj, "ENSENADA");
    printf("%s",msj);
}

void salida2 ()
{
    int lon=longitud();
    char msj[100];
    strcpy(msj, "ENSENADA");
    for(lon;lon>=0;lon--)
    {
        printf("%c",msj[lon]);
    }
}

void salida3 ()
{
    printf("Salida 3\n");
    int i;
    char msj[100];
    strcpy(msj, "ENSENADA");
    for(i=0;msj[i]!='\0';i++)
    {
        printf("%c\n",msj[i]);
    }
}
void salida4 ()
{
    printf("Salida 4");
    int i=longitud();
    char msj[100];
    strcpy(msj, "ENSENADA");
    fflush(stdin);
    for(i;i>=0;i--)
    {
        printf("%c\n",msj[i]);
    }
}

void salida5 ()
{
    printf("Salida 5");
    int i=longitud();
    int lon=i;
    int c=0;
    char msj[100];
    strcpy(msj, "ENSENADA");
    for(c=0;c<=lon;c++)
    {
    }
}

void salida6 ()
{
    printf("ola");
}

void salida7 ()
{
    printf("ola");
}

void salida8 ()
{
    printf("ola");
}