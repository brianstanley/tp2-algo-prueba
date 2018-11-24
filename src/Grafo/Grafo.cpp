#include "Grafo.h"

Grafo::Grafo(){
	this->VerticesDelGrafo = new ListaEnlazada<Vertice*>;
}

void Grafo::agregarVertice(Tablero* tableroAsociado){
	if (!this->buscarVertice(tableroAsociado)){
		Vertice* nuevoVertice = new Vertice(tableroAsociado);
		this->VerticesDelGrafo->agregar(nuevoVertice);
	}
}

void Grafo::eliminarVertice(Tablero* tableroAsociado){
	Vertice* verticeBuscado = this->buscarVertice(tableroAsociado);
	if (verticeBuscado){
		Vertice* verticeBuscado;
		this->VerticesDelGrafo->iniciarCursor();
		while (this->VerticesDelGrafo->avanzarCursor()){
			if (this->VerticesDelGrafo->obtenerCursor() != verticeBuscado){
				Vertice* verticeActual = this->VerticesDelGrafo->obtenerCursor();
				verticeActual->AristasDelGrafo->iniciarCursor();
				while (verticeActual->AristasDelGrafo->avanzarCursor()){
					Arista* aristaActual = verticeActual->AristasDelGrafo->avanzarCursor();
					if (aristaActual->getVerticeEmisor() == tableroAsociado ||
					aristaActual->getVerticeReceptor() == tableroAsociado){

					}
				}
			}
		}
	}
}

void Grafo::agregarArista(Tablero* tableroOrigen, Tablero* tableroDestino){
	Vertice* VerticeOrigen = this->buscarVertice(tableroOrigen);
	Vertice* VerticeDestino = this->buscarVertice(tableroDestino);
	if (VerticeOrigen && VerticeDestino){
		VerticeOrigen->crearArista(tableroDestino);
	}
}

void Grafo::eliminarArista(Tablero* tableroOrigen, Tablero* tableroDestino){
	Vertice* VerticeOrigen = this->buscarVertice(tableroOrigen);
	Vertice* VerticeDestino = this->buscarVertice(tableroDestino);
	if (VerticeOrigen && VerticeDestino){
		VerticeOrigen->eliminarArista(tableroDestino);
	}
}

Vertice* Grafo::buscarVertice(Tablero* tableroBuscado){
	this->VerticesDelGrafo->iniciarCursor();
	bool verticeBuscado = 0;
	while (!verticeBuscado && this->VerticesDelGrafo->avanzarCursor()){
		if (this->VerticesDelGrafo->obtenerCursor()->getPeso() == tableroBuscado){
			verticeBuscado = this->VerticesDelGrafo->obtenerCursor();
		}
	}
	return verticeBuscado;
}

Grafo::~Grafo(){

}
