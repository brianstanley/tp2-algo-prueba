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

int Grafo::buscarRecorridosMinimoParaTablero(Vertice* verticeOrigen, Vertice* verticeDestino){
	//this->resetearVerticesParaRecorrido();
	RecorridoTablero recorridoBuscado(verticeOrigen, verticeDestino);
	//ListaEnlazada<Vertice*>* aVisitar = new ListaEnlazada<Vertice*>;
	ListaEnlazada<Vertice*>* aVisitar = this->VerticesDelGrafo;
	int posicionOrigen = aVisitar->obtenerPosicion(verticeOrigen); //aca quiero sacar el vertice de Origen de la lista a recorrer
	Vertice* verticeActual;
	verticeActual = verticeOrigen;
	aVisitar->remover(posicionOrigen);
	verticeOrigen->setDistanciaRecorrida(0); //eso si tendriamos que tener este método.
	while (! aVisitar->estaVacia()) {
		if (! verticeActual->fueVisitado()){
			verticeActual->marcarVisitado();
			verticeActual->getAristas()->iniciarCursor();
			// aca tenemos que recorrer la lista para encontrar la arista conectada al actual con menor peso
			// de aca por abajo no llegué, hay que ver y cambiar.
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

Grafo::~Grafo(){
	this->VerticesDelGrafo->iniciarCursor();
	while (this->VerticesDelGrafo->avanzarCursor()){
		delete this->VerticesDelGrafo->obtenerCursor();
	}
	delete this->VerticesDelGrafo;
}
