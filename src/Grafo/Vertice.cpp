#include "Vertice.h"

Vertice::Vertice(Tablero* tableroAsociado){
	this->AristasDelGrafo = new ListaEnlazada<Arista*>;
	this->pesoVertice = tableroAsociado;
}

void Vertice::crearArista(Tablero* tableroDestino){
	Arista* nuevaArista = new Arista(this->pesoVertice, tableroDestino);
	this->AristasDelGrafo->agregar(nuevaArista);
}

void Vertice::eliminarArista(Tablero* tableroDestino){
	this->AristasDelGrafo->iniciarCursor();
	Arista* aristaBuscada;
	bool seHayoLaArista = false;
	int posicion = 1;
	while (!seHayoLaArista && this->AristasDelGrafo->avanzarCursor()){
		if (this->AristasDelGrafo->obtenerCursor()->getVerticeReceptor() == tableroDestino){
			aristaBuscada = this->AristasDelGrafo->obtenerCursor();
			delete aristaBuscada;
			this->AristasDelGrafo->remover(posicion);
			seHayoLaArista = true;
		}
		posicion ++;
	}
}

Tablero* Vertice::getPeso(){
	return this->pesoVertice;
}

ListaEnlazada<Arista*>* Vertice::getAristas(){
	return this->AristasDelGrafo;
}

Vertice::~Vertice(){
	this->AristasDelGrafo->iniciarCursor();
	while(this->AristasDelGrafo->avanzarCursor()){
		delete this->AristasDelGrafo->obtenerCursor();
	}

	delete this->AristasDelGrafo;
}
