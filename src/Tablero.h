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
	Tablero(int filas, int columnas);
	Parcela getParcela(int fila, int columna);
	string getNombre();
	int getFilas();
	int getColumnas();
	~Tablero(); //No estoy seguro que si estoy liberando bien
};

#endif /* SRC_TABLERO_H_ */
