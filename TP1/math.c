#include <stdio.h>
#include <stdlib.h>

/**
*\brief solicita un numero al usuario y lo guarda en la posicion de memoria recibida por parametro.
*\param pNumero puntero que apunta a la posicion de memoria de la variable a la cual se le asigna el numero ingresado por el usuario.

*/
 void ingresarNumero(double* pNumero)

    {
        double auxiliar;
        int flag = 1;
        do{
            printf("ingrese un numero: ");
    //        __fpurge(stdin);
            fflush(stdin);
            flag = scanf("%lf",&auxiliar);

            if(flag == 1)
            {
                *pNumero = auxiliar;
            }
            else{
                printf("Error, ingrese un numero valido... ");
            }
        }while(flag != 1);

    }

/**
*\brief suma los valores recibidos por parametro y retorna el resultado
*/
double sumar(double num1,double num2)
{
    return num1 + num2;
}
/**
*\brief resta los valores recibidos por parametro y retorna el resultado
*/
double restar(double num1,double num2)
{
    return num1 - num2;
}
/**
*\brief multiplica los valores recibidos por parametro y retorna el resultado
*/
double multiplicar(double num1,double num2)
{
    return num1 * num2;
}
/**
*\brief divide los valores recibidos por parametro y retorna el  resultado
*\return num1 dividido en num2. si el parametro num2 es 0 retornara -1
*/
double dividir(double num1,double num2)
{
    if(num2 != 0)
    {
        return num1 / num2;
    }
    return -1;
}
/**
*\brief retorna el factorial del numero recibido por parametro
*/
double calcularFactorial(double num)
{
    if(num > 100)
        return -1;

    if(num == 1)
    {
        return 1;
    }
    return num * calcularFactorial(num - 1);
}
