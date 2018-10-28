/*
 * CoordenadaParcela.h
 *
 *  Created on: 21 oct. 2018
 *      Author: yorickvinesse

 * El objetivo de esta clase es de tener una manera unica de localizar una parcela.
 * Lleva la pareja de coordenadas (x, y) y el tablero asociado.
 */

#ifndef SRC_COORDENADAPARCELA_H_
#define SRC_COORDENADAPARCELA_H_
#include "Tablero.h"

class Tablero;
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

	CoordenadaParcela * getCoordenada();

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

};


#endif /* SRC_COORDENADAPARCELA_H_ */
