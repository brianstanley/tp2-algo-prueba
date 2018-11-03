/*
 * JuegoNuevo.cpp
 *
 *  Created on: Nov 1, 2018
 *      Author: yorickvinesse
 */

#include "Juego.h"
#include "TurnoTablero.h"


void Juego::ejecutarTurno(ListaEnlazada<Tablero*>* tablerosJuego) {
	std::cout << "Entro";
	tablerosJuego->iniciarCursor();
	if (!tablerosJuego->estaVacia()) {
		while(tablerosJuego->avanzarCursor()) {
			Tablero * tablero = tablerosJuego->obtenerCursor();
			TurnoTablero turno(tablero);
			turno.jugarTurno();
			DatosTablero * datosTablero = tablero->getDatosTablero();
			std::cout  << "Hasta aca un turno.: " << datosTablero->getTurno() << std::endl;
		}
	}
}
