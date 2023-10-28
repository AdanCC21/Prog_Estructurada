/*Gonzalez Ceseña Adan 372799
En la materia programación estructurada se aplican 5 exámenes, 
calcular el promedio final de la materia donde la calificación menor de los exámenes se anula y el promedio se calcula en base a 4 exámenes.
Desplegar el promedio final.
09/02/2023
Activ_4_7_932*/

#include <stdio.h>

int main()
{
    int c1,c2,c3,c4,c5,men,sum;
    float prom;
    printf("Bienvenido al sistemsa de calificaciones porfavor ingrese su primera calificacion (enteros del 1 al 100)\n");
    scanf("%d",&c1);
    men=c1;
    printf("Bienvenido al sistemsa de calificaciones porfavor ingrese su primera calificacion\n");
    scanf("%d",&c2);
    if(c2<men)
    {
        men=c2;
    }
    printf("Bienvenido al sistemsa de calificaciones porfavor ingrese su primera calificacion\n");
    scanf("%d",&c3);
    if(c3<men)
    {
        men=c3;
    }
    printf("Bienvenido al sistemsa de calificaciones porfavor ingrese su primera calificacion\n");
    scanf("%d",&c4);
    if(c4<men)
    {
        men=c4;
    }
     printf("Bienvenido al sistemsa de calificaciones porfavor ingrese su primera calificacion\n");
    scanf("%d",&c5);
    if(c5<men)
    {
        men=c5;
    }
    sum=(c1+c2+c3+c4+c5)-men;
    prom=sum/4;
    printf("su promedio es de %.2f y su calificacion mas baja es %d",prom, men);
    return 0;
}