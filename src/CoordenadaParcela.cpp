/*
 * CoordenadaParcela.cpp
 *
 *  Created on: 21 oct. 2018
 *      Author: yorickvinesse
 */

#include "CoordenadaParcela.h"

void CoordenadaParcela::setCoordenada(Tablero * tablero, int fila,
		int columna) {
	//this->nombreDelTablero = tableroLeido;
	this->tablero = tablero;
	this->coordenadaX = fila;
	this->coordenadaY = columna;
}

int CoordenadaParcela::getCoordenadaX() {
	return this->coordenadaX;
}

int CoordenadaParcela::getCoordenadaY() {
	return this->coordenadaY;
}

Tablero * CoordenadaParcela::getTablero() {
	return this->tablero;
}
