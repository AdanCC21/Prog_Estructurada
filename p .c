#include <stdio.h>
#include <conio.h>

struct alumno
{
    char nombre[30];
    char nombre2[30];
    char app[30];
    char apm[30];
};

struct birth
{
    int month;
    int day;
    int year;
};

typedef struct datos
{
    struct alumno alu;
    struct birth fe;

}data;

int main()
{
    data name;
    printf("ponga su dia");
    printf("\n");
    scanf("%d",&name.fe.day);
    printf("\n");
    printf("%d",name.fe.day);
}
