#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 40
//*** PROTOTIPOS DE FUNCIONES  ******
int msges();
void menu();
void Ej1 (void);
void Ej2 (void);
void Ej3 (void);
void Ej4 (void);
//****  main principal  *********
int main()
{
  menu();

	return 0;
}
//  *** DESARROLLO DE LAS FUNCIONES  ******

int msges()
{ 
  int op;
  system ("CLS");
  printf ("   M  E   N   U \n");
  printf("1.- Numeros menores en orden descendiente \n");
  printf("2.- 40 Numeros aleatorios \n");
  printf("3.- mayor y menor \n");
  printf("4.- tablas de multiplicar\n");
  printf("0.- SALIR  \n");
  printf("ESCOGE UNA OPCION: ");
  scanf ("%d",&op);
  return op;
}

void menu()
{
  int op;
  do
  {
    op=msges();
    switch (op)
      {
        case 1:
              Ej1();
              break;
        case 2:
              Ej2();
              break;
        case 3:
              Ej3();
              break;
        case 4:
              Ej4();
              break;
      }

  }while (op != 0);
}

void Ej1 (void)
{
  system ("CLS"); //Limpiar consola
  printf("   Numeros descendientes    \n"); 
  int num_1, res_1, c_1;
  c_1=1;
  printf("porfavor ingrese un numero\n");
  scanf("%d",&num_1);
  do
  {
    res_1=num_1-c_1;
    printf("%d\n", res_1);
    c_1++;
  }
  while(res_1>0);

  system ("PAUSE");//Presionar cualquier tecla para continuar con el programa
}

void Ej2 (void)
{
  system ("CLS");
  
  int par, imp, al, cp, ci, i;
    srand(time(NULL));
    printf("40 numeros\n");
    par=0;
    imp=0;
    cp=0;
    ci=0;
    for(i=0; i<N;i++)
    {
        al=((rand()%200-1+1)+1);
        printf("%d ",al);
        if(al%2>0)
        {
            printf("Numero impar\n");
            imp=imp+al;
            ci++;
        }
        else
        {
            printf("Numero par\n");
            par=par+al;
            cp++;
        }
    }
    printf("La suma de los %d numeros impares es %d  y los %d numeros pares %d\n",ci,imp,cp,par);

  system ("PAUSE");
}

void Ej3 (void)
{
  
  system ("CLS");
  
  srand(time(NULL));
    int al, i, may, men;
    may=-1000;
    men=1000;
    for(i=0;i<35;i++)
    {
        al=rand()%101 + 100;
        if(al>may)
        {
            may=al;
        }
        if(al<may)
        {
            men=al;
        }
    }
    printf("Tu numero mayor es %d\n", may);
    printf("Tu numero menor es %d\n", men);

  system ("PAUSE");

}

void Ej4 (void)
{
  system("CLS");
  int num1, i,res;
    printf("Escoga su numero del 1 al 20 \n");
    scanf("%d",&num1);
    for(i=1;i<=10;i++)
    {
        res=num1*i;
        printf("%d * %d = %d\n",num1,i,res);
    }
  system("PAUSE");
}