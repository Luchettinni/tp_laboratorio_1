#include <stdio.h>

int suma(float x, float y)
{
    return x+y;
}

int restar(float x, float y)
{
    return x-y;
}

int multiplicacion(float x, float y)
{
    return x*y;
}

float division(float x, float y)
{
        return x/y;
}


float factorial(float x)
{
    int i;
    int contador = 1;
    for ( i = 1; i <= x; i++)
    {
        contador = contador*i;
    }
    return contador;

    /*

    if (x <= 0)
    {
        return 1;
    } else
    {
        do {
            contador = contador*i++;
    }   while ( i <= x);

    return contador;
    }*/
}
