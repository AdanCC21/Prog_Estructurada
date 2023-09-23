#include <stdio.h>
#include <string.h>

char* obtenerCadena() {
    char* msj = "ENSENADA";
    return msj;
}

int main() {
    char* resultado = obtenerCadena();
    printf("La cadena obtenida es: %s\n", resultado);
    return 0;
}

