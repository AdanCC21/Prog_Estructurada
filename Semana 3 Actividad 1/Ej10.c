/*  -Gonzalez Ceseña Adan 372799
    -Programa que sirva para calcular el salario semanal de un trabajador donde se obtiene
    como dato de entrada las ​ horas semanales​ trabajadas, el ​ salario por hora​ .
    El programa deberá calcular el ​ salario normal​ , ​ salario extra​ y ​ salario total considerando lo siguiente:
    ● Jornada Normal de 40 horas.
    ● El salario normal se considera las horas trabajadas menores o igual a la jornada
    normal
    ● Salario extra se considera las horas trabajadas mayores a la jornada normal y se
    pagan dobles las primeras 9 y triples a partir de la décima hora extra
    08/27/2023
    Actividad_1_10_932 */
#include <stdio.h>
int main()
{
    int hsm, hrex;
    float slhr, slsm, slnm, slex;
    hrex=0;
    
    //pregunta que cuantas horas trabaja a la semana y cuanto le pagan por hora
    printf("Bienvenido\n Porfavor escriba cuantas horas trabaja a la semana contando horas extra (Numero entero y redondeado)\n");
    scanf("%d",&hsm);
    printf("\nCuanto le pagan por hora?\n");
    scanf("%f",&slhr);
    
    //calcular horas extra que se trabaja arriba de la jornada laboral normal
    if (hsm>40)
    {
        hrex=hsm-40;
        if(hrex<9)
        {
            slsm=slhr*hsm;
            slex=slhr*hrex;
        }
        if(hrex==9)
        {
            slex=(slhr*2)*hrex;
            slsm=(slhr*hsm)+slex;
        }
        if(hrex==10)
        {
            slex=(slhr*3)*hrex;
            slsm=(slhr*hsm)+slex;
        }
    }
    if(hsm<=40)
    {
        slsm=slhr*hsm;
    }
    slnm=slhr*(hsm-hrex);
    printf("Su salario semanal es de %.2f\n", slsm);
    printf("Las horas que trabaja a la semana serian %d\n", hsm);
    printf("Su salario normal seria %.2f\n",slnm);
    printf("Su salario extra seria %.2f\n", slex);
    printf("Su salario total seria %.2f\n", slsm);
    return 0;
}