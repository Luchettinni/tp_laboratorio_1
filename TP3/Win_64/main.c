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
    Employee* emp;

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
                controller_loadFromText("data.csv",listaEmpleados);
                emp = (Employee*) listaEmpleados;
                printf("%p, %p\n", emp, (Employee*) listaEmpleados);
                printf("nombre: %s", emp->nombre);
                system("pause");
                break;

            case 2:
                break;

            case 3:
                break;

            case 4:
                break;

            case 5:
                break;

            case 6:
                break;

            case 7:
                break;

            case 8:
                break;

            case 9:
                break;

            case 10:
                printf("\nSaliendo...\n\n");
                system("pause");
                break;
        }

    } while( option != 10 );

    return 0;
}
