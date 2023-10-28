/*Gonzalez Ceseña Adan 372799
Programa en C que sirva para calcular el salario semanal de un trabajador donde se obtiene como dato de entrada las horas semanales trabajadas, el salario por hora.
El programa deberá calcular el salario normal, salario extra y salario total
09/02/2023
Activ_4_4_932*/
#include <stdio.h>
int main()
{
    int hsm, hrex;
    float slhr, slsm, slnm, slex, slex2, slext;
    hrex=0;
    slex=0;
    slex2=0;
    //pregunta que cuantas horas trabaja a la semana y cuanto le pagan por hora
    printf("Bienvenido\nPorfavor escriba cuantas horas trabaja a la semana contando horas extra (Numero entero y redondeado)\n");
    scanf("%d",&hsm);
    printf("\nCuanto le pagan por hora?\n");
    scanf("%f",&slhr);
    
    //calcular horas extra que se trabaja arriba de la jornada laboral normal
    if (hsm>40)
    {
        hrex=hsm-40;
        if(hrex<=9)
        {
            slex=(slhr*2)*hrex;
            
        }
        if(hrex>=10)
        {
            slex2=(slhr*3)*hrex;
        }
    }
    if(hsm<=40)
    {
        slsm=slhr*hsm;
    }
    slnm=slhr*(hsm-hrex);
    slsm=slnm+slex+slex2;
    slext=slex+slex2;
    printf("Su salario semanal es de %.2f\n", slsm);
    printf("Las horas que trabaja a la semana serian %d\n", hsm);
    printf("Su salario normal seria %.2f\n",slnm);
    printf("Su salario extra seria %.2f\n", slext);
    printf("Su salario total seria %.2f\n", slsm);
    return 0;
}
