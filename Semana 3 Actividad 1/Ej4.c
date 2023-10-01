//Gonzalez Ceseña Adan 372799
//Algoritmo que a través de opciones (1.- HOMBRE 2.- MUJER ) preguntar al usuario cual es su SEXO y desplegar la leyenda “HOLA, ERES HOMBRE ”, “ HOLA, ERES MUJER”
//fecha 22/08/2023
//Act_1_4_932
#include <stdio.h>
int main()
{
    int gen;
    printf("Escoga su genero\n");
    printf("1.-Hombre, 2.-Mujer\n");
    scanf("%d",&gen);
    if(gen==1)
    {
        printf("Hola Eres Hombre\n");
    }
    else
    {
        printf("Hola eres Mujer\n");
    }
    return 0;
}