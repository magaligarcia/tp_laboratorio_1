/*
 ============================================================================
Magali Garcia
Ejercicio 2-3:
Debemos alquilar el servicio de transporte para llegar a Mar del Plata con un grupo
de personas, de cada persona
debemos obtener los siguientes datos:
número de cliente,
estado civil (&#39;s&#39; para soltero&quot;, &#39;c&#39; para casado o &#39;v&#39; viudo),,
edad( solo mayores de edad, más de 17),
temperatura corporal (validar por favor)
y sexo (&#39;f&#39; para femenino, &#39;m&#39; para masculino, &#39;o&#39; para no binario).
NOTA: el precio por pasajero es de $600.
Se debe informar (solo si corresponde):
a) La cantidad de personas con estado &quot;viudo&quot; de más de 60 años.
b) el número de cliente y edad de la mujer soltera más joven.
c) cuánto sale el viaje total sin descuento.
d) si hay más del 50% de los pasajeros que tiene más de 60 años ,
el precio final tiene un descuento del 25%, que
solo mostramos si corresponde.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	setbuf(stdout, NULL);
	char respuesta = 's';
	char estadoCivil;
	char sexo;
	int edad;
	int temperatura;
	int numCliente;
	int contadorVmayor60 = 0;
	int numClienteSolteraMasJoven;
	int edadSolteraMasJoven;
	int contadorMujeresSolteras = 0;
	int contadorTotalPasajeros = 0;
	int acumuladorValorTotalViaje = 0;
	int precioFinalConDescuento;

	while(respuesta == 's')
	{
		printf("Ingrese el numero de cliente: ");
		fflush(stdin);
		scanf("%d",&numCliente);

		printf("Ingrese el estado civil ('c'-casado, 's'-soltero, 'v'-viudo): ");
		fflush(stdin);
		scanf("%c",&estadoCivil);
		while(estadoCivil != 'c' && estadoCivil !='s' && estadoCivil !='v')
		{
		printf("ERROR! \nDebe ingresar uno de los siguientes caracteres: \n'c'-casado, 's'-soltero, 'v'-viudo: ");
		fflush(stdin);
		scanf("%c",&estadoCivil);
		}

		printf("Ingrese la edad. Mayor de 17: ");
		fflush(stdin);
		scanf("%d",&edad);
		while(edad <18)
		{
			printf("ERROR! \nLa edad debe ser mayor de 17. Reintentelo: ");
			fflush(stdin);
			scanf("%d",&edad);
		}

		printf("Ingrese la temperatura entre 36 y 42: ");
		fflush(stdin);
		scanf("%d",&temperatura);
		while(temperatura < 36 || temperatura > 42)
		{
			printf("ERROR! \nLa temperatura debe ser entre 36 y 42. Reintentelo:");
			fflush(stdin);
			scanf("%d",&temperatura);
		}

		printf("Ingrese el sexo:'f' para femenino, 'm' para masculino, 'o' para no binario: ");
		fflush(stdin);
		scanf("%c",&sexo);
		while (sexo !='f' && sexo !='m' && sexo !='o')
		{
			printf("ERROR!: \nReingrese 'f' para femenino, 'm' para masculino, 'o' para no binario: ");
			fflush(stdin);
			scanf("%c",&sexo);
		}
		contadorTotalPasajeros++;
		acumuladorValorTotalViaje = acumuladorValorTotalViaje + 600;

		switch (estadoCivil){
		case 'v':
			if(edad >60)
			{
				contadorVmayor60 ++;//a)La cantidad de personas con estado viudo de más de 60 años.
			}

			break;
		case 's':
			if(sexo == 'f')//b) el número de cliente y edad de la mujer soltera más joven.
			{
				contadorMujeresSolteras++;
				if(contadorMujeresSolteras == 1 || edad < edadSolteraMasJoven)
				{
					numClienteSolteraMasJoven = numCliente;
					edadSolteraMasJoven = edad;
				}
			}
		break;

		}



		printf("Desea ingresar otro pasajero? Responda 's' para si o 'n' para no:  ");
		fflush(stdin);
		scanf("%c",&respuesta);
	}//FIN WHILE

//a)La cantidad de personas con estado &quot;viudo&quot; de más de 60 años.
	if(contadorVmayor60 !=0)
	{
		printf("\n-Cantidad de viudos mayores de 60: %d",contadorVmayor60);
		fflush(stdin);
	} else
	{
		printf("\n-No se ingresaron viudos mayores de 60. ");
		fflush(stdin);
	}
//b) el número de cliente y edad de la mujer soltera más joven.
	if(contadorMujeresSolteras != 0)
	{
		printf("\n-Edad de la mujer soltera más joven: %d", edadSolteraMasJoven);
		fflush(stdin);
		printf("\n-Número de cliente de la mujer soltera más joven: %d",numClienteSolteraMasJoven);
		fflush(stdin);
	} else
	{
		printf("\n-No se ingresaron mujeres solteras. ");
		fflush(stdin);
	}
//c) cuánto sale el viaje total sin descuento.
// d) si hay más del 50% de los pasajeros que tiene más de 60 años , el precio final
// tiene un descuento del 25%, que solo mostramos si corresponde.
	printf("\n-El valor total del viaje sin descuentos es: %d",acumuladorValorTotalViaje);
	fflush(stdin);

	if(contadorVmayor60 > (contadorTotalPasajeros / 2))
	{
		precioFinalConDescuento = acumuladorValorTotalViaje * 0.75;
		printf("\n-Más de la mitad de los pasajeros son mayores de 60 años. \nPor lo tanto el valor total del viaje con descuento del 25 porciento es: %d",precioFinalConDescuento);
		fflush(stdin);
	}

	return 0;
}
