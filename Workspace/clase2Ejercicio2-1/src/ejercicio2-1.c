/*
 ============================================================================
 Name        : ejercicio2-1.c
 Author      : Magali Garcia
 Ejercicio 2-1: Ingresar 5 números enteros calcular y mostrar el promedio de los números. Probar la
 aplicación con distintos valores.
 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>

int main(void) {
	setbuf(stdout, NULL);
	int num;
	int acumulador = 0;
	int contador = 0;
	int promedio;

	int i;
	for (i=0 ; i <5 ; i++)
	{
	    printf("Ingrese un numero entero");
	    scanf("%d",&num);
	    acumulador = acumulador + num;
	    contador++;

	}

	promedio = acumulador / contador;

	printf("El promedio de los numeros ingresados es: %d",promedio);

	return 0;
}
