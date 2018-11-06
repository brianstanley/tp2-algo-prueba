/*
 * JuegoNuevo.h
 *
 *  Created on: Oct 27, 2018
 *      Author: german
 */

#ifndef JUEGO_H_
#define JUEGO_H_

#include "Tablero.h"
#include "Listas/ListaEnlazada.h"
#include "LecturaArchivoConfiguracion.h"
#include "TurnoTablero.h"

const std::string EJECUTAR_TURNO = "e";
const std::string INICIAR_JUEGO = "r";
const std::string TERMINAR_JUEGO = "t";

/*
 * Clase conteniendo todos los datos del juego y que se instancia al principio de la partida.
 */

class Juego {
private:
	ListaEnlazada<Tablero*>* tablerosDelJuego;
	ListaEnlazada<DatosTablero*>* datosDelJuego;
	Cola<ParcelaAfectada*>* ParcelasAfectadas;
	//LecturaArchivoConfiguracion lectura;


public:
	/*
	 * pre:
	 * post: Aplica la ejecucion de un turno para cada uno de los tableros cambiando las parcelas.
	 */
	void ejecutarTurno();

	/*
	 * pre: -
	 * post: devuelve por pantalla los tableros en formato BMP.
	 */
	void mostrarJuego();



	void pasarCambios(TurnoTablero turno);

	void concretarCambios();

	/*
	 * pre: este método pide al usuario de ingresar lo que quiere hacer al proximo turno.
	 * post: devuelve un caracter correspondiente a la proxima accion.
	 */
	std::string pedirProximoTurno();

	/*
	 * pre: pide al usuario la ruta del archivo de texto valido que contiene los datos para el juego
	 * post: inicia o reinicia el juego seteando los datos a sus valores originales y armando los tableros,
	 * parcelas, celulas.
	 */
	void iniciarJuego();

	/*
	 * pre: el juego ya esta inciciado
	 * post: termina el juego y cierra las representaciones BMP de los tableros.
	 */
	void terminarJuego();

};


#endif /* JUEGO_H_ */
