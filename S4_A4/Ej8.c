/*Gonzalez Ceseña Adan 372799
Programa en C que sirva para el juego del CHINCHAMPU (Piedra, Papel, Tijera) para 1 jugador y la computadora, (usar condición anidada
09/02/2023
Activ_4_8_932*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
    int j, c;
    srand(time(NULL));
    c = rand() % 3 + 1;
    printf("Escriba su jugada\n1-Piedra, 2-Papel, 3-Tijera\n");
    scanf("%d",&j);
    if(j!=c)
    {
        if(j==1)
        {
            if(c==2)
            {
            printf("Perdiste tu oponente escogio %d\n", c);
            return 0;
            }
            if(c==3)
            {
            printf("Tu ganas, Tu oponente escogio %d\n", c);
            return 0;
            }
        }
        
        if(j==2)
        {
            if(c==3)
            {
                printf("Tu pierdes, tu oponente escogio %d\n", c);
                return 0;
            }
            if(c==1)
            {
                printf("Tu ganas, tu oponente escogio %d\n", c);
                return 0;
            }
        }
        
        if(j==3)
        {
            if(c==1)
            {
                printf("Tu pierdes, tu oponente escogio %d\n", c);
                return 0;
            }
            if(c==2)
            {    
                printf("Tu ganas, tu oponente escogio %d\n", c);
                return 0;
            }
        }
    }
    if(j==c)
    {
        printf("Empate\n");
        return 0;

    }
    return 0;
}