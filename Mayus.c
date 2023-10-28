#include <stdio.h>
#include <string.h>

int main()
{

}

void mius (char cad[])
{
    for(int i=0; cad[i]!='\0';i++)
    {
        if(cad[i]>='a')
        {
            if(cad[i]<='z')
            {
                cad[i]-=32;
            }
        }
        if(cad[i] == -92) //ñ
        {
            cad[i] = -91; //Ñ
        }
    }
}