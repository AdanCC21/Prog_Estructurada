#include <stdio.h>
#include <stdlib.h>

//Prototipos
int valid (char msg[],int ri, int rf);
int bus_sec (int vect [],int n,int num);
int num_alea_sr (int vect[], int n, int ri, int rf);
void impr_vect (int vect[],int n);

//Funciones
int valid (char msg[],int ri, int rf)
{
    char cad[50];
    int n;
    printf("\n");
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


void impr_vect (int vect[],int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        printf(" %d ", vect[i]);
    }
    printf("\n");
}

