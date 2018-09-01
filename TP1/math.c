#include <stdio.h>
#include <stdlib.h>

/**
*\brief solicita un numero al usuario y lo guarda en la posicion de memoria recibida por parametro.
*\param pNumero puntero que apunta a la posicion de memoria de la variable a la cual se le asigna el numero ingresado por el usuario.

*/
 void ingresarNumero(float* pNumero)

    {
        printf("ingrese un numero: ");
//        __fpurge(stdin);
        fflush(stdin);
        scanf("%f",pNumero);
    }

/**
*\brief suma los valores recibidos por parametro y retorna el resultado
*/
float sumar(float num1,float num2)
{
    return num1 + num2;
}
/**
*\brief resta los valores recibidos por parametro y retorna el resultado
*/
float restar(float num1,float num2)
{
    return num1 - num2;
}
/**
*\brief multiplica los valores recibidos por parametro y retorna el resultado
*/
float multiplicar(float num1,float num2)
{
    return num1 * num2;
}
/**
*\brief divide los valores recibidos por parametro y retorna el  resultado
*\return num1 dividido en num2. si el parametro num2 es 0 retornara -1
*/
float dividir(float num1,float num2)
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
float calcularFactorial(float num)
{
    if(num == 1)
    {
        return 1;
    }
    return num * calcularFactorial(num - 1);
}
