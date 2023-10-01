/*Gonzalez Ceseña Adan 372799
Programa en C que sirva para calcular el Total a pagar por consumo de agua, donde el dato de entrada son los M3 de agua consumidos, Tomar en cuenta que se cobra escalonada de la Siguiente manera:
Rango1: 0 al 4 M3 $50 x facturación sin importar cuánto consumió en este rango
Rango2: 5 a 15 M3 $8.00 x M3
Rango3: 16 a 50 M3 $10.00 x M3
Rango4: 51 M3 en adelante $11.00 x M3
Desplegar SubTotal, Iva(16%), y Total a pagar.
09/02/2023
Activ_4_6_932*/
#include <stdio.h>
#define R1 50 /*No importa el m3*/
#define R2 8  /*x M3*/
#define R3 10 /*x m3*/
#define R4 11 /*x M3*/
#define IVA .16

int main()
{
    float m3c, sbt, iv, tl;
    printf("cuantos metros cubicos (M3) a consumido este mes?\n");
    scanf("%f",&m3c);
    if(m3c<=4)
    {
        sbt=R1;
    }
    if(m3c>4 && m3c<=15)
    {
        sbt=R1*m3c;
    }
    if(m3c>15 && m3c<=50)
    {
        sbt=R3*m3c;
    }
    if(m3c>51)
    {
        sbt=R4*m3c;
    }
    
    iv=sbt*IVA;
    tl=sbt+iv;
    printf("Su subtotal es de %.2f, se cobraran %.2f de iva y su total sera %.2f\nMuchas Gracias por usar nuestro servicio\n",sbt,iv,tl);
    return 0;
}