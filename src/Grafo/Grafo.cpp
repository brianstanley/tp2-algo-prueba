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
		ListaEnlazada<Arista*>* AristasVerticeBuscado = verticeBuscado->getAristas();
		AristasVerticeBuscado->iniciarCursor();
		while (AristasVerticeBuscado->avanzarCursor()){
			Arista* aristaActual = AristasVerticeBuscado->obtenerCursor();
			verticeBuscado->eliminarArista(aristaActual->getVerticeReceptor());
		}
		int posicionVerticeBuscado = this->VerticesDelGrafo->obtenerPosicion(verticeBuscado);
		this->VerticesDelGrafo->remover(posicionVerticeBuscado);
		delete verticeBuscado;
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
	Vertice* verticeBuscado = 0;
	while (!verticeBuscado && this->VerticesDelGrafo->avanzarCursor()){
		if (this->VerticesDelGrafo->obtenerCursor()->getPeso() == tableroBuscado){
			verticeBuscado = this->VerticesDelGrafo->obtenerCursor();
		}
	}
	return verticeBuscado;
}

Grafo::~Grafo(){
	this->VerticesDelGrafo->iniciarCursor();
	while (this->VerticesDelGrafo->avanzarCursor()){
		delete this->VerticesDelGrafo->obtenerCursor();
	}
	delete this->VerticesDelGrafo;
}
