/*
 * CoordenadaParcela.cpp
 *
 *  Created on: 21 oct. 2018
 *      Author: yorickvinesse
 */

#include "CoordenadaParcela.h"

CoordenadaParcela::CoordenadaParcela(/* Tablero tableroLeido, */int fila,
		int columna) {
	//this->nombreDelTablero = tableroLeido;
	this->coordenadaX = fila;
	this->coordenadaY = columna;
}

int CoordenadaParcela::getCoordenadaX() {
	return this->coordenadaX;
}

int CoordenadaParcela::getCoordenadaY() {
	return this->coordenadaY;
}

//Tablero CoordenadaParcela::getTablero() {
//	return this->nombreDelTablero;
//}

