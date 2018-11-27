#include "Vertice.h"

Vertice::Vertice(Tablero* tableroAsociado){
	this->AristasDelGrafo = new ListaEnlazada<Arista*>;
	this->tableroAsociado = tableroAsociado;
	this->distanciaRecorridaParaLLegar = DISTANCIA_POR_DEFECTO;
	this->visitado = false;
}

void Vertice::crearArista(Vertice* verticeOrigen, Vertice* verticeDestino){
	Arista* nuevaArista = new Arista(verticeOrigen, verticeDestino);
	this->AristasDelGrafo->agregar(nuevaArista);
}

void Vertice::eliminarArista(Vertice* verticeDestino){
	this->AristasDelGrafo->iniciarCursor();
	Arista* aristaBuscada;
	bool seHayoLaArista = false;
	int posicion = 1;
	while (!seHayoLaArista && this->AristasDelGrafo->avanzarCursor()){
		if (this->AristasDelGrafo->obtenerCursor()->getVerticeReceptor() == verticeDestino){
			aristaBuscada = this->AristasDelGrafo->obtenerCursor();
			delete aristaBuscada;
			this->AristasDelGrafo->remover(posicion);
			seHayoLaArista = true;
		}
		posicion ++;
	}
}

Tablero* Vertice::getTableroAsociado(){
	return this->tableroAsociado;
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
