#include "Vertice.h"

Vertice::Vertice(Tablero* tableroAsociado){
	this->AristasDelGrafo = new ListaEnlazada<Arista*>;
	this->pesoVertice = tableroAsociado;
}

Tablero* Vertice::getPeso(){
	return this->pesoVertice;
}

Vertice::~Vertice(){
	this->AristasDelGrafo->iniciarCursor();
	while(this->AristasDelGrafo->avanzarCursor()){
		delete this->AristasDelGrafo->obtenerCursor();
	}

	delete this->AristasDelGrafo;
}
