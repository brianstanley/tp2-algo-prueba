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

void LecturaArchivoConfiguracion::procesarArchivo(std::string ruta) {
	std::ifstream archivoDeConfiguracion;
	std::string tipoDeOperacion, nombreTablero;
	Lectura archivo;

	archivo.abrir(ruta, archivoDeConfiguracion);

	while (!archivoDeConfiguracion.eof()) {
		archivoDeConfiguracion >> tipoDeOperacion;
		archivoDeConfiguracion >> nombreTablero;
		if (tipoDeOperacion == PARCELA) {
			this->crearParcela(nombreTablero, archivoDeConfiguracion);
		} else if (tipoDeOperacion == PORTAL) {
			this->crearPortal(nombreTablero, archivoDeConfiguracion);
		} else if (tipoDeOperacion == TABLERO) {
			this->crearTablero(nombreTablero, archivoDeConfiguracion);
		} else {
			ExcepcionesArchivo excepcion;
			excepcion.operacionInvalida();
		}
	}
	archivo.cerrar(archivoDeConfiguracion);
}

void LecturaArchivoConfiguracion::crearTablero(std::string nombreTablero, std::ifstream& archivoDeConfiguracion) {
	int posX, posY;
	std::cout << "Crear tablero " << std::endl;
	archivoDeConfiguracion >> posX;
	archivoDeConfiguracion >> posY;
	std::cout << "Recibe: tablero: " << nombreTablero << "  " << posX << " " << " posy: " << posY << std::endl;
	// Aca debería ir una intancia a la clase tablero
}

void LecturaArchivoConfiguracion::crearPortal(std::string tableroId, std::ifstream& archivoDeConfiguracion) {
	int posX, posY;
	std::string tipoPortal;
	std::cout << "Crear portal" << std::endl;
	archivoDeConfiguracion >> posX;
	archivoDeConfiguracion >> posY;
	archivoDeConfiguracion >> tipoPortal;
	std::cout << "Recibe: portal: " << tipoPortal << "  " << posX << " " << " posy: " << posY << std::endl;
	// Aca debería ir una intancia a la clase portal
}

void LecturaArchivoConfiguracion::crearParcela(std::string tableroId, std::ifstream& archivoDeConfiguracion) {
	int posX, posY, red, green, blue;
	double tazaNacimiento, tazaMortalidad;
	archivoDeConfiguracion >> posX;
	archivoDeConfiguracion >> posY;
	archivoDeConfiguracion >> red;
	archivoDeConfiguracion >> green;
	archivoDeConfiguracion >> blue;
	archivoDeConfiguracion >> tazaNacimiento;
	archivoDeConfiguracion >> tazaMortalidad;
	std::cout << "Recibe: parcela: " << posX << "  " << posY << " " << " red:: " << red << green << blue << std::endl;
	// Aca debería ir una intancia a la clase parcela
}


