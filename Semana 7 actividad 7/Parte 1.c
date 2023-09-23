#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Protitipos
//main
int main()
{
    int i,lon,lon2,lon3,res;
    char msj [100];
    fflush(stdin);
    strcpy(msj,"ENSENADA");
    //salida 1
    printf("%s",msj);
    printf("\n");
    //saber el tamano de la cadena
    
    for(i=0;msj[i]!='\0';i++);
    lon=i;
    lon2=lon;
    lon3=lon;

    printf("\n%d\n",i);

    //salida 2
    for(i;i>=0;i--)
    {
        printf(" %c ",msj[i]);
    }
    printf("\n");
    //salida 3
    for(i;i!=0;i++)
    {
        printf("%c\n",msj[i]);
    }
    printf("\n");
    //salida 4
    for(lon;lon>=0;lon--)
    {
        printf("%c\n",msj[lon]);
    }


    printf("\nsalida 8\n");
    //salida 8
    for(lon2;lon2>=0;lon2--)
    {
        lon3=lon2;
        for(lon3;lon3>=0;lon3--)
        {
            printf("%c",msj[lon3]);
        }
        printf("\n");
    }
}