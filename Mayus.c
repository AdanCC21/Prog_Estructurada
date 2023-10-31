#include <stdio.h>
#include <string.h>
#include "libad.h"

int main()
{
    int v;
    char cad[10];
    do
    {
        fflush(stdin);
        gets(cad);
        v=validCh(cad);
    }
    while (v==1);
    printf("%s",cad);
    
}