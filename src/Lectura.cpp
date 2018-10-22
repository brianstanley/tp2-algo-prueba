/*
 * Lectura.cpp
 *
 *  Created on: Oct 21, 2018
 *      Author: brianstanley
 */

#include "Lectura.h"
#include <iostream>
#include <fstream>

Lectura::Lectura() {
	// TODO Auto-generated constructor stub

}

int Lectura::leerConfig(std::string rutaEntrada) {

	/* crea el archivo y abre la ruta especificada */
	std::ifstream entrada;
	entrada.open(rutaEntrada.c_str());

	std::cout << rutaEntrada.c_str();
	if (!entrada) {
		std::cerr << "Error: " << strerror(errno);
		std::cout << "Gato";
		return -1;
	} else {
		/* lee la primera línea completa */
		std::string titulo;
		std::getline(entrada, titulo);
		std::cout << "*** " << titulo << " ***" << std::endl;

		/* lee el resto del archivo */
		while (! entrada.eof()) {

			int padron;
			std::string nombre;
			double nota;

			/* intenta leer un número de padrón */
	//		entrada >> padron;
	//
	//		/* verifica que no haya llegado al fin del archivo */
	//		if (! entrada.eof()) {
	//
	//			/* lee el nombre y la nota */
	//			entrada >> nombre;
	//			entrada >> nota;
	//
	//			std::cout << padron << " | " << nota << " | " << nombre << std::endl;
	//		}
		}

		/* cierra el archivo, liberando el recurso */
		entrada.close();
		std::cout << "lle";
	}
}

Lectura::~Lectura() {
	// TODO Auto-generated destructor stub
}

