#include <stdio.h>
int valid (char msj[],int ri, int rf)
{
    int n,band=0;
    do
    {
        printf("%s\n",msj);
        scanf("%d",&n);
        if(n>rf)
        {
            printf("Opcion invalida, intente de nuevo\n");
            band=1;
        }
        else
        {
            if(n<ri)
            {
                printf("Opcion invalida, intente de nuevo\n");
                band=1;
            }
        }
    }
    while(band!=0);
    return n;
}