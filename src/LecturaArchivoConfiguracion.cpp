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
			this->leerParcela(nombreTablero, archivoDeConfiguracion);
		} else if (tipoDeOperacion == PORTAL) {
			this->leerPortal(nombreTablero, archivoDeConfiguracion);
		} else if (tipoDeOperacion == TABLERO) {
			this->leerTablero(nombreTablero, archivoDeConfiguracion);
		} else {
			ExcepcionesArchivo excepcion;
			excepcion.operacionInvalida();
		}
	}
	archivo.cerrar(archivoDeConfiguracion);
}

void LecturaArchivoConfiguracion::leerTablero(std::string nombreTablero, std::ifstream& archivoDeConfiguracion) {
	int ancho, alto;
	std::cout << "Crear tablero " << std::endl;
	archivoDeConfiguracion >> ancho;
	archivoDeConfiguracion >> alto;
	std::cout << "Recibe: tablero: " << nombreTablero << "  " << ancho << " " << " alto: " << alto << std::endl;
	// Aca debería ir una intancia a la clase tablero
}

void LecturaArchivoConfiguracion::leerPortal(std::string tableroId, std::ifstream& archivoDeConfiguracion) {
	int filaOrigen, columnaOrigen, filaDestino, columnaDestino;
	bool esPortalOrigen;
	std::string tableroDestino, tipoPortal;
	std::cout << "Crear portal" << std::endl;
	archivoDeConfiguracion >> tableroDestino;
	archivoDeConfiguracion >> filaOrigen;
	archivoDeConfiguracion >> columnaOrigen;
	archivoDeConfiguracion >> filaDestino;
	archivoDeConfiguracion >> columnaDestino;
	archivoDeConfiguracion >> tipoPortal;
	archivoDeConfiguracion >> esPortalOrigen;
	std::cout << "Tipo: portal: " << tipoPortal << " origen fila: " << filaOrigen << std::endl;
	std::cout << "origen columna: " << columnaOrigen << std::endl;
	std::cout << "destino fila: " << filaDestino << std::endl;
	std::cout << "destino columna: " << columnaDestino << std::endl;
	std::cout << "Es portal de origen? " << esPortalOrigen << std::endl;
	// Aca debería ir una intancia a la clase portal
}

void LecturaArchivoConfiguracion::leerParcela(std::string tableroId, std::ifstream& archivoDeConfiguracion) {
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


