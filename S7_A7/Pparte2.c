/*Gonzalez Ceseña Adan 372799
1.- Función que reciba como parámetro una cadena y la convierta a MAYUSCULAS
2.- Función Que reciba como parámetro una cadena y la convierta a MINUSCULAS
3.- Función que reciba como parámetro una cadena y la convierta a CAPITAL
4.-Función que reciba como parámetro una cadena y retorne la cantidad de caracteres que tiene la cadena.
5.-Función que reciba como parámetro una cadena y retorne una cadena con sus caracteres acomodados de forma inversa (al reves)
6.-Función que reciba como parámetro una cadena y genere una nueva cadena basada en la origina pero sin espacios.
7.-Función que sirva para leer una cadena y solo permita caracteres alfabéticos (A...Z) y el espacio, donde una cadena no puede comenzar o terminar con espacio, 
no debe tener dos espacios seguidos. retornar la cadena ya sea como parámetro o variable.
8.-Función que reciba como parámetro una cadena, y utilizando las funciones anteriores, imprima en MAYUSCULAS, MINUSCULAS , CAPITAL, SIN ESPACIOS, ALREVES la cadena original.
9.-Función que reciba como parámetro una cadena, y desplegar la leyenda si la cadena es un palíndromo SI o NO
25/09/2023
Actv_7_2_932 */

#include <stdio.h>
#include <stdlib.h>

int msges();
int msgCiclos();
void menu();
void printMayus(char cadena[]);
void printMinus(char cadena[]);
void printCapital(char cadena[]);
void printCantChar(char cadena[]);
void printReversa(char cadena[]);
void printSinEspacios(char cadena[]);
void printCharAlfa(char cadena[]);
void printAll(char cadena[]);
void printPalindromo(char cadena[]);

int main()
{
    menu();

    return 0;
}

int msges()
{
    int op;
    system("CLS");
    printf("\n   M  E   N   U \n");
    printf("1.- MAYUSCULAS \n");
    printf("2.- MINUSCULAS \n");
    printf("3.- CAPITAL \n");
    printf("4.- CANTIDAD CARACTERES \n");
    printf("5.- REVERSA \n");
    printf("6.- SIN ESPACIOS \n");
    printf("7.- CARACTERES ALFABETICOS \n");
    printf("8.- IMPRIMIR VARIAS \n");
    printf("9.- PALINDROMO \n");
    printf("0.- SALIR  \n");
    printf("ESCOGE UNA OPCION: ");
    scanf("%d", &op);
    return op;
}

void menu()
{
    int op;
    char cadena[30];
    system("CLS");
    printf("Ingrese una cadena: ");
    fflush(stdin);
    gets(cadena);
    do
    {
        op = msges();
        system("CLS");
        switch (op)
        {
        case 1:
            printMayus(cadena);
            break;
        case 2:
            printMinus(cadena);
            break;
        case 3:
            printCapital(cadena);
            break;
        case 4:
            printCantChar(cadena);
            break;
        case 5:
            printReversa(cadena);
            break;
        case 6:
            printSinEspacios(cadena);
            break;
        case 7:
            printCharAlfa(cadena);
            break;
        case 8:
            printAll(cadena);
            break;
        case 9:
            printPalindromo(cadena);
            break;
        case 0:
            return 0;
        }

        printf("\n\n");
        system("PAUSE");
    } while (op != 0);
}

void printMayus(char cadena[])
{
    int i;
    char caracter;
    for (i = 0; cadena[i] != '\0'; i++)
    {
        caracter = cadena[i];

        if (caracter >= 'a' && caracter <= 'z')
        {
            caracter -= 32;
        }

        printf("%c", caracter);
    }
}

void printMinus(char cadena[])
{
    int i;
    char caracter;
    for (i = 0; cadena[i] != '\0'; i++)
    {
        caracter = cadena[i];

        if (caracter >= 'A' && caracter <= 'Z')
        {
            caracter += 32;
        }

        printf("%c", caracter);
    }
}

void printCapital(char cadena[])
{

    int i;
    char caracter;
    caracter = cadena[0];
    if (caracter >= 'a' && caracter <= 'z')
    {
        caracter -= 32;
    }
    printf("%c", caracter);

    for (i = 1; cadena[i] != '\0'; i++)
    {
        caracter = cadena[i];

        if (caracter >= 'A' && caracter <= 'Z')
        {
            caracter += 32; // Convertir a minúscula 
        }

        printf("%c", caracter);
    }
}

void printCantChar(char cadena[])
{
    int largo;

    for (largo = 0; cadena[largo] != '\0'; largo++);
    printf("La cadena tiene %d caracteres", largo);
}

void printReversa(char cadena[])
{
    int i, j, largo;
    char inversa[30];
    for (largo = 0; cadena[largo] != '\0'; largo++)
        ;

    for (i = largo - 1, j = 0; i >= 0; i--, j++)
    {
        inversa[j] = cadena[i];
        printf("%c", inversa[j]);
    }
}

void printSinEspacios(char cadena[])
{
    int i, j;
    char cadenaSE[30];

    // Programa
    for (i = 0, j = 0; cadena[i] != '\0'; i++)
    {
        if (cadena[i] != ' ')
        {
            cadenaSE[j] = cadena[i];
            printf("%c", cadenaSE[j]);
            j++;
        }
    }
}

void printCharAlfa(char cadena[])
{

    int i, j;
    char cadenaAlfa[30];

    for (i = 0, j = 0; cadena[i] != '\0'; i++)
    {
        if ((cadena[i] == ' ') || (cadena[i] >= 'a' && cadena[i] <= 'z') || (cadena[i] >= 'A' && cadena[i] <= 'Z'))
        {
            if (cadena[i] != ' ' || (i > 0 && cadena[i + 1] != '\0' && cadena[i - 1] != ' '))
            {
                cadenaAlfa[j] = cadena[i];
                printf("%c", cadenaAlfa[j]);
                j++;
            }
        }
    }
}

void printAll(char cadena[])
{
    printf("Mayusculas: \n");
    printMayus(cadena);
    printf("\n\n");
    printf("Minusculas: \n");
    printMinus(cadena);
    printf("\n\n");
    printf("Capital: \n");
    printCapital(cadena);
    printf("\n\n");
    printf("Sin Espacios: \n");
    printSinEspacios(cadena);
    printf("\n\n");
    printf("Al reves: \n");
    printReversa(cadena);
}

void printPalindromo(char cadena[])
{
    int i, inicio = 0, fin, largo = 0;
    char caracter;
    char cadenaM[30];
    for (i = 0; cadena[i] != '\0'; i++)
    {
        caracter = cadena[i];
        if (caracter >= 'a' && caracter <= 'z')
        {
            caracter -= 32; // Convertir a mayúscula (ASCII)
        }

        if (caracter != ' ' && !(caracter >= '0' && caracter <= '9'))
        {
            cadenaM[largo] = caracter;
            largo++;
        }
    }
    fin = largo - 1;

    while (inicio < fin)
    {
        if (cadenaM[inicio] != cadenaM[fin])
        {
            printf("No es un palindromo");
            return;
        }

        inicio++;
        fin--;
    }
    printf("Si es un palindromo");
}