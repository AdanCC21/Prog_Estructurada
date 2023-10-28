/*Gonzalez Ceseña Adan 372799
Que el usuario inserta 2 digitos, y un menu para seleccionar operador
08/29/2023
Activiad 4_1_932*/

#include <stdio.h>
int main()
{
    int op;
    float num1, num2, r;
    printf("Bienvenido al menu de operadores\nPorfavor seleccione un operador\n1=Suma 2=Resta 3=Multiplicacion 4=Divicion\n");
    scanf("%d",&op);
    if(op<4 && op>0)
    {
        if(op==1)
        {
            printf("Escriba su primer numero\n");
            scanf("%f",&num1);
            printf("Esciba su segundo numero\n");
            scanf("%f",&num2);
            r=num1+num2;
            printf("Su respuesta es %.2f\n", r);
            return 0;
        }
        if(op==2)
        {
            printf("Escriba su primer numero\n");
            scanf("%f",&num1);
            printf("Escriba su segundo numero\n");
            scanf("%f",&num2);
            r=num1-num2;
            printf("Su resultado es %.2f\n",r);
            return 0;
        }
        if(op==3)
        {
            printf("Escriba su primer numero\n");
            scanf("%f",&num1);
            printf("Escriba su segundo numero\n");
            scanf("%f",&num2);
            r=num1*num2;
            printf("Su resultado es %.2f\n", r);
        }
        if(op==4)
        {
            printf("Escriba su primer numero\n");
            scanf("%f",&num1);
            printf("Escriba su segundo numero\n");
            scanf("%f",&num2);
            if(num1==0 || num2==0)
            {
                printf("No puede divir entre 0\n");
                return 0;
            }
            r=num1/num2;
            printf("Su resultado es %.2f\n",r);
            return 0;
        }
    }
    else
    {
        printf("Escoga una opcion valida\n");
    }
    return 0;
}