/*
 ============================================================================
Magali Garcia 1E
Ejercicio 3-1:
Crear una función que permita determinar si un número es par o no.
La función retorna 1 en caso afirmativo y 0 en caso contrario. Probar en el main.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
char determinarParImpar(int num);
int main(void) {
	setbuf(stdout, NULL);
	int numeroIngresado;
	char resultado;

	printf("Ingrese un número para determinar si es par o impar: ");
	scanf("%d",&numeroIngresado);

	resultado = determinarParImpar(numeroIngresado);
	if(resultado == 1){
		printf("\nEl número %d es PAR",numeroIngresado);
	} else {
		printf("\nEl número %d es IMPAR",numeroIngresado);
	}
	return 0;
}

char determinarParImpar(int num)
{
	int resultado;
	if(num%2 == 0)
	{
		resultado = 1;
	} else {
		resultado = 0;
	}
	return resultado;
}
