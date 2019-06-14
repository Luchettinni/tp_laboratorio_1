#include <stdlib.h>
#include <stdio.h>
#include "string.h"

#ifndef EMPLOYEE_H_INCLUDED
#define EMPLOYEE_H_INCLUDED

#include "Employee.h"

#endif // EMPLOYEE_H_INCLUDED

/** \brief setea un nombre en la estructura Employee
 *
 * \param this es la estructura de tipo "Employee" con la que se realizara el seteo
 * \param nombre es la cadena de caracteres a cargar en el campo de la estructura
 * \return retorna (0) si no tuvo exito o (1) si tuvo exito
 *
 */
int employee_setNombre(Employee* this,char* nombre)
{
    int todoOk = 0;

    if( this != NULL && strlen(nombre) < 128 && strlen(nombre) > 0 )
    {
        strcpy(this->nombre, nombre);
        todoOk = 1;
    }

    return todoOk;
}

/** \brief obtiene los datos de un campo que contenga un "nombre" proveniente de la estructura Employee
 *
 * \param this es la estructura de tipo "Employee" de la cual obtendremos el dato
 * \param nombre es la cadena de caracteres a cargar con el dato
 * \return retorna (0) si no tuvo exito o (1) si tuvo exito
 *
 */
int employee_getNombre(Employee* this,char* nombre)
{
    int todoOk = 0;

    if( this != NULL && strlen(nombre) < 128 && strlen(nombre) > 0 )
    {
        strcpy(this->nombre, nombre);
        todoOk = 1;
    }

    return todoOk;
}

/** \brief setea una cantidad de horas trabajadas en la estructura Employee
 *
 * \param this es la estructura de tipo "Employee" con la que se realizara el seteo
 * \param horasTrabajadas es el entero a cargar en el campo de la estructura
 * \return retorna (0) si no tuvo exito o (1) si tuvo exito
 *
 */
int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
    int todoOk = 0;

    if( this != NULL && horasTrabajadas >0 && horasTrabajadas <=350 )
    {
        this->horasTrabajadas = horasTrabajadas;
        todoOk = 1;
    }

    return todoOk;
}

/** \brief obtiene los datos de un campo que contenga "horas trabajadas" proveniente de la estructura Employee
 *
 * \param this es la estructura de tipo "Employee" de la cual obtendremos el dato
 * \param horasTrabajadas es el entero a cargar con el dato
 * \return retorna (0) si no tuvo exito o (1) si tuvo exito
 *
 */
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
    int todoOk = 0;

    if( this != NULL && horasTrabajadas != NULL )
    {
        *horasTrabajadas = this->horasTrabajadas;
        todoOk = 1;
    }

    return todoOk;
}

/** \brief setea un sueldo en la estructura Employee
 *
 * \param this es la estructura de tipo "Employee" con la que se realizara el seteo
 * \param sueldo es el entero a cargar en el campo de la estructura
 * \return retorna (0) si no tuvo exito o (1) si tuvo exito
 *
 */
int employee_setSueldo(Employee* this,int sueldo)
{
    int todoOK = 1;

    if ( this != NULL && sueldo > 8000 && sueldo < 80000 )
    {
        this->sueldo = sueldo;
        todoOK = 0;
    }

    return todoOK;
}

/** \brief obtiene los datos de un campo que contenga "sueldo" proveniente de la estructura Employee
 *
 * \param this es la estructura de tipo "Employee" de la cual obtendremos el dato
 * \param sueldo es el entero a cargar con los datos
 * \return retorna (0) si no tuvo exito o (1) si tuvo exito
 *
 */
int employee_getSueldo(Employee* this,int* sueldo)
{
    int todoOK = 0;

    if ( this != NULL || sueldo != NULL)
    {
        *sueldo = this->sueldo;
        todoOK = 1;
    }

    return todoOK;
}

/** \brief setea un id en la estructura Employee
 *
 * \param this es la estructura de tipo "Employee" con la que se realizara el seteo
 * \param id es el entero a cargar en el campo de la estructura
 * \return retorna (0) si no tuvo exito o (1) si tuvo exito
 *
 */
int employee_setId(Employee* this,int id)
{
    int todoOK = 1;

    if ( this != NULL && id > 0 )
    {
        this->id = id;
        todoOK = 0;
    }

    return todoOK;
}

/** \brief obtiene los datos de un campo que contenga un "id" proveniente de la estructura Employee
 *
 * \param this es la estructura de tipo "Employee" de la cual obtendremos el dato
 * \param id es el entero a cargar con los datos
 * \return retorna (0) si no tuvo exito o (1) si tuvo exito
 *
 */
int employee_getId(Employee* this,int* id)
{
    int todoOK = 0;

    if ( this != NULL || id != NULL)
    {
        todoOK = 1;
        *id = this->id;
    }

    return todoOK;
}

/** \brief asigna espacio en memoria para un nuevo puntero a estructura de empleados e inicializa sus campos
 *
 * \return retorna la direccion de memoria del empleado que logro crear si tuvo exito o NULL si no logro conseguir espacio
 *
 */
Employee* employee_new()
{
    Employee* newEmployee = (Employee*) malloc(sizeof(Employee));

    if (newEmployee != NULL)
    {
        newEmployee->id = 0;
        strcpy(newEmployee->nombre, " ");
        newEmployee->horasTrabajadas = 0;
        newEmployee->sueldo = 0;
    }

    return newEmployee;
}

/** \brief crea una nueva estructura y la carga con valores
 *
 * \param idStr es uno de los datos a cargar
 * \param nombreStr es uno de los datos a cargar
 * \param horasTrabajadasStr es uno de los datos a cargar
 * \param sueldoStr es uno de los datos a cargar
 * \return retorna la direccion de memoria de la estructura cargada o NULL si no logro conseguir espacio en memoria
 *
 */
Employee* employee_newParametros(char* idStr, char* nombreStr, char* horasTrabajadasStr, char* sueldoStr)
{
    int todoOK = -1;

    Employee* newEmployee = employee_new();

    if (newEmployee != NULL)
    {
        employee_setId(newEmployee, atoi(idStr));
        employee_setNombre(newEmployee, nombreStr);
        employee_setHorasTrabajadas(newEmployee, atoi(horasTrabajadasStr));
        employee_setSueldo(newEmployee, atoi(sueldoStr));

        todoOK = 0;
    }

    if (todoOK == -1)
    {
        free(newEmployee);
        newEmployee = NULL;
    }

    return newEmployee;
}
