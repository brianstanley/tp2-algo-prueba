#include <iostream>
#include "LecturaArchivoConfiguracion.h"
#include "Juego.h"
//<<<<<<< HEAD
//int main() {
//	LecturaArchivoConfiguracion lectura;
//	lectura.procesarArchivo("src/entrada.txt");
//	ListaEnlazada<Tablero*>* tableros = lectura.obtenerListaTableros();
//	std::cout << "Hasta aca ";
//	Juego juego;
//	juego.ejecutarTurno(tableros);
//=======

int main() {

//	LecturaArchivoConfiguracion lectura;
//	lectura.procesarArchivo("src/entrada.txt");
//	ListaEnlazada<Tablero*>* tableros = lectura.obtenerListaTableros();
//	tableros->iniciarCursor();
//	if (!tableros->estaVacia()) {
//		std::cout << "Entro";
//		while(tableros->avanzarCursor()) {
//			Tablero * tablero = tableros->obtenerCursor();
//			std::cout  << "El tablero leido de la lista es: " << tablero->getNombre() << tablero->getFilas()  << std::endl;
//			TurnoTablero turno(tablero);
//			turno.jugarTurno();
//			DatosTablero * datosTablero = tablero->getDatosTablero();
//			std::cout  << "Hasta aca un turno.: " << datosTablero->getTurno() << std::endl;
//		}
//	}
	Juego miJuego;
	miJuego.iniciarJuego();
	std::string nuevoTurno = miJuego.pedirProximoTurno();
	while ((nuevoTurno == INICIAR_JUEGO) || (nuevoTurno == EJECUTAR_TURNO)) {
		if (nuevoTurno == EJECUTAR_TURNO) {
			miJuego.ejecutarTurno();
		}
		else {
			miJuego.iniciarJuego();
		}
		nuevoTurno = miJuego.pedirProximoTurno();
	}
	//el usuario pidio que se termino el juego.
	miJuego.terminarJuego();
	return 0;
}







