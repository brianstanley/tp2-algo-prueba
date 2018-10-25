/*
 * imagen_de_tablero.cpp
 *
 *  Created on: Oct 21, 2018
 *      Author: german
 */

#include "imagen_de_tablero.h"
#include<string>
#include<iostream>

const std::string GUION_BAJO = "_";
const int PROFUNDIDADCOLORSTANDAR = 8;
const int VALORRGBPORDEFECTO = 255;

ImagenDeTablero::ImagenDeTablero(int alto, int ancho, std::string nombre){
	this->nombreTableroRepresentado = nombre;
	this->archivoRepresentante.SetSize(alto, ancho);
	this->archivoRepresentante.SetBitDepth(PROFUNDIDADCOLORSTANDAR);
}

void ImagenDeTablero::representarCelulaViva(int fila, int columna, RGB& colorDeCelula){
	this->archivoRepresentante(fila, columna)->Red = colorDeCelula.getRed();
	this->archivoRepresentante(fila, columna)->Green = colorDeCelula.getGreen();
	this->archivoRepresentante(fila, columna)->Blue = colorDeCelula.getBlue();
}

void ImagenDeTablero::representarCelulaMuerta(int fila, int columna){
	this->archivoRepresentante(fila, columna)->Red = VALORRGBPORDEFECTO;
	this->archivoRepresentante(fila, columna)->Green = VALORRGBPORDEFECTO;
	this->archivoRepresentante(fila, columna)->Blue = VALORRGBPORDEFECTO;
}

void ImagenDeTablero::guardarImagenTabero(int numeroDeTurno){
	std::string turno = "";
	enteroAString(turno, numeroDeTurno);
	std::string nombreArchivo = nombreTableroRepresentado + GUION_BAJO + turno;
	std::cout<<nombreArchivo;
	archivoRepresentante.WriteToFile(nombreArchivo.c_str());

}
