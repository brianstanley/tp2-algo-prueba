#include "../Listas/ListaEnlazada.h"
#include "Vertice.h"

class Grafo{
private:
	int cantidadVertices;
	int* MatrizDegrafo;
	ListaEnlazada<Vertice*>* listaDeVertices;

public:

	/*
	 * pre: la cantidad de vertices pasada por parametro debe ser mayor a 0
	 * post: se crea una iteracion de la clase grafo con todo en 0
	 */
	Grafo(int cantidadVertices);

	/*
	 * pre: -
	 * post: se agrega un vertice a la lista de vertices
	 */
	void agregarVertice(Tablero* tableroAsociado);

};
