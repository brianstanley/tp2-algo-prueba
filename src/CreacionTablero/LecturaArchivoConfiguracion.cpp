#include "../CreacionTablero/LecturaArchivoConfiguracion.h"

void LecturaArchivoConfiguracion::procesarArchivo(std::string ruta) {
	StringHelper stringHelper;
	this->tableros = new ListaEnlazada<Tablero*>;
	std::ifstream archivoDeConfiguracion;
	std::string tipoDeOperacion, nombreTablero;
	Lectura archivo;

	archivo.abrir(ruta, archivoDeConfiguracion);

	while (!archivoDeConfiguracion.eof()) {
		archivoDeConfiguracion >> tipoDeOperacion;
		tipoDeOperacion = stringHelper.aMinuscula(tipoDeOperacion);
		archivoDeConfiguracion >> nombreTablero;
		if (tipoDeOperacion == PARCELA) {
			this->procesarParcela(nombreTablero, archivoDeConfiguracion);
		} else if (tipoDeOperacion == PORTAL) {
			this->procesarPortal(nombreTablero, archivoDeConfiguracion);
		} else if (tipoDeOperacion == TABLERO) {
			this->procesarTablero(nombreTablero, archivoDeConfiguracion);
		} else if (tipoDeOperacion == CELULA) {
			this->procesarCelula(nombreTablero, archivoDeConfiguracion);
		} else {
			ExcepcionesArchivo excepcion;
			excepcion.operacionInvalida();
		}
	}
	archivo.cerrar(archivoDeConfiguracion);
}

void LecturaArchivoConfiguracion::procesarTablero(std::string nombreTablero,
		std::ifstream& archivoDeConfiguracion) {
	int ancho, alto;
	archivoDeConfiguracion >> alto;
	archivoDeConfiguracion >> ancho;
	this->crearTablero(nombreTablero, alto, ancho);
}

void LecturaArchivoConfiguracion::procesarPortal(std::string tableroId,
		std::ifstream& archivoDeConfiguracion) {
	int filaOrigen, columnaOrigen, filaDestino, columnaDestino;
	std::string tableroDestino, tipoPortal;
	archivoDeConfiguracion >> tableroDestino;
	archivoDeConfiguracion >> filaOrigen;
	archivoDeConfiguracion >> columnaOrigen;
	archivoDeConfiguracion >> filaDestino;
	archivoDeConfiguracion >> columnaDestino;
	archivoDeConfiguracion >> tipoPortal;
	this->crearPortales(tableroId, tableroDestino, filaOrigen - 1,
			columnaOrigen - 1, filaDestino - 1, columnaDestino - 1, tipoPortal);
}

void LecturaArchivoConfiguracion::procesarParcela(std::string tableroId,
		std::ifstream& archivoDeConfiguracion) {
	int posX, posY, red, green, blue;
	float tasaNacimiento, tasaMortalidad;
	archivoDeConfiguracion >> posX;
	archivoDeConfiguracion >> posY;
	archivoDeConfiguracion >> red;
	archivoDeConfiguracion >> green;
	archivoDeConfiguracion >> blue;
	archivoDeConfiguracion >> tasaNacimiento;
	archivoDeConfiguracion >> tasaMortalidad;
	Tablero * tablero = this->string2punteroTablero(tableroId);
	RGB rgbDeParcela;
	rgbDeParcela.setRGB(red, green, blue);
	Parcela & parcelaASetear = tablero->getParcela(posX - 1, posY - 1);
	parcelaASetear.setFactorMuerte(tasaMortalidad);
	parcelaASetear.setFactorNacimiento(tasaNacimiento);
	parcelaASetear.setRBGparcela(rgbDeParcela);
}

void LecturaArchivoConfiguracion::procesarCelula(std::string nombreTablero,
		std::ifstream& archivoDeConfiguracion) {
	int fila, columna;
	archivoDeConfiguracion >> fila;
	archivoDeConfiguracion >> columna;
	this->crearCelula(nombreTablero, fila - 1, columna - 1);
}

void LecturaArchivoConfiguracion::crearTablero(std::string nombreTablero,
		int fila, int columna) {
	Tablero * tablero = new Tablero(nombreTablero, fila, columna);
	tablero->crearParcelas();
	this->tableros->agregar(tablero);
}

void LecturaArchivoConfiguracion::crearCelula(std::string tableroId, int fila,
		int columna) {
	Tablero * tablero = this->string2punteroTablero(tableroId);
	Parcela & parcelaAsociada = tablero->getParcela(fila, columna);
	RGB* rgbCelula = parcelaAsociada.getRBGparcela();
	float tasaNacimiento = parcelaAsociada.getfactorNacimiento();
	Celula * celulaASetear = parcelaAsociada.getCelula();
	celulaASetear->nacer(tasaNacimiento, rgbCelula);
	tablero->getDatosTablero()->sumarCelulaViva();
	tablero->getDatosTablero()->reiniciarContadorDeNacidasYMuertasEnUltimoTurno(); //Para que no las cuente como nacidas en primer turno
}

Tablero* LecturaArchivoConfiguracion::string2punteroTablero(
		std::string tableroId) {
	this->tableros->iniciarCursor();
	bool encontramosTablero = false;
	Tablero * tableroBuscado;
	while ((this->tableros->avanzarCursor()) && !encontramosTablero) {
		if (tableroId == this->tableros->obtenerCursor()->getNombre()) {
			encontramosTablero = true;
			tableroBuscado = this->tableros->obtenerCursor();
		}
	}
	return tableroBuscado;
}

void LecturaArchivoConfiguracion::crearPortales(std::string tableroId,
		std::string tableroDestino, int filaOrigen, int columnaOrigen,
		int filaDestino, int columnaDestino, std::string tipoDePortal) {
	Tablero * tableroOrigen = this->string2punteroTablero(tableroId);
	Tablero * tableroDeDestino = this->string2punteroTablero(tableroDestino);

	Parcela & parcelaOrigen = tableroOrigen->getParcela(filaOrigen,
			columnaOrigen);
	Parcela & parcelaDestino = tableroDeDestino->getParcela(filaDestino,
			columnaDestino);

	Portal * portalOrigen = new Portal(true, tipoDePortal,
			parcelaDestino.getCoordenadaParcela());
	Portal * portalDestino = new Portal(false, tipoDePortal,
			parcelaOrigen.getCoordenadaParcela());

	parcelaOrigen.setPortal(portalOrigen);
	parcelaDestino.setPortal(portalDestino);
}

ListaEnlazada<Tablero*>* LecturaArchivoConfiguracion::obtenerListaTableros() {
	return this->tableros;
}
