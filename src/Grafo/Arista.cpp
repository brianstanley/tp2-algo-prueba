#include "Arista.h"

Arista::Arista(Tablero* verticeEmisor, Tablero* verticeReceptor){
	this->pesoArista = PESO_NULO;
	this->verticeEmisor = verticeEmisor;
	this->verticeReceptor = verticeReceptor;
}

void Arista::incrementarPeso(){
	this->pesoArista ++;
}

int Arista::getPeso(){
	return this->pesoArista;
}

Tablero* Arista::getVerticeEmisor(){
	return this->verticeEmisor;
}

Tablero* Arista::getVerticeReceptor(){
	return this->verticeReceptor;
}
