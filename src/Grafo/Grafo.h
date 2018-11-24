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
	 * pre: el vertice en cuestion no debe tener aristas con ningun otro nodo
	 * post:siempre y cuando exista, se elimina el vertice que tiene como peso al tableroAsociado
	 */
	void eliminarVertice(Tablero* TableroAsociado);

	/*
	 * pre: -
	 * post: se agrega una arista que conecta el vertice sobre el cual se aplica este metodo con el
	 * vertice que tiene como peso al tablero pasado por parametro
	 */
	void agregarArista(Tablero* tableroOrigen, Tablero* tableroDestino);

	/*
	 * pre: -
	 * post: en caso de existir, se elimina la arista que conecta al vertice de peso tableroOrigen
	 * con el de peso tableroDestino
	 */
	void eliminarArista(Tablero* tableroOrigen, Tablero* tableroDestino);

	/*
	 * pre: -
	 * post: se devuelve el vertice asociado al tablero pasado por parametro, si el vertice en
	 * cuestion no existe se devuelve un puntero a 0
	 */
	Vertice* buscarVertice(Tablero* tableroBuscado);

	/*
	 * pre: -
	 * post: se libera toda la memoria utilizada en la creacion de un objeto de tipo Grafo
	 */
	~Grafo();
};
