#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Empleado.h"
#include "utn.h"

int inicializarEmpleado(Empleado* empleadoArray, int len){
    int retorno = OCUPADO;
    if(empleadoArray!=NULL && len>0)
    {
        for(int i =0; i<len; i++)
        {
            empleadoArray[i].isEmpty=1;
        }
        retorno=LIBRE;
    }
    return retorno;
}

int buscarLibre(Empleado* empleadoArray, int len){
    int retorno=OCUPADO;
    for (int i=0; i<len; i++)
    {
        if(empleadoArray[i].isEmpty)
        {
            retorno=i;
            break;
        }
    }
    return retorno;
}

void pedirDatosEmpleado(char nombre[], char apellido[], float* sueldo, int* sector){
	printf("\n==========================================\n");
	printf("	 ALTA EMPLEADO:		    ");
	printf("\n==========================================\n");
	utn_getNombre("Ingrese el nombre: \n","* ERROR *\n Asegurese de ingresar solo letras: \n", 3, 50, 3, nombre);
	utn_getNombre("Ingrese el apellido: \n","* ERROR *\n Asegurese de ingresar solo letras: \n", 3, 50, 3, apellido);
	utn_getFloat("Ingrese el sueldo: \n","* ERROR *\n Asegurese de ingresar solo números: \n", 4, 8, 3, sueldo);
	utn_getNumero_SinSigno("Ingrese el sector: \n"
						   "  1. Direccion\n"
						   "  2. Recursos Humanos\n"
						   "  3. Produccion\n"
						   "  4. Finanzas / Contabilidad\n"
						   "  5. Sistemas \n\n"
						   "Respuesta: ",
						   "* ERROR *\n Asegurese de ingresar solo números: \n",1,5,3,sector);
}

int cargarDatosEmpleado(Empleado* empleadoArray, int len, int id, char Nombre[],char Apellido[],float Salario,int Sector)
{
    int retorno = -1;
    int indiceLibre;
    indiceLibre = buscarLibre(empleadoArray, len);
    if(indiceLibre!=-1 && empleadoArray!= NULL && len>0)
    {
        empleadoArray[indiceLibre].id = id;
        empleadoArray[indiceLibre].isEmpty = OCUPADO;
        strcpy(empleadoArray[indiceLibre].Nombre,Nombre);
        strcpy(empleadoArray[indiceLibre].Apellido,Apellido);
        empleadoArray[indiceLibre].Salario = Salario;
        empleadoArray[indiceLibre].Sector = Sector;
        retorno=0;
    }
    return retorno;
}

int buscarEmpleadoPorID(Empleado* empleadoArray, int len, int id)
{
    int IDBuscado=-1;
    for (int i=0; i<len; i++)
    {
        if(empleadoArray[i].id == id && empleadoArray[i].isEmpty ==0)
        {
        	IDBuscado=i;
            break;
        }
    }
    return IDBuscado;
}

int eliminarEmpleadoPorID(Empleado* empleadoArray, int len, int id)
{
    int seDioDeBaja=NO;
    int idEmpleado;
    int indiceEmpleado;
    char confirmacion;

    system("cls");
	printf("\n==========================================\n");
	printf("	 BAJA DE EMPLEADO:		    ");
	printf("\n==========================================\n");
    imprimirEmpleados(empleadoArray, len);
    printf("\n");
    printf("Ingrese el ID del empleado que desea dar de baja:\n");
    scanf("%d", &idEmpleado);

    indiceEmpleado = buscarEmpleadoPorID(empleadoArray, len, idEmpleado);

    if(indiceEmpleado != -1 && empleadoArray!= NULL && len>0){
    	printf("\n=====================================================================\n");
    	printf("                           CONFIRMACION: 		    ");
    	printf("\n=====================================================================\n");
        printf("             Esta seguro que desea dar de baja a este empleado? \n\n");
        		mostrarEmpleado(empleadoArray[indiceEmpleado]);
        printf("\n             * Los datos eliminados no podrán recuperarse * \n"
        	   "                                s/n:\n");
    	printf("======================================================================\n");
    	printf("Respuesta: ");
        fflush(stdin);
        scanf("%c", &confirmacion);
    	printf("                                           \n");
            if(confirmacion == 's'){
                empleadoArray[indiceEmpleado].isEmpty = LIBRE;
                seDioDeBaja=SI;
            }else{
				printf("\n******************************");
				printf("\n      Baja Cancelada!\n");
				printf("******************************\n");
            }
    }else{

        printf("No existe el ID: %d \n", idEmpleado);
    }
    return seDioDeBaja;
}

void mostrarEmpleado(Empleado empleadoArray)
{
    printf("%d\t  %10s   \t%10s \t  %9.2f \t        %d\n", empleadoArray.id, empleadoArray.Nombre,
    		empleadoArray.Apellido, empleadoArray.Salario, empleadoArray.Sector);
}

int imprimirEmpleados(Empleado* empleadoArray, int len)
{
    int SeCargoEmpleado = NO;
    printf("n\n           LISTADO COMPLETO: \n");
    printf("-----------------------------------------------------------------------\n");
    printf("ID\t      NOMBRE \t    APELLIDO \t  SUELDO \t     SECTOR \n");
    printf("-----------------------------------------------------------------------\n");
    for(int i=0; i<len; i++)
    {
        if(!(empleadoArray[i].isEmpty))  // Vacio = 1 / Cargado = 0
        {
            mostrarEmpleado(empleadoArray[i]);
            SeCargoEmpleado = SI ;
        }
    }
    if (SeCargoEmpleado == NO)
    {
        printf("No hay empleados que mostrar");
    }
    return 0;

}

int modificarEmpleado (Empleado* empleadoArray, int len)
{
    int id;
    int i;
    int opcion;
    int retorno;

    system("cls");
    imprimirEmpleados(empleadoArray, len);
    printf("\n\nIngrese el ID del empleado que desea modificar: ");
    scanf("%d", &id);
    i = buscarEmpleadoPorID(empleadoArray, len, id);

    if(empleadoArray!=NULL && len>0 && i!=-1){
        mostrarEmpleado(empleadoArray[i]);
    	printf("\n==========================================\n");
    	printf("	 MODIFICAR DATOS DE EMPLEADO: 		    ");
    	printf("\n==========================================\n");
    	printf("	¿Que desea modificar?		\n");
    	printf("                                           \n");
    	printf("	1. NOMBRE					\n");
    	printf("	2. APELLIDO				\n");
    	printf("	3. SALARIO					\n");
    	printf("	4. SECTOR			    \n");
    	printf("                                           \n");
    	printf("==========================================\n");
    	printf("==========================================\n");
    	printf("                                           \n");
        fflush(stdin);
        scanf("%d", &opcion);

        switch(opcion){
        case 1:
            printf("\nIngrese un nuevo nombre: \n ");
            fflush(stdin);
            gets(empleadoArray[i].Nombre);
            retorno=0;
            break;

        case 2:
            printf("\nIngrese un nuevo apellido:  \n");
            fflush(stdin);
            gets(empleadoArray[i].Apellido);
            retorno=0;
            break;

        case 3:
            printf("\nIngrese un nuevo salario:  \n");
            fflush(stdin);
            scanf("%f", &empleadoArray[i].Salario);
            retorno=0;
            break;

        case 4:
            printf("\nIngrese un nuevo Sector:  \n");
            fflush(stdin);
            scanf("%d", &empleadoArray[i].Sector);
            retorno=0;
            break;
        default:
            printf("Opcion invalida.\n");
            retorno=-1;
        }
    }else{
        printf("\n****************************");
        printf("\n ERROR. \n El ID ingresado no existe. \n");
        printf("\n****************************\n");
    }
    return retorno;
}

int ordenamientoEmpleadosPorSector(Empleado* empleadoArray, int len, int order){

    int ordenamientoCorrecto = NO;

    Empleado auxEmpleado;
    if(empleadoArray!= NULL && len>0)
    {
        if(order){
            for(int i = 0; i < len-1; i++){
                for (int j=i+1; j<len; j++){

                    if(empleadoArray[i].Sector > empleadoArray[j].Sector){
                        auxEmpleado = empleadoArray[i];
                        empleadoArray[i] = empleadoArray[j];
                        empleadoArray[j]= auxEmpleado;
                    }
                }
            }
        }else if(order == 2){

            for(int i =0; i<len-1; i++){
                for (int j=i+1; j<len; j++){

                    if(empleadoArray[i].Sector < empleadoArray[j].Sector){

                        auxEmpleado = empleadoArray[i];
                        empleadoArray[i] = empleadoArray[j];
                        empleadoArray[j]= auxEmpleado;
                    }
                }
            }
        }
        ordenamientoCorrecto=SI;
    }
    return ordenamientoCorrecto;
}

int ordenamientoEmpleadosPorNombre(Empleado* empleadoArray, int len, int order)
{
    int ordenamientoCorrecto = NO;
    Empleado auxEmpleado;
    if(empleadoArray!= NULL && len>0)
    {
        if(order){
            for(int i = 0; i < len-1; i++){
                for (int j=i+1; j<len; j++){

                    if(empleadoArray[i].Nombre > empleadoArray[j].Nombre){
                        auxEmpleado = empleadoArray[i];
                        empleadoArray[i] = empleadoArray[j];
                        empleadoArray[j]= auxEmpleado;
                    }
                }
            }
        }else if(order == 2){

            for(int i =0; i<len-1; i++){
                for (int j=i+1; j<len; j++){

                    if(empleadoArray[i].Nombre < empleadoArray[j].Nombre){

                        auxEmpleado = empleadoArray[i];
                        empleadoArray[i] = empleadoArray[j];
                        empleadoArray[j]= auxEmpleado;
                    }
                }
            }

        }
        ordenamientoCorrecto=SI;

    }
    return ordenamientoCorrecto;
}

int promedioEmpleados(Empleado* empleadoArray, int len){

    int promedioRealizado = NO;
    int contador = 0;
    float sumaPromedio = 0;
    float total;
    int ciclo = 0;
    if(empleadoArray!=NULL && len>0){

        for(int i=0;i<len;i++){

            if(empleadoArray[i].isEmpty!=-1){
                ciclo++;
                sumaPromedio += empleadoArray[i].Salario;
            }

        }
        total=sumaPromedio/ciclo;

        for(int j=0;j<len;j++)
        {
            if(empleadoArray[j].isEmpty!=-1 && empleadoArray[j].Salario > total )
            {
                contador += 1;
            }
        }
        printf("________________________________________________________________________");
        printf("\nLa suma total de los salarios es de: $ %.2f.\n",sumaPromedio);
        printf("________________________________________________________________________");
        printf("\nEl promedio total de los salarios es de: $ %.2f.\n",total);
        printf("________________________________________________________________________");
        printf("\nLos empleados que superan el promedio son %d.\n",contador);
        printf("________________________________________________________________________");
        promedioRealizado = SI;
    }
    return promedioRealizado;
}
