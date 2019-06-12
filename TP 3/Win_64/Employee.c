#include <stdlib.h>
#include <stdio.h>
#include "string.h"

#ifndef EMPLOYEE_H_INCLUDED
#define EMPLOYEE_H_INCLUDED

#include "Employee.h"

#endif // EMPLOYEE_H_INCLUDED


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

Employee* employee_newParametros(char* idStr, char* nombreStr, char* horasTrabajadasStr, char* sueldo)
{
    int todoOK = -1;

    Employee* newEmployee = employee_new();

    if (newEmployee != NULL)
    {
        employee_setId(newEmployee, atoi(idStr));
        employee_setNombre(newEmployee, nombreStr);
        employee_setHorasTrabajadas(newEmployee, atoi(horasTrabajadasStr));
        employee_setSueldo(newEmployee, atoi(sueldo));

        todoOK = 0;
    }

    if (todoOK == -1)
    {
        free(newEmployee);
        newEmployee = NULL;
    }

    return newEmployee;
}
