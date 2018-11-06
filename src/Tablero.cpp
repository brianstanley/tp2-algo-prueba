#include "Tablero.h"

Tablero::Tablero(std::string nombre, int filas, int columnas) {
	this->nombre = nombre;
	this->filas = filas;
	this->columnas = columnas;
	this->parcelas = new Parcela*[this->filas];
	for (int i = 0; i < this->filas; i++) {
		this->parcelas[i] = new Parcela[this->columnas];
	}
	datosDelTablero = new DatosTablero(this);
	BMPDelTablero = new ImagenDeTablero(filas, columnas, nombre);
}

void Tablero::crearParcelas() {
	for (int i = 0; i < this->filas; i++) {
		for (int j = 0; j < this->columnas; j++) {
			RGB rgb;
			CoordenadaParcela * coordenadaParcela = new CoordenadaParcela;
			coordenadaParcela->setCoordenada(this, i, j);
			this->parcelas[i][j].setCoordenadaParcela(coordenadaParcela);
			this->parcelas[i][j].setRBGparcela(rgb);
		}
	}

}

Parcela& Tablero::getParcela(int fila, int columna) {
	return this->parcelas[fila][columna];
}

std::string Tablero::getNombre() {
	return this->nombre;
}

unsigned int Tablero::getFilas() {
	return this->filas;
}

unsigned int Tablero::getColumnas() {
	return this->columnas;
}

DatosTablero* Tablero::getDatosTablero() {
	return this->datosDelTablero;
}

void Tablero::generarBMP() {
	for (unsigned int fila = 0; fila < this->filas; fila++) {
		for (unsigned int columna = 0; columna < this->columnas; columna++) {
			if (this->getParcela(fila, columna).getCelula()->getEstado()) {
				this->BMPDelTablero->representarCelulaViva(fila, columna,
						this->getParcela(fila, columna).getCelula()->getRGB());
			} else {
				this->BMPDelTablero->representarCelulaMuerta(fila, columna);
			}
		}
	}
}

void Tablero::guardarBMP(int numeroTurno) {
	this->BMPDelTablero->guardarImagenTablero(numeroTurno);
}

Tablero::~Tablero() {
	for (unsigned int i = 0; i < this->filas; i++) {
		delete[] this->parcelas[i];
	}
	delete[] this->parcelas;
}

