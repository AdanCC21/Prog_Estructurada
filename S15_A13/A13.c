/*
    Gonzalez Cese;a Adan
    372799
    
    UTILIZAR UN ARREGLO DE 5000 REGISTROS  
    SE DEBERÁ UTILIZAR ESTRUCTURAS CON LOS DATOS BÁSICOS DE UN EMPLEADO 
    preguntar nombre de archivo binario o de archivo texto 
    Busqueda y Ordenacion por CAMPO LLAVE

    nota: usar librería propia con funciones
    nota2: 100 % validado, Cuidar desbordamiento de vector
    nota3: Campo llave matricula no repetido, archivos sozo cargar 1 sola vez. 
    nota4: Usar el tipo Tkey para hacer mas practico el programa

    INSTRUCCIONES DEL MENU
    1.- Agregar : El programa deberá ser capaz de agregar 100 registros al vector de registros (Generar automáticamente los datos).
    2.- Editar Registro : El programa deberá buscar una matrícula en el vector por medio del método de búsqueda más óptimo. Mostrar los datos en forma de registro Preguntar que campo quire Editar, actualiar los datos en el vector (solo a registros activos) 
    3.- Eliminar Registro : El programa deberá buscar una matrícula en el vector por medio del método de búsqueda más óptimo. Utilizar banderas para escoger el método más adecuado., imprimir el registro y preguntar si se quiere eliminar el registro.
    4.- Buscar : El programa deberá buscar una matrícula en el vector por medio del método de búsqueda más óptimo. Utilizar banderas para escoger el método más adecuado. Mostrar los datos en forma de registro
    5.- Ordenar : El programa deberá ordenar el vector por medio del método de ordenación más óptimo. Utilizar banderas para escoger el método más adecuado se ordenará por el campo llave (matrícula)
    6.- Imprimir: El programa deberá mostrar todos los registros del vector y como están en ese momento ordenado o desordenado. (mostrar en forma de tabla )
    7.- Generar Archivo Texto : El programa deberá preguntar al usuario el nombre del archivo,  solo nombre sin extensión, el programa generará un archivo con el nombre proporcionado por el usuario con extensión .txt los datos que pondrá en el archivo de texto serán idénticos a los contenidos en el Vector de registros. (ordenado o desordenado). El programa podrá generar múltiples archivos para comprobar las salidas. 
    8.- Mostrar Archivo Texto: El programa deberá preguntar al usuario el nombre del archivo,  solo nombre sin extensión, el programa generará un archivo con el nombre proporcionado por el usuario con extensión .txt mostrar el archivo de texto tal y como se encuantra.
    9.- Crear archivo binario : El programa deberá crear un archivo binario con los datos del vector actualizados, sustituir el archivo base, realizar respaldo del archivo anterior y guardarlo con el mismo nombre pero extencion .tmp (validar msges si el archivo no se puede crear por falta de registros en el vector)
    10 .- Cargar Archivo Binario : El programa deberá cargar al vector los registros del archivo binario (solo podrá cargarse una sola vez el archivo, el archivo binario se debara llamar datos.dll y si no existe debera indicar )
    11.- Mostrar Borrados: El programa deberá mostrar del archivo binario solo los registros que se eliminaron (marcados con status 0) y que fueron marcados en su momento como registros eliminados.

    14/11/2023
    Actv_13_932
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "libad.h"

//  -----Prototipos------//

void menu ();
void opci ();


