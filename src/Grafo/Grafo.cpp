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

void Grafo::agregarArista(Tablero* IDVerticeOrigen, Tablero* DIVerticeDestino){
	Vertice* verticeOrigen = this->buscarVertice(IDVerticeOrigen);
	Vertice* verticeDestino = this->buscarVertice(DIVerticeDestino);
	if (verticeOrigen && verticeDestino){
		if(!this->chequearExistenciaArista(verticeOrigen, verticeDestino))
			verticeOrigen->crearArista(verticeOrigen, verticeDestino);
	}
}

bool Grafo::chequearExistenciaArista(Vertice* verticeOrigen, Vertice* verticeDestino){
	ListaEnlazada<Arista*>* verticesAsociados = verticeOrigen->getAristas();

	bool aristaExiste = false;

	verticesAsociados->iniciarCursor();
	// Mientras que haya aristas
	while(verticesAsociados->avanzarCursor()){
		// el receptor (destino) sea el tableroDestino
		if(verticesAsociados->obtenerCursor()->getVerticeReceptor() == verticeDestino){
			aristaExiste = true;
		}
	}
	return aristaExiste;
}

void Grafo::eliminarArista(Tablero* IDVerticeOrigen, Tablero* DIVerticeDestino){
	Vertice* VerticeOrigen = this->buscarVertice(IDVerticeOrigen);
	Vertice* VerticeDestino = this->buscarVertice(DIVerticeDestino);
	if (VerticeOrigen && VerticeDestino){
		VerticeOrigen->eliminarArista(VerticeDestino);
	}
}

Vertice* Grafo::buscarVertice(Tablero* tableroBuscado){
	this->VerticesDelGrafo->iniciarCursor();
	Vertice* verticeBuscado = 0;
	while (!verticeBuscado && this->VerticesDelGrafo->avanzarCursor()){
		if (this->VerticesDelGrafo->obtenerCursor()->getTableroAsociado() == tableroBuscado){
			verticeBuscado = this->VerticesDelGrafo->obtenerCursor();
		}
	}
	return verticeBuscado;
}

void Grafo::incrementarPesoAristaConectora(Tablero* tableroOrigen, Tablero* tableroDestino){
	Vertice* verticeOrigen = this->buscarVertice(tableroOrigen);
	Vertice* verticeDestino = this->buscarVertice(tableroDestino);
	ListaEnlazada<Arista*>* verticesAsociados = verticeOrigen->getAristas();
	verticesAsociados->iniciarCursor();
	bool seEncontroArista = false;
	while(verticesAsociados->avanzarCursor() && seEncontroArista){
		if(verticesAsociados->obtenerCursor()->getVerticeReceptor() == verticeDestino){
			verticesAsociados->obtenerCursor()->incrementarPeso();
			seEncontroArista = true;
		}
	}
}

Grafo::~Grafo(){
	this->VerticesDelGrafo->iniciarCursor();
	while (this->VerticesDelGrafo->avanzarCursor()){
		delete this->VerticesDelGrafo->obtenerCursor();
	}
	delete this->VerticesDelGrafo;
}
