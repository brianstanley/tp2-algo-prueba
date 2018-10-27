/*
 * CoordenadaParcela.h
 *
 *  Created on: 21 oct. 2018
 *      Author: yorickvinesse
 */

#ifndef SRC_COORDENADAPARCELA_H_
#define SRC_COORDENADAPARCELA_H_


/*
 * El objetivo de esa clase es de tener una manera unica de localizar una parcela.
 * Lleva la pareja de coordenadas (x, y) y el tablero asociado.
 * Por ahora, el objeto Tablero esta puesto en comentarios en todas sus instancias porque
 * aun no lo definimos.
 */

class CoordenadaParcela {

private:

	// Tablero nombreDelTablero;
	int coordenadaX;
	int coordenadaY;

public:

	/* pre: -
		 * post: inicializa las coordenadas de la parcela
		 */
	CoordenadaParcela();
	/* pre: -
	 * post: inicializa las coordenadas de la parcela
	 */
	CoordenadaParcela(/* Tablero tableroLeido, */ int fila, int columna);

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
	 * post: devuelve el tablero de la parcela
	 */
	//Tablero getTablero();

};


#endif /* SRC_COORDENADAPARCELA_H_ */
