/*
 * turno.h
 *
 *  Created on: 27 oct. 2018
 *      Author: nazareno
 */

#ifndef SRC_TURNO_H_
#define SRC_TURNO_H_

#include "Tablero.h";

class Turno{
private:
	int celulasNacidasTurno;
	int celulasMuertasTurno;
	int numeroDeTurno;
	Tablero* tableroAsociado;
public:
	Turno(Tablero* tableroAsociado);

	void recorrerTablero();

	int chequearCelulasCircundantes(int fila, int columna);

	void marcarCelulaNacer(CoordenadaParcela coordenadaEnCuestion);

	void marcarCelulaMorir(CoordenadaParcela coordenadaEnCuestion);

	void decidirVidaOMuerte(int celulasVivasCircundantes,  CoordenadaParcela coordenadaEnCuestion);

};


#endif /* SRC_TURNO_H_ */
