/*
 * LecturaArchivoConfiguracion.cpp
 *
 *  Created on: Oct 22, 2018
 *      Author: brian
 */

#include "LecturaArchivoConfiguracion.h"

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

void LecturaArchivoConfiguracion::procesarTablero(std::string nombreTablero, std::ifstream& archivoDeConfiguracion) {
	int ancho, alto;
	archivoDeConfiguracion >> alto;
	archivoDeConfiguracion >> ancho;
	this->crearTablero(nombreTablero, alto, ancho);
}

void LecturaArchivoConfiguracion::procesarPortal(std::string tableroId, std::ifstream& archivoDeConfiguracion) {
	int filaOrigen, columnaOrigen, filaDestino, columnaDestino;
	bool esPortalOrigen;
	std::string tableroDestino, tipoPortal;
	archivoDeConfiguracion >> tableroDestino;
	archivoDeConfiguracion >> filaOrigen;
	archivoDeConfiguracion >> columnaOrigen;
	archivoDeConfiguracion >> filaDestino;
	archivoDeConfiguracion >> columnaDestino;
	archivoDeConfiguracion >> tipoPortal;
	archivoDeConfiguracion >> esPortalOrigen;
}

void LecturaArchivoConfiguracion::procesarParcela(std::string tableroId, std::ifstream& archivoDeConfiguracion) {
	int posX, posY, red, green, blue;
	double tasaNacimiento, tasaMortalidad;
	archivoDeConfiguracion >> posX;
	archivoDeConfiguracion >> posY;
	archivoDeConfiguracion >> red;
	archivoDeConfiguracion >> green;
	archivoDeConfiguracion >> blue;
	archivoDeConfiguracion >> tasaNacimiento;
	archivoDeConfiguracion >> tasaMortalidad;
	std::cout << "Recibe: parcela: " << posX << "  " << posY << " " << " red:: " << red << green << blue << std::endl;
	// Aca debería ir una intancia a la clase parcela
}

void LecturaArchivoConfiguracion::procesarCelula(std::string nombreTablero, std::ifstream& archivoDeConfiguracion) {
	int fila, columna;
	archivoDeConfiguracion >> fila;
	archivoDeConfiguracion >> columna;
	this->crearCelula(nombreTablero, fila, columna);
}


void LecturaArchivoConfiguracion::crearTablero(std::string nombreTablero, int fila, int columna) {
	Tablero * tablero = new Tablero(nombreTablero, fila, columna);
	tablero->crearParcelas();
	this->tableros->agregar(tablero);
}

void LecturaArchivoConfiguracion::crearCelula(std::string tableroId, int fila, int columna) {
	std::cout << "En  el tablero " << tableroId << " en la fila: " << fila << " columna: " << columna << "hay que agregar una celula"<<std::endl;
	// aca deberíamos ver como recorrer la lista de tableros hasta el tablero indicado
}

ListaEnlazada<Tablero*>* LecturaArchivoConfiguracion::obtenerListaTableros() {
	return this->tableros;
}
