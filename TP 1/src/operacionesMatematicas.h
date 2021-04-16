
#ifndef OPERACIONESMATEMATICAS_H_
#define OPERACIONESMATEMATICAS_H_

/*
 * brief Calcula la suma de dos números
 * param1 Recibe un número para sumar
 * param2 Recibe otro número para sumar
 * return Resultado de la suma de los dos números recibidos por parametro*/
int sumaDeDosNumeros(int num1, int num2);

/* brief Resta de dos numeros enteros:
 * param1 Recibe un número para restar (minuendo)
 * param2 Recibe otro número para restar (substraendo)
 * return El resultado de la resta de los dos números recibidos por parametro*/
int restaDeDosNumeros(int num1, int num2);

/* brief Division de dos numeros enteros:
 * param1 Recibe un número para dividir (Dividendo)
 * param2 Recibe otro número para dividir (Divisor)
 * return El resultado de la division entre los dos números recibidos por parametro*/
int divisionDeDosNumeros(int num1, int num2);

/* brief Multiplicación de dos numeros enteros:
 * param1 Recibe un número para multiplicar
 * param2 Recibe otro número para multiplicar
 * return El resultado de la multiplicación entre los dos números recibidos por parametro*/
int multiplicacionDeDosNumeros(int num1, int num2);

/* brief Toma dos números por punteros y calcula el factorial de cada uno
 * param1 Recibe por puntero el primer número ingresado para sacar su factorial
 * param2 Recibe por puntero el segundo número ingresado para sacar su factorial
 * return Void, Devuelve por puntero el factorial del primer y segundo número ingresado*/
void factorialDeDosNumeros(int *num1, int *num2);

#endif /* OPERACIONESMATEMATICAS_H_ */
