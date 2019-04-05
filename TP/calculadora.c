#include <stdio.h>

float suma(float x, float y)
{
    return x+y;
}

float restar(float x, float y)
{
    return x-y;
}

float multiplicacion(float x, float y)
{
    return x*y;
}

float division(float x, float y)
{
        return x/y;
}


int factorial(int x)
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
