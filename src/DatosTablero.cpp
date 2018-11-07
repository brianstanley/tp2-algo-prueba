#include "DatosTablero.h"

DatosTablero::DatosTablero(Tablero* tableroAsociado) {
	this->cantidadCelulasVivas = 0;
	this->muertasTotal = 0;
	this->nacidasTotal = 0;
	this->promedioMuertas = 0;
	this->promedioNacidas = 0;
	this->turnosCongelado = 0;
	this->numeroTurno = 0;
	this->congeladoTurnoActual = true;
	this->nacidasEnUltimoTurno = 0;
	this->muertasEnUltimoTurno = 0;
	this->tableroAsociado = tableroAsociado;
}

unsigned int DatosTablero::getCantidadCelulasVivas() {
	return this->cantidadCelulasVivas;
}
void DatosTablero::sumarCelulaViva() {
	this->nacidasEnUltimoTurno++;
	this->cantidadCelulasVivas++;
	this->nacidasTotal++;
}
void DatosTablero::sumarCelulaMuerta() {
	this->muertasEnUltimoTurno++;
	this->cantidadCelulasVivas--;
	this->muertasTotal++;
}
int DatosTablero::getNacidasTotal() {
	return this->nacidasTotal;
}
unsigned int DatosTablero::getMuertasTotal() {
	return this->muertasTotal;
}
float DatosTablero::getPromedioNacidas() {
	this->promedioNacidas = ((float) this->nacidasTotal )/ this->numeroTurno;
	return this->promedioNacidas;
}
float DatosTablero::getPromedioMuertas() {
	this->promedioMuertas = ((float) this->muertasTotal )/ this->numeroTurno;
	return this->promedioMuertas;
}

void DatosTablero::setCongeladoTurnoActual(bool estadoDeCongelamiento) {
	this->congeladoTurnoActual = estadoDeCongelamiento;
}

void DatosTablero::setCantidadTurnosCongeladosTablero() {
	if (this->congeladoTurnoActual) {
		this->turnosCongelado++;
	} else {
		this->turnosCongelado = 0;
	}
}

bool DatosTablero::estaCongelado() {
	return (this->turnosCongelado >= 2);
}

unsigned int DatosTablero::getTurno() {
	return this->numeroTurno;
}

void DatosTablero::avanzarUnTurno() {
	this->numeroTurno++;
}

unsigned int DatosTablero::getNacidasEnUltimoTurno() {
	return this->nacidasEnUltimoTurno;
}

unsigned int DatosTablero::getMuertasEnUltimoTurno() {
	return this->muertasEnUltimoTurno;
}

void DatosTablero::reiniciarContadorDeNacidasYMuertasEnUltimoTurno() {
	this->nacidasEnUltimoTurno = 0;
	this->muertasEnUltimoTurno = 0;
}

void DatosTablero::mostrarDatosTablero() {
	std::cout << "Tablero: " << this->tableroAsociado->getNombre()
			<< ", turno numero " << this->numeroTurno << std::endl;
	std::cout << "Células vivas: " << this->cantidadCelulasVivas << std::endl;
	std::cout << "Células nacidas en total: " << this->nacidasTotal
			<< std::endl;
	std::cout << "Células muertas en total: " << this->muertasTotal
			<< std::endl;
	std::cout << "Células nacidas en el turno actual: "
			<< this->nacidasEnUltimoTurno << std::endl;
	std::cout << "Células muertas en el turno actual: "
			<< this->muertasEnUltimoTurno << std::endl;
	std::cout << "Promedio de nacimientos: " << this->getPromedioNacidas()
			<< std::endl;
	std::cout << "Promedio de muertes: " << this->getPromedioMuertas() << "\n ";
	if (this->estaCongelado()) {
		std::cout << "El tablero se encuentra congelado" << std::endl;
	}
	std::cout << std::endl;

}
