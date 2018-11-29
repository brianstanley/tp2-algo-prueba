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

int Grafo::obtenerMenorTransferencia(Vertice* verticeOrigen,
		Vertice* verticeDestino) {

	Vertice* verticeActual = verticeOrigen;
	unsigned int cantidadVertices = this->VerticesDelGrafo->contarElementos();
	int costosVertices[cantidadVertices] = {10000};
	bool verticesVisitados[cantidadVertices] = {0};
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
			if (! verticesVisitados[posicionVerticeCursor]){
				int pesoAristaConectora = aristaConectora->getPeso();
				int costoVerticeCursor = costosVertices[posicionVerticeActual - 1] + pesoAristaConectora;
				if (costosVertices[posicionVerticeCursor - 1] > costoVerticeCursor){
					costosVertices[posicionVerticeCursor - 1] = costoVerticeCursor;
				}
			}
		}
		todosLosVerticesVisitados = chequearEstadoDeTodosLosVertices(verticesVisitados, cantidadVertices);
		if (! todosLosVerticesVisitados){
			posicionVerticeActual = this->obtenerPosicionMenor(verticesVisitados, costosVertices, cantidadVertices);
			verticeActual = this->VerticesDelGrafo->obtener(posicionVerticeActual);
		}
	}
	int posicionVerticeDestino = this->VerticesDelGrafo->obtenerPosicion(verticeDestino);
	return costosVertices[posicionVerticeDestino];
}


bool Grafo::chequearEstadoDeTodosLosVertices(bool verticesVisitados[], int cantidadVertices) {
	bool todosLosVerticesVisitados = true;
	for (int i=0; i<cantidadVertices; i++){
		if (! verticesVisitados[i]){
			todosLosVerticesVisitados = true;
		}
	}
	return todosLosVerticesVisitados;
}

int Grafo::obtenerPosicionMenor(bool verticesVisitados[], int costosVertices[], int cantidadVertices) {
	int menorCosto = 10000;
	int iMenorCosto = 0;
	for (int i=0; i<cantidadVertices; i++){
		if (verticesVisitados[i]){
			if (costosVertices[i] < menorCosto){
				menorCosto = costosVertices[i];
				iMenorCosto = i;
			}
		}
	}
	return iMenorCosto;
}

Grafo::~Grafo(){
	this->VerticesDelGrafo->iniciarCursor();
	while (this->VerticesDelGrafo->avanzarCursor()){
		delete this->VerticesDelGrafo->obtenerCursor();
	}
	delete this->VerticesDelGrafo;
}
