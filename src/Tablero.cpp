/*
 * Tablero.cpp
 *
 *  Created on: 27 oct. 2018
 *      Author: nazareno
 */

#include "Tablero.h"

Tablero::Tablero(string nombre, int filas, int columnas) {
	this->nombre = nombre;
	this->filas = filas;
	this->columnas = columnas;
	this->tablero = new Parcela*[filas];
	for(int i=0; i<filas; i++){
		this->tablero[i] = new Parcela[columnas];
	}
}

Parcela& Tablero::getParcela(int fila, int columna){
	return this->tablero[fila][columna];
}

string Tablero::getNombre(){
	return this->nombre;
}

int Tablero::getFilas(){
	return this->filas;
}

int Tablero::getColumnas(){
	return this->columnas;
}


Tablero::~Tablero() {
	for(int i=0; i<this->filas; i++){
		delete[] this->tablero[i];
	}
	delete[] this->tablero;
}

