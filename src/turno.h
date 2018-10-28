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

	int chequearCelulasCircundantes(int fila, int columna, RGB* coloresCelulasVivasCircundantes);

	void marcarCelulaNacer(CoordenadaParcela coordenadaEnCuestion);

	void marcarCelulaMorir(CoordenadaParcela coordenadaEnCuestion);

	void decidirVidaOMuerte(int celulasVivasCircundantes,  CoordenadaParcela coordenadaEnCuestion, RGB* coloresCelulasVivasCircundantes);
public:
	/*
	 * pre: -
	 * post: se crea una instancia de la clase turno con un puntero a un tablero pasado
	 * por parametro
	 */
	Turno(Tablero* tableroAsociado);

	/*
	 * pre: -
	 * post: se recorre el tablero asociado a turno parando en cada parcela. para cada parcela
	 * se chequan las parcelas circundantes contando cuantas de ellas tienen celulas vivas.
	 * Con esta informacion se llama a metodos que marcan la parcela para morir o nacer
	 */
	void marcarCambiosARealizarParaSiguienteTurno();

};


#endif /* SRC_TURNO_H_ */
