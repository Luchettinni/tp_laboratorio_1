#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/

int main()
{
    int option = 0;

    LinkedList* listaEmpleados = ll_newLinkedList();
    do
    {
        system("cls");
        printf("---------- NOMINA DE EMPLEADOS ----------\n\n");
        printf("1) Cargar los datos de los empleados (data.csv)\n");
        printf("2) Cargar los datos de los empleados (data.bin)\n");
        printf("3) Alta empleado\n");
        printf("4) Modificar empleado\n");
        printf("5) Baja empleado\n");
        printf("6) Listar empleados\n");
        printf("7) Ordenar empleados\n");
        printf("8) Guardar los datos de los empleados (data.csv)\n");
        printf("9) Guardar los datos de los empleados (data.bin)\n");
        printf("10) Salir\n");

        printf("\nque desea hacer?: ");
        scanf("%d", &option);

        switch(option)
        {
            case 1:
                if ( controller_loadFromText("data.csv",listaEmpleados) )
                {
                   printf("\nOcurrio un error al intentar cargar los datos...\n\n");
                }
                else
                {
                    printf("\nSe cargaron los datos satisfactoriamente!\n\n");
                }

                system("pause");
                break;

            case 2:

                if ( controller_loadFromBinary("data.bin", listaEmpleados) )
                {
                   printf("\nOcurrio un error al intentar cargar los datos...\n\n");
                }
                else
                {
                    printf("\nSe cargaron los datos satisfactoriamente!\n\n");
                }

                system("pause");
                break;

            case 3:

                if ( controller_addEmployee(listaEmpleados) )
                {
                    printf("\nOcurrio un error al intentar cargar un empleado...\n\n");
                }
                else
                {
                    printf("\nSe realizo el alta correctamente!\n\n");
                }
                system("pause");
                break;

            case 4:

                if ( controller_editEmployee(listaEmpleados) )
                {
                    printf("\nOcurrio un error al intentar realizar esta operacion...\n\n");
                }
                else
                {
                    printf("\nSe realizo la modificacion correctamente!\n\n");
                }

                system("pause");
                break;

            case 5:
                if ( controller_removeEmployee(listaEmpleados) == -1 )
                {
                    printf("\nERROR: ID inexistente // memoria insuficiente...\n\n");
                }
                else
                {
                    printf("\nSe dio de baja al empleado satisfactoriamente!\n\n");
                }
                system("pause");
                break;


            case 6:
                if ( controller_ListEmployee(listaEmpleados) )
                {
                    printf("\nERROR: no se encontraron empleados para listar...\n\n");
                }
                else
                {
                    printf("\nSe imprimio la lista correctamente!\n\n");
                }
                system("pause");
                break;

            case 7:
                if ( controller_sortEmployee(listaEmpleados) )
                {
                    printf("\nERROR: no se encontraron empleados para ordenar...\n\n");
                }
                else
                {
                    printf("\nse ordenaron los empleados correctamente!\n\n");
                }

                system("pause");
                break;

            case 8:
                if ( controller_saveAsText("data.csv", listaEmpleados) )
                {
                    printf("\nERROR: no hay datos que guardar...\n\n");
                }
                else
                {
                    printf("\nse guardaron los datos satisfactoriamente!\n\n");
                }
                system("pause");
                break;

            case 9:
                if ( controller_saveAsBinary("data.bin", listaEmpleados) )
                {
                    printf("\nERROR: no hay datos que guardar...\n\n");
                }
                else
                {
                    printf("\nse guardaron los datos satisfactoriamente!\n\n");
                }
                system("pause");
                break;

            case 10:
                ll_deleteLinkedList(listaEmpleados);
                printf("\nSaliendo...\n\n");
                system("pause");
                break;

            case 11:
                printf("LEN: %d", ll_len(listaEmpleados) );
                ll_clear(listaEmpleados);
                printf("LEN 2: %d", ll_len(listaEmpleados) );
                system("pause");
                break;
        }

    } while( option != 10 );

    return 0;
}
