#include "Juego.h"

std::string Juego::pedirProximoTurno() {
	std::string proximoTurno;
	std::cout
			<< "\nQué quieres hacer ahora?\n- Para reiniciar el juego, presiona la tecla 'r'\n"
					"- Para ejecutar un turno, presiona la tecla 'e'\n"
					"- Para terminar el juego, presiona la tecla 't'\n\n";
	std::cin >> proximoTurno;
	return proximoTurno;
}

void Juego::iniciarJuego() {
	std::string rutaDelArchivo;
	std::cout
			<< "Ingresa la ruta del archivo de texto que quieres utilizar: \n";
	std::cin >> rutaDelArchivo;
	LecturaArchivoConfiguracion lectura;
	lectura.procesarArchivo(rutaDelArchivo);
	ListaEnlazada<Tablero*>* tableros = lectura.obtenerListaTableros();
	this->tablerosDelJuego = tableros;
	ListaEnlazada<DatosTablero*> * datos = new ListaEnlazada<DatosTablero*>;
	tableros->iniciarCursor();
	while (tableros->avanzarCursor()) {
		DatosTablero * datosDelTablero =
				tableros->obtenerCursor()->getDatosTablero();
		datos->agregar(datosDelTablero);
		TurnoTablero turno(tableros->obtenerCursor());
		turno.actualizarBMP();
	}
	this->datosDelJuego = datos;

}

void Juego::terminarJuego() {
	std::cout << "\nTerminaste el juego\n";
	this->datosDelJuego->iniciarCursor();
	this->tablerosDelJuego->iniciarCursor();
	while(this->datosDelJuego->avanzarCursor()){
		delete this->datosDelJuego->obtenerCursor();
	}
	while(this->tablerosDelJuego->avanzarCursor()){
		delete this->tablerosDelJuego->obtenerCursor();
	}
	delete this->datosDelJuego;
	delete this->tablerosDelJuego;
}

void Juego::afectarCambiosPortalPorTablero(TurnoTablero * turnoTablero) {
	ListaEnlazada<ParcelaAfectada*> cambiosPorPortal =
			turnoTablero->getCambiosPorPortal();
	cambiosPorPortal.iniciarCursor();
	while (cambiosPorPortal.avanzarCursor()) {
		ParcelaAfectada* CambioARealizar = cambiosPorPortal.obtenerCursor();
		float factorMuertetoOrigen =
				CambioARealizar->getParcela().getfactorMuerte();
		float factorNacimientoOrigen =
				CambioARealizar->getParcela().getfactorNacimiento();
		bool nacer = CambioARealizar->naceLaCelula();
		CambioARealizar->getParcela().getPortal()->accionarPortal(nacer,
				CambioARealizar->getColorPromedio(), factorNacimientoOrigen,
				factorMuertetoOrigen);
		delete CambioARealizar;
	}
}

void Juego::jugarTurnosTableros(TurnoTablero ** turnos) {
	int topeTablero = 0;
	while (tablerosDelJuego->avanzarCursor()) {
		Tablero * tablero = tablerosDelJuego->obtenerCursor();
		TurnoTablero * turnoDelTablero = new TurnoTablero(tablero);
		turnoDelTablero->jugarTurnoTablero();
		turnos[topeTablero] = turnoDelTablero;
		topeTablero++;
	}
}

void Juego::procesarDatos() {
	tablerosDelJuego->iniciarCursor();
	while (tablerosDelJuego->avanzarCursor()) {
		Tablero * tablero = tablerosDelJuego->obtenerCursor();
		tablero->getDatosTablero()->mostrarDatosTablero();
		tablero->getDatosTablero()->reiniciarContadorDeNacidasYMuertasEnUltimoTurno();
	}
}

void Juego::ejecutarTurno() {
	tablerosDelJuego->iniciarCursor();
	if (!tablerosDelJuego->estaVacia()) {
		int cantidadTableros = tablerosDelJuego->contarElementos();
		TurnoTablero ** turnos = new TurnoTablero*[cantidadTableros];
		jugarTurnosTableros(turnos);
		tablerosDelJuego->iniciarCursor();
		for (int i = 0; i < cantidadTableros; i++) {
			TurnoTablero * turnoDelTablero = turnos[i];
			this->afectarCambiosPortalPorTablero(turnoDelTablero);
		}
		procesarDatos();
		for (int i = 0; i < cantidadTableros; i++) {
			TurnoTablero * turnoDelTablero = turnos[i];
			turnoDelTablero->actualizarBMP();
			delete turnoDelTablero;
		}
		delete[] turnos;
	}
}
