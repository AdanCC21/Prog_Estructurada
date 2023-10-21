#include <stdio.h>
#include <string.h>

void read ();

int main()
{
    read ();
    return 0;
}

void read ()
{
    FILE *arch;
    char car;
    arch=fopen("C:\\Users\\adang\\OneDrive\\Documentos\\CHAMBA\\Prog_Estructurada\\Clase\\Eje2.c\\AsciiArt.txt","r");
    do
    {
        car=fgetc(arch);
        printf("%c",car);
    }
    while (!feof(arch));
    fclose(arch);
}