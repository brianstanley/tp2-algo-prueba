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
	this->resetearVerticesParaRecorrido();
	Cola<Vertice*>* aVisitar = new Cola<Vertice*>;
	Vertice* verticeActual;
	aVisitar->acolar(verticeOrigen);
	verticeOrigen->setDistanciaRecorrida(0);
	while (! aVisitar->estaVacia()) {
		verticeActual = aVisitar->desacolar();
		if (! verticeActual->fueVisitado()){
			verticeActual->marcarVisitado();
			verticeActual->getAristas()->iniciarCursor();
			cambiarCostoAdyacentes(verticeActual, aVisitar);
			/*while (verticeActual->getAristas()->avanzarCursor()){
				Arista* aristaConectora = verticeActual->getAristas()->obtenerCursor();
				Vertice* verticeCursor = aristaConectora->getVerticeReceptor();
				int pesoAristaConectora = aristaConectora->getPeso();
				int pesoTotal = pesoAristaConectora + verticeActual->getDistanciaRecorrida();
				if (pesoTotal < verticeCursor->getDistanciaRecorrida()){
					verticeCursor->setDistanciaRecorrida(pesoTotal);
				}
				aVisitar->acolar(verticeCursor);
			}*/
		}
	}
	delete aVisitar;
	return verticeDestino->getDistanciaRecorrida();
}

void Grafo::cambiarCostoAdyacentes(Vertice* verticeActual, Cola<Vertice*>* aVisitar){
	verticeActual->getAristas()->iniciarCursor();
	while (verticeActual->getAristas()->avanzarCursor()){
		Arista* aristaConectora = verticeActual->getAristas()->obtenerCursor();
		Vertice* verticeCursor = aristaConectora->getVerticeReceptor();
		int pesoAristaConectora = aristaConectora->getPeso();
		int pesoTotal = pesoAristaConectora + verticeActual->getDistanciaRecorrida();
		if (pesoTotal < verticeCursor->getDistanciaRecorrida()){
			verticeCursor->setDistanciaRecorrida(pesoTotal);
		}
		aVisitar->acolar(verticeCursor);
	}
}

void Grafo::resetearVerticesParaRecorrido(){
	this->VerticesDelGrafo->iniciarCursor();
	while (this->VerticesDelGrafo->avanzarCursor()){
		this->VerticesDelGrafo->obtenerCursor()->resetValoresRecorridoMinimo();
	}
}

Grafo::~Grafo(){
	this->VerticesDelGrafo->iniciarCursor();
	while (this->VerticesDelGrafo->avanzarCursor()){
		delete this->VerticesDelGrafo->obtenerCursor();
	}
	delete this->VerticesDelGrafo;
}
