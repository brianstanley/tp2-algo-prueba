#include <iostream>
#include "EjecucionTurno/Juego.h"

int main() {
	Juego miJuego;
	miJuego.iniciarJuego();
	std::string nuevoTurno = miJuego.pedirProximoTurno();
	while ((nuevoTurno == INICIAR_JUEGO) || (nuevoTurno == EJECUTAR_TURNO)) {
		if (nuevoTurno == EJECUTAR_TURNO) {
			miJuego.ejecutarTurno();
		} else {
			miJuego.iniciarJuego();
		}
		nuevoTurno = miJuego.pedirProximoTurno();
	}
	miJuego.terminarJuego();
	return 0;
}

