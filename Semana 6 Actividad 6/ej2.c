/*Gonzalez Ceseña Adan 372799
1.- El profesor de una materia desea conocer la cantidad de sus alumnos que no tienen derecho al examen de nivelación.
Diseñe un programa en C que lea las calificaciones obtenidas en las 5 unidades por cada uno de los 40 alumnos y escriba la cantidad de ellos que no tienen derecho al examen de nivelación ( Los promedios menores de 50 no tiene derecho a examen de nivelación) .
2.- Realiza una función en C que imprima las tablas de multiplicar del 1 al 10
PRESIONA UNA TECLA PARA CONTINUAR.
3. Realizar función en C para un programa que sirva para leer n cantidad de números dentro de un rango dado por el usuario, desplegar la suma de los números y la media aritmética de los números válidos dentro del rango.
4- En los cabos la embarcación finisterra que tiene fondo de cristal, solo sale a navegar con un máximo de 10 turistas o un máximo de 700 kilos de pasajeros. (preguntar el peso a cada turista) con un máximo de 15% de sobrepeso. desplegar el promedio de peso de los turistas y cual de los 2 condiciones se cumplió.
5.- Un alumno solo puede cursar la misma asignatura en un máximo de 3 veses, si el alumno reprueba durante sus intentos deberá repetir la materia, y si en su tercera ocasión no aprueba se le dará de baja académica.
Elabore una función donde basada en sus 3 exámenes parciales calcular el promedio y basado en su promedio final, se deberá enviar mensaje al alumno de repetir materia, aprobado o baja temporal. 
Actv_6_2_18/09/2023*/

#include <stdio.h>

//prototipos
int menu ();
int valid(char opci[], int ri, int rf);
int opc();
void calif ();
void tablas ();
void rango ();
void turistas ();
void recursar ();

//main
int main ()
{
    menu();

}

//opciones
int opc()
{
    system("CLS");
    int op;
    printf("Escoja una de las opciones\n");
        printf("    1.-Calificaciones\n");
        printf("    2.-Tablas\n");
        printf("    3.-Rango\n");\
        printf("    4.-Turistas\n");
        printf("    5.-Recursar\n");
        printf("    0.-Salir del programa\n");
        op = valid("selecciona una opcion \n",0,5);
    return op;
}

//menu
int menu()
{
    system("CLS");
    int op;
    do
    {
        op = opc();
        switch(op)
        {
            case 1:
                calif();
                break;
            case 2:
                tablas();
                break;
            case 3:
                rango();
                break;
            case 4:
                turistas();
                break;
            case 5:
                recursar();
                break;
        }
    }
    while (op!=0);
}

//validacion
int valid(char opci[], int ri, int rf)
{
    int num;
    char cadena[50];
    do
    {
        printf("%s", opci);
        fflush(stdin);
        gets(cadena);
        num = atoi(cadena);
    } while (num < ri || num > rf);

    return num;
}

void calif()
{
    system("CLS");
    int calif1,calif2,calif3,sum,i,und,cd,sd,proms;
    float prom;
    sum=0;
    proms=0;
    cd=0;
    sd=0;
    printf("Bienvenido al sistema de calificaciones\n");
    for (i = 1; i <= 40; i++) 
    {
        proms = 0;
        for (und = 1; und <= 5; und++) {
            printf("Por favor ingrese las 3 calificaciones del 0 al 100 de la unidad %d de su alumno numero %d\n", und, i);

            printf("Calificacion 1\n");
            scanf("%d", &calif1);

            printf("Calificacion 2\n");
            scanf("%d", &calif2);

            printf("Calificacion 3\n");
            scanf("%d", &calif3);

            sum = calif1 + calif2 + calif3;
            proms += sum; 
        }
        prom = proms / 15.0;

        if (prom >= 50) {
            cd++;
        } else {
            sd++;
        }

        printf("Su promedio es de %.2f\n", prom);
    }
    printf("Tiene un total de %d alumnos con derecho y %d sin derecho",cd,sd);
    getchar();
}

void tablas ()
{
    system("CLS");
    int i,i2,mult;
    printf("Bienvenido al sistema de tablas\n");
    for(i=1;i<=10;i++)
    {
        for(i2=1;i2<=10;i2++)
        {
            mult=i*i2;
            printf("%d * %d = %d \n",i, i2, mult);
        }
    }
    system("PAUSE");
}

void rango ()
{
     int n, ri, rf, co = 0, sum = 0, num, i;
    float media;
    printf("Ingrese la cantidad de numeros a leer: ");
    scanf("%d", &n);
    printf("Ingrese el valor minimo del rango: ");
    scanf("%d", &ri);
    printf("Ingrese el valor maximo del rango: ");
    scanf("%d", &rf);
    for (i = 0; i < n; i++)
    {
        printf("Ingrese un numero: ");
        scanf("%d", &num);
        if (num >= ri && num <= rf)
        {
            sum += num;
            co++;
        }
    }
    if (co > 0)
    {
        media = (float)sum / co;
        printf("La suma de los numeros validos es: %d\n", sum);
        printf("La media aritmetica de los numeros validos es: %.2f\n", media);
    }
    else
    {
        printf("No se ingresaron numeros validos dentro del rango [%d, %d].\n", ri, rf);
    }
    system("PAUSE");
}

void turistas ()
{
    system("CLS");
    int numtu, maxtu, maxpe, i;
    float pstu, psto = 0, prompe;
    maxtu = 0;
    maxpe = 0;

    printf("Ingrese el numero de turistas: ");
    scanf("%d", &numtu);

    for (i = 1; i <= numtu; i++) 
    {
        printf("Ingrese el peso del turista %d (en kilos): ", i);
        scanf("%f", &pstu);

        psto += pstu;

        if (numtu <= 10) {
            maxtu = 1;
        }

        if (psto <= 700 && psto <= 1.15 * (numtu * pstu)) {
            maxpe = 1;
        }
    }
    prompe = psto / numtu;

    printf("El promedio de peso de los turistas es: %.2f kg\n", prompe);
    if (maxtu && maxpe) 
    {
        printf("Se cumplio ambas condiciones.\n");
    } else 
    {
        if (maxtu) 
        {
            printf("Se cumplio la condicion de maximo de turistas.\n");
        } 
        else 
        {
            if (maxpe) 
            {
                printf("Se cumplio la condicion de maximo de peso.\n");
            } 
            else
            {
                printf("No se cumplio ninguna condicion.\n");
            }
        }
    }
    system("PAUSE");
}

void recursar ()
{
    system("CLS");
    int calif1, calif2, calif3,prom,inte=0;
    do
    {
        printf("Escriba su calificacion del 1er examen\n");
        scanf("%d",&calif1);
        printf("Escriba su calificacion del 2er examen\n");
        scanf("%d",&calif2);
        printf("Escriba su calificacion del 3er examen\n");
        scanf("%d",&calif3);
        prom=(calif1+calif2+calif3)/3;
        if(prom>=60)
        {
            printf("Aprobaste felicidades\n");
            inte=-1;
        }
        else
        {
            printf("repobraste \n");
            inte++;
            if(inte>=3)
            {
                printf("repetir materia, intentos excesidos\n");
            }
        }
    }
    while(inte<3 && inte>0);
    system("PAUSE");
}
