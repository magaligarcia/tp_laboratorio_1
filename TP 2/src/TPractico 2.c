/*
 ============================================================================
 Name        : TP2.c
 Author      : Garcia Magali - 1E

 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "menu.h"
#include "Empleado.h"
#define TAM 3
#define NO -1
#define SI 0

void pedirDatosEmpleado(char nombre[], char apellido[], float* sueldo, int* sector);

int main(void) {
	setbuf(stdout,NULL);
	Empleado ArrayEmpleado[TAM];
	int idEmpleado=1000;

	char nombre[51];
	char apellido[51];
	float sueldo;
	int sector;
	char sectorMostrar[25];

	int cargaExitosa;
	int modificacionExitosa;
	int bajaExitosa;
	int respuesta = NO;
	int cargaPrevia=0;

	inicializarEmpleado(ArrayEmpleado, TAM);
	    do{
	        switch(menuPrincipal(1,5)){
	        case 1://ALTA
	            pedirDatosEmpleado(nombre, apellido, &sueldo, &sector);
	            cargaExitosa = cargarDatosEmpleado(ArrayEmpleado, TAM, idEmpleado, nombre, apellido, sueldo, sector);

	            if(cargaExitosa!=0){
					printf("\n************************************************************");
					printf("\nERROR! No se pudo completar la carga del empleado\n");
					printf("************************************************************\n");
	            } else {
					printf("\n******************************");
					printf("\n      Alta exitosa!\n");
					printf("******************************\n");
					printf("ID del empleado: %d\n",idEmpleado);
					printf("Nombre: %s\n",nombre);
					printf("Apellido: %s\n",apellido);
					printf("Salario: %.2f\n",sueldo);
					switch(sector)
					{
						case 1:
							strcpy(sectorMostrar,"1: Dirección");
							break;
						case 2:
							strcpy(sectorMostrar,"2: Recursos Humanos");
							break;
						case 3:
							strcpy(sectorMostrar,"3: Producción");
							break;
						case 4:
							strcpy(sectorMostrar,"4: Finanzas / Contabilidad");
							break;
						case 5:
							strcpy(sectorMostrar,"5: Sistemas");
							break;
					}
					printf("Sector N°%s\n\n",sectorMostrar);
	                idEmpleado++;
	                cargaPrevia = 1;
	            }
	            system("pause");
	            break;

	        case 2://MODIFICAR
	            if(cargaPrevia){
	               modificacionExitosa = modificarEmpleado(ArrayEmpleado, TAM);
	                if(modificacionExitosa ==0){
						printf("\n*********************************************");
						printf("\nCambios guardados en empleado: %s\n",nombre);
						printf("*********************************************\n");
	                }
	            }else{

					printf("\n************************************************************");
					printf("\n ERROR! \nPrimero debes cargar almenos un empleado para poder modificar\n");
					printf("************************************************************\n\n\n");
	            }
	            system("pause");
	            break;

	        case 3://BAJA
	            if(cargaPrevia){
	            	bajaExitosa = eliminarEmpleadoPorID(ArrayEmpleado, TAM, idEmpleado);
	                if(bajaExitosa == 0)
	                {
						printf("\n*********************************************");
						printf("\nSe han eliminado los datos correctamente. \n");
						printf("*********************************************\n");
	                }
	            }else{
					printf("\n******************************************************");
					printf("\n ERROR! \n No se pudo completar la baja, reintentelo.");
					printf("\n******************************************************\n\n\n");
	            }
	            system("pause");
	            break;


	        case 4://INFORMAR
	             if(cargaPrevia){
	                int orden;
	                switch(subMenuInformes(1,2)){
	                    case 1:
	                        orden = subMenuOrdenamientoEmpleados(1,2);
	                        ordenamientoEmpleadosPorSector(ArrayEmpleado, TAM, orden);
	                        printf("\nOrdenamiento por sector:\n");
	                        imprimirEmpleados(ArrayEmpleado, TAM);
	                        ordenamientoEmpleadosPorNombre(ArrayEmpleado, TAM, orden);
	                        printf("\nOrdenamiento por nombre:\n");
	                        imprimirEmpleados(ArrayEmpleado, TAM);
	                    break;
	                    case 2:
	                    	promedioEmpleados(ArrayEmpleado, TAM);
	                        break;
	                    }
	            }else {
					printf("\n************************************************************");
					printf("\nERROR! \nPrimero debes cargar almenos un empleado.\n");
					printf("************************************************************\n\n\n");
	            }
	            system("pause");
	            break;

	        case 5://SALIR
	            respuesta = SI;
	            break;

	        default://OPCION INCORRECTA
	            printf("\n************************");
				printf("\nERROR OPCION INVALIDA! "
					   "\nReintentelo: \n");
				printf("**************************\n\n\n");
	            system("pause");
	            break;
	        }
	    }while (respuesta==NO);
	return EXIT_SUCCESS;
}
