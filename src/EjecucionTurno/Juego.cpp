#include "../EjecucionTurno/Juego.h"

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
	this->grafoAsociado = new Grafo;
	LecturaArchivoConfiguracion lectura;
	lectura.procesarArchivo(rutaDelArchivo, this->grafoAsociado);
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

char Juego::imprimirPreguntaTransferenciaMinima() {
	char respuesta;
	std::cout << "Desea averiguar la transferencia mínima de células entre dos portales?" << std::endl;
	std::cout << "Ingrese S o N" << std::endl;
	std::cin >> respuesta;
	return respuesta;
}

void Juego::imprimirOpcionesTransferenciaMinima() {
	this->tablerosDelJuego->iniciarCursor();
	int i = 1;
	while(this->tablerosDelJuego->avanzarCursor()){
		std::cout << i << ": " << this->tablerosDelJuego->obtenerCursor()->getNombre() << std::endl;
		i++;
	}
}

Tablero* Juego::obtenerTableroParaTrasferenciaMinima(int opcionElegida) {
	Tablero * buscado = 0;
	int posicionTablero = 1;
	bool tableroEncontrado = false;
	this->tablerosDelJuego->iniciarCursor();
	while(this->tablerosDelJuego->avanzarCursor() && ! tableroEncontrado){
		if (posicionTablero == opcionElegida) {
			buscado = this->tablerosDelJuego->obtenerCursor();
			tableroEncontrado = true;
		}
		posicionTablero++;
	}
	return buscado;
}

void Juego::preguntarCaminoMasCorto() {
	char respuesta = this->imprimirPreguntaTransferenciaMinima();
	if (respuesta == 'S' || respuesta == 's') {
		std::cout << "Ingrese el numero de tablero origen: Ejemplo 1 para el primero de la lista.: " << std::endl;
		this->imprimirOpcionesTransferenciaMinima();
		int opcion1;
		int opcion2;
		std::cin >> opcion1;
		std::cout << "Ingrese el tablero destino: " << std::endl;
		std::cin >> opcion2;
		Tablero * tableroOrigen = this->obtenerTableroParaTrasferenciaMinima(opcion1);
		Tablero * tableroDestino = this->obtenerTableroParaTrasferenciaMinima(opcion2);
		if (tableroOrigen && tableroDestino) {
			int menorTransferencia = this->grafoAsociado->obtenerMenorTransferencia(tableroOrigen, tableroDestino);
			std::cout << "la minima transferencia de celulas desde " << tableroOrigen->getNombre() << " hasta "
			<< tableroDestino->getNombre() << " es de " << menorTransferencia << std::endl;
		}
		else{
			std::cout << "Alguna de las opciones que ingreso es incorrecta." << std::endl;
		}
	}
}

void Juego::terminarJuego() {
	this->preguntarCaminoMasCorto();
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
	delete this->grafoAsociado;
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
		Tablero* tableroOrigen = CambioARealizar->getTablero();
		CambioARealizar->getParcela().getPortal()->accionarPortal(nacer,
				CambioARealizar->getColorPromedio(), factorNacimientoOrigen,
				factorMuertetoOrigen, this->grafoAsociado, tableroOrigen);
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
