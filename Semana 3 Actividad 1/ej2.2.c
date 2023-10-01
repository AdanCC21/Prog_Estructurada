//Gonzalez Cesena Adan matricula 372799
//Codigo para identificar si es par o impar
//fecha 22/08/2023
//actividad_1_2_932
#include <stdio.h>
int main()
{
    int num1;
    float cal;
    printf("Escriba su numero entero\n");
    scanf("%d",&num1);
    cal=num1 % 2;
    if(cal==0)
    {
        printf("Su numero es par");
    }
    else
    {
        printf("Su numero es impar");
    }
}