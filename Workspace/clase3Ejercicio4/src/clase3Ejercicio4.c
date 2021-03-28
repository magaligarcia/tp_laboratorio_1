/*
 ============================================================================
Magali Garcia 1E

Ejercicio 3-4:
Realizar un programa en donde se puedan utilizar los prototipos de la función Sumar en sus 4 combinaciones.
int Sumar1(int, int);
int Sumar2(void);
void Sumar3(int, int);
void Sumar4(void);
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
int Sumar1(int n1, int n2);
int Sumar2(void);
void Sumar3(int n1, int n2);
void Sumar4(void);

int main(void) {
	setbuf(stdout, NULL);
	int num1, num2, resultado1, resultado2;

	printf("Ingrese un número: ");
	scanf("%d",&num1);

	printf("Ingrese otro número: ");
	scanf("%d",&num2);

	resultado1 = Sumar1(num1, num2);
	printf("\nEl resultado de la función Sumar1 es : %d",resultado1);

	Sumar3(num1, num2);

	resultado2 = Sumar2();
	printf("\nEl resultado de la función Sumar2 es : %d",resultado2);

	Sumar4();

	return 0;
}

int Sumar1(int n1, int n2)
{
	int sumar = n1 + n2;
	return sumar;
}

int Sumar2(void)
{
	int num1;
	int num2;
	int sumar;

	printf("\nIngrese un número: ");
	scanf("%d",&num1);

	printf("\nIngrese otro número: ");
	scanf("%d",&num2);

	sumar= num1 + num2;
	return sumar;
}

void Sumar3(int n1, int n2)
{
	int resultado3 = n1 + n2;
	printf("\nEl resultado de la función Sumar3 es : %d",resultado3);
}

void Sumar4(void)
{
	int num1;
	int num2;
	int resultado4;

	printf("\nIngrese un número: ");
	scanf("%d",&num1);

	printf("\nIngrese otro número: ");
	scanf("%d",&num2);

	resultado4 = num1 + num2;
	printf("\nEl resultado de la función Sumar4 es : %d",resultado4);
}











