#ifndef MENU_H_
#define MENU_H_
/*Brief Menu principal
 * param numero minimo de opciones que tiene el menu
 * param numero maximo de opciones que tiene el menu
 * return Retorna la opcion elegida por el usuario ya validada*/
int menuPrincipal(int minimoOpciones, int maximoOpciones);

/*Brief Sub-Menu de informes
 * param numero minimo de opciones que tiene el menu
 * param numero maximo de opciones que tiene el menu
 * return Retorna la opcion elegida por el usuario ya validada*/
int subMenuInformes(int minimoOpciones, int maximoOpciones);

/*Brief Sub-Menu de ordenamiento de empleados
 * param numero minimo de opciones que tiene el menu
 * param numero maximo de opciones que tiene el menu
 * return Retorna la opcion elegida por el usuario ya validada*/
int subMenuOrdenamientoEmpleados(int minimoOpciones, int maximoOpciones);

#endif /* MENU_H_ */

