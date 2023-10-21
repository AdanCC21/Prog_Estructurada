#include <stdio.h>
#include <string.h>

void read ();

int main()
{
    read();
}

void read ()
{
    FILE *arch;
    char car;

    arch=fopen("Name.txt","a");

    fprintf(arch,"ADAN ");
    fprintf(arch,"Gonzalez");

    fclose(arch);
}