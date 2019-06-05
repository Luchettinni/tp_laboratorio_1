#include <stdlib.h>
#include <stdio.h>
#include "Employee.h"

int employee_setSueldo(Employee* this,int sueldo)
{
    int todoOK = 1;

    if ( this != NULL && sueldo > 0 && sueldo < 100000 )
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
        todoOK = 1;
        *sueldo = this->sueldo;
    }

    return todoOK;
}

int employee_setId(Employee* this,int id)
{
    int todoOK = 1;

    if ( this != NULL && id > 0 && id < 100000 )
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

    return *newEmployee;
}

Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr)
{
    int todoOK;
    Employee* newEmployee = (Employee*) malloc(sizeof(Employee));
    if (newEmployee != NULL)
    {
        // otro if validando un id distinto de negativo (setID)
        // otro if validando si pudo escribir un numbro (setNombre)
        // otro if para validar las horas trabajadas
        // otro if para validar el sueldo (setSueldo) (agregar este parametro al a funciom)
        // usa atoi y esas boludeces
        todoOK = 1;

        if (todoOK == 0)
        {
            free(newEmployee);
            newEmployee == NULL;
        }
    }


    return *newEmployee;
}
