#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef EMPLOYEE_H_INCLUDED
#define EMPLOYEE_H_INCLUDED

#include "Employee.h"

#endif // EMPLOYEE_H_INCLUDED

#ifndef INPUT_H_INCLUDED
#define INPUT_H_INCLUDED

#include "Input.h"

#endif // INPUT_H_INCLUDED

void initEmployees(sEmployee listOfEmployees[], int lenght)
{
    if ( lenght != 0 )
    {
        for (int i = 0; i < lenght; i++)
        {
            listOfEmployees[i].isEmpty = 1;
        }
    }
}

void addEmployees( sEmployee employee[], int lenght, int id, char name[], char lastName[],float salary,int sector )
{
    int indice = -1;

    for (int i = 0; i < lenght; i++) // este for busca un espacio vacio en la estructura de empleados
    {
        if ( employee[i].isEmpty == 1 )
        {
            indice = i;
            employee[indice].isEmpty = 0;
            break;
        }
    }

    if (indice != -1)
    {
        strcpy(employee[indice].name, name);
        strcpy(employee[indice].lastName, lastName);

        employee[indice].salary = salary;
        employee[indice].sector = sector;
        employee[indice].id = id;
    }
}

void printEmployees(sEmployee employee[], int length)
{
    printf("\n ID   | Nombre                                              | Apellido                                            | Salario  | Sector\n\n");

    for (int j = 0; j < length; j++)
    {
        if ( employee[j].isEmpty == 0)
        {
            printf(" %04d | %-51s | %-51s | %-8.2f | %d \n", employee[j].id, employee[j].name, employee[j].lastName, employee[j].salary, employee[j].sector);
        }
    }
}

void sortEmployees(sEmployee employee[], int lenght, int order)
{
    sEmployee auxEmp;

    for (int i = 0; i < lenght; i++)
    {
        for (int j = i+1; j < lenght; j++)
        {
            if( order == 1)
            {
                if ( stricmp( employee[i].name, employee[j].name) > 0)
                {
                    auxEmp = employee[i];
                    employee[i] = employee[j];
                    employee[j] = auxEmp;
                }

                if ( employee[i].sector > employee[j].sector)
                {
                    auxEmp = employee[i];
                    employee[i] = employee[j];
                    employee[j] = auxEmp;
                }
            }
            else
            {
                if ( stricmp( employee[i].name, employee[j].name) < 0)
                {
                    auxEmp = employee[i];
                    employee[i] = employee[j];
                    employee[j] = auxEmp;
                }

                if ( employee[i].sector < employee[j].sector)
                {
                    auxEmp = employee[i];
                    employee[i] = employee[j];
                    employee[j] = auxEmp;
                }
            }

        }
    }
}

void removeEmployee(sEmployee employee[], int lenght, int id)
{
    int indice;
    char respuesta;

    indice = findEmployeeById(employee, lenght, id);



    if (indice != -1)
    {
        printf("\nLegajo: %04d | Nombre: %s | Aprllido: %s\n\n", employee[indice].id, employee[indice].name, employee[indice].lastName);
        getAnswer(&respuesta, "Esta seguro que desea eliminar este empleado? (s/n): ");
        if (respuesta == 's')
        {
            employee[indice].isEmpty = 1;
            printf("\n\nempleado dado de baja satisfactoriamente!\n\n");
        }
        else
        {
            printf("\n\nel empleado no se ha dado de baja...\n\n");
        }

    }
    else
    {
        printf("\nid erroneo o inexistente...\n\n");
    }

}

int findEmployeeById(sEmployee employee[], int lenght,int id)
{
    int indice = -1;

    for (int i = 0; i < lenght; i++)
    {
        if ( employee[i].id == id && employee[i].isEmpty == 0)
        {
            indice = i;
        }
    }

    return indice;
}

int findLastId(sEmployee employee[], int length)
{
    int lastId = 0;

    for (int j = 0; j < length; j++)
    {
        if ( employee[j].isEmpty == 0 && employee[j].id > lastId)
        {
            lastId = employee[j].id;
        }
    }
    return lastId;
}

void informarTotalYProm (sEmployee employee[], int tam)
{
    int contadorDeSalarios = 0;
    float salario = 0;
    float promedio = 0;

    for (int i = 0; i < tam; i++) // recorro todos los salarios
    {
        if (employee[i].isEmpty == 0)
        {
                contadorDeSalarios++;
                salario += employee[i].salary;
        }
    }

    printf("\nHay %d salarios, que suman un total de $%.f\n", contadorDeSalarios, salario);
    promedio = salario / contadorDeSalarios;
    printf("el promedio de los salarios es de = %.2f\n\n", promedio);

    contadorDeSalarios = 0;
    for (int i = 0; i < tam; i++)
    {
        if (employee[i].salary > promedio && employee[i].isEmpty == 0)
        {
            contadorDeSalarios++;
        }
    }
    printf("la cantidad de salarios que superaron el promedio son: %d salarios...\n\n", contadorDeSalarios);

}

// -------------------------------------------------------------------------------------------

int menuPrincipal ()
{
    int opcion;
    printf("--------------NOMINA DE EMPLEADOS--------------\n");
    printf("1) Alta empleado\n");
    printf("2) Modificar empleado\n");
    printf("3) Baja empleado\n");
    printf("4) Informar...\n");
    printf("5) Salir\n\n");

    printf("Que desea hacer?: ");
    scanf("%d", &opcion );

    return opcion;

}

int menuModificar (sEmployee employee[], int *id, int tam)
{
    int indice = findEmployeeById(employee,tam,*id);;

    int opcion;
    printf("--------------NOMINA DE EMPLEADOS--------------// MODIFICAR\n");
    printf("Empleado a modificar... Legajo: %04d | %s %s | salario: %.f | sector: %d \n\n", *id, employee[indice].name, employee[indice].lastName, employee[indice].salary, employee[indice].sector);
    printf("1) Modificar nombre\n");
    printf("2) Modificar apellido\n");
    printf("3) Modificar salario\n");
    printf("4) Modificar sector\n");
    printf("5) Salir\n\n");

    printf("Que desea hacer?: ");
    scanf("%d", &opcion );

    return opcion;

}

int menuDeInformes ()
{
        int opcion;
    printf("--------------NOMINA DE EMPLEADOS-------------- // INFORMES\n");
    printf("1) Listado de los empleados ordenados alfabeticamente por Apellido y Sector.\n");
    printf("2) Total y promedio de los salarios, y cuantos empleados superan el salario promedio. \n");
    printf("3) Salir\n\n");

    printf("Que desea hacer?: ");
    scanf("%d", &opcion );

    return opcion;
}
