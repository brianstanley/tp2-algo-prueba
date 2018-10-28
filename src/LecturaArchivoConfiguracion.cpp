/*
 * LecturaArchivoConfiguracion.cpp
 *
 *  Created on: Oct 22, 2018
 *      Author: brian
 */

#include "LecturaArchivoConfiguracion.h"
#include <string>
#include "Lectura.h"
#include "Excepciones/ExcepcionesArchivo.h"
#include "Tablero.h"
void LecturaArchivoConfiguracion::procesarArchivo(std::string ruta) {
	std::ifstream archivoDeConfiguracion;
	std::string tipoDeOperacion, nombreTablero;
	Lectura archivo;

	archivo.abrir(ruta, archivoDeConfiguracion);

	while (!archivoDeConfiguracion.eof()) {
		archivoDeConfiguracion >> tipoDeOperacion;
		archivoDeConfiguracion >> nombreTablero;
		if (tipoDeOperacion == PARCELA) {
			this->procesarParcela(nombreTablero, archivoDeConfiguracion);
		} else if (tipoDeOperacion == PORTAL) {
			this->procesarPortal(nombreTablero, archivoDeConfiguracion);
		} else if (tipoDeOperacion == TABLERO) {
			this->procesarTablero(nombreTablero, archivoDeConfiguracion);
		} else {
			ExcepcionesArchivo excepcion;
			excepcion.operacionInvalida();
		}
	}
	archivo.cerrar(archivoDeConfiguracion);
}

void LecturaArchivoConfiguracion::procesarTablero(std::string nombreTablero, std::ifstream& archivoDeConfiguracion) {
	int ancho, alto;
	archivoDeConfiguracion >> ancho;
	archivoDeConfiguracion >> alto;
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

void LecturaArchivoConfiguracion::crearTablero(std::string nombreTablero, int ancho, int alto) {
	Tablero tablero;
	tablero.inicializar(nombreTablero, alto, ancho);
	tablero.crearParcelas();
}


