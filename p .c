#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "libad.h"

int main()
{
    srand(time(NULL));
    int c;
    for(int i=0;i<100;i++)
    {
        c=rand()%(10-1+1)+1;
        printf(" %d ",c);
    }
}
