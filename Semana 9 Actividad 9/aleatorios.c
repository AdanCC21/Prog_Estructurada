#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "valid.h"

//Prototipos
int aleat (int vect[], int n);
int bsec (int vect[], int n, int num);
int prin (int vect[],int n);

int main()
{
    int n=10;
    int vect[n];
    srand(time(NULL));
    int vl;
    vl=valid("ingrese una cantidad",1,3);
    aleat(vect,n);
    prin (vect, n);
    return 0;
    
}

int bsec (int vect [],int n,int num)
{
    int i;
    for(i=0;i<n;i++)
    {
        if(vect[i]==num)
        {
            return i;
        }
    }
    return -1;
}

int aleat (int vect[], int n)
{
    int c, i;
    for(i=0;i<n;i++)
    {
        do
        {
            c=rand() % (20-10+1)+10;
        }
        while(bsec(vect,n,c)!=-1);
        vect[i]=c;
    }
    return 0;
}

int prin (int vect[],int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        printf(" %d ", vect[i]);
    }
    return 0;
}