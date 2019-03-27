#include <stdio.h>
#include <stdlib.h>

#include "Librerias\calculadora.h"

int main()
{
    float a = 0;
    float b = 0;
    int opcion = 0;

    int rSumar;
    int rRestar;
    int rMultiplicar;
    int rDividir;
    int rFactorialA;
    int rFactorialB;




    while (opcion != 5) {

        printf("-----para realizar una operacion, introduzca uno de los siguientes numeros-----\n1) Ingresar primer operando (A=x)\n2) Ingresar segundo operando (B=y)\n3) Calcular todas las operaciones\n4) Informar resultados\n5) Salir\n" );

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
                break;

                case 4:

                printf("\n1)el resultado de A+B es: %d", rSumar);

                printf("\n2)el resultado de A-B es: %d", rRestar);

                printf("\n3)el resultado de A/B es: %d", rDividir);

                printf("\n4)el resultado de A*B es: %d", rMultiplicar );

                printf("\n5)el factorial de A es: %d y el factorial de B es %d\n\n", rFactorialA, rFactorialB);
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
