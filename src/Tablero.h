/*
 * Tablero.h
 *
 *  Created on: 27 oct. 2018
 *      Author: nazareno
 */

#ifndef SRC_TABLERO_H_
#define SRC_TABLERO_H_

#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;

#include "Parcela.h"

class Tablero {
private:
	//Cuando usas formaciones1, el tamaño debe ser conocido en tiempo de
	//compilación o debes usar memoria dinámica
	string nombre;
	int filas;
	int columnas;
	Parcela **tablero;
public:
	/*pre:-
	 * post: Se crea un tablero dinamico de Parcelas de acuerdo a las filas y
	 * columnas indicadas. Con el nombre indicado para el tablero.
	 */
	Tablero(string nombre, int filas, int columnas);
	/*pre:-
	 * post: se devuelve la Parcela asociada al tablero[fila][columna]
	 */
	Parcela& getParcela(int fila, int columna);
	/*pre:-
	 * post: se devuelve el nombre del tablero
	 */
	string getNombre();
	/*pre:-
	 * post: se devuelve el numero de filas del tablero
	 */
	int getFilas();
	/*pre:-
	 * post: se devuelve el numero de columnas del tablero
	 */
	int getColumnas();
	/*pre:-
	 * post: se libera la memoria asociada al tablero
	 */
	~Tablero(); // NO ESTOY SEGURO DE ESTAR LIBERANDO CORRECTAMENTE
				//(tengo otro projecto parecido para correr en valgrind y ver si esta bien esto)
};

#endif /* SRC_TABLERO_H_ */
