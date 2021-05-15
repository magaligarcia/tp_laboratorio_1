#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include"menu.h"

//______________________________________________________________________________________________
//___________________________________ MENU PRINCIPAL _______________________________________________

int menuPrincipal(int minimoOpciones, int maximoOpciones){
	int seleccion;
	printf("\n==========================================\n");
	printf("		  MENU 		    ");
	printf("\n==========================================\n");
	printf("	Seleccione una opcion:		\n");
	printf("                                           \n");
	printf("	1. ALTAS					\n");
	printf("	2. MODIFICAR				\n");
	printf("	3. BAJA					\n");
	printf("	4. INFORMAR			    \n");
	printf("	5. SALIR			    \n");
	printf("                                           \n");
	printf("==========================================\n");
	printf("==========================================\n");
	printf("Respuesta: ");
	scanf("%d",&seleccion);
	while(seleccion <minimoOpciones || seleccion >maximoOpciones)
	{
		printf("*** ERROR *** \nAsegurese de ingresar una opcion del 1 al 4: \n");
		scanf("%d",&seleccion);
	}
	return seleccion;
}

//______________________________________________________________________________________________
//___________________________________SUB-MENU DE INFORMES _______________________________________________

int subMenuInformes(int minimoOpciones, int maximoOpciones){
    int seleccion;
	system("cls");
	printf("\n==========================================\n");
	printf("		  INFORMES: 		    ");
	printf("\n==========================================\n");
	printf("	Seleccione una opcion:		\n");
	printf("                                           \n");
	printf("1. Ordenar empleados alfabéticamente por "
			"\n   Apellido y Sector.\n\n");
	printf("2. Total y promedio de los salarios, y "
			"\n   cuántos empleados superan el salario "
			"\n   promedio.\n");
	printf("==========================================\n");
	printf("==========================================\n");
	printf("Respuesta: ");
	fflush(stdin);
	scanf("%d", &seleccion);
	while(seleccion <minimoOpciones || seleccion >maximoOpciones)
	{
		printf("*** ERROR *** \nReingrese opción 1 o 2: \n");
		scanf("%d",&seleccion);
	}
    return seleccion;
}

//______________________________________________________________________________________________
//___________________________________SUB MENU DE ORDENAMIENTO_______________________________________________
int subMenuOrdenamientoEmpleados(int minimoOpciones, int maximoOpciones){
    int seleccion;
	system("cls");
	printf("\n==========================================\n");
	printf("		  ORDENAMIENTO 		    ");
	printf("\n==========================================\n");
	printf("1. Ascendente.\n");
	printf("2. Descendente.\n");
	printf("==========================================\n");
	printf("==========================================\n");
	printf("Respuesta: ");
	fflush(stdin);
	scanf("%d", &seleccion);
	while(seleccion <minimoOpciones || seleccion >maximoOpciones)
	{
		printf("*** ERROR *** \nReingrese opción 1 o 2: \n");
		scanf("%d",&seleccion);
	}
    return seleccion;
}
