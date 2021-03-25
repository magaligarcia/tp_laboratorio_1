/*
 ============================================================================
Magali Garcia 1E

Entrada/salida
Pedir el sueldo al usuario. Sumarle un 10% e informarle cuál será su sueldo con aumento
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	setbuf(stdout, NULL);
	int sueldo;
	int sueldoConAumento;

	printf("Ingrese el sueldo:");
	scanf("%d", &sueldo);
	sueldoConAumento = sueldo * 1.1;
	printf("El sueldo más el aumento del 10 porciento es: %d",sueldoConAumento);

	return 0;
}

