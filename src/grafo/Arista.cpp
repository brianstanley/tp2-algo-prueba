#include "Arista.h"

Arista::Arista(Tablero* tableroDeDestino){
	this->pesoArista = PESO_ARISTA_INICIAL;
	this->tableroDeDestino = tableroDeDestino;
}

void Arista::sumarPeso(int pesoASumar){
	this->pesoArista += pesoASumar;
}

int Arista::getPeso(){
	return this->pesoArista;
}

Tablero* Arista::getVerticeAsociado(){
	return this->tableroDeDestino;
}
