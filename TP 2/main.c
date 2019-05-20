#include <stdio.h>
#include <stdlib.h>

#ifndef EMPLOYEE_H_INCLUDED
#define EMPLOYEE_H_INCLUDED

#include "Employee.h"

#endif // EMPLOYEE_H_INCLUDED

#ifndef INPUT_H_INCLUDED
#define INPUT_H_INCLUDED

#include "Input.h"

#endif // INPUT_H_INCLUDED

#define TAM_EMPLEADOS 100

int main()
{
    sEmployee employee2[TAM_EMPLEADOS] = {
    {1,"luciano", "aranda", 20000, 2, 0},
    {2,"amber", "wakefield", 45000, 1, 0},
    {3,"luciano", "aranda", 30000, 2, 0},
    {5,"thomas", "alvarez", 15000, 1, 0},
    {6,"brenda", "frias", 8000, 2, 0},
    {7,"kevin", "ahumada", 60000, 3, 0},
    {8,"luciano", "aranda", 20000, 2, 0},
    {4,"amber", "wakefield", 45000, 3, 0}
    };

    sEmployee employee[TAM_EMPLEADOS];

    initEmployees(employee, TAM_EMPLEADOS);

    for (int i = 0; i < 8; i++)
    {
        employee[i] = employee2[i];
    }

    sEmployee employeeToLoad;

    int idIncremental = 0;
    int opcion = 0;
    int id;
    int indice;

    do
    {
        system("cls");
        idIncremental = findLastId(employee,TAM_EMPLEADOS);
        switch (menuPrincipal())
        {
            case 1:
                getString( employeeToLoad.name, "Ingrese su nombre: ", "Error, el nombre es demasiado corto o demasiado largo", 2, 51 );
                getString( employeeToLoad.lastName, "Ingrese su apellido: ", "Error, el apellido es demasiado corto o demasiado largo", 2, 51 );
                getFloat( &employeeToLoad.salary, "Ingrese el salario: ", "ERROR: salario fuera de rango...", 8000,80000);
                getInt( &employeeToLoad.sector, "Ingrese el sector: ", "ERROR: ese sector no existe...", 1,5);
                idIncremental++;

                addEmployees(employee, TAM_EMPLEADOS, idIncremental, employeeToLoad.name, employeeToLoad.lastName, employeeToLoad.salary, employeeToLoad.sector );

                printf("\n\nalta realizada correctamente\n\n");
                system("pause");
                break;

            case 2:
                if ( idIncremental != 0)
                {
                    getInt( &id, "\nIngrese el id del empleado que desea modificar: ", "ERROR: ese empleado no existe...", 1,TAM_EMPLEADOS);
                    indice = findEmployeeById(employee,TAM_EMPLEADOS,id);
                    if (indice == -1)
                    {
                        printf("\nEste empleado no existe...\n\n");
                        system("pause");
                        break;
                    }
                    else
                    {
                        do {
                            system("cls");
                            switch(menuModificar(employee, &id, TAM_EMPLEADOS))
                            {
                                case 1:
                                    getString( employee[indice].name, "Ingrese su nombre: ", "Error, el nombre es demasiado corto o demasiado largo", 2, 51 );
                                    system("pause");
                                    break;

                                case 2:
                                    getString( employee[indice].lastName, "Ingrese su apellido: ", "Error, el apellido es demasiado corto o demasiado largo", 2, 51 );
                                    break;

                                case 3:
                                    getFloat( &employee[indice].salary, "Ingrese el salario: ", "ERROR: salario fuera de rango...", 8000,80000);
                                    break;

                                case 4:
                                    getInt( &employee[indice].sector, "Ingrese el sector: ", "ERROR: ese sector no existe...", 1,5);
                                    break;

                                case 5:
                                    opcion = 2;
                                    break;

                                default:
                                    system("pause");
                                    break;
                            }
                        } while (opcion != 2);
                    }

                }
                else
                {
                    printf("\nno se encontraron empleados a modificar...\n\n");
                    system("pause");
                }

                break;

            case 3:
                if ( idIncremental != 0)
                {
                    getInt( &id, "\nIngrese el id del empleado que desea dar de baja: ", "ERROR: ese empleado no existe...", 1,TAM_EMPLEADOS);
                    removeEmployee(employee,TAM_EMPLEADOS,id);
                }
                else
                {
                   printf("\nno se encontraron empleados para dar de baja...\n\n");
                }

                system("pause");
                break;

            case 4:
                if ( idIncremental != 0)
                {
                    do
                    {
                        system("cls");
                        switch(menuDeInformes())
                        {
                            case 1:
                                sortEmployees(employee, TAM_EMPLEADOS, 1);
                                printEmployees(employee, TAM_EMPLEADOS);
                                system("pause");
                                break;

                            case 2:
                                informarTotalYProm(employee, TAM_EMPLEADOS);
                                system("pause");
                                break;

                            case 3:
                                opcion = 3;
                                break;

                            default:
                                system("pause");
                                break;
                        }
                    } while (opcion != 3);
                }
                else
                {
                   printf("\nno se encontraron empleados para poder realizar informes...\n\n");
                   system("pause");
                }
                break;

            case 5:
                opcion = 1;
                break;

            default:
                break;
        }
    } while (opcion != 1);

    return 0;
}
