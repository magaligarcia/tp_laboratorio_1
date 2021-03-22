/*
 ============================================================================
d-Operadores Logicos
Aplicando el concepto de Operadores Lógicos con valores booleanos en el condicional:
Solicitar un número al usuario
Informar si el mismo es par o impar.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	setbuf(stdout, NULL);
	int numeroIngresado;
	int resultado;

	printf("Ingrese un número: ");
	fflush(stdin);
	scanf("%d",&numeroIngresado);

	resultado = numeroIngresado % 2 ==0;

	if(resultado)
	{
		printf("El número ingresado es par");

	}
	else
	{
		printf("El número ingresado es impar");

	}
	return 0;
}
