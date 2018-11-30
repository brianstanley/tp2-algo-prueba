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

void Grafo::agregarArista(Tablero* IDVerticeOrigen, Tablero* IDVerticeDestino){
	Vertice* verticeOrigen = this->buscarVertice(IDVerticeOrigen);
	Vertice* verticeDestino = this->buscarVertice(IDVerticeDestino);
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
	while(verticesAsociados->avanzarCursor() && ! seEncontroArista){
		if(verticesAsociados->obtenerCursor()->getVerticeReceptor() == verticeDestino){
			verticesAsociados->obtenerCursor()->incrementarPeso();
			seEncontroArista = true;
		}
	}
}

int Grafo::obtenerMenorTransferencia(Tablero* tableroOrigen, Tablero* tableroDestino) {
	Vertice* verticeDestino = this->buscarVertice(tableroDestino);
	Vertice* verticeActual = this->buscarVertice(tableroOrigen);
	unsigned int cantidadVertices = this->VerticesDelGrafo->contarElementos();
	int costosVertices[cantidadVertices];
	bool verticesVisitados[cantidadVertices];
	for (unsigned int i = 0; i < cantidadVertices; i++){
		costosVertices[i] = 10000;
		verticesVisitados[i] = false;
	}
	bool todosLosVerticesVisitados = false;
	int posicionVerticeActual = this->VerticesDelGrafo->obtenerPosicion(verticeActual);
	costosVertices[posicionVerticeActual-1] = 0;
	while (! todosLosVerticesVisitados){
		verticesVisitados[posicionVerticeActual-1] = true;
		verticeActual->getAristas()->iniciarCursor();
		while (verticeActual->getAristas()->avanzarCursor()){
			Arista* aristaConectora = verticeActual->getAristas()->obtenerCursor();
			Vertice* verticeCursor = aristaConectora->getVerticeReceptor();
			int posicionVerticeCursor = this->VerticesDelGrafo->obtenerPosicion(verticeCursor);
			if (! verticesVisitados[posicionVerticeCursor - 1]){
				int pesoAristaConectora = aristaConectora->getPeso();
				int costoVerticeCursor = costosVertices[posicionVerticeActual - 1] + pesoAristaConectora;
				if (costosVertices[posicionVerticeCursor - 1] > costoVerticeCursor){
					costosVertices[posicionVerticeCursor - 1] = costoVerticeCursor;
				}
			}
		}
		todosLosVerticesVisitados = estanTodosLosVerticesVisitados(verticesVisitados, cantidadVertices);
		if (! todosLosVerticesVisitados){
			posicionVerticeActual = this->obtenerPosicionMenor(verticesVisitados, costosVertices, cantidadVertices);
			verticeActual = this->VerticesDelGrafo->obtener(posicionVerticeActual);
		}
	}
	int posicionVerticeDestino = this->VerticesDelGrafo->obtenerPosicion(verticeDestino);
	return costosVertices[posicionVerticeDestino - 1];
}


bool Grafo::estanTodosLosVerticesVisitados(bool verticesVisitados[], int cantidadVertices) {
	bool todosLosVerticesVisitados = true;
	for (int i=0; i<cantidadVertices; i++){
		if (! verticesVisitados[i]){
			todosLosVerticesVisitados = false;
		}
	}
	return todosLosVerticesVisitados;
}

int Grafo::obtenerPosicionMenor(bool verticesVisitados[], int costosVertices[], int cantidadVertices) {
	int menorCosto = 10000;
	int nuevaPosicion = 0;
	for (int i=0; i<cantidadVertices; i++){
		if (! verticesVisitados[i]){
			if (costosVertices[i] <= menorCosto){
				menorCosto = costosVertices[i];
				nuevaPosicion = i;
			}
		}
	}
	return nuevaPosicion + 1;
}

Grafo::~Grafo(){
	this->VerticesDelGrafo->iniciarCursor();
	while (this->VerticesDelGrafo->avanzarCursor()){
		delete this->VerticesDelGrafo->obtenerCursor();
	}
	delete this->VerticesDelGrafo;
}
