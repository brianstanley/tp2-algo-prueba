/*
 * turno.h
 *
 *  Created on: 27 oct. 2018
 *      Author: nazareno
 */

#ifndef SRC_TURNOTABLERO_H_
#define SRC_TURNOTABLERO_H_

#include "Tablero.h"
#include "Listas/Cola.h"
#include "ParcelaAfectada.h"


class TurnoTablero{
private:
	Tablero* tableroAsociado;
	Cola<ParcelaAfectada*> ParcelasAfectadas;

	/*
	 * pre: -
	 * post: se devuelve la cantidad de celulas vivas circundantes a una celula
	 */
	int chequearCelulasCircundantes(int fila, int columna, RGB* coloresCeluasVivasCircundantes[]);

	/*
	 * pre: -
	 * post: se guardan los colores de las celulas circundantes en un arreglo
	 */
	void guardarColorCelulasCircundantes(RGB* coloresCeluasVivasCircundantes[], int celulasCircundantesVivas, int fila, int columna);

	/*
	 * pre:-
	 * post: se devuelve un puntero al promedio de los colores de las celulas vivas circundantes
	 */
	RGB* promedioColoresCelulasCircundantes(RGB* coloresCelulasVivasCircundantes[]);

	/*
	 * pre: -
	 * post: se lista la parcela obtenida para nacer
	 */
	void marcarCelulaNacer(CoordenadaParcela* coordenadaEnCuestion, RGB* colorCelulaANacer);

	/*
	 *pre: -
	 *post: se lista la parcela obtenida para morir
	 */
	void marcarCelulaMorir(CoordenadaParcela* coordenadaEnCuestion);
	/*
	 * pre:-
	 * post: se chequea si las celulas que deben nacer ya estan vivas o si las celulas para morir ya estan muertas
	 */
	void decidirVidaOMuerte(int celulasVivasCircundantes, CoordenadaParcela* coordenadaEnCuestion,
	RGB* coloresCeluasVivasCircundantes[]);

	/*
	 * pre: -
	 * post: se recorre el tablero asociado a turno parando en cada parcela. para cada parcela
	 * se chequan las parcelas circundantes contando cuantas de ellas tienen celulas vivas.
	 * Con esta informacion se llama a metodos que marcan la parcela para morir o nacer
	 */
	void marcarCambiosARealizarParaSiguienteTurno();

	/*
	 * pre: -
	 * post: se ejecutan las muertes y nacimientos de las celulas necesarios
	 */
	void concretarCambios();

	/*
	 * pre: -
	 * post: se plasma el estado definitivo del tablero en un archivo .bmp
	 */
	void plasmarCambiosEnArchivo();

public:

	 /* pre: -
	 * post: se crea una instancia de la clase turno con un puntero a un tablero pasado
	 * por parametro
	 */
	TurnoTablero(Tablero* tableroAsociado);

	/*
	 * pre: -
	 * post: se ejecutan todas las acciones pertinentes al turno
	 */
	void jugarTurno();
};


#endif /* SRC_TURNOTABLERO_H_ */
