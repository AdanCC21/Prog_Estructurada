/*Gonzalez Ceseña Adan 372799
parte 1 de la actividad 6 en la cual hacemos 3 ejercicios con for, dowhile y while cada uno
MENÚ
1.- FIBONACCI
2.- FACTORIAL
3.- CANTIDAD DE DÍGITOS

1.- PROGRAMA QUE PREGUNTE LA CANTIDAD DE VECES QUE DESEA QUE SE REALICE EL PROGRAMA DE FIBONACCI

2.- PROGRAMA QUE PIDA UN NÚMERO Y DESPLEGAR LA SALIDA DE FACTORIAL DE UN NÚMERO DADO.

3.- PROGRAMA QUE PIDA UN NÚMERO Y DESPLEGAR LA CANTIDAD DE DÍGITOS QUE TIENE EL NÚMERO.
Actv_6_1_18/09/2023*/
#include <stdio.h>

void menu();

void menuFibonacci();
void fibonacciFor();
void fibonacciWhile();
void fibonacciDoWhile();

void menuFactorial();
void factorialFor();
void factorialWhile();
void factorialDoWhile();


void menuDigitCounter();
void digitCounterFor();
void digitCounterWhile();
void digitCounterDoWhile();


int main()
{
    menu();
    return 0;
}

void menu()
{
    int op;
    printf("MENU:\n");
    printf("1.- Fibonacci\n");
    printf("2.- Factorial\n");
    printf("3.- Cantidad de digitos\n");
    scanf("%d", &op);

    switch (op)
    {
        case 1:
            menuFibonacci();
            break;
        case 2:
            menuFactorial();
            break;
        case 3:
            menuDigitCounter();
            break;
        default:
            printf("Opcion invalida");
            break;
    }
}

void menuFibonacci()
{
    int op;
    printf("Menu Fibonacci:\n");
    printf("1.- For\n");
    printf("2.- While\n");
    printf("3.- Do While\n");
    printf("Selecciona una opcion: ");
    scanf("%d", &op);
    switch (op)
    {
        case 1:
            fibonacciFor();
            break;
        case 2:
            fibonacciWhile();
            break;
        case 3:
            fibonacciDoWhile();
            break;
        default:
            printf("Error - Opcion no valida.");
            break;
    }
}

void fibonacciFor()
{
    int num;
    int n1, n2, aux;
    n1=-1;
    n2=1;
    aux=n1+n2;
    printf("Ingrese su numero\n");
    scanf("%d", &num);
    for (int i = 0; i < num ; i++)
    {
        aux = n1 + n2;
        n1 = n2;
        n2 = aux;
        printf("%d\n", aux);
    }

}
void fibonacciWhile()
{
    int num;
    int n1, n2, aux;
    n1=-1;
    n2=1;
    aux=n1+n2;
    printf("Ingrese su numero\n");
    scanf("%d", &num);
    
    int i = 0;
    while (i < num)
    {
        aux = n1 + n2;
        n1 = n2;
        n2 = aux;
        printf("%d\n", aux);
        i++;
    }
}
void fibonacciDoWhile()
{
    int num;
    int n1, n2, aux;
    n1=-1;
    n2=1;
    aux=n1+n2;
    printf("Ingrese su numero\n");
    scanf("%d", &num);

    int i = 0;
    do
    {
        aux = n1 + n2;
        n1 = n2;
        n2 = aux;
        printf("%d\n", aux);
        i++;
    } while (i < num);
}


void menuFactorial()
{
    int op;
    printf("Menu Factorial:\n");
    printf("1.- For\n");
    printf("2.- While\n");
    printf("3.- Do While\n");
    printf("Selecciona una opcion: ");
    scanf("%d", &op);
    switch (op)
    {
        case 1:
            factorialFor();
            break;
        case 2:
            factorialWhile();
            break;
        case 3:
            factorialDoWhile();
            break;
        default:
            printf("Opcion invalida");
            break;
    }
}
void factorialFor()
{
    int r, num;
    r=1;
    printf("Ingrese su numero\n");
    scanf("%d", &num);  
    for (int i = 1; i <= num; i++)
    {
        r = r * i; 
    }

    printf("El factorial del numero %d es %d.", num, r);
}
void factorialWhile()
{
    int r, num;
    r=1;
    printf("Ingrese su numero\n");
    scanf("%d", &num);  

    int i = 1;
    while (i <= num)
    {
        r = r * i;
        i++;
    }

    printf("El factorial del numero %d es %d.", num, r);
}
void factorialDoWhile()
{
    int r, num;
    r=1;
    printf("Ingrese su numero\n");
    scanf("%d", &num);  
    int i = 1;
    do
    {
        r = r * i;
        i++;
    } while (i <= num);

    printf("El factorial del numero %d es %d.", num, r);
}

void menuDigitCounter()
{
    int op;
    printf("Menu Contar Digitos:\n");
    printf("1.- For\n");
    printf("2.- While\n");
    printf("3.- Do While\n");
    printf("Selecciona una opcion: ");
    scanf("%d", &op);

    switch (op)
    {
    case 1:
        digitCounterFor();
        break;
    case 2:
        digitCounterWhile();
        break;
    case 3:
        digitCounterDoWhile();
        break;
    default:
        printf("Opcion invaldia");
        break;
    }
}
void digitCounterFor()
{
     int num, aux;
    int i = 0;
    printf("Numero a contar los digitos: ");
    scanf("%d", &num);
    aux = num;
    for(i; aux > 0; i++)
    {
        aux = aux / 10;
    }
    printf("%d", i);
}
void digitCounterWhile()
{
    int num, aux, i;
    printf("Ingrese su numero\n");
    scanf("%d", &num);
    aux = num;
    i = 0;
    while (aux > 0)
    {
        aux = aux / 10;
        i++;
    }
    printf("%d", i);
}
void digitCounterDoWhile()
{
    int num, aux;
    printf("Ingrese su numero\n");
    scanf("%d", &num);
    aux = num;
    int i = 0;
    do
    {
        aux = aux / 10;
        i++;
    } while (aux > 0);
    printf("%d", i);
}