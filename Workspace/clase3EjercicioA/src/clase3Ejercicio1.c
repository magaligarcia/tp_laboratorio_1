/*
 ============================================================================
Magali Garcia 1E - 25/03

a-Funciones
- Limpie la pantalla
- Asigne a la variable numero1 un valor solicitado al usuario
- Valide el mismo entre 10 y 100
- Realice un descuento del 5% a dicho valor a través de una función llamada realizarDescuento()
- Muestre el resultado por pantalla
 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>
float realizarDescuento(int num1);

int main(void) {
	setbuf(stdout, NULL);
	int numero1;
	float totalConDescuento;

	printf("Ingrese un numero: ");
	scanf("%d", &numero1);

	while(numero1 <10 || numero1 > 100)
	{
		printf("ERROR! Reingrese el número (entre 10 y 100): ");
		scanf("%d", &numero1);
	}
	totalConDescuento = realizarDescuento(numero1);
	printf("El número con el descuento del 5 porciento es: %.2f",totalConDescuento);
	return 0;
}
float realizarDescuento(int num1)
	{
		float descuento = num1 * 0.95; // Descuento del 5%
		return descuento;
	}
