/*
 ============================================================================
 Name        : clase1Ejercicio2.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
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

