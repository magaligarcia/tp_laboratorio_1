#ifndef UTN_H_
#define UTN_H_
//______________________________________________________________________________________________
//___________________________________VALIDACIONES_______________________________________________

int validar_NombreOApellido(char* stringRecibido);

int validar_Numero_Flotante(char* stringRecibido);

int validar_Numero_Entero(char* stringRecibido);

//______________________________________________________________________________________________
//___________________________________ UTN GET __________________________________________________

int utn_getString(char* mensaje, char* mensajeError, int min, int max, int* reintentos, char* resultado);

int utn_getNombre(char* mensaje, char* mensajeError, int min, int max, int reintentos, char* resultado);

int utn_getFloat(char* mensaje, char* mensajeError, int minSize, int maxSize, int reintentos, float* input);

int utn_getNumero_SinSigno(  char* mensaje,char* mensajeError,int minSize,int maxSize,int reintentos,int* input);

#endif /* UTN_H_ */
