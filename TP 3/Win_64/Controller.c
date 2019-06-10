#include <stdio.h>
#include <stdlib.h>
#include "string.h"

#include "LinkedList.h"

#ifndef EMPLOYEE_H_INCLUDED
#define EMPLOYEE_H_INCLUDED

#include "Employee.h"

#endif // EMPLOYEE_H_INCLUDED

#ifndef INPUT_H_INCLUDED
#define INPUT_H_INCLUDED

#include "Input.h"

#endif // INPUT_H_INCLUDED



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
    int error = 1;
    int cant;

    FILE* file;
    file = fopen(path, "rb");

    if (file != NULL)
    {
        ll_clear(pArrayListEmployee);

        while( !feof(file) )
        {
            Employee* auxEmp = employee_new();
            cant = fread(auxEmp,sizeof(Employee),1,file);

            if ( cant != 1 )
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

            if (auxEmp != NULL)
            {
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

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    int error = 1;
    int max = 1;
    int len = ll_len(pArrayListEmployee);

    Employee* empleado = employee_new();

    if( empleado != NULL && pArrayListEmployee != NULL )
    {
        for(int i = 0; i < len; i++ )
        {
            empleado = ll_get(pArrayListEmployee, i);
            if(empleado->id > max || i == 0)
            {
                max = empleado->id;
            }
        }

        empleado = employee_new();
        max = max + 1;

        employee_setId(empleado, max);
        input_getString(empleado->nombre,"Ingrese nombre del empleado: ", "ERROR: nombre muy corto o demasiado largo",2,15);
        input_getInt(&empleado->horasTrabajadas, "ingrese horas trabajadas: ", "ERROR: las horas trabajadas exeden el rango establecido por el programa", 1,350);
        input_getInt(&empleado->sueldo, "Ingrese sueldo del empleado: ", "ERROR: el sueldo excede el rango establecido por el programa ", 7000, 100000);
        ll_add(pArrayListEmployee, empleado);
    }
    return error;
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
    int error = 1;
    int index = -1;
    int len = ll_len(pArrayListEmployee);
    Employee* empleado = employee_new();


    int id;
    printf("Ingrese el id del empleado que desea dar de baja: ");
    scanf("%d", &id);

    for(int i = 0; i < len; i++ )
    {
        empleado = ll_get(pArrayListEmployee, i);
        if(empleado->id == id)
        {
            index = i;
        }
    }
    ll_remove(pArrayListEmployee, index);

    return error;
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
    int error = 1;
    int len = ll_len(pArrayListEmployee);

    FILE* file;
    Employee* empleado = employee_new();

    if ( len != 0 )
    {
        file = fopen(path, "wb");
    }
    else
    {
        file = NULL;
    }

    if ( file != NULL && empleado != NULL && pArrayListEmployee != NULL )
    {
        for(int i = 0; i < len; i++)
        {
            empleado = ll_get(pArrayListEmployee, i);
            fwrite(empleado,sizeof(Employee),1,file);
        }

        error = 0;
    }

    fclose(file);

    return error;
}

