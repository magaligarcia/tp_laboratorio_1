/*
 ============================================================================
Magali Garcia 1E

Ejercicio 3-3:
Crear una función que pida el ingreso de un entero y lo retorne.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
int pedirYMostrarEntero();
int main(void) {
	setbuf(stdout, NULL);
	pedirYMostrarEntero();
	return 0;
}

int pedirYMostrarEntero() {
	int numeroIngresado;
	int mostrar;
	printf("Ingrese un número entero: ");
	scanf("%d",&numeroIngresado);

	mostrar = printf("El número ingresado es: %d",numeroIngresado);
	return mostrar;
}
