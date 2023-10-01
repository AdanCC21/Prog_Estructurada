/*Gonzalez Ceseña Adan 372799
Programa que despliegue 6 numeros y diga cual de todos es el mayor
09/02/2023
Activ_4_3_932*/

#include<stdio.h>
int main()
{
    int num1, num2, num3, num4, num5, num6, mayor;
    //pedimos valores
    printf("Ingrese su primer valor\n");
    scanf("%d",&num1);
    printf("Ingrese su segundo valor\n");
    scanf("%d",&num2);
    printf("Ingrese su tercer valor\n");
    scanf("%d",&num3);
    printf("Ingrese su cuarto valor\n");
    scanf("%d",&num4);
    printf("Ingrese su quinto valor\n");
    scanf("%d",&num5);
    printf("Ingrese su sexto valor\n");
    scanf("%d",&num6);
    //Buscamos el mayor entre todos
    mayor=num1;
    if(num2>mayor)
    {
        mayor=num1;
        
    }   
    if(num3>mayor)
        {
            mayor=num3;
        }
    if(num4>mayor)
        {
            mayor=num4;
        }
    if(num5>mayor)
        {
            mayor=num5;
        }
    if(num6>mayor)
    {
        mayor=num6;
    }
    printf("Su numero mayor es %d ",mayor);


}