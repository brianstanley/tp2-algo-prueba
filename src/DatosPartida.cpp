/*
 * DatosPartida.cpp
 *
 *  Created on: 27 oct. 2018
 *      Author: nazareno
 */

#include "DatosPartida.h"

DatosPartida::DatosPartida() {
	this->cantidadCelulasVivas = 0;
	this->muertasTotal = 0;
	this->nacidasTotal = 0;
	this->promedioMuertas = 0;
	this->promedioNacidas = 0;
}

int DatosPartida::getCantidadCelulasVivas(){
	return this->cantidadCelulasVivas;
}
void DatosPartida::sumarCelulaViva(){
	this->cantidadCelulasVivas ++;
	this->nacidasTotal ++;
}
void DatosPartida::sumarCelulaMuerta(){
	this->cantidadCelulasVivas --;
	this->muertasTotal ++;
}
int DatosPartida::getNacidasTotal(){
	return this->nacidasTotal;
}
int DatosPartida::getMuertasTotal(){
	return this->muertasTotal;
}
float DatosPartida::getPromedioNacidas(){

	return this->promedioNacidas;
}
float DatosPartida::getPromedioMuertas(){
	return this->promedioMuertas;
}

