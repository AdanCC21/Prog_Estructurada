#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

//      Prototipos      //

void CUopci();
void CUinicio();

void CUnames(char name[],char name2[], char app[], char apm[],char curp[],int n2,int ap1,int apm2);
int CUbirth (char curp[]);
void CUgen (char gen[]);
void CUzona (char curp[]);
void CUcons_int (char name[],char name2[], char app[], char apm[], char curp[],int n2,int ap1,int apm2);
void CUsiglo (int year,char curp[]);

void CUantisonantes (char curp[]);
void CUestados ();
void CUvalidAc (char cad[]);
void CUdes (char name[]);
int CUvalidCh(char cadena[]);

//      Menu        //


void CUopci()
{
    CUinicio();
}

void CUinicio ()
{
    char name[30],name2[30],app[20],apm[20];
    char curp[18];
    int year,n2,ap1=1,apm2;

    system("CLS");

    printf("Antes de iniciar quisiera aclarar unos datos\n");
    getch();

    printf("Usted tiene mas de 1 nombre?\n");
    n2=valid("1-Si,2-No",1,2);
    printf("Usted cuenta con sus 2 apellidos?\n");
    apm2=valid("1.-Si.2.-No",1,2);
    if(apm2==2)
    {
        printf("Usted cuenta con solo 1 apellido?\n");
        ap1=valid("1.-Si.2.-No",1,2);
    }

    system("CLS");
    printf("Vamos a iniciar a registrar sus datos\n");
    getch();

    CUnames(name,name2 ,app, apm, curp,n2,ap1,apm2);
    year = CUbirth(curp);
    CUgen(curp);
    CUzona(curp);
    CUcons_int(name,name2, app,apm,curp,n2,ap1,apm2);
    CUsiglo(year, curp);
    
    CUantisonantes(curp);
}


//      Funciones       //

void CUestados ()
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

void CU_Auto_Gen (char curp[], int names2, int ap2, int ap1, char name[],char name2[], char app[], char apm[], int day, int month, int  year, int gen, int estado)
{
    /*
        1=Si, 0=No
        names2 = Tiene 2 nombres?
        ap2= tiene 2 apellidos?
        ap1= tiene 1 apellido?
    */

    //      -----------------------------nombre y apellidos-----------------------------       //
    CUvalidAc(name);
    CUdes(name);

    if(names2==1)
    {
        CUvalidAc(name2);    
        CUdes(name2);
    }

    if(ap1==1)
    {
        CUvalidAc(app);
        CUdes(app);
    }

    if(ap2==1)
    {
        CUvalidAc(apm);
        CUdes(apm);
    }

    int np,band,usada,i,h,k,c;
    np=strlen(app);
    c=0;
    h=0;

    if(ap1==1)
    {
        //Inicial del primer apellido
        curp[0]=app[0];
    
        //Vocal del primer apellido
        for(i=0;i<np;i++)
        {
            if(band<=0)
            {
                usada=0;
                for(k=c;h<np;h++)
                {
                    if(app[k]==curp[0])
                    {
                        usada=1;
                    }
                }
                if(usada==0)
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
                c++;
            }
        }
        if(band==0)
        {
            curp[1]='X';
        }
    }
    else
    {
        curp[0]='X';
        curp[1]='X';
    }

    //Inicial del 2do apellido
    if(ap2==1)
    {
        curp[2]=apm[0];
    }
    else
    {
        curp[2]='X';
    }

    //Inicial del Nombre
    if(names2==1)
    {
        if( strcmp(name,"MARIA") == 0 || strcmp(name,"MA.") == 0 || strcmp(name,"MA") == 0 || strcmp(name,"M.") == 0 || strcmp(name,"M") == 0)
        {
            curp[3]=name2[0];
        }
        else
        {
            if(strcmp(name,"JOSE") == 0 || strcmp(name,"J") == 0 || strcmp(name,"J.") == 0)
            {
                curp[3]=name2[0];
            }
            else
            {
                curp[3]=name[0];
            }    
        }
    }
    else
    {
        curp[3]=name[0];
    }

    //      -----------------------------Anio de nacimiento------------------------------       //
    char cad[4];

    //  Anio    //
    itoa(year,cad,10);
    curp[4]=cad[2];
    curp[5]=cad[3];

    // Month    //
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

    // Days     //
    // tendra que venir validado el dia con el mes desde el programa exterior//
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
    //      -----------------------------   Genero  ------------------------------       //
    //                                1=Hombre  2.-Mujer                                 //

    if(gen==1)
    {
        curp[10]='H';
    }
    else
    {
        curp[10]='M';
    }
    //      -----------------------------     Zona   ------------------------------       //
    //      Vas a tener que imprimir la lista de estados desde el programa inicial        //

    char cadEstado[33][2] = {"AS", "BC", "BS", "CC", "CS", "CH", "CL", "CM", "DG", "GT", "GR", "HG", "JC", "MC", "MN", 
    "MS", "NT", "NL", "OC", "PL", "QT", "QR", "SP", "SL", "SR", "TC", "TS", "TL", "VZ", "YN", "ZS", "DF", "NE"};

    curp[11] = cadEstado[estado - 1][0];
    curp[12] = cadEstado[estado - 1][1];

    //      --------------------     Consonantes internas   ----------------------       //
    int j,n;
    int usadaC=0,BandVoc=0, bandU=0;
    char vocal[5]={'A','E','I','O','U'};

    //Primera consonante
    bandU=0;
    if(ap1==1) //Si tiene 1 apellido (Paterno)
    {
        n=strlen(app);
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
                    bandU=1;
                }
                usada=0;
            }
            BandVoc=0;    
        }

        if(bandU==0)
        {
            curp[13]='X';
        }
    }
    else //Si no tiene apellidos
    {
        curp[13]='X';
    }
    
    //Segunda consonante
    bandU=0;
    if(ap2==1) //Si tiene 2 apeidos
    {
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
                    bandU=1;

                }
                usada=0;
            }
            BandVoc=0;    
        }

        if(bandU==0)
        {
            curp[14]='X';
        }

    }
    else //Si solo tiene 1 apeido
    {
        curp[14]='X';
    }

    //Tercera Consonante
    bandU=0;
    if(names2==0)//Si tiene 1 nombre
    {
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
                    bandU=1;
                }
                usada=0;
            }
            BandVoc=0;    
        }

        if(bandU==0)
        {
            curp[15]='X';
        }
    }
    else //Si tiene 2 nombres
    {
        //Maria Jose
        if(strcmp(name,"MARIA") == 0 || strcmp(name,"MA.") == 0 || strcmp(name,"MA") == 0 || strcmp(name,"M.") == 0 || strcmp(name,"M") == 0 || strcmp(name,"JOSE") == 0 || strcmp(name,"J") == 0 || strcmp(name,"J.") == 0)
        {
            n=strlen(name2);
            for(i=0;i<n;i++)
            {
                for(j=0;j<5;j++)
                {
                    if(name2[i]==vocal[j])
                    {
                        BandVoc=1;
                    }
                }
                if(BandVoc==0)
                {
                    curp[15]=name2[i];
                    i=n+1;
                    bandU=1;    
                }
                BandVoc=0;    
            }
            if(bandU==0)
            {
            curp[15]='X';
            }
        }
        else
        {
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
                        bandU=1;
                    }
                    usada=0;
                }
                BandVoc=0;
            }

            if(bandU==0)
            {
                curp[15]='X';
            }
        }
    }

    //      --------------------     Penultima letra/Siglo   ----------------------       //
    char Scad[1];
    c=0;
    srand(time(NULL));

    if(year<2000)
    {
        c=rand()% (9-0+1)-0;
        itoa(c,Scad,10);
        curp[16]=Scad[0];
    }
    else
    {   
        if(year<=2010)
        {
            Scad[0]='A';
        }
        else
        {
            if(year<=2020)
            {
                Scad[0]='B';
            }
            if(year<=2030)
            {
                Scad[0]='C';
            }
        }
        curp[16]=Scad[0]; 
    }
    //      --------------------     Ultima letra/Aleatoria   ----------------------       //
    c=rand()% (9-0+1)-0;
    itoa(c,Scad,10);
    curp[17]=Scad[0];
}

void CUnames(char name[],char name2[], char app[], char apm[],char curp[],int n2,int ap1,int apm2)
{
    int i,np,band=0,k,v=0;
    int usada=0,c;

    printf("Ingrese su primer nombre\n");
    do
    {
        fflush(stdin);
        gets(name);
        v=CUvalidCh(name);
    }
    while(v==1);
    CUvalidAc(name);
    v=0;
    CUdes(name);
   
    if(n2==1)
    {
        printf("Ingrese su segundo nombre\n");
        do
        {
            fflush(stdin);
            gets(name2);
            v=CUvalidCh(name2);
        }
        while(v==1);
        CUvalidAc(name2);
        v=0;
        CUdes(name2);
    }
    printf("\n %d \n",ap1);

    if(ap1==1)
    {
        printf("Ingrese su apellido paterno\n");
        do
        {
            fflush(stdin);
            gets(app);
            v=CUvalidCh(app);
        }
        while(v!=0);
        CUvalidAc(app);
        v=0;
        CUdes(app);
    }
    
    

    if(apm2==1)
    {
        printf("Ingrese su apellido materno\n");
        do
        {
            fflush(stdin);
            gets(apm);
            v=CUvalidCh(apm);
        }
        while(v!=0);
        CUvalidAc(apm);
        v=0;
        CUdes(apm);
    }    

    np=strlen(app);
    c=0;
    int h=0;
    if(ap1==1)
    {
        //Inicial del primer apellido
        curp[0]=app[0];
    
        //Vocal del primer apellido
        for(i=0;i<np;i++)
        {
            if(band<=0)
            {
                usada=0;
                for(k=c;h<np;h++)
                {
                    if(app[k]==curp[0])
                    {
                        usada=1;
                    }
                }
                if(usada==0)
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
                c++;
            }
        }
        if(band==0)
        {
            curp[1]='X';
        }
    }
    else
    {
        curp[0]='X';
        curp[1]='X';
    }

    //Inicial del 2do apellido
    if(apm2==1)
    {
        curp[2]=apm[0];
    }
    else
    {
        curp[2]='X';
    }

    //Inicial del Nombre
    if(n2==1)
    {
        if( strcmp(name,"MARIA") == 0 || strcmp(name,"MA.") == 0 || strcmp(name,"MA") == 0 || strcmp(name,"M.") == 0 || strcmp(name,"M") == 0)
        {
            curp[3]=name2[0];
        }
        else
        {
            if(strcmp(name,"JOSE") == 0 || strcmp(name,"J") == 0 || strcmp(name,"J.") == 0)
            {
                curp[3]=name2[0];
            }
            else
            {
                curp[3]=name[0];
            }    
        }
    }
    else
    {
        curp[3]=name[0];
    }
    
}

int CUbirth (char curp[])
{
    int day,month, year;
    char cad[4];

    year=valid("Que anio nacio \n(4 - digitos)",1893,2023);
    itoa(year,cad,10);
    curp[4]=cad[2];
    curp[5]=cad[3];
    
    printf("Que mes naciste?\n");
    month=valid("Numero del mes",1,12);
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
    
    if(month==2)
    {
        if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
        {
            day=valid("Ingrese el dia",1,29);
        }
        else
        {
            day=valid("Ingrese el dia",1,28);
        }
    }
    else
    {
        if(month==1)
        {
            day=valid("Ingrese el dia",1,31);
        }
        if(month==3)
        {
            day=valid("Ingrese el dia",1,31);
        }
        if(month==4)
        {
            day=valid("Ingrese el dia",1,30);
        }
        if(month==5)
        {
            day=valid("Ingrese el dia",1,31);
        }
        if(month==6)
        {
            day=valid("Ingrese el dia",1,30);
        }
        if(month==7)
        {
            day=valid("Ingrese el dia",1,31);
        }
        if(month==8)
        {
            day=valid("Ingrese el dia",1,31);
        }
        if(month==9)
        {
            day=valid("Ingrese el dia",1,30);
        }
        if(month==10)
        {
            day=valid("Ingrese el dia",1,31);
        }
        if(month==11)
        {
            day=valid("Ingrese el dia",1,30);
        }
        if(month==12)
        {
            day=valid("Ingrese el dia",1,31);
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

void CUgen (char curp[])
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

void CUzona (char curp[])
{
    int estado;
    char cadEstado[33][2] = {"AS", "BC", "BS", "CC", "CS", "CH", "CL", "CM", "DG", "GT", "GR", "HG", "JC", "MC", "MN", "MS", "NT", "NL", "OC", "PL", "QT", "QR", "SP", "SL", "SR", "TC", "TS", "TL", "VZ", "YN", "ZS", "DF", "NE"};
    printf("Escoja su estado\n");
    CUestados();
    printf("\n");
    estado=valid("Ingrese el indice del estado",1,33);

    curp[11] = cadEstado[estado - 1][0];
    curp[12] = cadEstado[estado - 1][1];

}

void CUcons_int (char name[],char name2[], char app[], char apm[], char curp[],int n2,int ap1,int apm2)
{
    int i,j,k,n,usada=0,BandVoc=0;;
    int bandU;
    char vocal[5]={'A','E','I','O','U'};

    //Primera consonante
    bandU=0;
    if(ap1==1)
    {
        n=strlen(app);
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
                    bandU=1;
                }
                usada=0;
            }
            BandVoc=0;    
        }

        if(bandU==0)
        {
            curp[13]='X';
        }
    }
    else
    {
        curp[13]='X';
    }
    
    //Segunda consonante
    bandU=0;
    if(apm2==1)
    {
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
                    bandU=1;

                }
                usada=0;
            }
            BandVoc=0;    
        }

        if(bandU==0)
        {
            curp[14]='X';
        }

    }
    else
    {
        curp[14]='X';
    }

    //Tercera Consonante
    //Si tiene 1 nombre
    bandU=0;
    if(n2==2)
    {
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
                    bandU=1;
                }
                usada=0;
            }
            BandVoc=0;    
        }

        if(bandU==0)
        {
            curp[15]='X';
        }
    }
    else //Si tiene 2 nombre
    {
        //Maria Jose
        if(strcmp(name,"MARIA") == 0 || strcmp(name,"MA.") == 0 || strcmp(name,"MA") == 0 || strcmp(name,"M.") == 0 || strcmp(name,"M") == 0 || strcmp(name,"JOSE") == 0 || strcmp(name,"J") == 0 || strcmp(name,"J.") == 0)
        {
            n=strlen(name2);
            for(i=0;i<n;i++)
            {
                for(j=0;j<5;j++)
                {
                    if(name2[i]==vocal[j])
                    {
                        BandVoc=1;
                    }
                }
                if(BandVoc==0)
                {
                    curp[15]=name2[i];
                    i=n+1;
                    bandU=1;    
                }
                BandVoc=0;    
            }
            if(bandU==0)
            {
            curp[15]='X';
            }
        }
        else
        {
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
                        bandU=1;
                    }
                    usada=0;
                }
                BandVoc=0;
            }

            if(bandU==0)
            {
                curp[15]='X';
            }
        }
    }
}

void CUlet (char cad[],int n)
{
    n--;
    char list[10]={'A','B','C','D','E','F','G','H','I','J'};
    cad[0]=list[n];
}

void CUsiglo (int year,char curp[])
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
        if(year<=2010)
        {
            CUlet(cad,1);
        }
        else
        {
            if(year<=2020)
            {
                CUlet(cad,2);
            }
            if(year<=2030)
            {
                CUlet(cad,3);
            }
        }
        curp[16]=cad[0]; 
    }
    c=rand()% (9-0+1)-0;
    itoa(c,cad,10);
    curp[17]=cad[0];
}

//      Validaciones        //

void CUvalidAc (char cad[])
{
    int i,n;
    unsigned char caract;
    n=strlen(cad);
    for(i=0;i<n;i++)
    {
        caract=(unsigned char)cad[i];

        if(caract==181)
        {
            cad[i]='A';
        }
        if(caract==142)
        {
            cad[i]='A';
        }

        if(caract==144)
        {
            cad[i]='E';
        }
        if(caract==211)
        {
            cad[i]='E';
        }

        if(caract==214)
        {
            cad[i]='I';
        }
        if(caract==216)
        {
            cad[i]='I';
        }

        if(caract==224)
        {
            cad[i]='O';
        }
        if(caract==153)
        {
            cad[i]='O';
        }

        if(caract==233)
        {
            cad[i]='U';
        }
        if(caract==154)
        {
            cad[i]='U';
        }
        if(caract==164)
        {
            cad[i]='X';
        }
        if(caract==165)
        {
            cad[i]='X';
        }
        if(caract==44)
        {
            cad[i]='X';
        }
        if(caract==45)
        {
            cad[i]='X';
        }
        if(caract==46)
        {
            cad[i]='X';
        }
        if(caract==47)
        {
            cad[i]='X';
        }
        if(caract==39)
        {
            cad[i]='X';
        }
        if(caract==239)
        {
            cad[i]='X';
        }
    }
}

void CUantisonantes (char curp[])
{
    char antisonantes[][100] = {"BACA", "BAKA", "BUEI", "BUEY", "CACA", "CACO", "CAGA", "CAGO", "CAKA", "CAKO", "COGE", "COGI", "COJA", "COJE","COJI", "COJO", "COLA", "CULO", "FALO", 
    "FETO", "GETA", "GUEI", "GUEY", "JETA", "JOTO", "KACA", "KACO", "KAGA","KAGO", "KAKA", "KAKO", "KOGE", "KOGI", "KOJA", "KOJE", "KOJI", "KOJO", "KOLA", "KULO", "LILO", "LOCA", 
    "LOCO","LOKA", "LOKO", "MAME", "MAMO", "MEAR", "MEAS", "MEON", "MIAR", "MION", "MOCO", "MOKO", "MULA", "MULO", "NACA","NACO", "PEDA", "PEDO", "PENE", "PIPI", "PITO", "POPO", 
    "PUTA", "PUTO", "QULO", "RATA", "ROBA", "ROBE", "ROBO","RUIN", "SENO", "TETA", "VACA", "VAGA", "VAGO", "VAKA", "VUEI", "VUEY", "WUEI", "WUEY"};

    char cad[5];
    strncpy(cad,curp,4);
    cad[4]='\0';
    for (int i = 0; i <= 81; i++)
    {
        if (strcmp(cad, antisonantes[i]) == 0)
        {
            curp[1]='X';
        }
    }
}

void CUdes (char name[])
{
    char conj[][3]={"DA","DAS","DE", "DEL", "DER", "DI", "DIE", "DD", "EL", "LA", "LOS", "LAS", "LE", "LES", "MAC", "MC", "VAN", "VON", "Y"};
    int lon,i,k,esp=0;
    lon=strlen(name);
    
    for(k=0;k<=lon;k++)
    {
        if(name[k]==' ')
        {
            esp=k;
        }
    }

    i=0;
    if(esp>0)
    {
        for(k=0;k<=lon;k++)
        {
            if(strstr(name,conj[k])==0)
            {
                do
                {
                    name[i]=name[esp+1];
                    i++;
                    esp++;
                }
                while(esp<lon);
            }
        }
    }
}

int CUvalidCh(char cadena[])
{
    int i=0;
    unsigned char cad;
    if (cadena[0] == ' ')
    {
        printf("Tu texto no puede iniciar con un espacio\n");
        return 1;
    }
    if (cadena[0] == '\0')
    {
        printf("Texto vacio\n");
        return 1;
    }

    while (cadena[i] != '\0')
    {
        cad=(unsigned char)cadena[i];

        if ((cadena[i] >= 'A' && cadena[i] <= 'Z'))
        {
            
        }
        else
        {
            if ((cadena[i] >= 'a' && cadena[i] <= 'z'))
            {
                printf("Porfavor ingresa solamente letras mayusculas\n");
                return 1;
            }
            else
            {
                if (cadena[i] == ' ')
                {
                    
                }
                else
                {
                    if(cad== 164)
                    {   
                    }
                    else
                    {
                        if(cad==165)
                        {
                        }
                        else
                        {
                            if(cad>=44 && cad<=47)
                            {
                            }
                            else
                            {
                                if(cad==39)
                                {
                                }
                                else
                                {
                                    if(cad==239)
                                    {
                                    }
                                    else
                                    {
                                        if(cad==233 || cad == 154)
                                        {

                                        }
                                        else
                                        {
                                            if(cad==153 || cad==224)
                                            {

                                            }
                                            else
                                            {
                                                if(cad==216 || cad== 214)
                                                {

                                                }
                                                else
                                                {
                                                    if(cad==211 || cad== 144)
                                                    {

                                                    }
                                                    else
                                                    {
                                                        if(cad==181 || cad==143)
                                                        {

                                                        }
                                                        else
                                                        {
                                                            printf("Simbolos no permitidos\n");
                                                            return 1;
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        i++;
    }

    if (cadena[i - 1] == ' ')
    {
        printf("Tu texto no puede terminar con espacio\n");
        return 1;
    }

    return 0; 
}