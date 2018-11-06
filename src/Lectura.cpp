#include "Lectura.h"
#include <iostream>
#include <fstream>
#include <errno.h>
#include "Excepciones/ExcepcionesArchivo.h"

void Lectura::abrir(std::string rutaEntrada, std::ifstream& entrada) {
	entrada.open(rutaEntrada.c_str());
	if (!entrada || entrada.is_open() == false) {
		ExcepcionesArchivo excepcion;
		excepcion.noSePuedeAbrir();
	}
}

void Lectura::cerrar(std::ifstream & entrada) {
	entrada.close();
}

