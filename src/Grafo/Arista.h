#ifndef SRC_GRAFO_ARISTA_H_
#define SRC_GRAFO_ARISTA_H_

#include "../Tablero/Tablero.h"
#include "Vertice.h"

class Vertice; //forward declaration

const int PESO_NULO = 0;


class Arista{
private:
	Vertice* verticeEmisor;
	Vertice* verticeReceptor;
	int pesoArista;

public:

	/*
	 * pre: -
	 * post: se crea un objeto de la clase arista con un peso nulo y los vertices emisor y receptor
	 * pasados por parametro
	 */
	Arista(Vertice* verticeEmisor, Vertice* verticeReceptor);

	/*
	 * pre:
	 * post: se incrementa en uno el peso de la arista
	 */
	void incrementarPeso();

	/*
	 * pre: -
	 * post: se devuelve el peso de la arista
	 */
	int getPeso();

	/*
	 * pre: -
	 * post: se obtiene el vertice emisor
	 */
	Vertice* getVerticeEmisor();

	/*
	 * pre: -
	 * post: se obtiene el vertice receptor
	 */
	Vertice* getVerticeReceptor();
};

#endif /* SRC_GRAFO_ARISTA_H_ */
