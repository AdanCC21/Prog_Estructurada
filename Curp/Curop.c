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

void names(char name[],char app[], char apm[],char curp[]);
int birth (char curp[]);
void gen (char gen[]);
void zona (char curp[]);
void cons_int (char name[], char app[], char apm[], char curp[]);
void siglo (int year,char curp[]);

void prohb (char cad[]);
void estados ();

int main()
{
    //Me faltarian las nacionalidades creo (Preguntar si son de a wbo)
    char name[30],app[20],apm[20];
    char curp[18];
    int year;
    //Mandar name app y apm a cada funcion y remplazarlas por las ya definidas
    names(name, app, apm, curp);
    year = birth(curp);
    gen(curp);
    zona(curp);
    cons_int(name,app,apm,curp);
    siglo(year, curp);
    
    printf("%s",curp);
}


//      Funciones       //

void estados ()
{
    printf("1. Aguascalientes\n");
    printf("2. Baja California\n");
    printf("3. Baja California Sur\n");
    printf("4. Campeche\n");
    printf("5. Chiapas\n");
    printf("6. Chihuaha\n");
    printf("7. Coahuila\n");
    printf("8. Colima\n");
    printf("9. Durango\n");
    printf("10. Guanajuato\n");
    printf("11. Guerrero\n");
    printf("12. Hidalgo\n");
    printf("13. Jalisco\n");
    printf("14. Estado de Mexico\n");
    printf("15. Michoacan\n");
    printf("16. Morelos\n");
    printf("17. Nayarit\n");
    printf("18. Nuevo Leon\n");
    printf("19. Oaxaca\n");
    printf("20. Puebla\n");
    printf("21. Queretaro\n");
    printf("22. Quintana Roo\n");
    printf("23. San Luis Potosi\n");
    printf("24. Sinaloa\n");
    printf("25. Sonora\n");
    printf("26. Tabasco \n");
    printf("27. Tamaulipas\n");
    printf("28. Tlaxcala\n");
    printf("29. Veracruz\n");
    printf("30. Yucatan\n");
    printf("31. Zacatecas\n");
    printf("32. Ciudad de Mexico\n");
    printf("33. Extranjero\n");
}

void names(char name[],char app[], char apm[],char curp[])
{
    int i,np,band=0,v=0;

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

int birth (char curp[])
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
    return year;
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
    int estado;
    char cadEstado[33][2] = {"AS", "BC", "BS", "CC", "CS", "CH", "CL", "CM", "DG", "GT", "GR", "HG", "JC", "MC", "MN", "MS", "NT", "NL", "OC", "PL", "QT", "QR", "SP", "SL", "SR", "TC", "TS", "TL", "VZ", "YN", "ZS", "DF", "NE"};
    printf("Escoja su estado\n");
    estados();
    estado=valid("ingrese el indicide del estado",1,33);

    curp[11] = cadEstado[estado - 1][0];
    curp[12] = cadEstado[estado - 1][1];

}

void cons_int (char name[], char app[], char apm[], char curp[])
{
    int i,j,k,n,usada=0,BandVoc=0;;
    char vocal[5]={'A','E','I','O','U'};
    n=strlen(app);

    //Primera consonante
    for(i=0;i<n;i++)
    {
        for(j=0;j<5;j++)
        {
            if(app[i]==vocal[j])
            {
                BandVoc=1;
            }
        }
        if(BandVoc==0)
        {
            for(k=0;k<5;k++)
            {
                if(app[i]==curp[k])
                {
                    
                    usada=1;
                }
            }
            if(usada==0)
            {            
                curp[13]=app[i];
                i=n+1;
            }
            usada=0;
        }
        BandVoc=0;    
    }
    
    
    //Segunda consonante
    n=strlen(apm);
    for(i=0;i<n;i++)
    {
        for(j=0;j<5;j++)
        {
            if(apm[i]==vocal[j])
            {
                BandVoc=1;
            }
        }
        if(BandVoc==0)
        {
            for(k=0;k<5;k++)
            {
                if(apm[i]==curp[k])
                {
                    
                    usada=1;
                }
            }
            if(usada==0)
            {            
                curp[14]=apm[i];
                i=n+1;
            }
            usada=0;
        }
        BandVoc=0;    
    }

    //Tercera Consonante
    n=strlen(name);
    for(i=0;i<n;i++)
    {
        for(j=0;j<5;j++)
        {
            if(name[i]==vocal[j])
            {
                BandVoc=1;
            }
        }
        if(BandVoc==0)
        {
            for(k=0;k<5;k++)
            {
                if(name[i]==curp[k])
                {
                    
                    usada=1;
                }
            }
            if(usada==0)
            {            
                curp[15]=name[i];
                i=n+1;
            }
            usada=0;
        }
        BandVoc=0;    
    }
}

//Lista de la A hasta la J dependiendo el indicie
void let (char cad[],int n)
{
    n--;
    char list[10]={'A','B','C','D','E','F','G','H','I','J'};
    cad[0]=list[n];
}

//16
void siglo (int year,char curp[])
{
    int c;
    char cad[1];
    srand(time(NULL));
    if(year<2000)
    {
        c=rand()% (9-0+1)-0;
        itoa(c,cad,10);
        curp[16]=cad[0];
    }
    else
    {
        c=rand()% (10-1+1)+1;
        let(cad,c);
        curp[16]=cad[0]; 
    }

    c=rand()% (9-0+1)-0;
    itoa(c,cad,10);
    curp[17]=cad[0];
}
