//Gonzalez Cesena Adan Matricula 372799
//6.- Algoritmo que lea 3 calificaciones calcule el promedio del alumno y desplegar que tan bien le fue
//Fecha 22/08/2023
//Actividad_1_6_932
#include <stdio.h>
int main()
{
    int calif, cond;
    cond=1;
    printf("Bienvenido al sistema de calificaciones\n");
    do
    {
        printf("\nVamos con la %d calificacion\n", cond);
        printf("Escribe tu calificacion\nDel 0 al 100 sin decimales\n");
        scanf("%d", &calif);
        if(calif<=30)
        {
            printf("Repetir\n");
        }else 
        {
            if(calif<=60)
            {
            printf("Extraordinario\n");
            }
            else
            {
                if(calif<=70)
                {
                    printf("Suficiente\n");
                }
                else
                {
                    if(calif<=80)
                    {
                        printf("Regular\n");
                    }
                    else
                    {
                        if(calif<=90)
                        {
                            printf("Bien\n");
                        }
                        else
                        {
                            if(calif<=100)
                            {
                            printf("excelente\n");
                            }
                            else
                            {
                                printf("Algo salio mal\n");
                            }
                        }
                    }
                }
            }
        }
        cond++;
    }
    while (cond <=3);

}