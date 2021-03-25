/******************************************************************************
Magali Garcia
Ejercicio 2-2:
Ingresar 10 números enteros, distintos de cero. Mostrar:
a. Cantidad de pares e impares.
b. El menor número ingresado.
c. De los pares el mayor número ingresado.
d. Suma de los positivos.
e. Producto de los negativos.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
int main()
{
    setbuf(stdout, NULL);
	int num;
	int contadorPares = 0;
	int contadorImpares = 0;
	int menorNumero;
	int mayorPar;
	int acumuladorPositivos = 0;
	int acumuladorNegativos = 1;
	int productoNegativos;


	int i;
	for (i=0; i<10; i++)
	{
	   printf("Ingrese un número: ");
	   fflush(stdin);
	   scanf("%d",&num);
	   while (num == 0)
	    {
    	   printf("ERROR. El número debe ser distinto de 0 cero. Reintentelo: ");
    	   fflush(stdin);
    	   scanf("%d",&num);
	    }

	   switch (num % 2) //contador pares-impares
	   {
	       case 0:
	       contadorPares++;
	       if(num>mayorPar || i == 0) // mayor de los pares
	       {
	           mayorPar = num;
	       }
	       break;

    	   default:
    	       contadorImpares++;
    	   break;
	   }

	   if(num < menorNumero || i == 0  ) // menor numero
	   {
	       menorNumero = num;
	   }

	   if (num > 0) //Suma de los positivos.
	   {
	       acumuladorPositivos = acumuladorPositivos + num;
	   }
	   else
	   if(num < 0) // Producto de los negativos.
	   {
	       acumuladorNegativos = (acumuladorNegativos + num) -1;
	       productoNegativos = acumuladorNegativos * num;
	   }



	} //fin bucle

    printf("Cantidad de pares: %d", contadorPares);
    printf("\nCantidad de impares: %d", contadorImpares);
    printf("\nEl menor número ingresado: %d", menorNumero);
    printf("\nDe los pares el mayor número ingresado es: %d", mayorPar);
    printf("\nSuma de los positivos es: %d", acumuladorPositivos);
    printf("\nProducto de los negativos es: %d", productoNegativos);

    return 0;
}
