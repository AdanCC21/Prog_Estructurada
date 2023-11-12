/*  
    Gonzalez Cesena Adan 372799

    Programa que contenga el menú anterior, el programa utiliza un vector de registros de máximo 1,500 registros, de la siguiente estructura: [status, matricula, ApPat, ApMat, Nombre, Edad, sexo] donde el campo llave es matricula. 
    datos.txt  es el archivo con los registros a cargar en el vector de registros
    1.- Cargar Archivo : El programa deberá cargar el vector de registros desde el archivo de texto (solo podrá cargarse una sola vez el archivo)
    2.- Agregar : El programa deberá ser capaz de agregar un 10 registros al arreglo y al final del archivo de texto.  (Generar automáticamente los datos).
    3.- Eliminar : El programa deberá buscar una matrícula en el vector por medio del método de búsqueda más óptimo. Utilizar banderas para escoger el método más adecuado., imprimir el registro y preguntar si se quiere eliminar el registro, (al cerrar el programa se deberar agregar al archivo borrados el registro o registros eliminados, asi se debera mantener dos archivos uno con datos validos y otro con los datos que se borraron)
    4.- Buscar : El programa deberá buscar una matrícula en el vector por medio del método de búsqueda más óptimo. Utilizar banderas para escoger el método más adecuado. Mostrar los datos en forma de registro
    5.- Ordenar : El programa deberá ordenar el vector por medio del método de ordenación más óptimo. Utilizar banderas para escoger el método más adecuado se ordenará por el campo llave (matrícula)
    6.- Mostrar Todo: El programa deberá mostrar todos los registros del vector tal y como están en ese momento ordenado o desordenado. (mostrar en forma de tabla, y de 40 en 40)
    7.- Generar Archivo : El programa deberá preguntar al usuario el nombre del archivo,  solo nombre sin extensión, el programa generará un archivo con el nombre proporcionado por el usuario con extensión .txt los datos que pondrá en el archivo de texto serán idénticos a los contenidos en el Vector de registros. (ordenado o desordenado). El programa podrá generar múltiples archivos para comprobar las salidas. 
    8.- Cantidad de registros en archivo : El programa deberá llamar a un archivo externo, donde mande ejecutar el archivo y como parametros el nombre del archivo que se desea evaluar, el programa externo deberar ser capaz de retornar un valor enero que sea la cantida de registros que contiene el archivo en cuestion
    9.- Mostrar Borrados: El programa deberá mostrar el archivo de texto tal y como se visualiza con la cantidad de registros que se eliminaron del archivo original y que fueron marcados en su momnto como registros eliminados
    
    12/11/2023
    Actv_12_932
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "libad.h"
#include "list.h"
#define P 1500

//       ------Structs------        //

typedef struct alumno
{
    char name [30];
    char app [30];
    char apm[30];

    int gen;
    char genc;
    int age;
    int status;
    int mat;
}data;

//      ------Prototipos------      //

void menu ();
void opci();
//      ------  Archivos  ------      //
void carg_txt (data alu[], int *p);
void eli_txt (data reg[], int p,int pe);
void doc_eli_txt ();
void counterRegisters();

//  ------ Auto Generacion ------- //
void AutoAlumn (data alu[],int p);

//  ------ Elimanacion ------- //
int eliminacion (data dat[],int pu, int pe,int band);

//  ------  Busqueadas ------- //
int buscsec(data alumno[], int p, int num);
int buscbin(data alumno[], int lef, int rig, int num);

//  ------  Ordenar ------- //
void ordenarB (data alumno[], int n);
//  ------Quicksort------- //
void swap(data students[], int i, int j);
int partition(data students[], int low, int high);
void quicksort(data students[], int low, int high);

//  ------  Print   ------- //
void print(data dat[], int p);
void printb (data reg[],int p);
void txt (data dat[], int p);

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
    printf("1-Cargar Archivo\n");
    printf("2-Agregar\n");
    printf("3-Eliminar\n");
    printf("4-Buscar\n");
    printf("5-Ordenar\n");
    printf("6-Mostrar Todo\n");
    printf("7-Generar Archivo\n");
    printf("8-Cantidad de registros en un archivo\n");
    printf("9-Mostrar Borrados\n");
    printf("0-Salir\n");
}

void opci()
{
    int i,j,op,pu,ord;
    int num,bus;
    int elim;
    elim=0;
    ord=0;
    pu=0;
    data registro[P];
    do
    {
        system("CLS");
        menu();
        op=valid2("Fuera de rango",0,9);
        switch(op)
        {
            case 1:
                carg_txt(registro,&pu);
                break;
            case 2:
            //      --------------------AGREGAR--------------------         //
                system("CLS");
                if(pu<P)
                {
                    j=P-pu;
                    if(j>10)
                    {                   
                        for(i=0;i<10;i++)
                        {
                            AutoAlumn(registro,pu);
                            pu++;
                            ord=1;
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
                else
                {
                    printf("Registro lleno\n");
                    system("PAUSE");
                }
                break;
            case 3:
            //      --------------------ELIMINAR--------------------         //
                
                if(pu>0)
                {
                    
                        pu=eliminacion(registro,pu,elim,ord);
                        ord=1;
                        elim++;
                        system("PAUSE");
                    
                }
                else
                {
                    printf("Lista vacia\n");
                    system("PAUSE");
                }
                break;
            case 4:
            //      --------------------BUSCAR--------------------         //
                if(pu==0)
                {
                    printf("lista vacia\n");
                }
                else
                {
                    if(ord==1)
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
                            printb(registro,bus);
                        }
                    }
                    else
                    {
                        printf("Busqueda binaria\n");
                        num=valid("Ingrese la matricula",300000,399999);
                        
                        bus=buscbin(registro,0, pu-1, num);
                        if(bus==-1)
                        {
                            printf("No se encontro la matricula\n");
                        }
                        else
                        {
                            printf("La matricula se encuentra en la posicion %d \n", bus+1);
                            printb(registro,bus);
                        }
                    }
                }
                system("PAUSE");
                break;
            case 5:
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
                    }
                    ord=0;
                }
                system("PAUSE");
            }
            else
            {
                printf("Cadena vacia\n");
                system("PAUSE");
            }
                break;
            case 6:
            //      -------------------Imprimir--------------------         //
                if(pu>0)
                {
                    int k=40;
                    printf("%-5s %-10s %-15s %-15s %-15s %-10s %-10s %-10s\n","\tNo","Matricula","Nombre","Ap Pat","Ap Mat","Edad","Gen","Status");                    
                    for(i=0;i<pu;i++)
                    {
                        if(i<k)
                        {
                            print(registro,i);
                        }
                        else
                        {
                            k=k+40;
                            getch();
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
            case 7:
            //      --------------------Archivo De Texto--------------------         //
                if(pu>0)
                {
                    txt(registro,pu);
                    printf("Archivo de texto creado\n");
                }
                else
                {
                    printf("Registros vacios\n");
                }
                system("PAUSE");
                break;
            case 8:
                counterRegisters();
                system("PAUSE");
                break;
            case 9:
                if(elim>0)
                {
                    printf("Archivos eliminados");
                    doc_eli_txt();
                }
                else
                {
                    printf("Archivo vacio\n");
                    getch();
                }
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

void AutoAlumn (data alu[],int p)
{
    int c,mat;
    c=rand()%(2-1+1)+1;
    char name[30],ap[30],apm[30];
    

        li_nombres(name,c);
        strcpy(alu[p].name,name);

        li_apellidos(ap);
        strcpy(alu[p].app,ap);

        li_apellidos(apm);
        strcpy(alu[p].apm,apm);

        alu[p].gen=c;

        alu[p].age=rand()%(30-17+1)+17;

        alu[p].status=1;

        mat=rand() % (399999-300000+1)+300000;
        alu[p].mat=mat;
}
//  ------ Elimanacion ------- //
int eliminacion (data dat[],int pu, int pe,int band)
{
    int i,pes,po,op;
    printf("Ingrese la matricula que desea eliminar\n");
    pes=valid2("Fuera de rango (300000 - 399999)",300000,399999);

    if(band==1)
    {
        po=buscsec(dat,pu,pes);
    }
    else
    {
        po=buscbin(dat,0,pu-1,pes);
    }

    if(po!=-1)
    {
        printb(dat,po);
        printf("Este es tu registro, deseas borrarlo?\n1.-Si,Eliminar 2.-No,Conservar");
        op = valid2("fuera de rango",1,2);
        if(op==1)
        {
            eli_txt(dat,po,pe);
            for(i=po;i<pu;i++)
            {
                dat[i]=dat[i+1];
            }
            pu--;
        }
    }
    else
    {
        printf("Matricula no encontrada\n");
    }
    return pu;
}

//  ------  Busqueads ------- //
int buscsec(data reg[], int p, int num)
{
    int i;
    for(i=0;i<=p;i++)
    {
        if(reg[i].mat==num)
        {
            return i;
        }
    }
    return -1;
}

int buscbin(data reg[], int lef, int rig, int num) 
{
    int med;
    while (lef <= rig)
    {
        med = lef + (rig - lef) / 2;
        
        if (reg[med].mat == num)
        {
            return med;
        }

        if (reg[med].mat < num)
        {
            lef = med + 1;
        }
        else
        {
            rig = med - 1;
        }
    }
    return -1;
}

//  ------  Ordenar ------- //
void ordenarB (data reg[], int n)
{
    int i,j;
    data temp;
    for(j=0;j<n;j++)
    {
        for(i=j+1;i<n;i++)
        {
            if(reg[j].mat>reg[i].mat)
            {
                temp=reg[i];
                reg[i]=reg[j];
                reg[j]=temp;
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
    pivot.mat = students[high].mat;
    int i = low - 1;

    for (int j = low; j <= high - 1; j++)
    {
        if (students[j].mat <= pivot.mat)
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
void print (data reg[], int p)
{
    char cad[7];
    if(reg[p].gen==1)
    {
        strcpy(cad,"HOMBRE");
    }
    else
    {
        strcpy(cad,"MUJER");
    }
    printf("\t%d%-4s %-10d %-15s %-15s %-15s %-10d %-10s %-10d\n", p+1, ".-" , reg[p].mat , reg[p].name , reg[p].app , reg[p].apm , reg[p].age , cad , reg[p].status);
}

void printb (data reg[],int p)
{
    char cad[7];
    if(reg[p].gen==1)
    {
        strcpy(cad,"HOMBRE");
    }
    else
    {
        strcpy(cad,"MUJER");
    }
    printf("Matricula : %d\n",reg[p].mat);
    printf("Nombre : %s\n",reg[p].name);
    printf("Apellido Paterno : %s\n",reg[p].app);
    printf("Apellido Materno : %s\n",reg[p].apm);
    printf("Edad : %d\n",reg[p].age);
    printf("Genero : %s\n",cad);
    printf("Edad : %d\n",reg[p].status);

}

//  ------  Archivos   ------- //

void carg_txt (data alu[], int *p)
{
    int v;
    char name[20];
    printf("Ingrese el nombre del documento\n");
    do
    {
        gets(name);
        v=validCh(name);
    }
    while (v==1);
    strcat(name, ".txt");
    
    FILE *doc = fopen (name,"r");
    if(doc)
    {
        data reg;
        char cad[7];
        int i;
        while(!feof(doc))
        {
            if(((*p)+1) <= P)
            {
                reg.status=1;
                fscanf(doc,"%d.- %d %s %s %s %d %s", &i , &reg.mat , reg.name , reg.app , reg.apm , &reg.age , cad);
                if(strcmp(cad,"HOMBRE")==0)
                {
                    reg.gen=1;
                }
                else
                {
                    if(strcmp(cad,"MASCULINO")==0)
                    {
                        reg.gen=1;
                    }
                    else
                    {
                        if(strcmp(cad,"MUJER")==0)
                        {
                            reg.gen=2;
                        }
                        else
                        {
                            if(strcmp(cad,"FEMENINO")==0)
                            {
                                reg.gen=2;
                            }
                        }
                    }
                }
                alu[(*p)++]=reg;
            }
            else
            {
                printf("Registro lleno\n");
            }
        }   
        
        printf("Registros cargado\n");
        system("PAUSE");
    }
    else
    {
        printf("Error 404\nNo se encontro el archivo o no existe\n");
        system("PAUSE");
    }
    fclose(doc);
}

void txt (data reg[], int p)
{
    int v;
    char name[20];
    printf("Ingrese el nombre del documento nuevo, solo se permiten letras sin numeros\n(Si el archivo de texto ya existe este se reescribira)\n");
    do
    {
        gets(name);
        v=validCh(name);
    }
    while (v==1);
    strcat(name, ".txt");
    
    FILE *doc = fopen (name,"w");
    char cad[7];
    int i;
    
    for(i=0;i<p;i++)
    {
        if(reg[p].gen==1)
        {
            strcpy(cad,"HOMBRE");
        }
        else
        {
            strcpy(cad,"MUJER");
        }
        fprintf(doc,"%d%-4s %-10d %-15s %-15s %-15s %-10d %-10s\n", i+1 , ".-" , reg[i].mat , reg[i].name , reg[i].app , reg[i].apm , reg[i].age , cad);
    }
    
    fclose(doc);
}

void eli_txt (data reg[], int p,int pe)
{   
    FILE *doc = fopen ("eliminados.txt","a");
    char cad[7];

    if(reg[p].gen==1)
    {
        strcpy(cad,"HOMBRE");
    }
    else
    {
        strcpy(cad,"MUJER");
    }
    fprintf(doc,"%d%-4s %-10d %-15s %-15s %-15s %-10d %-10s\n", pe+1 , ".-" , reg[p].mat , reg[p].name , reg[p].app , reg[p].apm , reg[p].age , cad);
    
    fclose(doc);
}

void doc_eli_txt ()
{   
    FILE *doc = fopen ("eliminados.txt","r");
    char linea[100];

    if (doc) 
    {
        while (fgets(linea, sizeof(linea), doc) != NULL) 
        {
            printf("%s", linea);
        }
    } 
    else 
    {
        printf("Error al abrir el archivo.\n");
    }
    fclose(doc);
    getch();
}

void counterRegisters()
{
    int count;
    char fileName[50];
    char cmd[50];
    printf("Ingrese el nombre del archivo\n");
    gets(fileName);
    
    system("gcc.exe Rcontador.c -o Rcontador");
    sprintf(cmd,"Rcontador.exe %s", fileName);
    count = system(cmd);

    if(count != -1)
    {
        printf("El archivo %s contiene %d registros\n", fileName, count);
    }
    else 
    {
        printf("El archivo no fue encontrado\n");
    }
}
