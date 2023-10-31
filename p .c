#include <stdio.h>

// Función para mezclar dos subarreglos de arr[]
// El primer subarreglo es arr[l..m]
// El segundo subarreglo es arr[m+1..r]
void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    // Crear subarreglos temporales
    int L[n1], R[n2];

    // Copiar los datos a los subarreglos L[] y R[]
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    // Mezclar los subarreglos de vuelta a arr[l..r]
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copiar los elementos restantes de L[], si los hay
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copiar los elementos restantes de R[], si los hay
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// Función principal que implementa el algoritmo Merge Sort
// l es el índice izquierdo y r es el índice derecho del subarreglo de arr que se ordenará
void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;

        // Ordenar la primera y la segunda mitad
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        // Mezclar las mitades ordenadas
        merge(arr, l, m, r);
    }
}

// Función para imprimir un arreglo
void printArray(int A[], int size)
{
    for (int i = 0; i < size; i++)
        printf("%d ", A[i]);
    printf("\n");
}

// Ejemplo de uso del Merge Sort
int main()
{
    int arr[] = {12, 11, 13, 5, 6, 7};
    int arr_size = sizeof(arr) / sizeof(arr[0]);

    printf("Arreglo original:\n");
    printArray(arr, arr_size);

    mergeSort(arr, 0, arr_size - 1);

    printf("\nArreglo ordenado:\n");
    printArray(arr, arr_size);
    return 0;
}
