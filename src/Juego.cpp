/*
 * JuegoNuevo.cpp
 *
 *  Created on: Nov 1, 2018
 *      Author: yorickvinesse
 */

#include "Juego.h"

Juego::Juego(std::string archivoDelJuego) {
	LecturaArchivoConfiguracion lectura;
	lectura.procesarArchivo(archivoDelJuego);

}
