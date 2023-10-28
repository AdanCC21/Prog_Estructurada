/*Gonzalez Ceseña Adan 372799
Programa en C que lea 3 números y desplegar el número del medio (usar AND o OR)
09/10/2024
Actv_3_5_932*/

#include <stdio.h>
int main()
{
    int num1, num2, num3;
    printf("oa\nporfavor escriba su numero entero positivo\n");
    scanf("%d",&num1);
    printf("Porfavor escriba su segundo numero entero positivo\n");
    scanf("%d",&num2);
    printf("Porfavor escriba su segundo numero entero positivo\n");
    scanf("%d",&num3);
    if((num1<num2 && num1>num3)||(num1>num2 && num1<num3))
    {
        printf("Su intermedio es %d", num1);
    }
    if((num2<num1 && num2>num3)||(num2>num1 &&num2<num3))
    {
        printf("Su intermedio es %d", num2);
    }
    if((num3<num2 && num3>num1)||(num3>num2 && num3<num1))
    {
        printf("Su intermedio es %d", num3);
    }
    return 0;
}