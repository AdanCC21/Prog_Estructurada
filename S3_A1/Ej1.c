//Gonzalez Cesena Adan Matricula 372799
//1.- Algoritmo que lea 4 calificaciones de un alumno, calcular y desplegar el promedio acompañado de la leyenda APROBADO o REPROBADO
//Fecha 22/08/2023
//Act_1_1_932

#include <stdio.h>
int calif1, calif2, calif3, calif4, prom, sum;
int main()
{
    sum=0;
    printf("Bienvenido al sistema de clalificaciones\n");
    printf("Escibra su primera calificacion del 0 al 100\n");
    scanf("%d",&calif1);
    sum=sum+calif1;
    printf("Escriba su segunda calificacion\n");
    scanf("%d", &calif2);
    sum=sum+calif2;
    printf("Escriba su tercera calificacion\n");
    scanf("%d",&calif3);
    sum=sum+calif3;
    printf("Escriba su cuarta calificacion \n");
    scanf("%d",&calif4);
    sum=sum+calif4;
    prom=sum/4;
    if(prom>=60)
    {
        printf("Su promedio es de %.2d, Felicidades usted a APROBADO\n", prom);
    }
    else
    {
        printf("Su promedio es de %.2d, Su calificacion no es aprobatoria, REPROBADO", prom);
    }
    return 0;
}