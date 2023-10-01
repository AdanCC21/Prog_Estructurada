/*Gonzalez Ceseña Adan 372799
Programa que haga converciones con un menu para el usuario
08/29/2023
Activ_4_2_932*/
#include <stdio.h>
int main()
{
    int op;
    float num1, r;
    printf("Bienvenido al menu de converciones\nSeleccione una opcion\n");
    printf("1-cm a pulgadas\n2-cm a pies\n3-Km a millas\n4-Pulgadas a cm\n5-Pies a cm\n6-millas a Km\n");
    scanf("%d",&op);
    if(op==1)
    {
        printf("Escoja sus cm\n");
        scanf("%f",&num1);
        r=num1/2.54;
        printf("De %.2f cm a pulgadas son %.2f pulgadas\n",num1, r);
        return 0;
    }
    if(op==2)
    {
        printf("Escoja sus cm\n");
        scanf("%f",&num1);
        r=num1/30.48;
        printf("De %.2f cm pasa a %.2f pies\n", num1, r);
        return 0;
    }
    if(op==3)
    {
        printf("Escoja sus km\n");
        scanf("%f",&num1);
        r=num1/1.609;
        printf("Pasamos de %.2f km a %.2f millas\n",num1, r);
        return 0;
    }
    if(op==4)
    {
        printf("Escoja sus pulgadas");
        scanf("%f",&num1);
        r=num1*2.54;
        printf("Su resultado es %.2f",num1);
        return 0;
    }
    if(op==5)
    {
        printf("Ingree sus pies\n");
        scanf("%f",&num1);
        r=num1*30.48;
        printf("Su valor de %.2f pies pasa a %.2f cm\n",num1,r);
        return 0;
    }
    if(op==6)
    {
        printf("Ingrese su valor de millas");
        scanf("%f",&num1);
        r=num1*1.609;
        printf("su resultado es %.2f\n",r);
        return 0;
    }
    return 0;
}