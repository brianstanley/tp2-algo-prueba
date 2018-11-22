#include "Grafo.h"

Grafo::Grafo(int cantidadVertices){
	this->listaDeVertices = 0;
	this->cantidadVertices = 0;
	this->MatrizDegrafo = 0;
}

void Grafo::agregarVertice(Tablero* tableroAsociado){
	if (! this->listaDeVertices->esta(tableroAsociado)){
		this->cantidadVertices++;
		this->listaDeVertices->agregar(tableroAsociado);
	}
}
