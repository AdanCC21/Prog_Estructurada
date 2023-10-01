//Gonzalez Ceseña Adan 372799
//5.- Algoritmo que lea 3 calificaciones calcule el promedio del alumno y desplegar ciertas condiciones
//fecha 22/08/2023
//ACTIVIDAD_1_5_932
#include <stdio.h>
int main ()
{
    int calif1, calif2,calif3, sum;
    float prom;
    printf("Bienvenido al sistema de calificaciones del 0 al 100\n");
    printf("Escibra su primera calificacion del 0 al 100\n");
    scanf("%d",&calif1);
    sum=sum+calif1;
    printf("Escriba su segunda calificacion\n");
    scanf("%d", &calif2);
    sum=sum+calif2;
    printf("Escriba su tercera calificacion\n");
    scanf("%d",&calif3);
    sum=sum+calif3;
    prom=sum/4;
    if(prom<30)
    {
        printf("Usted va a repetir\n");
    }
    if(prom>=30 && prom<60)
    {
        printf("Usted va a extraordinario\n");
    }
    if(prom>=60 && prom<70)
    {
        printf("Su promedio es suficiente");
    }
    if(prom>=70 && prom<80)
    {
        printf("Su promedio es regular\n");
    }
    if(prom>=80 && prom<90)
    {
        printf("Su promedio esta bien");
    }
    if(prom>=90 && prom<=100)
    {
        printf("Su promedio es excelente");
    }
    if(prom>100)
    {
        printf("algo salio mal, Error en promedio");
    }
    return 0;
}