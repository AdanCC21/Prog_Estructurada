#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

#include "libad.h"
#include "list.h"

#define TRUE 1
#define FALSE 0

//-----------------------Structs---------------------------//

typedef int Tkey;

typedef struct indice
{
    int indice;
    Tkey llave;
}indi;

typedef struct datos
{
    int status;
    Tkey enrollment;

    char name[30];
    char app[50];
    char apm[50];
    
    char gen[15];
    char job[30];
    char state[30];
    
    int age;
    Tkey phone;
} data;

//----------------------Prototipos-------------------------//
void menu();
void opci();
//--Base--//
void new (data reg , int p,indi indice[]);
void del (int p, indi indice[], int *Band_ord);

//--Imprimir--//
void prin_only (data reg);
void prin_org();
void prin_ord(indi indice[],int p);

//--Busqueda--//
int Tbus_sec (indi vect [],int n,int num);
int Tbuscbin(indi reg[], int lef, int rig, int num);

//--Ordenamiento--//
void ord_index(indi indice[],int p,int band_preo,int band_ord);
//Burbuja
void ordenarB (indi reg[], int n);
//Quick
void quicksort(indi students[], int low, int high);
int partition(indi students[], int low, int high);
void swap(indi students[], int i, int j);
//Marge
void merge(indi arr[], int l, int m, int r);
void mergeSort(indi arr[], int l, int r);
//----

//---Archivos---//
void carg_index (indi indice [],int *p);
void crear_index (int p);
void carg_dat (data reg);

void most_dat (indi indice[], int p);
void do_txt (indi indice[],int p,int band_ord);

void empa ();
int cont_reg(char name[]);


//-------------------------Main----------------------------//
int main()
{
    opci();
    return 0;
}

//---------------------Funciones---------------------------//

void menu()
{
    printf("MENU\n");
    printf("1.-AGREGAR\n");
    printf("2.-ELIMINAR\n");
    printf("3.-Buscar\n");
    printf("4.-Ordenar\n");
    printf("5.-Imprimir Registros (Archivo Original)\n");
    printf("6.-Imprimir Registros (Archivo Ordenado)\n");
    printf("7.-Generar Archivo De Texto\n");
    printf("8.-Empaquetar\n");
    printf("0.-Salir\n");
}

void opci()
{
    int opci,elim,bus, bpos, p=0, P;
    int band_ord = FALSE, band_preo = 0,cont= 0;

    P = cont_reg("datos");
    P *=1.25;
    
    data reg;
    indi indice[P];
    
    carg_index(indice,&p);
    do
    {
        system("CLS");
        menu();
        opci = valid("Fuera de rango", 0, 8);
        switch (opci)
        {
            case 1:
            {
                if(p<P)
                {
                    new(reg, p, indice);
                    if(band_ord==TRUE)
                    {
                        cont=0;
                    }
                    p++;
                    band_ord=FALSE;
                    band_preo=1;
                    cont++;

                    if(cont>5)
                    {
                        band_preo=0;
                    }
                    printf("Listo\n");
                }
                else
                {
                    printf("Registros llenos\n");
                }
                getch();
                break;
            }
            case 2:
            {
                if(p>0)
                {
                    printf("Seguro de querer eliminar un empleado?\n1.-Si, Eliminar\t2.-No, Salir\n");
                    elim = valid("FUERA DE RANGO",1,2);
                    if(elim==1)
                    {
                        del(p,indice, &band_ord);
                    }
                    else
                    {
                        printf("Arre\n");
                        getch();
                    }
                }
                else
                {
                    printf("Registro vacio\n");
                    getch();
                }
                break;
            }
            case 3:
            {
                if(p<0)
                {
                    printf("Registros vacios\n");
                }                
                else
                {
                    printf("Ingrese el No.Empleado que desea buscar\n");
                    bus=valid("FUERA DE RANGO",300000,399999);

                    if(band_ord == TRUE)
                    {
                        bpos = Tbuscbin(indice,0,p-1,bus);
                        if(bpos!=-1)
                        {
                            most_dat(indice,bpos);
                        }
                        else
                        {
                            printf("Empleado no encontrado\n");
                        }
                    }
                    else
                    {
                        bpos = Tbus_sec(indice,p,bus);
                        if(bpos!=-1)
                        {
                            most_dat(indice,bpos);
                        }
                        else
                        {
                            printf("Empleado no encontrado\n");
                        }
                    }
                    getch();
                }
                break;
            }
            case 4:
            {
                if(band_ord == FALSE || band_preo == 1)
                {
                    ord_index(indice,p,band_preo,band_ord);
                    band_ord=TRUE;
                }
                else
                {
                    printf("Registros ya ordenados\n");
                    getch();
                }
                break;
            }
            case 5:
            {
                printf("Archivo original\n");
                prin_org();
                break;
            }
            case 6:
            {
                if(band_ord==TRUE)
                {
                    printf("Archivo ordenado\n");
                    prin_ord(indice,p);
                }
                else
                {
                    printf("Archivo no ordenado\nPorfavor ordenelo");
                    getch();
                }
                break;
            }
            case 7:
            {
                do_txt(indice,p,band_ord);
                break;   
            }
            case 8:
            {
                empa();
                printf("Listo\n");
                getch();
                break;
            }
            case 0:
            {
                printf("Seguro que quiere salir\n1.-Salir\t2.-Repetir\n");
                opci = valid("FUERA DE RANGO",1,2);
                opci--;
            }
        }
    } while (opci != 0);
}

void new (data reg , int p, indi indice[])
{
    char temp[30];
    int c,i,tempN;
    c=rand()%(2-1+1)+1;
    
    reg.status=1;
    
    li_nombres(temp,c);
    strcpy(reg.name,temp);

    li_apellidos(temp);
    strcpy(reg.app,temp);

    li_apellidos(temp);
    strcpy(reg.apm,temp);

    li_generos(temp);
    strcpy(reg.gen,temp);

    li_puestos(temp);
    strcpy(reg.job,temp);

    li_estados(temp);
    strcpy(reg.state, temp);

    reg.age = rand()%(30-17+1)+17;
 
    reg.phone = rand() % (1000000 - 3999999 + 1) + 3999999;

    tempN = rand() % (399999-300000+1)+300000;
    for(i=0;i<p;i++)
    {
        if(indice[i].llave==tempN)
        {
            tempN = rand() % (399999-300000+1)+300000;
            i=0;
        }
    }
    reg.enrollment = tempN;

    indice[p].indice = p;
    indice[p].llave = reg.enrollment;

    crear_index(p); //Cargara datos al indice
    carg_dat(reg); //agregara la nueva persona al datos.dat
}

void del (int p, indi indice[], int *Band_ord)
{
    int num,pos,opci;
    data reg;

    printf("Que numero de empleado desea eliminar?\n");
    num=valid("FUERA DE RANGO",300000,399999);
    
    if(*Band_ord==TRUE)
    {
        pos = Tbuscbin(indice,0,p-1,num);
    }
    else
    {
        pos = Tbus_sec(indice,p,num);
    }
    
    if(pos != -1)
    {
        FILE *doc = fopen("datos.dat", "rb+");
        if(doc)
        {
            system("CLS");
            fseek(doc, indice[pos].indice * sizeof(data), SEEK_SET);
            fread(&reg, sizeof(data), 1, doc);
            prin_only(reg);

            printf("Este es su registro, Seguro que desea elimnarlo?\n1.-Si, Eliminar\t2.-No, Conservar\n");
            opci = valid("FUERA DE RANGO",1,2);

            if(opci== 1)
            {
                reg.status = 0;
                fseek(doc, indice[pos].indice * sizeof(data), SEEK_SET);
                fwrite(&reg, sizeof(data), 1, doc);

                *Band_ord=FALSE;
                prin_only(reg);
                printf("Listo\n");
                getch();
            }
            else
            {
                printf("Registro NO eliminado\n");
                getch();
            }
        }
        fclose(doc);
    }
    else
    {
        printf("Empleado no encontrado\n");
        getch();
    }
}

//--------------------------Busquedas--------------------------//

int Tbus_sec (indi vect [],int n,int num)
{
    int i;
    for(i=0;i<n;i++)
    {
        if(vect[i].llave==num)
        {
            return i;
        }
    }
    return -1; 
}

int Tbuscbin(indi reg[], int lef, int rig, int num) 
{
    int med;
    while (lef <= rig)
    {
        med = lef + (rig - lef) / 2;
        
        if (reg[med].llave == num)
        {
            return med;
        }

        if (reg[med].llave < num)
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

//--------------------------Ordenar--------------------------//
void ord_index(indi indice[],int p,int band_preo,int band_ord)
{
    if(band_preo == 1)
    {
        ordenarB(indice,p);
        printf("Ordenado, metodo : burbuja\n");
        getch();
    }
    else
    {
        if(band_ord==FALSE)
        {
            quicksort(indice,0,p-1);
            printf("Ordenado, metodo : QuickSort\n");
            getch();
        }
        else
        {
            mergeSort(indice,0,p-1);
            printf("Ordenado, metodo : MargeSort\n");
            getch();
        }
    }
}

void ordenarB (indi reg[], int n)
{
    int i,j;
    indi temp;
    for(j=0;j<n;j++)
    {
        for(i=j+1;i<n;i++)
        {
            if(reg[j].llave > reg[i].llave)
            {
                temp=reg[i];
                reg[i]=reg[j];
                reg[j]=temp;
            }
        }
    }
}

//  -------Quicksort-------- //
void swap(indi students[], int i, int j)
{
    indi temp = students[i];
    students[i] = students[j];
    students[j] = temp;
}

int partition(indi students[], int low, int high)
{
    indi pivot;
    pivot.llave = students[high].llave;
    int i = low - 1;

    for (int j = low; j <= high - 1; j++)
    {
        if (students[j].llave <= pivot.llave)
        {
            i++;
            swap(students, i, j);
        }
    }
    swap(students, i + 1, high);
    return i + 1;
}

void quicksort(indi students[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(students, low, high);

        quicksort(students, low, pi - 1);
        quicksort(students, pi + 1, high);
    }
}

//  ----------MARGE-------------- //
void merge(indi arr[], int l, int m, int r) 
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    // Crear arreglos temporales
    int L[n1], R[n2];

    // Copiar datos a los arreglos temporales L[] y R[]
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i].llave;
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j].llave;

    // Fusionar los arreglos temporales de vuelta en arr[l..r]
    i = 0; // Índice inicial del primer subarreglo
    j = 0; // Índice inicial del segundo subarreglo
    k = l; // Índice inicial del arreglo fusionado
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k].llave = L[i];
            i++;
        } else {
            arr[k].llave = R[j];
            j++;
        }
        k++;
    }

    // Copiar los elementos restantes de L[], si hay alguno
    while (i < n1) {
        arr[k].llave = L[i];
        i++;
        k++;
    }

    // Copiar los elementos restantes de R[], si hay alguno
    while (j < n2) {
        arr[k].llave = R[j];
        j++;
        k++;
    }
}

// Función recursiva que implementa el algoritmo Merge Sort
void mergeSort(indi arr[], int l, int r) 
{
    if (l < r) {
        int m = l + (r - l) / 2; // Encuentra el punto medio

        // Ordena la primera y la segunda mitad
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        // Fusiona las mitades ordenadas
        merge(arr, l, m, r);
    }
}

//--------------------------Iprimir--------------------------//
void prin_only (data reg)
{
    if(reg.status==1)
    {
        printf("%-15d %-15s %-15s %-15s %-15s %-10s %-10s %-10d %-10d\n",reg.enrollment, reg.name,reg.app,reg.apm,reg.job,reg.gen,reg.state, reg.phone, reg.status);
    }
    else
    {
        printf("Su empleado esta dado de baja\n");
    }
}

void prin_org()
{
    data reg;
    int i;
    FILE *doc = fopen("datos.dat","rb");
    printf("%-5s %-15s %-15s %-15s %-15s %-15s %-10s %-10s %-10s %-10s\n","No.","No.Empleado","Nombre","Ap. PAT","Ap. MAT","Job","Genero","Estado","No.Celular","Status");
    while(fread(&reg,sizeof(data), 1 ,doc))
    {
        if(reg.status==1)
        {
            printf("%-5d %-15d %-15s %-15s %-15s %-15s %-10s %-10s %-10d %-10d\n",i,reg.enrollment, reg.name,reg.app,reg.apm,reg.job,reg.gen,reg.state, reg.phone, reg.status);
            i++;
        }
        else
        {
            printf("Su empleado esta dado de baja\n");
        }
    }
    getch();
}

void prin_ord(indi indice[],int p)
{
    data reg;
    int j;
    FILE *fa;
    printf("%-5s %-15s %-15s %-15s %-15s %-15s %-10s %-10s %-10s %-10s\n","No.","No.Empleado","Nombre","Ap. PAT","Ap. MAT","Job","Genero","Estado","No.Celular","Status");
    fa = fopen("datos.dat", "rb");
    if (fa)
    {
        for(j=0;j < p;j++)
        {
            rewind(fa);
            fseek(fa, indice[j].indice * sizeof(data), SEEK_SET);
            fread(&reg, sizeof(data), 1, fa);
            printf("%-5d %-15d %-15s %-15s %-15s %-15s %-10s %-10s %-10d %-10d\n",j,reg.enrollment, reg.name,reg.app,reg.apm,reg.job,reg.gen,reg.state, reg.phone, reg.status);
        }
    }
    else
    {
        printf("Error al abrir archivo\n");
    }
    getch();
    fclose(fa);
}
//--------------------------Archivos--------------------------//
void carg_index (indi indice [], int *p)
{
    int i = 0;
    data temp;
    FILE *doc;

    doc = fopen("datos.dat","rb");
    if(doc)
    {
        while(fread(&temp,sizeof(data), 1 ,doc))
        {
            if(temp.status==1)
            {
                indice[i].llave=temp.enrollment;
                indice[i].indice=i;
                i++;
                (*p)++;
            }
        }
        fclose(doc);
    }
}

void crear_index (int p)
{
    int i; 
    indi temp;
    FILE *doc = fopen("index.dat","wb");

    if(doc == NULL)
    {
        printf("ERROR 404, Archivo no encontrado\n");
        getch();
    }
    else
    {
        for(i = 0;i < p ;i++)
        {
            fwrite(&temp,sizeof(indi),1,doc);
        }
    }
    fclose(doc);
}

void carg_dat (data reg)
{
    FILE *doc = fopen("datos.dat","ab");
    if(doc)
    {
        fwrite(&reg,sizeof(data),1,doc);
    }
    fclose(doc);
}

void most_dat (indi indice[], int p)
{
    data reg;
    FILE *doc = fopen("datos.dat", "rb");
    if(doc)
    {
        fseek(doc, indice[p].indice * sizeof(data), SEEK_SET);
        fread(&reg, sizeof(data), 1, doc);
        prin_only(reg);
    }
    fclose(doc);
}

void do_txt (indi indice[],int p,int band_ord)
{
    int v,opci,i=0;
    data reg;
    char name[20];
    printf("Ingrese el nombre del documento nuevo, solo se permiten letras sin numeros\n(Si el archivo de texto ya existe este se reescribira)\n");
    do
    {
        gets(name);
        v=validCh(name);
    }
    while (v==1);
    strcat(name, ".txt");
    
    FILE *doc = fopen("datos.dat","rb");
    FILE *tx = fopen (name,"w");

    printf("Desea que este ordenado o no\n1.-Ordenado\t2.-Base\n");
    opci = valid("FUERA DE RANGO",1,2);
    if(opci == 1)
    {
        if(band_ord==TRUE)
        {
            int j;
            fprintf(tx,"%-5s %-15s %-15s %-15s %-15s %-15s %-10s %-10s %-10s %-10s\n","No.","No.Empleado","Nombre","Ap. PAT","Ap. MAT","Job","Genero","Estado","No.Celular","Status");
            for(j=0;j < p;j++)
            {
                rewind(doc);
                fseek(doc, indice[j].indice * sizeof(data), SEEK_SET);
                fread(&reg, sizeof(data), 1, doc);
                fprintf(tx,"%-5d %-15d %-15s %-15s %-15s %-15s %-10s %-10s %-10d %-10d\n",j,reg.enrollment, reg.name,reg.app,reg.apm,reg.job,reg.gen,reg.state, reg.phone, reg.status);
            }
        }
        else
        {
            printf("Archivo no ordenado\n");
        }
    }
    else
    {
        fprintf(tx,"%-5s %-15s %-15s %-15s %-15s %-15s %-10s %-10s %-10s %-10s\n","No.","No.Empleado","Nombre","Ap. PAT","Ap. MAT","Job","Genero","Estado","No.Celular","Status");
        while(fread(&reg,sizeof(data), 1 ,doc))
        {
            if(reg.status==1)
            {
                fprintf(tx,"%-5d %-15d %-15s %-15s %-15s %-15s %-10s %-10s %-10d %-10d\n",i,reg.enrollment, reg.name,reg.app,reg.apm,reg.job,reg.gen,reg.state, reg.phone, reg.status);
                i++;
            }
            else
            {
                printf("Su empleado esta dado de baja\n");
            }
        }
    }
    printf("Listo\n");
    getch();
}

void empa ()
{
    FILE *doc = fopen("datos.dat","rb");;
    FILE *fa = fopen("datos.bak","wb");

    data reg;

    if(doc)
    {
        while(fread(&reg,sizeof(data), 1 ,doc))
        {
            if(reg.status==1)
            {
                fwrite(&reg,sizeof(data),1,fa);
            }
        }
    }

    fclose(doc);
    fclose(fa);
}

int cont_reg(char name[])
{
    int c;
    char cmd[50];
    
    system("gcc.exe Rcontador.c -o Rcontador");
    sprintf(cmd,"Rcontador.exe %s", name);
    c = system(cmd);

    return c;
}
