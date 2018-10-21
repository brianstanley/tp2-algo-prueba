/*
 * imagen_de_tablero.cpp
 *
 *  Created on: Oct 21, 2018
 *      Author: german
 */

#include "imagen_de_tablero.h"
#include<string>

const int profundidadDeColorStandar = 8;

ImagenDeTablero::ImagenDeTablero(int alto, int ancho, std::string nombre){
	this->nombreTableroRepresentado = nombre;
	this->archivoRepresentante.SetSize(alto, ancho);
	this->archivoRepresentante.SetBitDepth(profundidadDeColorStandar);
}

void ImagenDeTablero::representarCelulaViva(int fila, int columna, RGB& colorDeCelula){

}

void ImagenDeTablero::representarCelulaMuerta(int fila, int columna){

}

void ImagenDeTablero::guardarImagenTabero(int NumeroDeTurno){


}
