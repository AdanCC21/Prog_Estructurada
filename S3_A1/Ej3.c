//Gonzalez Cesena Adan Matricula 372799
//Fecha 22/08/2023
//3.- Algoritmo que lea 4 calificaciones de un alumno, calcular y desplegar el promedio acompañado de la leyenda APROBADO o REPROBADO
//Actividad_1_3_932

#include <stdio.h>
int main()
{
    int calif1, calif2, calif3, calif4, sum;
    float prom;
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
        printf("Su calificacion es %.2f, APROBATORIA\n", prom);
    }
    else
    {
        printf("Su calificacion es %.2f, REPROBATORIA\n", prom);
    }
}
