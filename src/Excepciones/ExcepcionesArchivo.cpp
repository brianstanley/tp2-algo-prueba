#include "ExcepcionesArchivo.h"
#include <stdexcept>

void ExcepcionesArchivo::noSePuedeAbrir() {
	throw std::runtime_error("No se puede abrir el archivo");
}

void ExcepcionesArchivo::operacionInvalida() {
	throw std::runtime_error("La operación leída es invalida");
}
