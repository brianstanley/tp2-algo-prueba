#include "Vertice.h"

Vertice::Vertice(Tablero* tableroAsociado){
	this->AristasDelGrafo = new ListaEnlazada<Arista*>;
	this->tableroAsociado = tableroAsociado;
	this->costo = DISTANCIA_POR_DEFECTO;
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

void Vertice::setDistanciaRecorrida(int distancia){
	this->costo = distancia;
}

int Vertice::getDistanciaRecorrida(){
	return this->costo;
}

void Vertice::marcarVisitado(){
	if (! this->visitado){
		this->visitado = true;
	}
}

bool Vertice::fueVisitado(){
	return this->visitado;
}

void Vertice::resetValoresRecorridoMinimo(){
	this->visitado = false;
	this->costo = DISTANCIA_POR_DEFECTO;
}

Vertice::~Vertice(){
	this->AristasDelGrafo->iniciarCursor();
	while(this->AristasDelGrafo->avanzarCursor()){
		delete this->AristasDelGrafo->obtenerCursor();
	}

	delete this->AristasDelGrafo;
}
