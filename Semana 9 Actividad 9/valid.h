#include <stdio.h>
#include <stdlib.h>

//Prototipos
int valid (char msg[],int ri, int rf);

int valid (char msg[],int ri, int rf)
{
    int cad[50],n;
    do
    {
        printf("%s\n",msg);
        //Imprime mensaje

        fflush(stdin);
        //limpiamos memoria

        fgets(cad, sizeof(cad),stdin);
        /*Le la cadena y hace lo sig, cad donde se guardara, sizeof(cad) el limite de caracteres en este ejemplo ponemos los 50 espacios de cad
        stdin de donde sera la entrada, por ejemplo el teclado stdin*/

        n=atoi(cad);
        //convierte la cadena a int o numero entero pue, ejemplo a en codigo asci vale 65 pero en asci, convierte ese 65 a int valor entero
    }
    while(n>rf || n<ri);
    //Mientras n este fuera de rango, repetira

    return n;
}