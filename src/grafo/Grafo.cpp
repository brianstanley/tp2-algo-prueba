#include "Grafo.h"

Grafo::Grafo(){
	this->cantidadVertices = 0;
	this->listaDeVertices = new ListaEnlazada<Tablero*>;
	this->verticesAdyacentes = new ListaEnlazada<ListaEnlazada<Tablero*>*>;
}

void Grafo::agregarVertice(Tablero* tableroAsociado){
	if (! this->listaDeVertices->esta(tableroAsociado)){
		this->cantidadVertices++;
		this->listaDeVertices->agregar(tableroAsociado);

		ListaEnlazada<Tablero*>* adyacentesAlVerticeAsociado = new ListaEnlazada<Tablero*>;
		this->verticesAdyacentes->agregar(adyacentesAlVerticeAsociado);
	}
}

void Grafo::agregarArista(Tablero* verticeEmisor, Tablero* verticeReceptor){
	unsigned int posicionVerticeEmisor = this->listaDeVertices->obtenerPosicion(verticeEmisor);
	unsigned int posicionCursor = 1;
	this->verticesAdyacentes->iniciarCursor();
	while(this->verticesAdyacentes->avanzarCursor() && posicionCursor != posicionVerticeEmisor){
		posicionCursor++;
	}
	this->verticesAdyacentes->obtenerCursor()->agregar(verticeReceptor);
}

