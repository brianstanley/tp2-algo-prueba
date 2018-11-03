/*
 * JuegoNuevo.cpp
 *
 *  Created on: Nov 1, 2018
 *      Author: yorickvinesse
 */

#include "Juego.h"

Juego::Juego() {
}

std::string Juego::pedirProximoTurno() {
	std::string proximoTurno;
	std::cout << "Qué quieres hacer ahora?\n- Para reiniciar el juego, presiona la tecla 'r'\n"
			"- Para ejecutar un turno, presiona la tecla 'e'\n"
					"- Para terminar el juego, presiona la tecla 't'\n\n";
	std::cin >> proximoTurno;
	return proximoTurno;
}

void Juego::iniciarJuego() {
	delete this->datosDelJuego;
	delete this->tablerosDelJuego;
	std::string rutaDelArchivo;
	std::cout << "Ingresa la ruta del archivo de texto que quieres utilizar: \n";
	std::cin >> rutaDelArchivo;
	LecturaArchivoConfiguracion lectura;
	lectura.procesarArchivo(rutaDelArchivo);
	ListaEnlazada<Tablero*>* tableros = lectura.obtenerListaTableros();
	this->tablerosDelJuego = tableros;
	tableros->iniciarCursor();
	while(tableros->avanzarCursor()) {
		DatosTablero * datosDelTablero = tableros->obtenerCursor()->getDatosTablero();
		this->datosDelJuego->agregar(datosDelTablero);
	}
}

void Juego::terminarJuego() {
	std::cout << "\n Terminaste el juego\n";
	delete this->datosDelJuego;
	delete this->tablerosDelJuego;

}
