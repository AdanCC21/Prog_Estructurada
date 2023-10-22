/*  
    Gonzalez Cesena Adan
    Version 20/10/2023
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

//      Prototipos      //
int valid (char msg[],int ri, int rf);
int validCh(char cadena[]);
int bus_sec (int vect [],int n,int num);
int num_alea_sr (int vect[], int n, int ri, int rf);
void impr_vect (int vect[],int n);
int longitudDeCh (char msj[]);


//       Funciones   //

//  Validacion de numeros
int valid (char msg[],int ri, int rf)
{
    char cad[50];
    int n;
    do
    {
        printf("%s\n",msg);
        fflush(stdin);
        fgets(cad, sizeof(cad),stdin);
        n=atoi(cad);
    }
    while(n>rf || n<ri);
    return n;
}

//  Validacion de characteres
int validCh(char cadena[])
{
    int i=0;
    unsigned char cad;
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
        cad=(unsigned char)cadena[i];

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
                    printf("No puedes poner mas de 1 dato o utilizar espacios\n");
                    return 1;
                }
                else
                {
                    if(cad== 164)
                    {   
                    }
                    else
                    {
                        if(cad==165)
                        {
                        }
                        else
                        {
                            if(cad>=44 && cad<=47)
                            {
                            }
                            else
                            {
                                if(cad==39)
                                {
                                }
                                else
                                {
                                    if(cad==239)
                                    {
                                    }
                                    else
                                    {
                                        if(cad==233 || cad == 154)
                                        {

                                        }
                                        else
                                        {
                                            if(cad==153 || cad==224)
                                            {

                                            }
                                            else
                                            {
                                                if(cad==216 || cad== 214)
                                                {

                                                }
                                                else
                                                {
                                                    if(cad==211 || cad== 144)
                                                    {

                                                    }
                                                    else
                                                    {
                                                        if(cad==181 || cad==143)
                                                        {

                                                        }
                                                        else
                                                        {
                                                            printf("Simbolos no permitidos\n");
                                                            return 1;
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
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

//Longitud de cadena
int longitudDeCh (char msj[])
{
    //Lanzara los espacios ocupados o mas bn la longitud de un arreglo tipo char
    int i;
    for(i=0;msj[i]!='\0';i++);
    return i-1;
}