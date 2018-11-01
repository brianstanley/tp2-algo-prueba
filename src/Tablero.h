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
#include "Parcela.h"
#include "DatosTablero.h"

class Parcela;

class Tablero {
private:
	std::string nombre;
	int filas;
	int columnas;
	Parcela **parcelas;
	DatosTablero* datosDelTablero;

public:
	/*
	 * pre: El nombre del tablero, la cantidad de filas y columnas.
	 * post: Se inicializa un tablero como una matriz dinamica de Parcelas
	 * de acuerdo a la cantidad de filas y columnas indicadas.
	 */
	Tablero(std::string nombre, int filas, int columnas);
	/**
	 * pre: El tablero debe estar inicializado
	 * pos: Asigna los punteros a parcelas en la matriz dinámica
	 */
	void crearParcelas();
	/*
	 * pre: Fila y Columna dentro del rango de la matriz dinámica de parcelas.
	 * post: Se devuelve una referencia a la parcela en la posición indicada.
	 */
	Parcela& getParcela(int fila, int columna);
	/*
	 * pre:-
	 * post: se devuelve el nombre del tablero
	 */
	std::string getNombre();
	/*
	 * pre:-
	 * post: Devuelve el numero de filas del tablero
	 */
	int getFilas();
	/*
	 * pre:-
	 * post: Devuelve el numero de columnas del tablero
	 */
	int getColumnas();
	/*
	 * pre:-
	 * post: se libera la memoria asociada al tablero
	 */
	~Tablero();
};

#endif /* SRC_TABLERO_H_ */
