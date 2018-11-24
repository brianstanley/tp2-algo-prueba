#include "Vertice.h"

class Grafo{
private:
	ListaEnlazada<Vertice*>* VerticesDelGrafo;

public:

	/*
	 * pre: -
	 * post: crea una instancia de grafo sin aristas ni vertices
	 */
	Grafo();

	/*
	 * pre: el vertice que se quiere agregar no debe existir en el grafo (no puede haber un grafo
	 * con el mismo peso que este)
	 * post: se agrega un vertice con el tablero pasado por parametro como peso
	 */
	void agregarVertice(Tablero* tableroAsociado);

	/*
	 * pre: -
	 * post: se elimina el vertice que tiene como peso al tableroAsociado, asi como a todas las
	 * aristas que este tenga con otros vertices o que otros vertices puedan tener con este
	 */
	void eliminarVertice(Tablero* TableroAsociado);

	/*
	 * pre: -
	 * post: se agrega una arista que conecta el vertice sobre el cual se aplica este metodo con el
	 * vertice que tiene como peso al tablero pasado por parametro
	 */
	void agregarArista(Tablero* TableroAdyacente);

	/*
	 * pre: -
	 * post: en caso de existir, se elimina la arista que conecta al vertice de peso tableroOrigen
	 * con el de peso tableroDestino
	 */
	void eliminarArista(Tablero* tableroOrigen, Tablero* tableroDestino);

	/*
	 * pre: -
	 * post: se libera toda la memoria utilizada en la creacion de un objeto de tipo Grafo
	 */
	~Grafo();
};
