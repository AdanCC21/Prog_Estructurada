/*Gonzalez Ceseña Adan 372799
Programa en C que lea 3 números y despegarlos en forma ascendente (usar AND o OR)
09/10/2024
Actv_3_6_932*/
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
    if(num1<num2 && num2<num3)
    {
        printf("Su numero menor es %d, Intermedio %d y el mayor es %d", num1, num2, num3);
    }
    if(num2<num1 && num2<num3)
    {
        if(num1>num3)
        {
            printf("Su numero menor es %d, intermedio %d, y el mayor %d", num2, num3, num1);
        }
        else
        {
            printf("Su numero menor es %d, intermedio %d, y el mayor %d", num2, num1, num3);
        }
    }
    if(num3<num2 && num3<num1)
    {
        if(num2>num1)
        {
            printf("Su numero menor es %d, intermedio %d, y el mayor %d", num3, num1, num2);
        }
        else
        {
            printf("Su numero menor es %d, intermedio %d, y el mayor %d", num3, num2, num1);
        }
    }
    return 0;
}