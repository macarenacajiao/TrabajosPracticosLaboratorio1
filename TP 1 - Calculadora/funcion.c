float funcionSuma(float operandoUno, float operandoDos)
{
    float respuesta;
    respuesta=operandoUno+operandoDos;
    return respuesta;
}
float funcionResta(float operandoUno, float operandoDos)
{
    float respuesta;
    respuesta=operandoUno-operandoDos;
    return respuesta;
}
float funcionDivision(float operandoUno, float operandoDos)
{
    float respuesta;
    respuesta=operandoUno/operandoDos;
    return respuesta;
}
float funcionMultiplicacion(float operandoUno, float operandoDos)
{
    float respuesta;
    respuesta=operandoUno*operandoDos;
    return respuesta;
}
int factorialUno(float operandoUno)
{
    int respuestaOperandoUno=1;
    int i=0;
    (int) operandoUno;
    for (i=0; i>1 ; i--)
    {
        respuestaOperandoUno=respuestaOperandoUno*i;

    }
    return respuestaOperandoUno;
}
    long int factorial (long int numero)
{
    int i;
    int resultado = 1;

    for (i=numero; i >= 1; i--)
    {
        resultado = resultado * i;
    }
    return resultado;
}
//funciones, suma, resta, multiplicación, división y factorial.

