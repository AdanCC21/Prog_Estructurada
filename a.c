#include <stdio.h>
#include "libad.h"

int main()
{
    srand(time(NULL));
    int c;
    c=rand() %(11-1+1)+1;
    printf("%d",c);
}