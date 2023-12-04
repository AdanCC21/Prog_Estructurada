#include <stdio.h>
#include <string.h>

int main()
{
    int array[5] = {3,7,5,8,6};
    int tam = sizeof(array)/sizeof(array[0]);

    printf("Original\n");
    prin(array,tam);

    qs(array,0,tam-1);

    printf("Alterado\n");
    prin(array,tam);
}

void qs (int array[],int start,int finish)
{
    int l,r,med;
    l=start;
    r=finish;
    med = array[(l+r)/2];

    do
    {
        while (array[l]<med && l<finish)
        {
            l++;
        }
        
        while(array[r]>med && r>start)
        {
            r--;
        }

        if(l<=r)
        {
            int temp;
            temp=array[l];
            array[l]=array[r];
            array[r]=temp;
            l++;
            r--;
        }
        
    }while(l <= r);

    if(start <= r)
    {
        qs(array,start,r);
    }

    if(finish >= l)
    {
        qs(array,l,finish);
    }
}

void prin(int array[],int tam)
{
    int i;
    for (i = 0;i<tam;i++)
    {
        printf("%d ",array[i]);
    }
    printf("\n");
}