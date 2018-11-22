#include "Grafo.h"

Grafo::Grafo(){
	this->listaDeVertices = 0;
	this->cantidadVertices = 0;
	this->MatrizDegrafo = 0;
}

void Grafo::crearMatrizGrafo(){
	this->MatrizDegrafo = new Arista[this->cantidadVertices][this->cantidadVertices];
}

void Grafo::agregarVertice(Tablero* tableroAsociado){
	if (! this->listaDeVertices->esta(tableroAsociado)){
		this->cantidadVertices++;
		this->listaDeVertices->agregar(tableroAsociado);
	}
}
