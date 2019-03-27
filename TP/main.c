#include <stdio.h>
#include <stdlib.h>

#include "Librerias\calculadora.h"

int main()
{
    float a = 0;
    float b = 0;
    int opcion = 0;
    int hacerCalculos = 0;

    float rSumar;
    float rRestar;
    float rMultiplicar;
    float rDividir;
    int rFactorialA;
    int rFactorialB;




    while (opcion != 5) {

        printf("\n-----para realizar una operacion, introduzca uno de los siguientes numeros-----\n1) Ingresar primer operando (A= %0.2f)\n2) Ingresar segundo operando (B= %0.2f)\n3) Calcular todas las operaciones\n4) Informar resultados\n5) Salir\n", a, b );

        printf("\nque operacion desea realizar?: ");
        scanf("%d", &opcion);
        fflush(stdin);

        switch (opcion)
            {
                case 1:

                    printf("\nIngrese el primer operando: ");
                    scanf("%f", &a);
                    fflush(stdin);
                    break;

                case 2:

                    printf("\nIngrese el segundo operando: ");
                    scanf("%f", &b);
                    fflush(stdin);
                    break;

                case 3:

                    rSumar = suma(a,b);
                    rRestar = restar(a,b);
                    rDividir = division(a, b);
                    rMultiplicar = multiplicacion(a, b);
                    rFactorialA = factorial(a);
                    rFactorialB = factorial(b);

                    hacerCalculos = 1;
                    printf("\n/// se realizaron los calculos para %f y %f correctamente ///\n", a, b);
                    break;

                case 4:

                    if ( hacerCalculos == 1 )
                    {

                        printf("\n///////////////////////\n1)el resultado de A+B es: %f", rSumar);

                        printf("\n2)el resultado de A-B es: %f", rRestar);

                        if (b == 0)
                        {
                            printf("\n3)no se puede dividir por 0");
                        } else
                        {
                            printf("\n3)el resultado de A/B es: %f", rDividir);
                        }

                        printf("\n4)el resultado de A*B es: %f", rMultiplicar );

                        printf("\n5)el factorial de A es: %d y el factorial de B es %d\n///////////////////////\n", rFactorialA, rFactorialB);

                    } else
                    {
                        printf("\nOops!, no se encontraron calculos realizados para mostrar\n\n");
                    }
                    break;


                case 5:

                    break;

                default:
                    printf("\nEl comando ingresado es desconocido...\n\n");
                    break;

            }
    }

    return 0;
}
