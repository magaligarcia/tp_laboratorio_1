#ifndef VALIDACIONES_H_
#define VALIDACIONES_H_
/*
 * brief Valida que el usuario ingrese si o si dos numeros antes de seleccionar una opcion de calculos.
 *		 Si ambos números ingresados son 0(ceros) pide que ingrese otros.
 * param1 Recibe la opcion de menú elegida por el usuario
 * param2 Recibe el primer numero ingresado
 * param3 Recibe el segundo numero ingresado
 * return 0 si recibio un dato valido, 1 si recibio un dato no valido,*/
int valIngresoOperandos(int opcion,int  num1,int num2);

/*
 * brief Valida que la division no sea por 0 (cero).
 * param1 Recibe el dividendo.
 * param2 Recibe el divisor.
 * return Void, Muestra el cociente de la division entre los dos números recibidos por parametro*/
void valDividirPorCero(int num1, int num2);

#endif /* VALIDACIONES_H_ */
