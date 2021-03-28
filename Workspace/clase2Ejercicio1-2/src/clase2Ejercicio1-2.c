/*
 ============================================================================
Magali Garcia 1E

ingresar 3 números y mostrar el mayor de los tres.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	setbuf(stdout, NULL);
		int numeroUno;
		int numeroDos;
		int numeroTres;
		int mayorNumero;

		printf("Ingrese el primer número: ");
		fflush(stdin);
		scanf("%d",&numeroUno);

		printf("Ingrese el segundo número: ");
		fflush(stdin);
		scanf("%d",&numeroDos);

		printf("Ingrese el tercer número: ");
		fflush(stdin);
		scanf("%d",&numeroTres);

		if(numeroUno > numeroDos && numeroUno > numeroTres)
		{
			mayorNumero = numeroUno;
		} else
		{

		}


	return 0;
}
