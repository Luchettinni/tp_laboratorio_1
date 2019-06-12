#include <stdio.h>
#include <stdlib.h>
#include "string.h"

#include "LinkedList.h"

#ifndef PARSER_H_INCLUDED
#define PARSER_H_INCLUDED

#include "parser.h"

#endif // PARSER_H_INCLUDED


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
    int error;

    FILE* file;
    file = fopen(path, "r");

    error = parser_EmployeeFromText(file, pArrayListEmployee);

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
    int error;

    FILE* file;
    file = fopen(path, "rb");

    error = parser_EmployeeFromBinary(file,pArrayListEmployee);


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
    int max = 0;
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

        max = max + 1;

        empleado = employee_new();

        employee_setId(empleado, max);
        input_getName(empleado->nombre,"Ingrese nombre del empleado: ", "ERROR: nombre muy corto o demasiado largo",2,15);
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
    int error = -1;

    int id;
    int len = ll_len(pArrayListEmployee);

    Employee* empleado = NULL;

    printf("\nIngrese el id del empleado que desea dar de baja: ");
    scanf("%d", &id);

    for(int i = 0; i < len; i++ )
    {
        empleado = ll_get(pArrayListEmployee, i);

        if( id == empleado->id )
        {
            ll_remove(pArrayListEmployee, i);
            error = 0;
            break;
        }
    }

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
    int error = 1;
    int len = ll_len(pArrayListEmployee);

    Employee* empleado = employee_new();
    Employee* empleadoAux = employee_new();

    printf("\nordenando... (esto puede tardar unos segundos...)\n");

    if ( empleado != NULL && empleadoAux != NULL && len != 0)
    {
        for (int i = 0; i < len; i++)
        {
            for ( int j = i + 1; j < len; j++)
            {
                empleado = ll_get(pArrayListEmployee, i);
                empleadoAux = ll_get(pArrayListEmployee, j);
                if ( strcmp(empleado->nombre, empleadoAux->nombre) > 0 )
                {
                    ll_set(pArrayListEmployee,j, empleado);
                    ll_set(pArrayListEmployee,i, empleadoAux);
                }
            }
        }
        error = 0;
        printf("\nse ordenaron los empleados correctamente!\n\n");
    }

    return error;
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

