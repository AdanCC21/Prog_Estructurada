#include <stdio.h>
#include <conio.h>

int main()
{
    int tecla;
    do
    {
    
    tecla=getch();
    printf("tecla %d\n",tecla);
    }
    while(tecla !=27);
}