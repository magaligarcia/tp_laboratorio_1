#include <stdio.h>
#include <stdlib.h>
#include "operacionesMatematicas.h"

int valIngresoOperandos(int opcion,int  num1,int num2){
	int retorno;
	if((opcion == 3 || opcion == 4) && (num1 == 0 && num2 == 0)){
		printf("\n3)>>>>>ERROR! Primero debe ingresar dos números distintos de cero para poder realizar las operaciones\n");
		retorno = 1;
	} else {retorno = 0;}
return retorno;
}

void valDividirPorCero(int num1, int num2){
	if(num2 == 0 ){
		printf("\n--No es posible dividir por cero.\n");
	} else {
		printf("\n--El resultado de %d / %d es: %d",num1, num2,divisionDeDosNumeros(num1, num2));
	}
}
