const int PESO_ARISTA_INICIAL = 0;

#include "../Tablero/Tablero.h"

class Arista{
private:
	int pesoArista;
	Tablero* tableroDeDestino;
public:
	/*
	 * pre: -
	 * post: se crea una instancia de arista con un peso PESO_ARISTA_INICIAL
	 * y el tablero de destino asociado
	 */
	Arista(Tablero* tableroDeDestino);

	/*
	 * pre: -
	 * post: se suma la cantidad pasada por parametro al peso actual de la arista
	 */
	void sumarPeso(int pesoASumar);

	/*
	 * pre; -
	 * post: se devuelve el peso de la arista
	 */
	int getPeso();

	/*
	 * pre: -
	 * post: se devuelve un puntero al tablero al que esta conectado el vertice
	 */
	Tablero* getVerticeAsociado();
};
