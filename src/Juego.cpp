/*
 * JuegoNuevo.cpp
 *
 *  Created on: Nov 1, 2018
 *      Author: yorickvinesse
 */

#include "Juego.h"

std::string Juego::pedirProximoTurno() {
	std::string proximoTurno;
	std::cout << "Qué quieres hacer ahora?\n- Para reiniciar el juego, presiona la tecla 'r'\n"
			"- Para ejecutar un turno, presiona la tecla 'e'\n"
					"- Para terminar el juego, presiona la tecla 't'\n\n";
	std::cin >> proximoTurno;
	return proximoTurno;
}

void Juego::iniciarJuego() {
	std::string rutaDelArchivo;
	std::cout << "Ingresa la ruta del archivo de texto que quieres utilizar: \n";
	std::cin >> rutaDelArchivo;
	LecturaArchivoConfiguracion lectura;
	lectura.procesarArchivo(rutaDelArchivo);
	ListaEnlazada<Tablero*>* tableros = lectura.obtenerListaTableros();
	this->tablerosDelJuego = tableros;
	ListaEnlazada<DatosTablero*> * datos = new ListaEnlazada<DatosTablero*>;
	tableros->iniciarCursor();
	while(tableros->avanzarCursor()) {
		DatosTablero * datosDelTablero = tableros->obtenerCursor()->getDatosTablero();
		datos->agregar(datosDelTablero);
		TurnoTablero turno(tableros->obtenerCursor());
		turno.guardarBMP();
	}
	this->datosDelJuego = datos;

}

void Juego::terminarJuego() {
	std::cout << "\n Terminaste el juego\n";
	delete this->datosDelJuego;
	delete this->tablerosDelJuego;
}

void Juego::ejecutarTurno() {
	tablerosDelJuego->iniciarCursor();
	if (!tablerosDelJuego->estaVacia()) {
		TurnoTablero ** turnos = new TurnoTablero*[10];
		int topeTurnos = 0;
		while(tablerosDelJuego->avanzarCursor()) {
			Tablero * tablero = tablerosDelJuego->obtenerCursor();
			TurnoTablero * turno = new TurnoTablero(tablero);
			turno->jugarTurno();
			turnos[topeTurnos] = turno;
			topeTurnos++;
		}
		tablerosDelJuego->iniciarCursor();
		for(int i = 0; i < topeTurnos; i++) {
			TurnoTablero * turno = turnos[i];
			ListaEnlazada<ParcelaAfectada*> cambiosPorPortal = turno->getCambiosPorPortal();
			cambiosPorPortal.iniciarCursor();
			while(cambiosPorPortal.avanzarCursor()) {
				ParcelaAfectada* CambioARealizar = cambiosPorPortal.obtenerCursor();
				float factorMuertetoOrigen = CambioARealizar->getParcela().getfactorMuerte();
				float factorNacimientoOrigen = CambioARealizar->getParcela().getfactorNacimiento();
				bool nacer = CambioARealizar->naceLaCelula();
				CambioARealizar->getParcela().getPortal()->accionarPortal(nacer, CambioARealizar->getColorPromedio(), factorNacimientoOrigen, factorMuertetoOrigen);
			}
			turno->guardarBMP();
		}
		delete [] turnos;
		tablerosDelJuego->iniciarCursor();
		while(tablerosDelJuego->avanzarCursor()){
			Tablero * tablero = tablerosDelJuego->obtenerCursor();
			tablero->getDatosTablero()->mostrarDatosTablero();
			tablero->getDatosTablero()->reiniciarContadorDeNacidasYMuertasEnUltimoTurno();
		}
	}
}
