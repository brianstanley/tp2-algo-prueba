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

void Juego::pasarCambios(TurnoTablero turno) {
	Cola<ParcelaAfectada*> * colaDelTurno = turno.obtenerColaDeCambios();
	while (!colaDelTurno->estaVacia()){
		this->ParcelasAfectadas->acolar(colaDelTurno->desacolar());
	}
}


void Juego::concretarCambios(){
//	this->tableroAsociado->getDatosTablero()->setCongeladoTurnoActual(true);
	Tablero * tableroLeido = NULL;
	while (! this->ParcelasAfectadas->estaVacia()){
		ParcelaAfectada* CambioARealizar = this->ParcelasAfectadas->desacolar();
		Tablero * tableroAsociado = CambioARealizar->getParcela().getCoordenadaParcela()->getTablero();
		if (!tableroLeido) {
			Tablero * tableroLeido = CambioARealizar->getParcela().getCoordenadaParcela()->getTablero();
		} else if((tableroLeido != tableroAsociado)) {
			bool debeCambiarCongelado = tableroLeido->getDatosTablero()->getNacidasEnUltimoTurno() != 0 ||
					tableroLeido->getDatosTablero()->getMuertasEnUltimoTurno() != 0;
			if (debeCambiarCongelado) {
				tableroLeido->getDatosTablero()->setCongeladoTurnoActual(false);
			}
			tableroLeido = tableroAsociado;
		}

		if (CambioARealizar->naceLaCelula()){
			float factorNacimientoParcela = CambioARealizar->getParcela().getfactorNacimiento();
			CambioARealizar->getParcela().getCelula()->nacer(factorNacimientoParcela, CambioARealizar->getColorPromedio());
			tableroAsociado->getDatosTablero()->sumarCelulaViva();
		}
		else{
			float factorMuerteParcelaAsociada = CambioARealizar->getParcela().getfactorMuerte();
			bool murio = CambioARealizar->getParcela().getCelula()->restarEnergia(factorMuerteParcelaAsociada);
			if (murio){
				tableroAsociado->getDatosTablero()->sumarCelulaMuerta();
			}
		}
		if (CambioARealizar->hayPortal()){
			float factorMuertetoOrigen = CambioARealizar->getParcela().getfactorMuerte();
			float factorNacimientoOrigen = CambioARealizar->getParcela().getfactorNacimiento();
			bool nacer = CambioARealizar->naceLaCelula();
			CambioARealizar->getParcela().getPortal()->accionarPortal(nacer, CambioARealizar->getColorPromedio(), factorNacimientoOrigen, factorMuertetoOrigen);
		}

	}
}

void Juego::ejecutarTurno() {
	std::cout << "Entro";
	tablerosDelJuego->iniciarCursor();
	if (!tablerosDelJuego->estaVacia()) {
		while(tablerosDelJuego->avanzarCursor()) {
			Tablero * tablero = tablerosDelJuego->obtenerCursor();
			TurnoTablero turno(tablero);
			turno.jugarTurno();
			this->pasarCambios(turno);
		}
		this->concretarCambios();
		tablerosDelJuego->iniciarCursor();
		while(tablerosDelJuego->avanzarCursor()){
			Tablero * tablero = tablerosDelJuego->obtenerCursor();
			tablero->generarBMP();
			tablero->guardarBMP(tablero->getDatosTablero()->getTurno());
			tablero->getDatosTablero()->mostrarDatosTablero();
			tablero->getDatosTablero()->reiniciarContadorDeNacidasYMuertasEnUltimoTurno();
		}
	}
}
