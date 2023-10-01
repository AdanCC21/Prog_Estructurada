/*Gonzalez Ceseña Adan 372799
Programa en C que sirva para el juego del CHINCHAMPU (Piedra, Papel, Tijera) para 1 jugador y la computadora
09/05/2023 - 09/10/2024
Actv_3_3_932*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int j, c;
    srand(time(NULL));
    c = (rand() % 3 - 1 + 1) + 1;
    // Variable, rand, maximo, minimo, +1, +minimo
    printf("Bienvenido al sistema de juego contra la computadora, seleccione un numero del 1 al 3\n");
    scanf("%d", &j);
    // pieda
    // papel
    // tijera
    if (j != c)
    {
        switch (j)
        {
        case 1:
            if (c == 2)
            {
                printf("Tu pierdes, Tu jugador escogio %d\n", c);
            }
            else
            {
                printf("Tu ganas, Tu jugador escogio %d\n", c);
            }
            break;
        case 2:
            if (c == 3)
            {
                printf("Tu perdiste, la computadora escogio %d\n", c);
            }
            else
            {
                printf("Tu ganas, la computadora escogio %d\n", c);
            }
            break;
        case 3:
            if (c == 1)
            {
                printf("Tu perdiste, la computadora escogio %d\n", c);
            }
            else
            {
                printf("Tu ganas, la computadora escogio %d\n", c);
            }
            break;
        default:
            printf("Algo salio mal\n");
        }
    }
    else
    {
        printf("Empate");
    }
    return 0;
}