int validCh(char arreglo[])
{
    int lon,i;
    lon=longitudDeCh(arreglo);
    
    //Espacio al inicio
    if(arreglo[0]==32)
    {
        printf("Tu texto no puede iniciar con un espacio\n");
        return 1;
    }
    //espacio al final
    if(arreglo[lon-1]==32)
    {
        printf("Tu texto no puede terminar con un espacio\n");
        return 1;
    }
    //Sin ningun caracter
    if(arreglo[0]=='\0')
    {
        printf("No se encontraron caracteres\n");
        return 1;
    }
    //Buscara por toda la cadena y si encuentra x error en alguna parte lo imprimira
    for(i=0;i<=lon;i++)
    {
        //simbolos
        if(arreglo[i]>=33)
        {
            if(arreglo[i]<=47)
            {
                printf("No se aceptan simbolos\n");
                return 1;
            }
        }
        //simbolos 2
        if(arreglo[i]>=58)
        {
            if(arreglo[i]<=64)
            {
                printf("No se aceptan simbolos\n");
                return 1;
            }
        }
        //simbolos 3
        if(arreglo[i]>=91)
        {
            if(arreglo[i]<=96)
            {
                printf("No se aceptan simbolos\n");
                return 1;
            }
        }
        //simbolos 4
        if(arreglo[i]>=123)
        {
            printf("No se aceptan simbolos\n");
            return 1;
        }
        //dobles espacios
        if(arreglo[i]==32)
        {
            if(arreglo[i+1]==32)
            {
                printf("No se permite doble espacio\n");
                return 1;
            }
        }
        //Numeros
        if(arreglo[i]>=48)
        {
            if(arreglo[i]<=57)
            {
                printf("No se permiten numeros\n");
                return 1;
            }
        }
        //Minusculas
        if(arreglo[i]>='a')
        {
            if(arreglo[i]<='z')
            {
                printf("Ingrese solo mayusculas\n");
                return 1;
            }
        }
        //Condicion que hara que solo acepte caracteres entre a y z mayusculas
        if(arreglo[i]>='A')
        {
            if(arreglo[i]<='Z')
            {
                return 0;
            }
            else
            {
                printf("Algun caracter no esta permitido\n");
                return 1;
            }
        }
        else
        {
            printf("Algun caracter no esta permitido\n");
            return 1;
        }
    }
    return 1;
}