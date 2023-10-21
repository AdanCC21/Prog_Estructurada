#include <stdio.h>
#include <string.h>
#include "libad.h"

int main()
{
    char cad[4];
    int month;
    printf("Que mes naciste?\n");
    month=valid("Ingrese su mes",1,12);
    strcpy(cad,month);
    printf("%s",cad);
}