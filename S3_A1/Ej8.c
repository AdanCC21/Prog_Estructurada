//Gonzalez Cesñea Adan 372799
//Algoritmo que lea 3 números y desplegar cuál número es del medio y su valor
//08/27/2023
//Actividad_1_8_932

#include <stdio.h>
int main()
{
    int num1, num2, num3, temp_num;
        printf("Escriba su primer numero entero positivo\n");
        scanf("%d",&num1);

        printf("Escriba su segundo numero\n");
        scanf("%d",&num2);

        printf("Escriba su tercer numero\n");
        scanf("%d",&num3);

        printf("\nSus numeros originales eran,\nNumero 1 : %d\nNumero 2 : %d\nNumero 3 : %d\n",num1, num2, num3);
        if(num2>num1)
        {
            temp_num=num1;
            num1=num2;
            num2=temp_num;
        }
        if(num3>num1)
        {
            temp_num=num1;
            num1=num3;
            num3=temp_num;
        }
        if(num3>num2)
        {
            temp_num=num3;
            num3=num2;
            num2=temp_num;
        }
        printf("Su valor intermedio seria : %d", num2);
    return 0;
}