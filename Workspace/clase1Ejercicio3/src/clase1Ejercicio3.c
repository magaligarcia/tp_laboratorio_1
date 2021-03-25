/*
 ============================================================================
 Magali Garcia 1E

c-Control de Flujo
Pedirle al usuario su edad y su estado civil ('c'-casado, 's'-soltero, 'v'-viudo, 'd'-divorciado)
Si ingresa una edad menor a 18 años y un estado civil distinto a "Soltero",
mostrar el siguiente mensaje: 'Es muy pequeño para NO ser soltero.'
 ============================================================================
*/

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	setbuf(stdout, NULL);
	int edad;
	char estadoCivil;

	printf("Ingrese su edad");
	fflush(stdin);
	scanf("%d",&edad);
	printf("Ingrese su estado civil ('c'-casado, 's'-soltero, 'v'-viudo, 'd'-divorciado)");
	fflush(stdin);
	scanf("%c",&estadoCivil);

	if (edad < 18 && estadoCivil != 's')
	{
		printf("Es muy pequeño para NO ser soltero");
	}

	printf("\n su edad es: %d",edad);
	fflush(stdin);
	printf("\n su estado civil es: %c",estadoCivil);

	return 0;
}
