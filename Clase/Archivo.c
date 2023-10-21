#include <stdio.h>
#include <stdlib.h>

void read ();

int main()
{
    read();
    return 0;
}

void read ()
{
    char caract;
    FILE *arch;

    arch=fopen("Letra.txt", "r");
    
    do
    {
        caract=fgetc(arch);
        printf("%c",caract);            
    }
    while(!feof(arch));
    fclose(arch);
}