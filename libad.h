/*  
    Gonzalez Cesena Adan
    Version 28/10/2023
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

//      ------Prototipos------      //

//Validacion de numeros
int valid (char msg[],int ri, int rf);

//Validacion de caracteres
int validCh(char cadena[]);

//Busqueda secuencial de la posicion de un numero dentro de un arreglo
int bus_sec (int vect [],int n,int num);

//Generacion de numero aleatorio sin repetir
int num_alea_sr (int vect[], int n, int ri, int rf);

//Imprimir vect/arreglo
void impr_vect (int vect[],int n);

//Longitud ed un arreglo
int longitudDeIn (int msj[]);

//      ------Funciones------       //

//  Validacion de numeros
int valid (char msg[],int ri, int rf)
{
    char cad[50];
    int n;
    do
    {
        
        fflush(stdin);
        fgets(cad, sizeof(cad),stdin);
        n=atoi(cad);
        if(n>rf || n<ri)
        {
            printf("%s\n",msg);
        }
    }
    while(n>rf || n<ri);
    return n;
}

//  Validacion de characteres
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
            //No hace nada
        }
        else
        {
            
            if(cadena[i]>='a')
            {
                if(cadena[i]<='z')
                {
                    cadena[i]-=32;
                }
            }

            if(cadena[i] == -92) //ñ
            {
                cadena[i] = -91; //Ñ
            }

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
        i++;
    }
}

//Minusculas a mayusculas
void minus (char cad[])
{
    for(int i=0; cad[i]!='\0';i++)
    {
        if(cad[i]>='a')
        {
            if(cad[i]<='z')
            {
                cad[i]-=32;
            }
        }
        if(cad[i] == -92) //ñ
        {
            cad[i] = -91; //Ñ
        }
    }
}

//  Busqueda secuencial en un arreglo   //
int bus_sec (int vect [],int n,int num)
{
    int i;
    for(i=0;i<n;i++)
    {
        if(vect[i]==num) //Si llega a encontrar que en posicion i esta el numero buscado retornara la posicion
        {
            return i;
        }
    }
    return -1; 
    //de lo contrario lanzara un -1, que este esta fuera del rango de cualquier arreglo/cadena evitando lanzar una posicion erronea
}

//  Generaicon de numeros aleatorios sin repetir
int num_alea_sr (int vect[], int n, int ri, int rf)
{
    int c, i;
    for(i=0;i<n;i++)
    {
        do
        {
            c=rand() % (rf-ri+1)+ri;
            //Generara un numero aleatorio entre los rangos recibidos
        }
        while(bus_sec(vect,n,c)!=-1);
        //hara una busqueda entre el arreglo para ver si el numero aleatorio generado ya esta puesto en alguna otra posicion
        
        vect[i]=c; 
        //de no ser el caso la busqueda lanzara un -1 y por lo tanto saldra del ciclo do while
    }
    return 0;
}

//Longitud de arreglo
int longitudDeIn (int arreglo[])
{
    //Lanzara los espacios ocupados o mas bn la longitud de un arreglo tipo int 
    int lon;
    lon = sizeof(arreglo)/sizeof(arreglo[0]);
    return lon;
}

//Imprimir un vector o arreglo
void impr_vect (int vect[],int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        printf(" %d ", vect[i]);
    }
    printf("\n");
}