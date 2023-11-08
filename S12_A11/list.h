#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

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