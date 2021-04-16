#include <stdio.h>
#include <stdlib.h>

int sumaDeDosNumeros(int num1, int num2){
	int resultado;
	resultado = num1 + num2;
	return resultado;
}

int restaDeDosNumeros(int num1, int num2){
	int resultado;
	resultado = num1 - num2;
	return resultado;
}

int divisionDeDosNumeros(int num1, int num2){
	int resultado;
	resultado = num1 / num2;
	return resultado;
}

void factorialDeDosNumeros(int *num1, int *num2)
 {
	 int i;
	 int numero1 = *num1;
	 int numero2 = *num2;
	 int factorial1 = 1;
	 int factorial2 = 1;
		 for(i=1; i<=numero1; i++){
			 factorial1 *= i;
		 }
	 *num1 = factorial1;
		 for(i=1; i<=numero2; i++){
				 factorial2 *= i;
			 }
	 *num2 = factorial2;
}













