#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "utn.h"

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
    int option;
    int flag = 0;
    LinkedList* listaEmpleados = ll_newLinkedList();
    do{
        utn_getNumero(&option, "\n 01-Cargar los datos de los empleados desde el archivo data.csv (modo texto).\n 02-Cargar los datos de los empleados desde el archivo data.csv (modo binario).\n 03-Alta de empleado\n 04-Modificar datos de empleado\n 05-Baja de empleado\n 06-Listar empleados\n 07-Ordenar empleados\n 08-Guardar los datos de los empleados en el archivo data.csv(modo texto).\n 09-Guardar los datos de los empleados en el archivo data.csv(modo binario).\n 10-Salir\n","Ingrese un numero valido\n",1,10,1);
        switch(option)
        {
            case 1:
                printf("\nSize de la lista: %d \n",ll_len(listaEmpleados));
                if(!controller_loadFromText("data.csv",listaEmpleados))
                {
                    flag = 1;
                    printf("\nDatos cargados correctamente\n");
                }
                printf("\nSize de la lista: %d \n",ll_len(listaEmpleados));
                break;
            case 2:
                printf("\nSize Linked List %d",ll_len(listaEmpleados));
                if(!controller_loadFromBinary("data.bin",listaEmpleados))
                {
                    flag = 1;
                    printf("\nDatos cargados correctamente");
                }
                printf("\nSize Linked List %d",ll_len(listaEmpleados));
                break;
            case 3:
                if(!controller_addEmployee(listaEmpleados))
                {
                    flag = 1;
                    printf("Empleado agregado correctamente!");
                }
                else{
                    printf("No se pudo agregar el empleado");
                }
                break;
            case 4:
                controller_ListEmployee(listaEmpleados);
                if(flag)
                {
                    if(!controller_editEmployee(listaEmpleados))
                    {
                        printf("Empleado modificado correctamente!");
                    }
                    else
                    {
                        printf("No se pudo modificar el empleado");
                    }
                }
                else
                {
                    printf("No hay empleado/s para modificar");
                }
                break;
            case 5:
                if(flag)
                {
                    controller_ListEmployee(listaEmpleados);
                    if(!controller_removeEmployee(listaEmpleados))
                    {
                        printf("El empleado se borro correctamente");
                    }
                    else
                    {
                        printf("El empleado no se borro correctamente");
                    }
                }
                else
                {
                    printf("No hay empleado/s para borrar");
                }
                break;
            case 6:
                if(flag)
                {
                   controller_ListEmployee(listaEmpleados);
                }
                else
                {
                    printf("No hay empleado/s para listar");
                }
                break;
            case 7:
                if(flag)
                {
                    printf("Ordenando....\n");
                    if(!controller_sortEmployee(listaEmpleados))
                    {
                        printf("Se ordeno correctamente");
                    }
                    else
                    {
                        printf("No se pudo ordenar");
                    }
                }
                else
                {
                    printf("No hay empleado/s para ordenar");
                }

                break;

            case 8:
                if(flag)
                {
                    if(!controller_saveAsText("data.csv",listaEmpleados))
                    {
                        printf("\nArchivo guardado.");
                    }
                    else
                    {
                        printf("\nNo se pudo guardar los datos cargados correctamente");
                    }
                }
                else
                {
                    printf("No hay datos cargados");
                }
                break;

            case 9:
                if(flag)
                {
                    if(!controller_saveAsBinary("data.bin",listaEmpleados))
                    {
                        printf("\nArchivo guardado.");
                    }
                    else
                    {
                        printf("\nNo se pudo guardar el archivo correctamente");
                    }
                }
                else
                {
                    printf("No hay datos cargados");
                }
                break;
        }
     pause();
     limpiarPantalla();
    }while(option != 10);
    return 0;
}
