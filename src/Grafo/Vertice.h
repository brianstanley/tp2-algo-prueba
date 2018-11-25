#include "../Listas/ListaEnlazada.h"
#include "Arista.h"

class Vertice{
private:
	ListaEnlazada<Arista*>* AristasDelGrafo;
	Tablero* pesoVertice;

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
	void crearArista(Tablero* tableroDestino);

	/*
	 * pre: -
	 * post: siempre y cuando exista, se elimina una arista con origen en el nodo en cuestion
	 * y destino en el nodo pasado por parametro
	 */
	void eliminarArista(Tablero* tableroDestino);

	/*
	 * pre: -
	 * post: se devuelve el peso del vertice en cuestion
	 */
	Tablero* getPeso();

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
