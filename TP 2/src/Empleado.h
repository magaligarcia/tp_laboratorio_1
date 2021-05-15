#ifndef EMPLEADO_H_
#define EMPLEADO_H_
#define LIBRE 1
#define OCUPADO 0
#define NO -1
#define SI 0

typedef struct{
int id;
char Nombre[51];
char Apellido[51];
float Salario;
int Sector;
int isEmpty;
} Empleado;

/*\brief Incializa todo el array como LIBRE
* \param empleadoArray es un puntero a la estrctura
* \param len tamaño de empleadoArray
* \return retorno (-1) si hubo error o (0) si se pudo inicializar todo el array como LIBRE
*/
int inicializarEmpleado(Empleado* empleadoArray, int len);

/*\brief Pide al usuario los datos necesarios
* \param nombre: Recibe el nombre del empleado
* \param apellido: Recibe el apellido del empleado
* \param sueldo: Recibe el sueldo del empleado
* \param sector: Recibe el sector donde trabaja el empleado
*/
void pedirDatosEmpleado(char nombre[], char apellido[], float* sueldo, int* sector);

/*\brief Carga todos los patos recolectados por la funcion pedirDatosEmpleado()
* \param empleadoArray es un puntero a la estrctura
* \param len tamaño de empleadoArray
* \param id numero de ID del empleado
* \param nombre: Recibe el nombre del empleado
* \param apellido: Recibe el apellido del empleado
* \param sueldo: Recibe el sueldo del empleado
* \param sector: Recibe el sector donde trabaja el empleado
* \return retorno (-1) si hubo error o (0) si se pudieron cargar todos los datos satisfactoriamente
*/
int cargarDatosEmpleado(Empleado* empleadoArraya, int len, int id, char Nombre[],char Apellido[],float Salario,int Sector);

/*\brief Recorre el array para buscar por ID
* \param empleadoArray es un puntero a la estrctura
* \param len tamaño de empleadoArray
* \param id numero de ID del empleado
* \return retorno (-1) si hubo error o el numero de indice en caso de encontrarse
*/
int buscarEmpleadoPorID(Empleado* empleadoArray, int len,int id);

/*\brief Busca y Elimina un empleado por su ID
* \param empleadoArray es un puntero a la estrctura
* \param len tamaño de empleadoArray
* \param id numero de ID del empleado
*\return retorno (-1) si hubo error o (0) si se elimino el empleado*/
int eliminarEmpleadoPorID(Empleado* empleadoArray, int len, int id);

/*\brief Ordena y swapea el array por sector
* \param empleadoArray es un puntero a la estrctura
* \param len tamaño de empleadoArray
* \param order 1 ordena de forma Ascendente 0 de forma Descendente
* \return retorna -1 no hubo un error y 0 si se pudo ordenar el array*/
int ordenamientoEmpleadosPorSector(Empleado* empleadoArray, int len, int order);

/*\brief Ordena y swapea el array por nombre
* \param empleadoArray es un puntero a la estrctura
* \param len tamaño de empleadoArray
* \param order 1 ordena de forma Ascendente 0 de forma Descendente
* \return retorna -1 no hubo un error y 0 si se pudo ordenar el array*/
int ordenamientoEmpleadosPorNombre(Empleado* empleadoArray, int len, int order);

/*\briefImprime el array de empleados
* \param empleadoArray es un puntero a la estrctura
* \param len tamaño de empleadoArray
* \return retorna -1 no hubo un error y 0 si se pudo imprimir el array*/
int imprimirEmpleados(Empleado* empleadoArray, int len);


int modificarEmpleado (Empleado* empleadoArraya, int len);

/*\brief Solo muestra un empleado
* \param empleadoArray es un puntero a la estrctura*/
void mostrarEmpleado(Empleado empleadoArray);

/*\brief Suma todos los salarios, saca e promedio e informa los empleados que superan el promedio
* \param empleadoArray es un puntero a la estrctura
* \param len tamaño de empleadoArray
* \return retorna -1 no hubo un error y 0 si se pudo promediar*/
int promedioEmpleados(Empleado* empleadoArray, int len);

#endif /* EMPLEADO_H_ */
