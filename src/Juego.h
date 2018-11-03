/*
 * JuegoNuevo.h
 *
 *  Created on: Oct 27, 2018
 *      Author: german
 */

#ifndef JUEGO_H_
#define JUEGO_H_

#include "Tablero.h"
#include "ListaEnlazada.h"
#include "LecturaArchivoConfiguracion.h"

const char EJECUTAR_TURNO = "e";
const char INICIAR_JUEGO = "r";
const char TERMINAR_JUEGO = "t";

/*
 * Clase conteniendo todos los datos del juego y que se instancia al principio de la partida.
 */

class Juego {
private:
	ListaEnlazada<Tablero*> tablerosDelJuego;
	ListaEnlazada<DatosTablero*> datosDelJuego;
	//LecturaArchivoConfiguracion lectura;
	char proximaAccion;


public:

	/*
	 * pre: recibe un archivo de texto valido con toda la informacion del juego
	 * post: asigna la lista de tableros creada por la lectura del archivo al atributo tablerosDelJuego.
	 * y la lista de DatosTablero a datosDelJuego
	 */
	Juego(std::string archivoDelJuego);

	/*
	 * pre: recibe los tableros del juego en el estado del turno anterior.
	 * post: Aplica la ejecucion de un turno para cada uno de los tableros cambiando las parcelas.
	 */
	void ejecutarTurno(ListaEnlazada<Tablero*> tablerosJuego);

	/*
	 * pre: -
	 * post: devuelve por pantalla los tableros en formato BMP.
	 */
	void mostrarJuego();

	/*
	 * pre: este método pide al usuario de ingresar lo que quiere hacer al proximo turno.
	 * post: devuelve un caracter correspondiente a la proxima accion.
	 */
	char pedirProximoTurno();

	/*
	 * pre: -
	 * post: inicia o reinicia el juego seteando los datos a sus valores originales.
	 */
	void iniciarJuego();



};


#endif /* JUEGO_H_ */
