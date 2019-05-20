#include <stdio.h>
#include <stdlib.h>
#include "calculadora.h"

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




    do {
        printf("-----para realizar una operacion, introduzca uno de los siguientes numeros-----\n1) Ingresar primer operando (A= %0.2f)\n2) Ingresar segundo operando (B= %0.2f)\n3) Calcular todas las operaciones\n   a)(A+B)\n   b)(A-B)\n   c)(A*B)\n   d)(A/B)\n   e)(!Ay!B)\n4) Informar resultados\n5) Salir\n", a, b );
        printf("\nque operacion desea realizar?: ");

        scanf("%d", &opcion);

        switch (opcion)
        {

        case 1:

            printf("\nIngrese el primer operando: ");
            scanf("%f", &a);
            hacerCalculos = 0;
            break;


        case 2:

            printf("\nIngrese el segundo operando: ");
            scanf("%f", &b);
            hacerCalculos = 0;
            break;

        case 3:

            rSumar = suma(a,b);
            rRestar = restar(a,b);
            rDividir = division(a, b);
            rMultiplicar = multiplicacion(a, b);
            rFactorialA = factorial(a);
            rFactorialB = factorial(b);

            hacerCalculos = 1;
            printf("\n/// se calcularon todas las operaciones correctamente! /// \n\n");
            break;

        case 4:

            if ( hacerCalculos == 1 )
            {

                printf("\n///////////////////////\na)el resultado de A+B es: %f", rSumar);

                printf("\nb)el resultado de A-B es: %f", rRestar);

                if (b == 0)
                {
                    printf("\nc)no se puede dividir por 0");
                } else
                {
                    printf("\nc)el resultado de A/B es: %f", rDividir);
                }

                printf("\nd)el resultado de A*B es: %f", rMultiplicar );


                if ( a < 0 && b < 0 )
                {

                    printf("\ne)el factorial de un numero negativo en A y B no existe\n///////////////////////\n\n");
                } else if ( a < 0 && b >= 0 )
                {
                    printf("\ne)el factorial del numero negativo en A no existe y el factorial de B es %d\n///////////////////////\n\n", rFactorialB);
                } else if ( a >= 0 && b < 0 )
                {
                    printf("\ne)el factorial de A es %d y el factorial del numero negativo en B no existe\n///////////////////////\n\n", rFactorialA);
                } else
                {
                    printf("\ne)el factorial de A es %d y el factorial de B es %d\n///////////////////////\n\n", rFactorialA, rFactorialB);
                }


            } else
            {
                printf("\nOops!, deberias hacer los calculos antes de pedir los resultados...\n\n");
            }

            break;

            case 5:

                break;

            default:

                printf("\nEl comando ingresado es desconocido...\n\n");
                break;
        }
    } while (opcion != 5);

    return 0;
}
