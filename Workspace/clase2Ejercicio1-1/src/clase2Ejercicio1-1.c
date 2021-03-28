/*
 ============================================================================
Magali Garcia 1E

Ingresar dos números enteros, sumarlos y mostrar el resultado.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	setbuf(stdout, NULL);
	int numeroUno;
	int numeroDos;
	int resultado;

	printf("Ingrese el primer número: ");
	fflush(stdin);
	scanf("%d",&numeroUno);

	printf("Ingrese el segundo número: ");
	fflush(stdin);
	scanf("%d",&numeroDos);

	resultado = numeroUno + numeroDos;

	printf("La suma de los dos números es: %d",resultado);

	return 0;
}
