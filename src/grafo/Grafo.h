#include "../Listas/ListaEnlazada.h"
#include "Arista.h"
#include "../Tablero/Tablero.h"

class Grafo{
private:

	// Bastante simple, la cantidad de vertices del grafo
	int cantidadVertices;

	//Aca se crea un nodo de la lista de listas por cada vertice que se agrega y despues se ponen
	//los vertices adyacentes a dicho vertice en la lista. El orden de los nodos se puede obtener
	//a traves de la "listaDeVertices"
	ListaEnlazada<ListaEnlazada<Tablero*>*>* verticesAdyacentes;

	//Aca se listan los vertices que tiene el grafo (tableros, en este caso)
	ListaEnlazada<Tablero*>* listaDeVertices;

public:

	/*
	 * pre: la cantidad de vertices pasada por parametro debe ser mayor a 0
	 * post: se crea una iteracion de la clase grafo con todo en 0
	 */
	Grafo();

	/*
	 * pre: -
	 * post: se agrega un vertice a la lista de vertices
	 */
	void agregarVertice(Tablero* tableroAsociado);
};
