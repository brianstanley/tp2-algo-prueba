/*
 * imagen_de_tablero.cpp
 *
 *  Created on: Oct 21, 2018
 *      Author: german
 */

#include "imagen_de_tablero.h"

const std::string GUION_BAJO = "_";
const int PROFUNDIDADCOLORSTANDAR = 8;
const int VALORRGBPORDEFECTO = 255;

ImagenDeTablero::ImagenDeTablero(int alto, int ancho, std::string nombre){
	this->nombreTableroRepresentado = nombre;
	this->archivoBmp.SetSize(alto, ancho);
	this->archivoBmp.SetBitDepth(PROFUNDIDADCOLORSTANDAR);
}

void ImagenDeTablero::representarCelulaViva(int fila, int columna, RGB* colorDeCelula){
	this->archivoBmp(fila, columna)->Red = (ebmpBYTE) colorDeCelula->getRed();
	this->archivoBmp(fila, columna)->Green = (ebmpBYTE) colorDeCelula->getGreen();
	this->archivoBmp(fila, columna)->Blue = (ebmpBYTE) colorDeCelula->getBlue();
}

void ImagenDeTablero::representarCelulaMuerta(int fila, int columna){
	this->archivoBmp(fila, columna)->Red = (ebmpBYTE) VALORRGBPORDEFECTO;
	this->archivoBmp(fila, columna)->Green = (ebmpBYTE) VALORRGBPORDEFECTO;
	this->archivoBmp(fila, columna)->Blue = (ebmpBYTE) VALORRGBPORDEFECTO;
}

void ImagenDeTablero::guardarImagenTablero(int numeroDeTurno){
	std::string turno = "";
	StringHelper stringHelper;
	stringHelper.enteroAString(turno, numeroDeTurno);
	std::string nombreArchivo = nombreTableroRepresentado + GUION_BAJO + turno;
	archivoBmp.WriteToFile(nombreArchivo.c_str());

}
