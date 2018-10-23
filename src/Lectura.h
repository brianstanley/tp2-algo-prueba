/*
 * Lectura.h
 *
 *  Created on: Oct 21, 2018
 *      Author: brianstanley
 */

#ifndef SRC_LECTURA_H_
#define SRC_LECTURA_H_
#include <iostream>
#include <fstream>

class Lectura {
public:
	/**
	 * pre: La ruta y un manejador de archivo
	 * pos: Abre el archivo en el buffer
	 */
	void abrir(std::string ruta, std::ifstream& archivo);
	/**
	 * pre: El manejador del archivo
	 * pos: cierra el buffer del archivo
	 */
	void cerrar(std::ifstream&);
};

#endif /* SRC_LECTURA_H_ */
