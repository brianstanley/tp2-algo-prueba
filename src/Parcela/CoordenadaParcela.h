#ifndef SRC_COORDENADAPARCELA_H_
#define SRC_COORDENADAPARCELA_H_
#include "../Tablero/Tablero.h"

class Parcela;
class Tablero;

/*
 * El objetivo de esta clase es de tener una manera unica de localizar una parcela.
 * Lleva la pareja de coordenadas (x, y) y el tablero asociado.
 */

class CoordenadaParcela {

private:
	Tablero * tablero;
	int coordenadaX;
	int coordenadaY;

public:
	/* pre: -
	 * post: inicializa las coordenadas de la parcela
	 */
	void setCoordenada(Tablero * tablero, int fila, int columna);

	/*
	 * pre: -
	 * post: devuelve la coordenada X de la parcela
	 */
	int getCoordenadaX();

	/*
	 * pre: -
	 * post: devuelve la coordenada Y de la parcela
	 */
	int getCoordenadaY();

	/*
	 * pre: -
	 * post: devuelve un puntero al tablero que contiene
	 * a la parcela.
	 */
	Tablero * getTablero();

	/*
	 * pre: -
	 * post: devuelve la parcela asociada a la coordenada.
	 */
	Parcela & getParcela();

};

#endif /* SRC_COORDENADAPARCELA_H_ */
