#ifndef SRC_GRAFO_VERTICE_H_
#define SRC_GRAFO_VERTICE_H_

#include "../Listas/ListaEnlazada.h"
#include "Arista.h"

const int DISTANCIA_POR_DEFECTO = 10000;

class Arista; //forward declaration

class Vertice{
private:
	ListaEnlazada<Arista*>* AristasDelGrafo;
	Tablero* tableroAsociado;
	int distanciaRecorridaParaLLegar;  //para Dijkstra
	bool visitado;                     //para Dijkstra

public:

	/*
	 * pre: -
	 * post: se crea un objeto de la clase vertice con el tablero pasado por parametro como
	 * peso del vertice
	 */
	Vertice(Tablero* tableroAsociado);

	/*
	 * pre:-
	 * post: siepre y cuando exista, se crea una arista con origen en el nodo en cuestion y
	 * destino en el nodo pasado por parametro
	 */
	void crearArista(Vertice* verticeOrigen, Vertice* verticeDestino);

	/*
	 * pre: -
	 * post: siempre y cuando exista, se elimina una arista con origen en el nodo en cuestion
	 * y destino en el nodo pasado por parametro
	 */
	void eliminarArista(Vertice* verticeDestino);

	/*
	 * pre: -
	 * post: se devuelve el peso del vertice en cuestion
	 */
	Tablero* getTableroAsociado();

	/*
	 * pre: -
	 * post: se devuelve la lista de aristas asociadas al vertice en cuestion
	 */
	ListaEnlazada<Arista*>* getAristas();

	/*
	 * pre: -
	 * post: se libera toda la memoria utilizada para la creacion de un objeto de clase Vertice
	 */
	~Vertice();
};

#endif
