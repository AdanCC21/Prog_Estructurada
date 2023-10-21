/*  
    Gonzalez Cesena Adan 372799
    Curp
    20/10/2023
    Actv_9.5_932
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "libad.h"

//      Prototipos      //

int menu ();
int opci();

void names(char curp[]);
void birth (char curp[]);
void gen (char gen[]);
void zona (char curp[]);
void cons_int (char name[], char app[], char apm[]);
void siglo (char year[]);

void prohb (char cad[]);
void estados (char cad[]);

int main()
{
    char curp[18];
    names(curp);
    birth(curp);
    gen(curp);
    
    printf("%s",curp);
}


//      Funciones       //

void estados (char cad[])
{
    //No creo que jale este pedo
    //revisa que pedo como podria comparar la cadena resivida con la lista de estados y en base a la posicion donde encuentre la similitud enviar el bc o cs
    int i,num=0;
    char list[100][50]={"AGUAS CALIENTES","BAJA CALIFORNIA","BAJA CALIFORNIA SUR","CAMPECHE","COAHUILA","COLIMA","CHIAPAS","CHIHUAHUA","DISTRITO FEDERAL","DURANGO","GUANAJUATO",
    "GUERRERO","HIDALGO","JALISCO","MEXICO","MICHOACAN"};
    char list2[100][50]={"AS ","BC","BS","CC","CL","CM","CS","CH","DF","DG","GT",
    "GR","HG","JG","MC","MN"};
    char temp[10];
    for(i=0;i<=100;i++)
    {
        if(cad[i]==list[i])
        {
            num=i;
        }
    }
    strcpy(cad,list2[num]);
}

void names(char curp[])
{
    int i,np,band=0,v=0;
    char name[30],app[20],apm[20];

    printf("Ingrese su nombre\n");
    do
    {
        fflush(stdin);
        gets(name);
        v=validCh(name);
    }
    while(v==1);
    v=0;
    
    printf("Ingrese su apeido paterno\n");
    do
    {
        fflush(stdin);
        gets(app);
        v=validCh(app);
    }
    while(v!=0);
    v=0;
    
    printf("Ingrese su apeido materno\n");
    do
    {
        fflush(stdin);
        gets(apm);
        v=validCh(apm);
    }
    while(v!=0);
    v=0;

    np=longitudDeCh(app);

    //Inicial del primer apellido
    curp[0]=app[0];

    //Vocal del primer apellido
    for(i=0;i<np;i++)
    {
        if(band<=0)
        {
            if(app[i]== 'A')
            {
                curp[1]=app[i];
                band++;
            }
            else
            {
                if(app[i]=='E')
                {
                    curp[1]=app[i];
                    band++;
                }
                else
                {
                    if(app[i]=='I')
                    {
                        curp[1]=app[i];
                        band++;
                    }
                    else
                    {
                        if(app[i]=='O')
                        {
                            curp[1]=app[i];
                            band++;
                        }
                        else
                        {
                            if(app[i]=='U')
                            {
                                curp[1]=app[i];
                                band++;
                            }
                        }
                    }
                }
            }
        }
    }
    if(band==0)
    {
        curp[1]='X';
    }

    //Inicial del 2do apellido
    curp[2]=apm[0];

    //Inicial del Nombre
    curp[3]=name[0];
}

void birth (char curp[])
{
    int day,month, year;
    char cad[4];

    printf("Que dia anio naciste\n");
    year=valid("Ingrese el anio",1800,2023);
    itoa(year,cad,10);
    curp[4]=cad[2];
    curp[5]=cad[3];
    
    printf("Que mes naciste?\n");
    month=valid("Ingrese el mes",1,12);
    itoa(month,cad,10);
    
    if(month<10)
    {
        curp[6]='0';
        curp[7]=cad[0];
    }
    else
    {
        curp[6]=cad[0];
        curp[7]=cad[1];
    }

    printf("Que dia naciste\n");
    if(month==2)
    {
        if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
        {
            day=valid("Ingrese su dia",1,29);
        }
        else
        {
            day=valid("Ingrese su dia",1,28);
        }
    }
    else
    {
        if(month==1)
        {
            day=valid("Ingrese su dia",1,31);
        }
        if(month==3)
        {
            day=valid("Ingrese su dia",1,31);
        }
        if(month==4)
        {
            day=valid("Ingrese su dia",1,30);
        }
        if(month==5)
        {
            day=valid("Ingrese su dia",1,31);
        }
        if(month==6)
        {
            day=valid("Ingrese su dia",1,30);
        }
        if(month==7)
        {
            day=valid("Ingrese su dia",1,31);
        }
        if(month==8)
        {
            day=valid("Ingrese su dia",1,31);
        }
        if(month==9)
        {
            day=valid("Ingrese su dia",1,30);
        }
        if(month==10)
        {
            day=valid("Ingrese su dia",1,31);
        }
        if(month==11)
        {
            day=valid("Ingrese su dia",1,30);
        }
        if(month==12)
        {
            day=valid("Ingrese su dia",1,31);
        }
    }

    itoa(day,cad,10);
    
    if(day<10)
    {
        curp[8]='0';
        curp[9]=cad[0];
    }
    else
    {
        curp[8]=cad[0];
        curp[9]=cad[1];
    }

}

void gen (char curp[])
{
    int op;
    printf("Seleccione su genero\n");
    op=valid("1.-Hombre 2.-Mujer",1,2);
    if(op==1)
    {
        curp[10]='H';
    }
    else
    {
        curp[10]='M';
    }
}

void zona (char curp[])
{

}