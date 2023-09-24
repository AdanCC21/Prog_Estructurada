#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Prototipos
int menu ();
int longitud();
int salir ();
int validacion (char mensaje[],int ri, int rf);
void salida1 ();
void salida2 ();
void salida3 ();
void salida4 ();
void salida5 ();
void salida6 ();
void salida7 ();
void salida8 ();
void salida9 ();

int main()
{
    int op,ex;
    do
    {
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
            case 9:
                salida9();
                break;
            default :
                printf("Seleccione una opcion valida\n");
        }
        ex=salir();
    }while(ex==2);
    printf("Buen dia\n");
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
    printf("9.-Salida9\n");
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

int salir ()
{
    int sl;
    sl=validacion("\nDesea salir del programa?\n1.-salir, 2.-Repetir\n", 1 , 2);
    return sl;
}

int validacion (char mensaje[], int ri, int rf)
{
    int n;
    do
    {
        printf("%s",mensaje);
        scanf("%d",&n);
        if(n>rf)
        {
            printf("Opcion invalida\n");
        }
        if(n<ri)
        {
            printf("Opcion invalida \n");
        }
    }
    while(n<ri || n>rf);
    return n;
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
    printf("Salida 5\n");
    int lon=longitud();
    int i;
    char msj[100];
    strcpy(msj, "ENSENADA");
    for(lon;lon>=0;lon--)
    {
        for(i=0;i<lon;i++)
        {
            printf("%c",msj[i]);
        }
        printf("\n");
    }
   
}

void salida6 ()
{
    printf("Salida 5\n");
    int lon=longitud(),i,a;
    char msj[100];
    strcpy(msj, "ENSENADA");
    for(a=0;a<=lon;a++)
    {
        for(i=lon;i>=a;i--)
        {
            printf("%c",msj[i]);
        }
        printf("\n");
    }
}

void salida7 ()
{
    printf("Salida 7\n");
    char msj[100];
    strcpy(msj, "ENSENADA");
    int i, a, lon=longitud();
    for(a=0;a<=lon;a++)
    {
        for(i=a;i<=lon;i++)
        {
            printf("%c",msj[i]);
        }
        printf("\n");
    }
}

void salida8 ()
{
    printf("Salida 8\n");
    char msj[100];
    strcpy(msj, "ENSENADA");
    int i, a, lon=longitud();
    for(a=lon;a>=0;a--)
    {
        for(i=a;i>=0;i--)
        {
            printf("%c",msj[i]);
        }
        printf("\n");
    }
}

void salida9 ()
{
    printf("Salida 9\n");
    int i;
    char msj[100];
    strcpy(msj, "ENSENADA");
    for (int i = 0; msj[i] != '\0'; i++)
    {
        char caracter = msj[i];
        if (caracter >= 'A' && caracter <= 'Z')
        {
            caracter += 32;//Convertir a minuscula
        }
        if ((caracter >= 'a' && caracter <= 'z') && (caracter != 'a' && caracter != 'e' && caracter != 'i' && caracter != 'o' && caracter != 'u'))
        {
            printf("%c", msj[i]);
        }
    }
}