#include <stdio.h>
#include <string.h>

void read ();

int main()
{
    read();
    return 0;
}

void read ()
{
    FILE *arch;
    char car1[10],car2[10],car3[10],car4[10];

    arch=fopen("cadenas.txt","a");
    gets(car1);
    gets(car2);
    gets(car3);
    gets(car4);
    fprintf(arch,"%s\n%s\n%s\n%s\n",car1, car2, car3, car4);
    fclose(arch);
}