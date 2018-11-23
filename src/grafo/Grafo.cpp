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
