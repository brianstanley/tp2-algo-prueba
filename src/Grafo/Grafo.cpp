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
	Vertice* VerticeOrigen = this->buscarVertice(IDVerticeOrigen);
	Vertice* VerticeDestino = this->buscarVertice(DIVerticeDestino);
	if (VerticeOrigen && VerticeDestino){
		VerticeOrigen->crearArista(VerticeOrigen, VerticeDestino);
	}
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

Arista* Grafo::buscarArista(Vertice* verticeOrigen, Vertice* verticeDestino){
	Arista* aristaBuscada = 0;
	bool halladaLaArista = false;
	verticeOrigen->getAristas()->iniciarCursor();
	while (! halladaLaArista && verticeOrigen->getAristas()->avanzarCursor()){
		Arista* aristaActual = verticeOrigen->getAristas()->obtenerCursor();
		if (aristaActual->getVerticeReceptor() == verticeDestino){
			aristaBuscada = aristaActual;
			halladaLaArista = true;
		}
	}
	return aristaBuscada;
}

int Grafo::buscarRecorridoMinimo(Vertice* verticeOrigen, Vertice* verticeDestino){
	Cola<Vertice*>* aVisitar = new Cola<Vertice*>;
	Vertice* verticeActual = verticeOrigen;
	verticeActual->setDistanciaRecorrida(0);
	while (! aVisitar->estaVacia()) { //todavia es problema
		verticeActual->marcarVisitado();
		verticeActual->listaAristas->iniciarCursor();
		while (verticeActual->listaAristas->avanzarCursor()){
			Arista* aristaConectora = verticeActual->listaAristas->obtenerCursor();
			Vertice* verticeCursor = aristaConectora->getVerticeReceptor;
			if (! verticeCursor->yaVisitado()){
				int pesoAristaConectora = aristaConectora->getPeso();
				int pesoTotal = pesoAristaConectora + verticeCursor->getDistRec();
				if (pesoTotal < verticeCursor->getDistRec()){
					verticeCursor->setDistanciaRecorrida(pesoTotal);
				}
				aVisitar->encolar(verticeCursor);
			}
		}
		if (! aVisitar->estaVacia()){
			verticeActual = aVisitar->desencolar();
		}
	}
	delete aVisitar;
	return verticeDestino->getDistRec();
}

Grafo::~Grafo(){
	this->VerticesDelGrafo->iniciarCursor();
	while (this->VerticesDelGrafo->avanzarCursor()){
		delete this->VerticesDelGrafo->obtenerCursor();
	}
	delete this->VerticesDelGrafo;
}
