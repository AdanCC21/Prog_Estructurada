#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "libad.h"
#define P 2000

//       ------Structs------        //

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

//      ------Prototipos------      //

void menu ();
void opci();

void basic (data alu[],int p);
void AutoAlumn (data alu[],int p);
int eliminacion (data dat[],int pu);

int buscsec(data alumno[], int p, int num);
int buscbin(data alumno[], int lef, int rig, int num);

void ordenarB (data alumno[], int n);

void swap(data students[], int i, int j);
int partition(data students[], int low, int high);
void quicksort(data students[], int low, int high);


void print(data dat[], int p);
void print_tabla (data dat[], int p);
void txt (data dat[], int p);

void li_estados();
void li_nombres(char cad[],int gen);
void li_apellidos(char cad[]);
int edad (int year, int month, int day);
void gencurp (data registro[], int p, int n2, int ap1, int ap2, char nombre[], char nombre2[],char app[], char apm[], int day, int month, int year, int gen, int estado);

//        Main          //
int main()
{
    srand(time(NULL));
    opci();
    return 0;
}

//        ------Menu------          //

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
    int i,j,op,op2,pu,ord,el,qs;
    int num,bus,lef,rig;
    ord=0;
    pu=0;
    qs=0;
    data registro[P];
    do
    {
        system("CLS");
        menu();
        op=valid2("Fuera de rango",0,6);
        switch(op)
        {
            case 1:
            //      --------------------AGREGAR--------------------         //
                system("CLS");
                if(pu<P)
                {
                    printf("1.-Agregar Manual\t2.-Agregar Automaticamente\t3.-Regresar\n");
                    op2=valid2("Ingrese una opcion valida",1,3);
                    if(op2==1)
                    {
                        basic(registro,pu);
                        pu++;
                        ord=1;
                    }
                    else
                    {
                        if(op2==2)
                        {
                            j=P-pu;
                            if(j>100)
                            {
                                for(int k=0;k<2;k++)
                                {
                                    for(i=0;i<50;i++)
                                    {
                                        AutoAlumn(registro,pu);
                                        pu++;
                                        ord=1;
                                    }
                                }
                            }
                            else
                            {
                                for(i=0;i<j;i++)
                                {
                                    AutoAlumn(registro,pu);
                                    pu++;
                                    ord=1;
                                }
                            }
                            printf("Registros llenado\n");
                            system("PAUSE");
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
            //      --------------------ELIMINAR--------------------         //
                if(pu>0)
                {
                    printf("Seguro que quiere eliminar un registro?\n1.-Si, Eliminar\t2.-No, Salir\n");
                    el=valid2("Fuera de rango",1,2);
                    if(el==1)
                    {
                        pu=eliminacion(registro,pu);
                        printf("Hecho\n");
                        ord=1;
                        system("PAUSE");
                    }
                }
                else
                {
                    printf("Lista vacia\n");
                    system("PAUSE");
                }
                break;
            case 3:
            //      --------------------BUSCAR--------------------         //
                if(pu==0)
                {
                    printf("lista vacia\n");
                }
                else
                {
                    if(ord==0)
                    {
                        printf("Metodo de secuencial\n");
                        num=valid("Ingrese la matricula",300000,399999);
                        bus=buscsec(registro,pu,num);

                        if(bus==-1)
                        {
                            printf("No se encontro la matricula\n");
                        }
                        else
                        {
                            printf("La matricula se encuentra en la posicion %d \n", bus+1);
                            print(registro,bus);
                        }
                    }
                    else
                    {
                        printf("Busqueda binaria\n");
                        num=valid("Ingrese la matricula",300000,399999);
                        lef=0;
                        rig=pu;
                        
                        bus=buscbin(registro,lef, rig, num);
                        if(bus==-1)
                        {
                            printf("No se encontro la matricula\n");
                        }
                        else
                        {
                            printf("La matricula se encuentra en la posicion %d \n", bus+1);
                            print(registro,bus);
                        }
                    }
                }
                system("PAUSE");
                break;
            case 4:
            //      --------------------ORDENAR--------------------         //
            if(pu>0)
            {
                if(ord==0)
                {
                    printf("Ya esta ordenado\n");
                    
                }
                else
                {
                    if(pu<50)
                    {
                        printf("Metodo de burbuja\n");
                        ordenarB(registro,pu);
                        printf("Ordenada\n");
                    }
                    else
                    {
                        printf("Quicksort\n");
                        quicksort(registro,0,pu-1);
                        printf("Ordenada\n");
                        qs=1;
                    }

                }
                system("PAUSE");
                ord=1;
            }
            else
            {
                printf("Cadena vacia\n");
                system("PAUSE");
            }
                break;
            case 5:
            //      -------------------Imprimir--------------------         //
                if(pu>0)
                {
                    int k=40;
                    printf("%-5s %-15s %-15s %-15s %-15s %-10s %-10s %-20s %-20s %-15s %-18s\n","No.","Matricula","NOMBRE","NOMBRE 2","AP_PAT","AP_MAT","EDAD","DIA MES ANIO","ZONA","GENERO","CURP");
                    for(i=0;i<pu;i++)
                    {
                        if(i<k)
                        {
                            print_tabla(registro,i);
                        }
                        else
                        {
                            k=k+40;
                            system("PAUSE");
                        }
                    }
                    printf("Listo\n");
                }
                else
                {
                    printf("Lista vacia\n");
                }
                system("PAUSE");
                break;
            case 6:
            //      --------------------Archivo De Texto--------------------         //
                txt(registro,pu);
                printf("Archivo de texto creado\n");
                system("PAUSE");
                break;
            case 0:
            //      --------------------    SALIR   --------------------         //
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

//      ------Funciones------       //
void basic (data alu[],int p)
{
    int v;
    char cad[30];
    char tempN[30],tempN2[30],tempAp[30],tempApm[30];

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

    int TempAge;
    int tday, tmonth, tyear;

    tday=alu[p].dbirth.day;
    tmonth=alu[p].dbirth.month;
    tyear=alu[p].dbirth.year;

    TempAge=edad(tyear,tmonth,tday);
    alu[p].dbirth.age=TempAge;

    printf("Ingrese su genero\n1.-Hombre\t2.-Mujer\n");
    alu[p].dalum.gen=valid2("Fuera de rango",1,2);

    li_estados();
    printf("Ingrese el indice del estado donde nacio\n");
    alu[p].dalum.zone=valid2("Fuera de rango",1,33);

     strcpy(tempN,alu[p].dalum.name);

    strcpy(tempN2,alu[p].dalum.name2);
    
    strcpy(tempAp,alu[p].dalum.app);
    
    strcpy(tempApm,alu[p].dalum.apm);

    gencurp(alu,p,alu[p].dalum.n2,alu[p].dalum.ap1,alu[p].dalum.ap2,tempN,tempN2,tempAp,tempApm,alu[p].dbirth.day,alu[p].dbirth.month,alu[p].dbirth.year,alu[p].dalum.gen,alu[p].dalum.zone);

    printf("Ingrese su matricula\n");
    alu[p].dalum.mat=valid2("Fuera de rango",300000,399999);
        
    printf("Posicion numero %d llena\n",p+1);
}

void AutoAlumn (data alu[],int p)
{
    int c,y,m,d,z,mat,n;
    c=rand()%(2-1+1)+1;
    char name[30],ap[30],apm[30];
    char tempN[30],tempN2[30],tempAp[30],tempApm[30];
    

        alu[p].dalum.n2=1;
        alu[p].dalum.ap2=1;
        alu[p].dalum.ap1=1;

        li_nombres(name,c);
        strcpy(alu[p].dalum.name,name);

        li_nombres(name,c);
        strcpy(alu[p].dalum.name2,name);

        n=0;
        do
        {
            if(alu[p].dalum.name==alu[p].dalum.name2)
            {
                li_nombres(name,c);
                strcpy(alu[p].dalum.name2,name);
                n=1;
            }
            else
            {
                n=0;
            }
        }
        while(n!=0);

        li_apellidos(ap);
        strcpy(alu[p].dalum.app,ap);

        li_apellidos(apm);
        strcpy(alu[p].dalum.apm,apm);

        alu[p].dalum.gen=c;
        
        y=rand()%(2023-1900+1)+1900;
        alu[p].dbirth.year=y;

        m=rand()%(12-1+1)+1;
        alu[p].dbirth.month=m;

        d=rand()%(28-1+1)+1;
        alu[p].dbirth.day=d;

        int TempAge;
        int tday, tmonth, tyear;

        tday=alu[p].dbirth.day;
        tmonth=alu[p].dbirth.month;
        tyear=alu[p].dbirth.year;

        TempAge=edad(tyear,tmonth,tday);
        alu[p].dbirth.age=TempAge;

        z=rand()%(33-1+1)+1;
        alu[p].dalum.zone=z;

        mat=rand()%(399999-300000+1)+300000;
        alu[p].dalum.mat=mat;

        strcpy(tempN,alu[p].dalum.name);
        strcpy(tempN2,alu[p].dalum.name2);
        strcpy(tempAp,alu[p].dalum.app);
        strcpy(tempApm,alu[p].dalum.apm);

        gencurp(alu,p,alu[p].dalum.n2,alu[p].dalum.ap1,alu[p].dalum.ap2,tempN,tempN2,tempAp,tempApm,alu[p].dbirth.day,alu[p].dbirth.month,alu[p].dbirth.year,alu[p].dalum.gen,alu[p].dalum.zone);
}
//  ------ Elimanacion ------- //
int eliminacion (data dat[],int pu)
{
    int i,pe;
    printf("Que posicion desea eliminar\nPosciones registradas del 1 al %d\n",pu);
    pe=valid2("Posicion vacia",1,pu);
    pe--;
    for(i=pe;i<pu;i++)
    {
        dat[i]=dat[i+1];
    }
    pu--;
    return pu;
}
//  ------  Busqueads ------- //
int buscsec(data alumno[], int p, int num)
{
    int i;
    for(i=0;i<=p;i++)
    {
        if(alumno[i].dalum.mat==num)
        {
            return i;
        }
    }
    return -1;
}

int buscbin(data alumno[], int lef, int rig, int num) 
{
    int med;
    while (lef<=rig)
    {
        med=lef + (rig - lef) / 2;
        
        if(alumno[med].dalum.mat==num)
        {
            return med;
            lef=rig+1;
        }
        if(alumno[med].dalum.mat< num)
        {
            lef= med+1;
        }
        if(alumno[med].dalum.mat > num)
        {
            rig=med-1;
        }
    }
    return -1;
}
//  ------  Ordenar ------- //
void ordenarB (data alumno[], int n)
{
    int i,j;
    data temp;
    for(j=0;j<n;j++)
    {
        for(i=j+1;i<n;i++)
        {
            if(alumno[j].dalum.mat>alumno[i].dalum.mat)
            {
                temp=alumno[i];
                alumno[i]=alumno[j];
                alumno[j]=temp;
            }
        }
    }
}

//  ------Quicksort------- //
void swap(data students[], int i, int j)
{
    data temp = students[i];
    students[i] = students[j];
    students[j] = temp;
}

int partition(data students[], int low, int high)
{
    data pivot;
    pivot.dalum.mat = students[high].dalum.mat;
    int i = low - 1;

    for (int j = low; j <= high - 1; j++)
    {
        if (students[j].dalum.mat <= pivot.dalum.mat)
        {
            i++;
            swap(students, i, j);
        }
    }
    swap(students, i + 1, high);
    return i + 1;
}

void quicksort(data students[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(students, low, high);

        quicksort(students, low, pi - 1);
        quicksort(students, pi + 1, high);
    }
}

//  ------  Print   ------- //
void print(data dat[], int p)
{
    int i;
    char cad[33][100]={"Aguascalientes","Baja California","Baja California Sur","Campeche", "Chiapas", "Chihuahua","Coahuila", "Colima","Durango","Guanajuato","Guerrero","Hidalgo",
    "Jalisco","Estado de Mexico","Michoacan","Morelos","Nayarit","Nuevo Leon","Oaxaca","Puebla","Queretaro","Quintana Roo","San Luis Potosi","Sinaloa","Sonora","Tabasco","Tamaulipas",
    "Tlaxcala","Veracruz","Yucatan,","Zacatecas","Ciudad de Mexico","Extranjero"};

    printf("Alumno posicion %d\n",p+1);

    printf("MATRICULA : %d\n",dat[p].dalum.mat);

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

    printf("FECHA DE NACIMIENTO ");
    printf("%d - %d - %d\n",dat[p].dbirth.day, dat[p].dbirth.month, dat[p].dbirth.year);

    printf("EDAD : %d\n",dat[p].dbirth.age);

    printf("GENERO : ");
    if(dat[p].dalum.gen==1)
    {
        printf("HOMBRE\n");
    }
    else
    {
        if(dat[p].dalum.gen==2)
        {
            printf("MUJER\n");
        }
    }

    printf("LUGAR DE NACIMIENTO :");
    printf("%s\n",cad[dat[p].dalum.zone-1]);

    printf("CURP :");
    for(i=0;i<18;i++)
    {
        printf("%c",dat[p].dalum.curp[i]);
    }
    printf("\n");
}

void print_tabla (data dat[], int p) //ACOMODAR NADAMAS
{
    char cad[33][100]={"Aguascalientes","Baja California","Baja California Sur","Campeche", "Chiapas", "Chihuahua","Coahuila", "Colima","Durango","Guanajuato","Guerrero","Hidalgo",
    "Jalisco","Estado de Mexico","Michoacan","Morelos","Nayarit","Nuevo Leon","Oaxaca","Puebla","Queretaro","Quintana Roo","San Luis Potosi","Sinaloa","Sonora","Tabasco","Tamaulipas",
    "Tlaxcala","Veracruz","Yucatan,","Zacatecas","Ciudad de Mexico","Extranjero"};
    char temp[100];
    char tempg[10];
    strcpy(temp,cad[dat[p].dalum.zone - 1]);
    if(dat[p].dalum.gen==1)
    {
        strcpy(tempg,"HOMBRE");
    }
    else
    {
        strcpy(tempg,"MUJER");

    }
    printf("%-5d %-15d %-15s %-15s %-15s %-10s %-10d %-5d %-5d %-8d %-20s %-15s",p+1,dat[p].dalum.mat,dat[p].dalum.name,dat[p].dalum.name2,dat[p].dalum.app,dat[p].dalum.apm,dat[p].dbirth.age,dat[p].dbirth.day,dat[p].dbirth.month,dat[p].dbirth.year,temp,tempg);
    for(int i=0;i<18;i++)
    {
        printf("%c",dat[p].dalum.curp[i]);
    }
    printf("\n");

}

void txt (data dat[], int p)
{
    FILE *text = fopen ("C:\\Users\\PC\\Documents\\CHAMBA\\Prog_Estructurada\\S11_A11\\registro.txt","w");

    char cad[33][100]={"Aguascalientes","Baja California","Baja California Sur","Campeche", "Chiapas", "Chihuahua","Coahuila", "Colima","Durango","Guanajuato","Guerrero","Hidalgo",
    "Jalisco","Estado de Mexico","Michoacan","Morelos","Nayarit","Nuevo Leon","Oaxaca","Puebla","Queretaro","Quintana Roo","San Luis Potosi","Sinaloa","Sonora","Tabasco","Tamaulipas",
    "Tlaxcala","Veracruz","Yucatan,","Zacatecas","Ciudad de Mexico","Extranjero"};
    char temp[100];
    char tempg[10];

    fprintf(text, "%-5s %-15s %-15s %-15s %-15s %-10s %-10s %-20s %-20s %-15s %-18s\n","No.","Matricula","NOMBRE","NOMBRE 2","AP_PAT","AP_MAT","EDAD","DIA MES ANIO","ZONA","GENERO","CURP");
    for(int i=0;i<p;i++)
    {
        strcpy(temp,cad[dat[i].dalum.zone - 1]);
        if(dat[i].dalum.gen==1)
        {
            strcpy(tempg,"HOMBRE");
        }
        else
        {
            strcpy(tempg,"MUJER");

        }
        fprintf(text,"%-5d %-15d %-15s %-15s %-15s %-10s %-10d %-5d %-5d %-8d %-20s %-15s",i+1,dat[i].dalum.mat,dat[i].dalum.name,dat[i].dalum.name2,dat[i].dalum.app,dat[i].dalum.apm,dat[i].dbirth.age,dat[i].dbirth.day,dat[i].dbirth.month,dat[i].dbirth.year,temp,tempg);
        for(int k=0;k<18;k++)
        {
            fprintf(text,"%c",dat[i].dalum.curp[k]);
        }
        fprintf(text,"\n");    
    }
        fclose(text);
}
//  ------  Listas ------- //
int edad (int year, int month, int day)
{
    int y1,m1=12,d1=13;
    y1 = 2023 - year;
    if(month>m1)
    {
        y1--;
    }
    else
    {
        if(day>d1)
        {
            y1--;
        }
    }
    if(y1==-1)
    {
        y1++;
    }
    return y1;
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

void li_nombres(char cad[],int gen)
{
    
    int c;
    c=rand()%(20-1+1)+1;
    char namesM[20][30]={"MARIA", "SOFIA", "CARMEN", "ISABEL", "LAURA", "ANA", "JULIA", "PAULA", "ANAHI", "ROSA", "ELISA", "ELENA", "VANESA", 
    "ALICIA", "MONICA", "CLAUDIA", "DIANA", "SARA", "CAROLINA", "ANDREA"};

    char namesH[20][30]={"ADAN", "JAVIER", "MIGUEL", "CARLOS", "LUIS", "ALEJANDRO", "DIEGO", "ANDRES", "JUAN", "PEDRO", "FERNANDO", "RAUL", 
    "JOSE", "RICARDO", "HUGO", "OSCAR", "PABLO", "EMILIO", "SERGIO", "FRANCISCO"};

    if(gen==1)
    {
        strcpy(cad,namesH[c-1]);
    }
    else
    {
        if(gen==2)
        {
            strcpy(cad,namesM[c-1]);
        }
    }
}

void li_apellidos (char cad[])
{
    int c;
    c=rand() % (49-1+1)+1;
    char ap [50][30]= {"RODRIGUEZ", "GONZALEZ", "HERNANDEZ", "LOPEZ", "MARTINEZ", "PEREZ", "GARCIA", "SANCHEZ", "RAMIREZ", "TORRES", "FLORES", 
    "VAZQUEZ", "GOMEZ", "DIAZ", "REYES", "MORALES", "JIMENEZ", "ORTIZ", "CASTRO", "RUIZ", "ALVAREZ", "FERNANDEZ", "VARGAS", "RAMOS", "SUAREZ", "MENDOZA", 
    "CRUZ", "ALVAREZ", "RIVERA", "DOMINGUEZ", "MORENO", "BLANCO", "IGLESIAS", "ROMERO", "RUBIO", "NUNEZ", "SOSA", "GUTIERREZ", "MOLINA", "DELGADO", "AGUILAR", 
    "MEDINA", "GUERRERO", "SOTO", "SALAZAR", "ARIAS", "PAZ", "SOSA", "HERRERA"};
    strcpy(cad,ap[c-1]);
}

void gencurp (data curp[], int p, int n2, int ap1, int ap2, char nombre[], char nombre2[],char app[], char apm[], int day, int month, int year, int gen, int estado)
{
    char TempCurp[18];
    CU_Auto_Gen(TempCurp,n2,ap2,ap1,nombre,nombre2,app,apm,day,month,year,gen,estado);
    strcpy(curp[p].dalum.curp,TempCurp);
}
