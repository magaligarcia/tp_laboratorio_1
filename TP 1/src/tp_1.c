/*============================================================================
Magali Garcia (1E) - Trabajo practico N°1
Hacer una calculadora. Para ello el programa iniciará y contará con un menú de opciones:
1. Ingresar 1er operando (A=x)
2. Ingresar 2do operando (B=y)
3. Calcular todas las operaciones
	a) Calcular la suma (A+B)
	b) Calcular la resta (A-B)
	c) Calcular la division (A/B)
	d) Calcular la multiplicacion (A*B)
	e) Calcular el factorial (A!)
4. Informar resultados
	a) “El resultado de A+B es: r”
	b) “El resultado de A-B es: r”
	c) “El resultado de A/B es: r” o “No es posible dividir por cero”
	d) “El resultado de A*B es: r”
	e) “El factorial de A es: r1 y El factorial de B es: r2”
5. Salir
• Todas las funciones matemáticas del menú se deberán realizar en una biblioteca aparte,
  que contenga las funciones para realizar las cinco operaciones.
• En el menú deberán aparecer los valores actuales cargados en los operandos A y B
  (donde dice “x” e “y” en el ejemplo, se debe mostrar el número cargado)
• Deberán contemplarse los casos de error (división por cero, etc)
• Documentar todas las funciones
 ============================================================================*/
#include <stdio.h>
#include <stdlib.h>
#include "operacionesMatematicas.h"
#include "validaciones.h"
#include "cabeceraYfooter.h"

int main(void) {
setbuf(stdout, NULL);
int flagPrimerNum = 0,  flagSegundoNum = 0;
int primerOperando = 0, segundoOperando = 0;
int opcionElegida;
int factorial1, factorial2;
int salir = 0;

cabecera();
do{
	if(salir == 0){
		if(flagPrimerNum == 0){
			printf("\n1) Ingresar 1er operando (A)");
			flagPrimerNum = 1;
		} else {
			printf("\nIngrese otra opción: ");
			printf("\n1) Modificar 1er operando (A = %d)",primerOperando);
			}
		if(flagSegundoNum == 0){
			printf("\n2) Ingresar 2do operando (B)");
			flagSegundoNum = 1;
		} else{
			printf("\n2) Modificar 2do operando (B = %d)",segundoOperando);
			}
		printf("\n3) Calcular todas las operaciones.");
		printf("\n4) Informar resultados.");
		printf("\n5) Salir \n");
		scanf("%d",&opcionElegida);
	}
	switch(opcionElegida){
		case 1:
			printf("\n>>>>> Ingrese el 1er operando: ");
			scanf("%d",&primerOperando);
			factorial1 = primerOperando;
			break;
		case 2:
			printf("\n>>>>> Ingrese el 2do operando: ");
			scanf("%d",&segundoOperando);
			factorial2 = segundoOperando;
			break;
		case 3:
			if (valIngresoOperandos(opcionElegida, primerOperando, segundoOperando) == 0){
				sumaDeDosNumeros(primerOperando, segundoOperando);
				restaDeDosNumeros(primerOperando, segundoOperando);
				if(segundoOperando != 0 ) {divisionDeDosNumeros(primerOperando, segundoOperando);}
				factorialDeDosNumeros(&factorial1, &factorial2);
				printf("\n>>>>> Operaciones calculadas exitosamente!\n>>>>> Opción 4 para visualizarlos.\n");
			}
			break;
		case 4:
			if (valIngresoOperandos(opcionElegida, primerOperando, segundoOperando) == 0){
				printf("\n--El resultado de %d + %d es: %d",primerOperando, segundoOperando, sumaDeDosNumeros(primerOperando, segundoOperando));
				printf("\n--El resultado de %d - %d es: %d",primerOperando, segundoOperando,restaDeDosNumeros(primerOperando, segundoOperando));
				valDividirPorCero(primerOperando, segundoOperando);
				printf("\n--El factorial de %d es: %d\n--El factorial de %d es: %d\n",primerOperando,factorial1,segundoOperando,factorial2);
			}
			break;
		case 5:
			salir = 1;
			footer();
			break;
		default:
			printf("\n>>>>> El número ingresado no es una opción de menú valida. \nReintentelo: \n");
	}//fin switch
} while(salir == 0);//fin while
	return 0;
}//fin main
