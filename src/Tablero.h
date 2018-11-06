#ifndef SRC_TABLERO_H_
#define SRC_TABLERO_H_

#include <iostream>
#include <string>
#include "Parcela.h"
#include "DatosTablero.h"
#include "ImagenDeTablero.h"

class Parcela;
class DatosTablero;

class Tablero {
private:
	std::string nombre;
	unsigned int filas;
	unsigned int columnas;
	Parcela **parcelas;
	DatosTablero* datosDelTablero;
	ImagenDeTablero* BMPDelTablero;

public:
	/*
	 * pre: El nombre del tablero, la cantidad de filas y columnas.
	 * post: Se inicializa un tablero como una matriz dinamica de Parcelas
	 * de acuerdo a la cantidad de filas y columnas indicadas.
	 */
	Tablero(std::string nombre, int filas, int columnas);

	/*
	 * pre: El tablero debe estar inicializado
	 * pos: Asigna los punteros a parcelas en la matriz dinámica
	 */
	void crearParcelas();

	/*
	 * pre: Fila y Columna dentro del rango de la matriz dinámica de parcelas.
	 * post: Se devuelve una referencia a la parcela en la posición indicada.
	 */
	Parcela& getParcela(int fila, int columna);

	/*
	 * pre: -
	 * post: se devuelve el nombre del tablero
	 */
	std::string getNombre();

	/*
	 * pre:-
	 * post: devuelve el numero de filas del tablero
	 */
	unsigned int getFilas();

	/*
	 * pre:-
	 * post: Devuelve el numero de columnas del tablero
	 */
	unsigned int getColumnas();

	/*
	 * pre: -
	 * post: devuelve un puntero a los datos asociados al tablero
	 */
	DatosTablero* getDatosTablero();

	/*
	 * pre: -
	 * post: guarda las celulas de tablero en el archivo bmp
	 */
	void generarBMP();

	/*
	 * pre: -
	 * post: guarda los datos de archivoDelTablero en un archivo .bmp
	 */
	void guardarBMP(int numeroTurno);

	~Tablero();

};

#endif /* SRC_TABLERO_H_ */
