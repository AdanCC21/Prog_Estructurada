/*Gonzalez Ceseña Adan 372799
Programa en C que lea 3 calificaciones calcule el promedio del alumno y desplegar
09/5/2023
Act_3_1_932*/
#include <stdio.h>

int main()
{
    int calif, c, sum, prom;
    c=1;
    sum=0;
    do
    {
        printf("Escribe su calificacion numero %d\n", c);
        scanf("%d",&calif);
        sum=sum+calif;
        c++;
    }
    while(c<=3);
    prom=sum/3;
    printf("Su promedio es %d\n",prom);
   if(prom>=80)
   {
        if(prom>=90)
        {
            if(prom>=100)
            {
                printf("Algo salio mal\n");
                return 0;
            }
            printf("MuyBien\n");
            return 0;
        }
    printf("Bien\n");
    return 0; 
   }
   else
   {
        if(prom<80)
        {
            if(prom<70)
            {
                if(prom<60)
                {
                    if(prom<30)
                    {
                        printf("repetir\n");
                        return 0;
                    }
                    printf("Extraordinario\n");
                    return 0;
                }
                printf("Suficiente\n");
                return 0;
            }
            printf("Regular\n");
            return 0;
        }
   }
   return  0;
}