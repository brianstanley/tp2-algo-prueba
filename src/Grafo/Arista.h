#include "../Tablero/Tablero.h"

class Arista{
private:
	Tablero* VerticeEmisor;
	Tablero* VerticeReceptor;
	int pesoArista;

public:

	/*
	 * pre: -
	 * post: se crea un objeto de la clase arista con un peso nulo y los vertices emisor y receptor
	 * pasados por parametro
	 */
	Arista(Tablero* VerticeEmisor, Tablero* VerticeReceptor);

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
	 * post: se libera toda la memoria utilizada para la creacion de un objeto de clase Arista
	 */
	~Arista();
};
