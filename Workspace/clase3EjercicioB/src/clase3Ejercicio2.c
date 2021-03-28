/*
 ============================================================================
Magali Garcia 1E - 25/03

b-Funciones
- Limpie la pantalla
- 	Asigne a las variables numero1 y numero2 los valores solicitados al usuario
- 	Valide los mismos entre 10 y 100
- 	Asigne a la variable operacion el valor solicitado al usuario
- 	Valide el mismo 's'-sumar, 'r'-restar
- Realice la operación de dichos valores a través de una función
- Muestre el resultado por pantalla
 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>
int realizarOperacion(int num1,int num2,char operacion);
int main(void) {
	setbuf(stdout, NULL);
	int numero1, numero2, resultado;
	char operacion;
	printf("\nIngrese un número del 10 al 100: ");
	scanf("%d",&numero1);
	while(numero1 < 10 || numero1 > 100)
	{
		printf("\nERROR! \nEl número debe ser entre 10 y 100. \n Por favor, Reintentelo:  ");
		scanf("%d",&numero1);
	}

	printf("\nIngrese un segundo número del 10 al 100: ");
	scanf("%d",&numero2);
	while(numero2 < 10 || numero2 > 100)
	{
		printf("\nERROR! \nEl número debe ser entre 10 y 100. \n Por favor, Reintentelo:  ");
		scanf("%d",&numero2);
	}

	printf("\nIngrese una operación para realizar entre los dos números: \n's' para sumar, 'r' para restar. ");
	fflush(stdin);
	scanf("%c",&operacion);
	while(operacion !='s' && operacion !='r')
	{
		printf("\nERROR! \nAsegurese de ingresar: 's' para sumar ó 'r' para restar. ");
		fflush(stdin);
		scanf("%c",&operacion);
	}

	resultado = realizarOperacion(numero1, numero2, operacion);
	printf("\nEl resultado es %d",resultado);
	return 0;
}

int realizarOperacion(int num1, int num2, char operacion)
{
	int total;
	if(operacion == 's')
	{
		total = num1 + num2;
	} else {
		total = num1 - num2;
	}
	return total;
}

