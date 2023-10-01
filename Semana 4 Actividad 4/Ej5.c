/*Gonzalez Ceseña Adan 372799
Programa en C que sirva para desplegar el Total de una llamada telefónica donde se pide como datos de entrada los minutos y el tipo de llamada, se cobra de la siguiente manera:
MENÚ
1.-Llamada Local $3.00 sin límite de tiempo
2.-Llamada Nacional $7.00 por los 3 primeros minutos y $2.00 minuto adicional
3.-Llamada Internacional $9.00 por los 2 primeros minutos y $4.00 minuto adicional
Desplegar, Subtotal,Iva (16%) y Total.
09/02/2023
Activ_4_5_932*/

#include <stdio.h>
#define LOCAL 3
#define NACIONAL 7
#define NA 2
#define INTER 9
#define INTA 4
#define IVA 0.16

int main()
{
    int tpll, tmp, tmpex;
    float sbt, ivv, tl;
    printf("Que tipo de llamada realizo\n1=Local \n2=Nacional \n3=Internacional\n");
    scanf("%d",&tpll);
    printf("Cuantos minutos estuvo en llamada?\n");
    scanf("%d",&tmp);
    if(tpll==1)
    {
        sbt=LOCAL;
        ivv=sbt*IVA;
        tl=sbt+ivv;
        printf("Su subtotal es de %.2f\nSu iva es de %.2f\nY su total seria de %.2f", sbt,ivv,tl);
    }
    else
    { 
        if(tpll==2)
        {
            if(tmp>3)
            {
                tmpex=tmp-3;
                sbt=NACIONAL + (NA*tmpex);
                ivv=sbt*IVA;
                tl=sbt+ivv;
                printf("Su subtotal es de %.2f\nSu iva es de %.2f\nY su total seria de %.2f", sbt,ivv,tl);
            }else
            {
                sbt=NACIONAL;
                ivv=sbt*IVA;
                tl=sbt+ivv;
                printf("Su subtotal es de %.2f\nSu iva es de %.2f\nY su total seria de %.2f", sbt,ivv,tl);
            }
    }
        else 
        {
            if(tpll==3)
            {
                if(tmp>2)
                {
                    tmpex=tmp-2;
                    sbt=INTER + (INTA*tmpex);
                    ivv=sbt*IVA;
                    tl=sbt+ivv;
                    printf("Su subtotal es de %.2f\nSu iva es de %.2f\nY su total seria de %.2f", sbt,ivv,tl);
                }
                else
                {
                sbt=INTER;
                ivv=sbt*IVA;
                tl=sbt+ivv;
                printf("Su subtotal es de %.2f\nSu iva es de %.2f\nY su total seria de %.2f", sbt,ivv,tl);
            }

            }
        }
    }
    return 0;
}