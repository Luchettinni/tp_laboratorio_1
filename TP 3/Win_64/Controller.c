#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

#ifndef EMPLOYEE_H_INCLUDED
#define EMPLOYEE_H_INCLUDED

#include "Employee.h"

#endif // EMPLOYEE_H_INCLUDED

#include "string.h"

// PARCIAL DE LABORATORIO UNA SEMANA ANTES POR QUE SON ALTOS PETES Y NO SE LA BANCAN 26/6/2019
/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
    int error = 1;
    int cant;
    char buffer[4][20];

    FILE* file;
    file = fopen(path, "r");

    if (file != NULL)
    {
        fscanf(file, "%[^,],%[^,],%[^,],%[^\n]\n", buffer[0], buffer[1], buffer[2], buffer[3]); // LECTURA FANTASMA
        ll_clear(pArrayListEmployee); // CON ESTO BORRO LA LISTA EN CASO DE QUE CONTENGA DATOS PREVIOS

        while( !feof(file) )
        {
            cant = fscanf(file, "%[^,],%[^,],%[^,],%[^\n]\n", buffer[0], buffer[1], buffer[2], buffer[3]);

            if ( cant < 4 )
            {
                if(feof(file))
                {
                    break;
                }
				else
				{
					printf("No leyo el ultimo registro");
					break;
				}
            }

            Employee* auxEmp = employee_new();

            if (auxEmp != NULL)
            {
                auxEmp = employee_newParametros(buffer[0], buffer[1], buffer[2], buffer[3]);
                ll_add(pArrayListEmployee, auxEmp);
            }
            else
            {
                printf("ERROR: no se pudo conseguir espacio para realizar el cargado\n\n");
                ll_clear(pArrayListEmployee);
                break;
            }
        }

        error = 0;
        fclose(file);
    }

    return error;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    int error = 1;
    int len = ll_len(pArrayListEmployee);
    Employee* empleado = employee_new();


    if ( empleado != NULL && len != 0)
    {
        printf("\n ID   | NOMBRE          | HORAS TRABAJADAS | SUELDO\n");
        for (int i = 0; i < len; i++)
        {
            empleado = ll_get(pArrayListEmployee, i);
            printf(" %04d | %-15s | %-16d | %-6d \n", empleado->id, empleado->nombre, empleado->horasTrabajadas, empleado->sueldo);
        }
        error = 0;
    }

    return error;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{

    int error = 1;
    int len = ll_len(pArrayListEmployee);

    Employee* empleado = employee_new();

    FILE* file;

    if ( len != 0 )
    {
        file = fopen(path, "w");
    }
    else
    {
        file = NULL;
    }

    if ( file != NULL && empleado != NULL && pArrayListEmployee != NULL)
    {
        fprintf(file,"id,nombre,horasTrabajadas,sueldo\n");
        for (int i = 0; i < len; i++)
        {
            empleado = ll_get(pArrayListEmployee, i);
            fprintf(file, "%d,%s,%d,%d\n", empleado->id, empleado->nombre, empleado->horasTrabajadas, empleado->sueldo);
        }
        error = 0;
    }

    fclose(file);

    return error;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
    return 1;
}

