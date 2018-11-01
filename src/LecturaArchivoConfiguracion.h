/*
 * LecturaArchivoConfiguracion.h
 *
 *  Created on: Oct 22, 2018
 *      Author: brian
 */

#ifndef SRC_LECTURAARCHIVOCONFIGURACION_H_
#define SRC_LECTURAARCHIVOCONFIGURACION_H_
#include <string>
#include <fstream>
#include "Lectura.h"
#include "Excepciones/ExcepcionesArchivo.h"
#include "Tablero.h"
#include "StringHelper.h"


std::string const PARCELA = "parcela";
std::string const PORTAL = "portal";
std::string const TABLERO = "tablero";
std::string const CELULA = "celula";

class LecturaArchivoConfiguracion {
private:
	void procesarTablero(std::string nombreTablero, std::ifstream&);
	void procesarPortal(std::string nombreTablero, std::ifstream&);
	void procesarParcela(std::string nombreTablero, std::ifstream&);
	void procesarCelula(std::string nombreTablero, std::ifstream&);
	void crearTablero(std::string, int ancho, int alto);
	void crearCelula(std::string, int fila, int columna);
public:
	/**
	 * pre: Ruta al archivo del cual se desea leer la configuración de
	 * inicio del juego. La ruta tiene que ser a un archivo que exista,
	 * tenga un formato valido como  específica la documentación y
	 * tiene que tener permisos de lectura.
	 * pos: Procesa el archivo de configuración creando los elementos
	 * que se encuentran indicadas en el archivo.
	 */
	void procesarArchivo(std::string);
};

#endif /* SRC_LECTURAARCHIVOCONFIGURACION_H_ */
