#include <stdio.h>
#include <stdlib.h>
#include "funcion.h" //biblioteca creada para las funciones

int main ()
{
    //variables
    int opcion;
    float operandoUno=0;
    float operandoDos=0;
    float suma;
    float resta;
    float multiplicacion;
    float division;
    long int resultadoFactorialUno;
    long int resultadoFactorialDos;
    int flag1=0, flag2=0;

    do
    {
        //Menu
        system("pause");
        system("cls");
        printf("\n Calculadora by Macarena Cajiao\n");
        printf(" Menu");
        printf("\n ----------------------------------------");
        printf("\n 1.Ingresar primer operando (A=%f).",operandoUno);
        printf("\n 2.Ingresar segundo operando (B=%f).",operandoDos);
        printf("\n 3.Calcular todas las operaciones.");
        printf("\n a)Calcular la suma (A+B).");
        printf("\n b)Calcular la resta (A-B).");
        printf("\n c)Calcular la division (A/B).");
        printf("\n d)Calcular la multiplicacion (A*B).");
        printf("\n e)Calcular el factorial (A) & (B)\n");
        printf(" 4.Informar resultados.");
        printf("\n 5.Salir de la calculadora.");
        printf("\n ----------------------------------------\n");
        printf(" Elija una opcion: \n");
        scanf ("%d", &opcion);

        switch(opcion)
        {
        case 1:
            flag1=1;
            printf(" Por favor ingrese primer operando: ");
            scanf ("%f", &operandoUno);
            long int factorialUno = (int)operandoUno;
            break;
        case 2:
            flag2=1;
            printf(" Por favor ingrese segundo operando: ");
            scanf ("%f", &operandoDos);
            long int factorialDos = (int)operandoDos;
            break;
        case 3:
            if (flag1==0 || flag2==0)
            {
                printf (" Error, no ingresaste los operandos!");
            }
            else
            {
                suma=funcionSuma( operandoUno,  operandoDos);
                resta=funcionResta( operandoUno,  operandoDos);
                if (operandoDos==0)
                {
                    printf (" No se puede dividir por cero! Ingrese un numero valido");
                }
                else
                {
                    division=funcionDivision( operandoUno,  operandoDos);
                }
                multiplicacion=funcionMultiplicacion( operandoUno,  operandoDos);
                if (operandoUno<0 || operandoDos<0)
                {
                    printf (" No se pueden factorear numeros negativos!");
                }
                else
                {
                    resultadoFactorialUno=factorial(factorialUno);
                    resultadoFactorialDos=factorial(factorialDos);
                }
            }
            break;
        case 4:
            if (flag1==0 || flag2==0)
            {
                printf (" Error, no ingresaste los operandos!");
            }
            else
            {
                printf("\n La suma de %.2f+%.2f es %.2f", operandoUno, operandoDos, suma);
                printf("\n La resta de %.2f-%.2f es %.2f", operandoUno, operandoDos, resta);
                printf("\n La division de %.2f/%.2f es %.2f", operandoUno, operandoDos, division);
                printf("\n La multiplicacion de %.2f*%.2f es %.2f \n", operandoUno, operandoDos, multiplicacion);
                if (operandoUno<0 || operandoDos<0)
                {
                    printf (" No se pueden factorear numeros negativos!");
                }
                else
                {
                    printf(" El factorial de %.2f es %li",operandoUno, resultadoFactorialUno);
                    printf(" y el factorial de %.2f es %li \n",operandoDos, resultadoFactorialDos);
                }
            }
            break;
        case 5:
            printf (" Gracias por usar la calculadora ^_^! ");
            break;
        default:
            printf (" Error. Ingrese nuevamente el comando del 1 al 5.");
        }
    }
    while (opcion!=5);
}

