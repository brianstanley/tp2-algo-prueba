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

	/*
	 * pre: el numero de celulas y columnas que se recive debe ser coherente con el alto y ancho del tablero
	 * post: se miran todas las celulas al rededor de la celula apuntada verificando si estan vivas o muertas y copiando sus colores
	 */
	int chequearCelulasCircundantes(int fila, int columna, RGB* coloresCelulasVivasCircundantes);
	/*
	 * pre: -
	 * post:
	 */
	void marcarCelulaNacer(CoordenadaParcela coordenadaEnCuestion, RGB* ColorParaCelulaANacer);
	/*
	 * pre: -
	 * post:
	 */
	void marcarCelulaMorir(CoordenadaParcela coordenadaEnCuestion);
	/*
	 * pre: -
	 * post: teniendo en cuenta el estado actual de la celula y la cantidad de celulas vivas circundantes se decide si en el proximo
	 * turno dicha celula nacera o morira
	 */
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
