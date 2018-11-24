#include "../Tablero/Tablero.h"

const int PESO_NULO = 0;

class Arista{
private:
	Tablero* verticeEmisor;
	Tablero* verticeReceptor;
	int pesoArista;

public:

	/*
	 * pre: -
	 * post: se crea un objeto de la clase arista con un peso nulo y los vertices emisor y receptor
	 * pasados por parametro
	 */
	Arista(Tablero* verticeEmisor, Tablero* verticeReceptor);

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
	Tablero* getVerticeEmisor();

	/*
	 * pre: -
	 * post: se obtiene el vertice receptor
	 */
	Tablero* getVerticeReceptor();
};
