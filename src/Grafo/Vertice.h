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
	 * pre: -
	 * post: se devuelve el peso del vertice en cuestion
	 */
	Tablero* getPeso();

	/*
	 * pre: -
	 * post: se libera toda la memoria utilizada para la creacion de un objeto de clase Vertice
	 */
	~Vertice();
};
