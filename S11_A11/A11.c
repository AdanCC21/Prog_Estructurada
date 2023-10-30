#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "libad.h"
#define P 2000

//       Structs        //

typedef struct alumno
{
    int n2;
    int ap2;
    int ap1;

    char name [30];
    char name2 [30];
    char app [30];
    char apm[30];

    int zone;
    int gen;
    
    char curp[18];
    int mat;
}alum;

typedef struct fecha
{
    int day;
    int month;
    int year;
    int age;
}birth;

typedef struct datos
{
    alum dalum;
    birth dbirth;
}data;

//      Prototipos      //

void menu ();
void opci();

void basic (data alu[],int p);


void print(data dat[], int p);

void li_estados();
void gencurp (data registro[], int p, int n2, int ap1, int ap2, char nombre[], char nombre2[],char app[], char apm[], int day, int month, int year, int gen, int estado);

//        Main          //
int main()
{
    opci();
    return 0;
}

//        Menu          //

void menu ()
{
    printf("\tMENU\n");
    printf("1.-Agregar\n");
    printf("2.-Eliminar Registro\n");
    printf("3.-Buscar\n");
    printf("4.-Ordenar\n");
    printf("5.-Imprimir\n");
    printf("6.-Archivo de texto\n");
    printf("0.-Salir del programa\n");
}

void opci()
{
    int op,op2,pu,po;
    pu=0;
    data registro[P];
    do
    {
        system("CLS");
        menu();
        op=valid2("Fuera de rango",0,6);
        switch(op)
        {
            case 1:
                system("CLS");
                if(pu<P)
                {
                    printf("1.-Agregar Manual\t2.-Agregar Automaticamente\t3.-Regresar\n");
                    op2=valid2("Ingrese una opcion valida",1,3);
                    
                    if(op2==1)
                    {
                        basic(registro,pu);
                        pu++;
                    }
                    else
                    {
                        if(op2==2)
                        {
                            pu++;
                        }
                        else
                        {
                            //Regresa
                        }

                    }
                }
                else
                {
                    printf("Registro lleno\n");
                    system("PAUSE");
                }
                break;
            case 2:
                
                break;

            case 3:

                break;
            case 4:

                break;
            case 5:
                scanf("%d",&po);
                print(registro,po-1);
                break;
            case 6:

                break;
            case 0:
                system("CLS");
                printf("Seguro que quieres salir del programa?\n1.-Si, salir\t2.-No, repetir\n");
                op=valid2("Ingrese una opcion valida valida",1,2);
                if(op==1)
                {
                    op=0;
                }
        }
    }
    while(op!=0);
    printf("Buen dia\n");
}

//      Funciones       //

void basic (data alu[],int p)
{
    int v;
    char cad[30];

    system("CLS");
    printf("Antes de iniciar a registrar datos, le pedire que aclare unos puntos\n");
    printf("Tiene 2 nombres?\n1.-Si\t2.-No\n");
    alu[p].dalum.n2=valid2("Fuera de rango",1,2);

    printf("Tiene 2 Apellidos?\n1.-Si\t2.-No\n");
    alu[p].dalum.ap2=valid2("Fuera de rango",1,2);
    alu[p].dalum.ap1=1;

    if(alu[p].dalum.ap2==2)
    {
        printf("Tiene 1 Apellido?\n1.-Si\t2.-No\n");
        alu[p].dalum.ap1=valid2("Fuera de rango",1,2);
    }

    system("CLS");
    printf("De acuerdo, ahora comenzaremos a llenar los datos basicos del alumno\n");
    printf("Ingrese su nombre\n");
    do
    {
        fflush(stdin);
        gets(cad);
        v=validCh(cad);
    }
    while (v==1);
    strcpy(alu[p].dalum.name,cad);

    if(alu[p].dalum.n2==1)
    {
        printf("Ingrese su segundo nombre\n");
        
        do
        {
            gets(cad);
            v=validCh(cad);
        }
        while (v==1);
        strcpy(alu[p].dalum.name2,cad);
    }

    if(alu[p].dalum.ap1==1)
    {
        printf("Ingrese su apellido paterno\n");
        do
        {
            gets(cad);
            v=validCh(cad);
        }
        while (v==1);
        strcpy(alu[p].dalum.app,cad);
    }

    if(alu[p].dalum.ap2==1)
    {
        printf("Ingrese su apellido materno\n");
        do
        {
            gets(cad);
            v=validCh(cad);
        }
        while (v==1);
        strcpy(alu[p].dalum.apm,cad);
    }
    
    printf("Ingrese su edad actual\n");
    alu[p].dbirth.age=valid2("Intente de nuevo",0,130);

    printf("Ingrese su anio de nacimiento\n");
    alu[p].dbirth.year=valid2("Caducado",1893,2023);

    printf("Ingrese el numero de mes\n");
    alu[p].dbirth.month=valid2("Fuera de rango",1,12);

    printf("Ingrese el dia\n");
    if(alu[p].dbirth.month==2)
    {
        if ((alu[p].dbirth.year % 4 == 0 && alu[p].dbirth.year % 100 != 0) || (alu[p].dbirth.year % 400 == 0))
        {
            alu[p].dbirth.day=valid2("Fuera de rango",1,29);
        }
        else
        {
            alu[p].dbirth.day=valid2("Fuera de rango",1,28);
        }
    }
    else
    {
        if(alu[p].dbirth.month==1)
        {
            alu[p].dbirth.day=valid2("Fuera de rango",1,31);
        }
        if(alu[p].dbirth.month==3)
        {
            alu[p].dbirth.day=valid2("Fuera de rango",1,31);
        }
        if(alu[p].dbirth.month==4)
        {
            alu[p].dbirth.day=valid2("Fuera de rango",1,30);
        }
        if(alu[p].dbirth.month==5)
        {
            alu[p].dbirth.day=valid2("Fuera de rango",1,31);
        }
        if(alu[p].dbirth.month==6)
        {
            alu[p].dbirth.day=valid2("Fuera de rango",1,30);
        }
        if(alu[p].dbirth.month==7)
        {
            alu[p].dbirth.day=valid2("Fuera de rango",1,31);
        }
        if(alu[p].dbirth.month==8)
        {
            alu[p].dbirth.day=valid2("Fuera de rango",1,31);
        }
        if(alu[p].dbirth.month==9)
        {
            alu[p].dbirth.day=valid2("Fuera de rango",1,30);
        }
        if(alu[p].dbirth.month==10)
        {
            alu[p].dbirth.day=valid2("Fuera de rango",1,31);
        }
        if(alu[p].dbirth.month==11)
        {
            alu[p].dbirth.day=valid2("Fuera de rango",1,30);
        }
        if(alu[p].dbirth.month==12)
        {
            alu[p].dbirth.day=valid2("Fuera de rango",1,31);
        }
    }

    printf("Ingrese su genero\n1.-Hombre\t2.-Mujer\n");
    alu[p].dalum.gen=valid2("Fuera de rango",1,2);

    li_estados();
    printf("Ingrese el indice del estado donde nacio\n");
    alu[p].dalum.zone=valid2("Fuera de rango",1,33);

    printf("Ingrese su matricula\n");
    alu[p].dalum.mat=valid2("Fuera de rango",300000,399999);

    gencurp(alu,p,alu[p].dalum.n2,alu[p].dalum.ap1,alu[p].dalum.ap2,alu[p].dalum.name,alu[p].dalum.name2,alu[p].dalum.app,alu[p].dalum.apm,alu[p].dbirth.day,alu[p].dbirth.month,alu[p].dbirth.year,alu[p].dalum.gen,alu[p].dalum.zone);

    printf("Posicion numero %d llena\n",p+1);
    printf("APELLIDO MATERNO : %s\n",alu[p].dalum.apm);
    system("PAUSE");
}

void li_estados()
{
    printf("1. Aguascalientes\t");
    printf("2. Baja California\t");
    printf("3. Baja California Sur\n");
    printf("4. Campeche\t\t");
    printf("5. Chiapas\t\t");
    printf("6. Chihuaha\n");
    printf("7. Coahuila\t\t");
    printf("8. Colima\t\t");
    printf("9. Durango\n");
    printf("10. Guanajuato\t\t");
    printf("11. Guerrero\t\t");
    printf("12. Hidalgo\n");
    printf("13. Jalisco\t\t");
    printf("14. Estado de Mexico\t");
    printf("15. Michoacan\n");
    printf("16. Morelos\t\t");
    printf("17. Nayarit\t\t");
    printf("18. Nuevo Leon\n");
    printf("19. Oaxaca\t\t");
    printf("20. Puebla\t\t");
    printf("21. Queretaro\n");
    printf("22. Quintana Roo\t");
    printf("23. San Luis Potosi\t");
    printf("24. Sinaloa\n");
    printf("25. Sonora\t\t");
    printf("26. Tabasco \t\t");
    printf("27. Tamaulipas\n");
    printf("28. Tlaxcala\t\t");
    printf("29. Veracruz\t\t");
    printf("30. Yucatan\n");
    printf("31. Zacatecas\t\t");
    printf("32. Ciudad de Mexico\t");
    printf("33. Extranjero\n");
}


void print(data dat[], int p)
{
    int i;
    char cad[33][100]={"Aguascalientes","Baja California","Baja California Sur","Campeche", "Chiapas", "Chihuahua","Coahuila", "Colima","Durango","Guanajuato","Guerrero","Hidalgo",
    "Jalisco","Estado de Mexico","Michoacan","Morelos","Nayarit","Nuevo Leon","Oaxaca","Puebla","Queretaro","Quintana Roo","San Luis Potosi","Sinaloa","Sonora","Tabasco","Tamaulipas",
    "Tlaxcala","Veracruz","Yucatan,","Zacatecas","Ciudad de Mexico","Extranjero"};

    printf("Alumno posicion %d\n",p+1);

    printf("NOMBRE : %s\n",dat[p].dalum.name);
    
    if(dat[p].dalum.n2==1)
    {
        printf("NOMBRE 2 : %s\n",dat[p].dalum.name2);
    }

    if(dat[p].dalum.ap1==1)
    {
        printf("APELLIDO PATERNO : %s\n",dat[p].dalum.app);
    }

    if(dat[p].dalum.ap2==1)
    {
        printf("APELLIDO MATERNO : %s\n",dat[p].dalum.apm);
    }

    printf("EDAD : %d\n",dat[p].dbirth.age);

    printf("GENERO : ");
    if(dat[p].dalum.gen==1)
    {
        printf("HOMBRE\n");
    }
    else
    {
        printf("MUJER\n");
    }

    printf("LUGAR DE NACIMIENTO :");
    printf("%s\n",cad[dat[p].dalum.zone-1]);

    printf("CURP :");
    for(i=0;i<18;i++)
    {
        printf("%c",dat[p].dalum.curp[i]);
    }
    printf("\n");
    
    system("PAUSE");

}

void gencurp (data curp[], int p, int n2, int ap1, int ap2, char nombre[], char nombre2[],char app[], char apm[], int day, int month, int year, int gen, int estado)
{
    char TempCurp[18];
    CU_Auto_Gen(TempCurp,n2,ap2,ap1,nombre,nombre2,app,apm,day,month,year,gen,estado);
    strcpy(curp[p].dalum.curp,TempCurp);
}


