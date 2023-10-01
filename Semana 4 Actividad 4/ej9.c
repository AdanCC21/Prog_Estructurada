/*Gonzalez Ceseña Adan 372799
Programa en C que sirva para el juego del CHINCHAMPU (Piedra, Papel, Tijera) para 1 jugador y la computadora, (usar selección múltiple)
09/02/2023
Activ_4_9_932*/
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
        switch (c)
        {
            case 1: //piedra
                    if(j==2)
                    {
                        printf("Tu ganas, Tu oponente escogio %d\n",c);
                    }
                    else
                    {
                        printf("Tu pierdes, Tu oponente escogio %d\n",c);
                    }
                    break;
            case 2: //papel
                    if(j==1)
                    {
                        printf("Tu pierdes, Tu oponente escogio %d\n",c);
                    }
                    else
                    {
                        printf("Tu ganas, Tu oponente escogio %d\n",c);
                    }
                    break;
            case 3: //tijeras
                    if(j==2)
                    {
                        printf("Tu pierdes, Tu oponente escogio %d\n",c);
                    }
                    else
                    {
                        printf("Tu ganas, Tu oponente escogio %d\n",c);
                    }
                    break;
            default:
                    printf("Opcion invalida, algo salio mal");
                    break;
        }
    }
    else
    {
        printf("Empate\n");
    }
    return 0;
}
