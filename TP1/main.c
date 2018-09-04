#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio_ext.h>
#include "math.h"

int main()
{
    int operacionesRealizadas;
    int opcion;
    int salir;
    double num1 = 0,num2 = 0, rtdoSuma,rtdoResta, rtdoProducto, rtdoDivision, rtdoFactorial;
    do{

        printf("1.ingrese 1er operando (A=%.2lf)\n2.ingrese 2do operando (B=%.2lf)\n3.calcular todas las operaciones\n4 informar resultados\n5 salir\n", num1,num2);
        printf("ingrese una opcion del menu:");
        __fpurge(stdin);
        scanf("%d",&opcion);
        switch(opcion)
        {
            case 1: ingresarNumero(&num1);
            operacionesRealizadas = 0;
                break;
            case 2: ingresarNumero(&num2);
            operacionesRealizadas = 0;
                break;
            case 3:
                rtdoSuma = sumar(num1,num2);
                rtdoResta = restar(num1,num2);
                rtdoProducto = multiplicar(num1,num2);
                rtdoDivision = dividir(num1,num2);
                rtdoFactorial = calcularFactorial(num1);
                printf("Calculos realizados correctamente.");
                operacionesRealizadas = 1;
                break;

            case 4:
                if(operacionesRealizadas == 1)
                {

                    printf("\n %.2lf + %.2lf = %.2lf",num1,num2,rtdoSuma);
                    printf("\n %.2lf - %.2lf = %.2lf",num1,num2,rtdoResta);
                    printf("\n %.2lf * %.2lf = %.2lf",num1,num2,rtdoProducto);
                    if(rtdoDivision != -1)
                    {
                        printf("\n %.2lf / %.2lf = %.2lf",num1,num2,rtdoDivision);
                    }
                    else
                    {
                        printf("\n %.2lf / %.2lf = Error matematico",num1,num2);
                    }
                    if(rtdoFactorial == -1)
                    {
                         printf("\n %.2lf ! = Numero demasiado grande",num1);
                    }
                    else{
                          printf("\n %.2lf ! = %.2lf",num1,rtdoFactorial);
                    }

                }
                else
                {
                    printf("Calcule las operaciones antes de ver los resultados.");
                }
                break;

            case 5:
                salir = 1;
                break;
            default:
                printf("Ingrese una opcion valida!\n");
        }

        __fpurge(stdin);
        printf("\n ingrese enter para continuar....");
        getchar();
        system("@cls||clear");

    }while(salir != 1);
    return 0;
}

