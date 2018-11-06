#include "CoordenadaParcela.h"

void CoordenadaParcela::setCoordenada(Tablero * tablero, int fila,
		int columna) {
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

Parcela & CoordenadaParcela::getParcela() {
	return this->getTablero()->getParcela(this->getCoordenadaX(),
			this->getCoordenadaY());
}
