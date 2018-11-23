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

		ListaEnlazada<Arista*>* adyacentesAlVerticeAsociado = new ListaEnlazada<Tablero*>;
		this->verticesAdyacentes->agregar(adyacentesAlVerticeAsociado);
	}
}

void Grafo::agregarArista(Tablero* verticeEmisor, Tablero* verticeReceptor){
	unsigned int posicionVerticeEmisor = this->listaDeVertices->obtenerPosicion(verticeEmisor);
	if (posicionVerticeEmisor != 0){
		unsigned int posicionCursor = 1;
		this->verticesAdyacentes->iniciarCursor();
		while(this->verticesAdyacentes->avanzarCursor() && posicionCursor != posicionVerticeEmisor){
			posicionCursor++;
		}
		Arista* nuevaArista = new Arista(verticeReceptor);
		this->verticesAdyacentes->obtenerCursor()->agregar(nuevaArista);
	}
}

void Grafo::eliminarVertice(Tablero* tableroAsociado){

}

void Grafo::elminimarArista(Tablero* verticeEmisor, Tablero* verticeReceptor){

}
