/*
 * DatosTablero.cpp
 *
 *  Created on: 1 nov. 2018
 *      Author: nazareno
 */

#include "DatosTablero.h"

DatosTablero::DatosTablero(Tablero* tableroAsociado) {
	this->cantidadCelulasVivas = 0;
	this->muertasTotal = 0;
	this->nacidasTotal = 0;
	this->promedioMuertas = 0;
	this->promedioNacidas = 0;
	this->turnosCongelado = 0;
	this->numeroTurno = 0;
	this->congeladoTurnoActual = true;
	this->nacidasEnUltimoTurno = 0;
	this->muertasEnUltimoTurno = 0;
	this->tableroAsociado = tableroAsociado;
}

unsigned int DatosTablero::getCantidadCelulasVivas(){
	return this->cantidadCelulasVivas;
}
void DatosTablero::sumarCelulaViva(){
	this->nacidasEnUltimoTurno ++;
	this->cantidadCelulasVivas ++;
	this->nacidasTotal ++;
}
void DatosTablero::sumarCelulaMuerta(){
	this->muertasEnUltimoTurno ++;
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
	this->promedioNacidas = this->nacidasTotal/this->numeroTurno;
	return this->promedioNacidas;
}
float DatosTablero::getPromedioMuertas(){
	this->promedioMuertas = this->muertasTotal/this->numeroTurno;
	return this->promedioMuertas;
}

void DatosTablero::setCongeladoTurnoActual(bool estadoDeCongelamiento){
	this->congeladoTurnoActual = estadoDeCongelamiento;
}

void DatosTablero::setCantidadTurnosCongeladosTablero(){
	if(this->congeladoTurnoActual){
		this->turnosCongelado ++;
	}
	else{
		this->turnosCongelado = 0;
	}
}

bool DatosTablero::estaCongelado(){
	return (this->turnosCongelado >= 2);
}

unsigned int DatosTablero::getTurno(){
	return this->numeroTurno;
}

void DatosTablero::avanzarUnTurno(){
	this->numeroTurno ++;
}

unsigned int DatosTablero::getNacidasEnUltimoTurno(){
	return this->nacidasEnUltimoTurno;
}

unsigned int DatosTablero::getMuertasEnUltimoTurno(){
	return this->muertasEnUltimoTurno;
}

void DatosTablero::reiniciarContadorNacidasMuertasEnUltimoTurno(){
	this->nacidasEnUltimoTurno = 0;
	this->muertasEnUltimoTurno = 0;
}

void DatosTablero::mostrarDatosTablero(){
	std::cout<< "tablero: " << this->tableroAsociado->getNombre() << ", turno nro " << this->numeroTurno << std::endl;
	std::cout<< "celulas vivas: " << this->cantidadCelulasVivas << std::endl;
	std::cout<< "celulas nacidas en total: " << this->nacidasTotal << std::endl;
	std::cout<< "celulas muertas en total: " << this->muertasTotal << std::endl;
	std::cout<< "celulas nacidas en el turno actual: " << this->nacidasEnUltimoTurno << std::endl;
	std::cout<< "celulas muertas en el turno actual: " << this->muertasEnUltimoTurno << std::endl;
	std::cout<< "promedio de nacimientos: " << this->promedioNacidas << std::endl;
	std::cout<< "promedio de muertes: " << this->promedioMuertas << std::endl;
	if (this->estaCongelado()){
		std::cout<< "El tablero se encuentra congelado"<< std::endl;
	}
	std::cout << std::endl;

}
