/*
 * imagen_de_tablero.cpp
 *
 *  Created on: Oct 21, 2018
 *      Author: german
 */

#include "imagen_de_tablero.h"
#include<string>

const int profundidadDeColorStandar = 8;
const int valorRGBPorDefecto = 255;

ImagenDeTablero::ImagenDeTablero(int alto, int ancho, std::string nombre){
	this->nombreTableroRepresentado = nombre;
	this->archivoRepresentante.SetSize(alto, ancho);
	this->archivoRepresentante.SetBitDepth(profundidadDeColorStandar);
}

void ImagenDeTablero::representarCelulaViva(int fila, int columna, RGB& colorDeCelula){
	this->archivoRepresentante(fila, columna)->Red = colorDeCelula.getRed();
	this->archivoRepresentante(fila, columna)->Green = colorDeCelula.getGreen();
	this->archivoRepresentante(fila, columna)->Blue = colorDeCelula.getBlue();
}

void ImagenDeTablero::representarCelulaMuerta(int fila, int columna){
	this->archivoRepresentante(fila, columna)->Red = valorRGBPorDefecto;
	this->archivoRepresentante(fila, columna)->Green = valorRGBPorDefecto;
	this->archivoRepresentante(fila, columna)->Blue = valorRGBPorDefecto;
}

void ImagenDeTablero::guardarImagenTabero(int numeroDeTurno){


	std::string nombreArchivo = nombreTableroRepresentado;
	archivoRepresentante.WriteToFile(nombreArchivo.c_str());

}
