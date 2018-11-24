#include "Grafo.h"

Grafo::Grafo(){
	this->VerticesDelGrafo = new ListaEnlazada<Vertice*>;
}

void Grafo::agregarVertice(Tablero* tableroAsociado){
	if (!this->existeVertice(tableroAsociado)){
		Vertice* nuevoVertice = new Vertice(tableroAsociado);
		this->VerticesDelGrafo->agregar(nuevoVertice);
	}
}

void Grafo::eliminarVertice(Tablero* tableroAsociado){

}

void Grafo::agregarArista(Tablero* tableroOrigen, Tablero* tableroDestino){

}

void Grafo::eliminarArista(Tablero* tableroOrigen, Tablero* tableroDestino){

}

bool Grafo::existeVertice(Tablero* tableroBuscado){
	this->VerticesDelGrafo->iniciarCursor();
	bool hayadoTableroBuscado = false;
	while (!hayadoTableroBuscado && this->VerticesDelGrafo->avanzarCursor()){
		if (this->VerticesDelGrafo->obtenerCursor()->getPeso() == hayadoTableroBuscado){
			hayadoTableroBuscado = true;
		}
	}
	return hayadoTableroBuscado;
}

Grafo::~Grafo(){

}
