#include <iostream>
#include "LecturaArchivoConfiguracion.h"
int main() {
	LecturaArchivoConfiguracion lectura;
	lectura.procesarArchivo("src/entrada.txt");
	ListaEnlazada<Tablero*>* tableros = lectura.obtenerListaTableros();
	tableros->iniciarCursor();
	if (!tableros->estaVacia()) {
		std::cout << "Entro";
		while(tableros->avanzarCursor()) {
			Tablero * tablero = tableros->obtenerCursor();
			std::cout  << "El tablero leido de la lista es: " << tablero->getNombre() << tablero->getFilas()  << std::endl;
		}
	}
	return 0;
}
