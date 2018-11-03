/*
 * DatosTablero.cpp
 *
 *  Created on: 1 nov. 2018
 *      Author: nazareno
 */

#include "DatosTablero.h"

#include "DatosTablero.h"

DatosTablero::DatosTablero() {
	this->cantidadCelulasVivas = 0;
	this->muertasTotal = 0;
	this->nacidasTotal = 0;
	this->promedioMuertas = 0;
	this->promedioNacidas = 0;
}

unsigned int DatosTablero::getCantidadCelulasVivas(){
	return this->cantidadCelulasVivas;
}
void DatosTablero::sumarCelulaViva(){
	this->cantidadCelulasVivas ++;
	this->nacidasTotal ++;
}
void DatosTablero::sumarCelulaMuerta(){
	this->cantidadCelulasVivas --;
	this->muertasTotal ++;
}
int DatosTablero::getNacidasTotal(){
	return this->nacidasTotal;
}
unsigned int DatosTablero::getMuertasTotal(){
	return this->muertasTotal;
}
float DatosTablero::getPromedioNacidas(){

	return this->promedioNacidas;
}
float DatosTablero::getPromedioMuertas(){
	return this->promedioMuertas;
}
