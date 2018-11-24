#include "Vertice.h"

Vertice::Vertice(Tablero* tableroAsociado){
	this->AristasDelGrafo = new ListaEnlazada<Arista*>;
	this->pesoVertice = tableroAsociado;
}

void Vertice::crearArista(Tablero* tableroDestino){
	Arista* nuevaArista = new Arista(this->pesoVertice, tableroDestino);
	this->AristasDelGrafo->agregar(nuevaArista);
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
