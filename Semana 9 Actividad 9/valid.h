#include <stdio.h>
int valid (char msj[],int ri, int rf)
{
    int n;
    do
    {
        printf("%s\n",msj);
        scanf("%d",&n);
        if(n>rf)
        {
            printf("Opcion invalida, intente de nuevo\n");
        }
        else
        {
            if(n<ri)
            {
                printf("Opcion invalida, intente de nuevo\n");
            }
        }
    }
    while(n>rf || n<ri);
    return n;
}