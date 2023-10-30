#include <stdio.h>
#include <string.h>
#include "libad.h"

int main()
{
    int n;
    n=valid2("Fuera de rango\n",0,1);
    printf("%d",n);
}