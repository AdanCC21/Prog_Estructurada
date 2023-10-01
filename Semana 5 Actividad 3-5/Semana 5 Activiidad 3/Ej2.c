/*Gonzalez Ceseña Adan 372799
Programa en C que sirva para el juego del CHINCHAMPU (Piedra, Papel, Tijera) para 1 jugador y la computadora
09/05/2023
Actv_3_2_932*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int j, c;
    srand(time(NULL));
    c=(rand()%3-1+1) +1;
    //rango final - rango inicial, +1, +rango inicio
    printf("Bienvenido al sistema de juego contra la computadora, seleccione un numero del 1 al 3\n");
    scanf("%d",&j);
    if(j!=c)
    {
        if(j==1)
        {
            if(c==2)
            {
                printf("Tu pierdes\nLa computadora escogio %d", c);
                return 0;
            }
            else
            {
                printf("Tu ganas\nLa computadora escogio %d", c);
                return 0;
            }
        }
        if(j==2)
        {
            if(c==1)
            {
                printf("Tu ganas\nLa computadora escogio %d", c);
                return 0;
            }
            else
            {
                printf("Tu pierdes\nLa computadora escogio %d", c);
                return 0;
            }
        }
        if(j==3)
        {
            if(c==2)
            {
                printf("Tu ganas\nLa computadora escogio %d", c);
            }
            else
            {
                printf("Tu pierdes\nLa computadora escogio %d", c);
            }
        }
    }
    else
    {
        printf("Empate");
    }
    return 0;
}