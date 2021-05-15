#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "utn.h"

//______________________________________________________________________________________________
//___________________________________VALIDACIONES_______________________________________________


//NOMBRE O APELLIDO
int validar_NombreOApellido(char* stringRecibido)
{
	int retorno=1;  	//	OK
	int i;
	for(i=0;stringRecibido[i]!='\0';i++)
	{
		//printf("%d",i);
		if(stringRecibido[i]<'A' || (stringRecibido[i]>'Z' && stringRecibido[i]<'a') || stringRecibido[i]>'z')// o ((stringRecibido[i]<'A' || (stringRecibido[i]>'Z') && (stringRecibido[i]<'a' || stringRecibido[i]>'z'))
		{
			retorno=0; 	//ERROR
			break;
		}
	}
	return retorno;
}

//NUMERO FLOTANTE
int validar_Numero_Flotante(char* stringRecibido)
{
    int retorno=1;  	//OK
    int i;
    for(i=0;stringRecibido[i]!='\0';i++)
    {
        if((stringRecibido[i]<'0' || stringRecibido[i]>'9') && (stringRecibido[i]!='.'))
        {
            retorno=0;	//ERROR
            break;
        }
    }
    return retorno;
}

//NUMERO ENTERO
int validar_Numero_Entero(char* stringRecibido)
{
    int retorno=1;  //	OK
    int i;
    for(i=0;stringRecibido[i]!='\0';i++)
    {
        if(stringRecibido[i]<'0' || stringRecibido[i]>'9')
        {
            retorno=0;	//ERROR
            break;
        }
    }
    return retorno;
}

//______________________________________________________________________________________________
//___________________________________ UTN GET __________________________________________________

//GET STRING
int utn_getString(char* mensaje, char* mensajeError, int min, int max, int* reintentos, char* resultado)
{
    int retorno=-1;
    char bufferStr[max+10];

    if(mensaje!=NULL && mensajeError!=NULL && min<=max && reintentos>=0 && resultado!=NULL)
    {
        do
        {
            printf("%s",mensaje);
            fflush(stdin);
            fgets(bufferStr,sizeof(bufferStr),stdin);
            bufferStr[strlen(bufferStr)-1]='\0';

            if(strlen(bufferStr)>=min && strlen(bufferStr)<max)
            {
                strncpy(resultado,bufferStr,max);
                retorno=0;
                break;
            }
            printf("%s 1",mensajeError);
            (*reintentos)--;
        }
        while((*reintentos)>=0);
    }
    return retorno;
}

//GET NOMBRE
int utn_getNombre(char* mensaje, char* mensajeError, int min, int max, int reintentos, char* resultado)
{
    int retorno=-1;
    char bufferStr[max];

    if(mensaje!=NULL && mensajeError!=NULL && min<=max && reintentos>=0 && resultado!=NULL)
    {
        do
        {
            if(!utn_getString(mensaje,mensajeError,min,max,&reintentos,bufferStr)) //==0
            {
                if(validar_NombreOApellido(bufferStr)==1)
                {
                    strncpy(resultado,bufferStr,max);
                    retorno=0;
                    break;
                }
                else
                {
                    printf("%s 2",mensajeError);
                    reintentos--;
                }
            }
        }
        while(reintentos>=0);
    }
    return retorno;
}

//GET FLOAT
int utn_getFloat(char* mensaje, char* mensajeError, int minSize, int maxSize, int reintentos, float* input)
{
    int retorno=-1;
    char bufferStr[maxSize];

    if(mensaje!=NULL && mensajeError!=NULL && minSize<maxSize && reintentos>=0 && input!=NULL)
    {
        do
        {
            if(!utn_getString(mensaje,mensajeError,minSize,maxSize,&reintentos,bufferStr))  // 0 == Sin errores
            {
                if(validar_Numero_Flotante(bufferStr)==1) 									// 1 == flotante
                {
                    *input=atof(bufferStr); 			  									//cadena a float, retorno por input
                    retorno=0;
                    break;
                }
                else
                {
                    printf("%s 2",mensajeError);
                    reintentos--;
                }
            }
        }
        while(reintentos>=0);
    }
    return retorno;
}

//GET NUMERO ENTERO SIN SIGNO
int utn_getNumero_SinSigno(  char* mensaje,char* mensajeError,int minSize,int maxSize,int reintentos,int* input)
{
    int retorno=-1;
    char bufferStr[maxSize];

    if(mensaje!=NULL && mensajeError!=NULL && minSize<maxSize && reintentos>=0 && input!=NULL)
    {
        do
        {
            if(!utn_getString(mensaje,mensajeError,minSize,maxSize,&reintentos,bufferStr)) //==0 sin errores !0
            {
                if(validar_Numero_Entero(bufferStr)==1)
                {
                    *input=atoi(bufferStr);     // unsigned long int strtoul(const char *str, char **end, int base)?
                    retorno=0;
                    break;
                }
                else
                {
                    printf("%s 2",mensajeError);
                    reintentos--;
                }
            }
        }
        while(reintentos>=0);
    }
    return retorno;
}










