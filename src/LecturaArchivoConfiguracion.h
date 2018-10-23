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

std::string const PARCELA = "Parcela";
std::string const PORTAL = "Portal";
std::string const TABLERO = "Tablero";

class LecturaArchivoConfiguracion {
private:
	void crearTablero(std::string nombreTablero, std::ifstream&);
	void crearPortal(std::string nombreTablero, std::ifstream&);
	void crearParcela(std::string nombreTablero, std::ifstream&);
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
