#include "Arista.h"

Arista::Arista(Vertice* verticeEmisor, Vertice* verticeReceptor){
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

Vertice* Arista::getVerticeEmisor(){
	return this->verticeEmisor;
}

Vertice* Arista::getVerticeReceptor(){
	return this->verticeReceptor;
}
