#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

void li_nombres(char cad[],int gen)
{
    /*
        Hombre = 1
        Mujer = 2
    */
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

void li_generos (char cad[])
{
    int c;
    c=rand() % (2-1+1)+1;
    char generos[2][15] = {"HOMBRE","MUJER"};
    strcpy(cad,generos[c]);
}

void li_puestos (char cad[])
{
    int c;
    char puest [5][30] = {"EMPLEADO","SECRETARIO","AUXILIAR","LIMPIEZA","SEGURIDAD"};
    c = rand() % (5 - 1 + 1)+1;
    strcpy(cad,puest[c]);
}

int li_state_num(char cad[])
{
    int prefijo;
    char estados [33][100]={"Aguascalientes","Baja California","Baja California Sur","Campeche", "Chiapas", "Chihuahua","Coahuila", "Colima","Durango","Guanajuato","Guerrero","Hidalgo",
    "Jalisco","Estado de Mexico","Michoacan","Morelos","Nayarit","Nuevo Leon","Oaxaca","Puebla","Queretaro","Quintana Roo","San Luis Potosi","Sinaloa","Sonora","Tabasco","Tamaulipas",
    "Tlaxcala","Veracruz","Yucatan,","Zacatecas","Ciudad de Mexico","Extranjero"};

    return prefijo;
}
