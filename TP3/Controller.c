#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "utn.h"


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path Ruta del archivo para leer
 * \param pArrayListEmployee Es el LinkedList
 * \return retorna 0 si el array no es null y si el archivo existe, sino retorna -1
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
    FILE* pArchivo;
    int retorno = -1;
    pArchivo = fopen(path,"r");
    if(!parser_EmployeeFromText(pArchivo,pArrayListEmployee))
    {
        retorno = 0;
    }
    fclose(pArchivo);
    return retorno;
}

/** \brief Carga los datos de los empleados desde el archivo data.bin (modo binario).
 *
 * \param path Ruta del archivo para leer
 * \param pArrayListEmployee Es el LinkedList
 * \return retorna 0 si el array no es null y si el archivo existe, sino retorna -1
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
    FILE* pArchivo;
    int retorno = -1;
    pArchivo = fopen(path,"rb");
    if(!parser_EmployeeFromBinary(pArchivo,pArrayListEmployee))
    {
        printf("\nArchivo cargado");
        retorno = 0;
    }
    fclose(pArchivo);
    return retorno;
}

/** \brief Alta de empleados
 *
 * \param pArrayListEmployee Es el LinkedList donde se agregara el empleado
 * \return Retorna 0 si se logra hacer el alta, sino retorna -1
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    int sueldo;
    int horasTrabajadas;
    char nombre[64];
    if(!utn_getNumero(&sueldo,"Ingrese el sueldo: ","Error,reingrese el sueldo: ",0,99999,2)&&
    !utn_getNumero(&horasTrabajadas,"\nIngrese las horas: ","Error,reingrese las horas: ",0,99999,2)&&
    !utn_getNombre(nombre,64,"\nIngrese el nombre: ","Error,reingrese el nombre: ",2))
    {
        Employee* empleado = Employee_new_AI(nombre,horasTrabajadas,sueldo);
        if(empleado != NULL)
        {
            retorno = ll_add(pArrayListEmployee,empleado);
        }
    }
    return retorno;
}

/** \brief Modificar datos de empleado
 *
 * \param pArrayListEmployee Es el LinkedList del cual se va a editar un empleado
 * \return Retorna 0 si se logra editar sino retorna -1
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    int i;
    int id, idAux;
    Employee* empleado;
     int sueldo;
    int horasTrabajadas;
    char nombre[64];

    if(pArrayListEmployee != NULL)
    {
        if(!utn_getNumero(&id,"Ingrese el ID del empleado a modificar: ","Error",0,99999,2))
        {
            for(i = 0;i< ll_len(pArrayListEmployee);i++)
            {
               empleado = ll_get(pArrayListEmployee,i);
               Employee_getId(empleado,&idAux);
               if(idAux == id)
               {
                    if(!utn_getNumero(&sueldo,"Ingrese el nuevo sueldo: ","Error",0,99999,2)&&
                    !utn_getNumero(&horasTrabajadas,"Ingrese las nuevas horas: ","Error",0,99999,2)&&
                    !utn_getNombre(nombre,64,"Ingrese el nuevo nombre: ","Error",2))
                    {
                        if(
                          !Employee_setNombre(empleado, nombre)&&
                          !Employee_setSueldo(empleado, sueldo)&&
                          !Employee_setHorasTrabajadas(empleado, horasTrabajadas))
                          {
                            retorno = 0;
                            break;
                          }

                    }
                    else{
                        break;
                    }
               }
            }
        }

    }
    return retorno;
}

/** \brief Baja de empleado
 *
 * \param pArrayListEmployee Es la LinkedList de empleados
 * \return Retorna 0 si se logra realizar la baja sino retorna -1
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    int i;
    int id, idAux;
    Employee* empleado;

    if(pArrayListEmployee != NULL)
    {
        if(!utn_getNumero(&id,"Ingrese el ID del empleado a borrar: ","Error",0,99999,2))
        {
            for(i = 0;i< ll_len(pArrayListEmployee);i++)
            {
               empleado = ll_get(pArrayListEmployee,i);
               Employee_getId(empleado,&idAux);

               if(idAux == id)
               {
                    Employee_delete(empleado);
                    ll_remove(pArrayListEmployee,i);
                    retorno = 0;
                    break;
               }

            }
        }

    }
    return retorno;
}

/** \brief Listar empleados
 *
 * \param pArrayListEmployee Es la LinkedList del cual se desea listar los empleados
 * \return retorna 0 si la LinkedList es diferente a NULL sino retorna -1
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    int i;
    char nombre[128];
    int id;
    int sueldo;
    int horasTrabajadas;
    Employee* auxPunteroEmpleado;

    if(pArrayListEmployee != NULL)
    {
        retorno = 0;
        for(i=0;i < ll_len(pArrayListEmployee);i++)
        {
            auxPunteroEmpleado = ll_get(pArrayListEmployee,i);
            Employee_getNombre(auxPunteroEmpleado,nombre);
            Employee_getId(auxPunteroEmpleado,&id);
            Employee_getSueldo(auxPunteroEmpleado,&sueldo);
            Employee_getHorasTrabajadas(auxPunteroEmpleado,&horasTrabajadas);

            printf("\nEl nombre del empleado es: %s",nombre);
            printf("\nEl id del empleado es: %d",id);
            printf("\nEl sueldo del empleado es: %d",sueldo);
            printf("\nLas horas trabajadas del empleado son: %d",horasTrabajadas);
            printf("\n\n");

        }
    }
    return retorno;
}

/** \brief Ordenar empleados por criterio
 *
 * \param pArrayListEmployee Es la LinkedList que se desea ordenar
 * \return retorna 0 si se logra ordenar sino retorna -1
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    int retorno = -1;

    if(pArrayListEmployee != NULL)
    {
        if(!ll_sort(pArrayListEmployee,Employee_criterioSortNombre,1))
        {
            retorno = 0;
        }
    }

    return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path Ruta donde se guardara el archivo
 * \param pArrayListEmployee Es la LinkedList con los elementos a guardar
 * \return Retorna 0 si se logra guardar sino retorna -1
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
    FILE* pArchivo = fopen(path,"w");
    int retorno = -1;

    if(pArchivo != NULL && !parser_SaveToText(pArchivo,pArrayListEmployee))
    {
        retorno = 0;
    }
    fclose(pArchivo);
    return retorno;
}


/** \brief Guarda los datos de los empleados en el archivo data.bin (modo binario).
 *
 * \param path Ruta donde se guardara el archivo
 * \param pArrayListEmployee Es la LinkedList con los elementos a guardar
 * \return Retorna 0 si se logra guardar sino retorna -1
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
    FILE* pArchivo = fopen(path,"wb");
    int retorno = -1;
    if(pArchivo != NULL && !parser_SaveToBinary(pArchivo,pArrayListEmployee))
    {
        retorno = 0;
    }
    fclose(pArchivo);
    return retorno;
}

