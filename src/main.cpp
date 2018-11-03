#include <iostream>
#include "LecturaArchivoConfiguracion.h"
#include "Juego.h"
int main() {
	LecturaArchivoConfiguracion lectura;
	lectura.procesarArchivo("src/entrada.txt");
	ListaEnlazada<Tablero*>* tableros = lectura.obtenerListaTableros();
	std::cout << "Hasta aca ";
	Juego juego;
	juego.ejecutarTurno(tableros);
	return 0;
}
