#include "../Tablero/ImagenDeTablero.h"

const int FACTOR_AUMENTO_IMAGEN = 30;
const std::string GUION_BAJO = "_";
const int PROFUNDIDADCOLORSTANDAR = 8;
const int VALORRGBPORDEFECTO = 255;

ImagenDeTablero::ImagenDeTablero(int alto, int ancho, std::string nombre) {
	this->nombreTableroRepresentado = nombre;
	int altoDeImagen = alto * FACTOR_AUMENTO_IMAGEN;
	int anchoDeImagen = ancho * FACTOR_AUMENTO_IMAGEN;
	this->archivoBmp.SetSize(anchoDeImagen, altoDeImagen);
	this->archivoBmp.SetBitDepth(PROFUNDIDADCOLORSTANDAR);
}

void ImagenDeTablero::representarCelulaViva(int fila, int columna,
		RGB* colorDeCelula) {
	int filaDeImagen = fila * FACTOR_AUMENTO_IMAGEN;
	int columnaDeImagen = columna * FACTOR_AUMENTO_IMAGEN;
	for (int i = filaDeImagen; i < filaDeImagen + FACTOR_AUMENTO_IMAGEN; i++) {
		for (int j = columnaDeImagen;
				j < columnaDeImagen + FACTOR_AUMENTO_IMAGEN; j++) {
			this->archivoBmp(j, i)->Red = (ebmpBYTE) colorDeCelula->getRed();
			this->archivoBmp(j, i)->Green =
					(ebmpBYTE) colorDeCelula->getGreen();
			this->archivoBmp(j, i)->Blue = (ebmpBYTE) colorDeCelula->getBlue();
		}
	}
}

void ImagenDeTablero::representarCelulaMuerta(int fila, int columna) {
	int filaDeImagen = fila * FACTOR_AUMENTO_IMAGEN;
	int columnaDeImagen = columna * FACTOR_AUMENTO_IMAGEN;
	for (int i = filaDeImagen; i < filaDeImagen + FACTOR_AUMENTO_IMAGEN; i++) {
		for (int j = columnaDeImagen;
				j < columnaDeImagen + FACTOR_AUMENTO_IMAGEN; j++) {
			this->archivoBmp(j, i)->Red = (ebmpBYTE) VALORRGBPORDEFECTO;
			this->archivoBmp(j, i)->Green = (ebmpBYTE) VALORRGBPORDEFECTO;
			this->archivoBmp(j, i)->Blue = (ebmpBYTE) VALORRGBPORDEFECTO;
		}
	}
}

void ImagenDeTablero::guardarImagenTablero(int numeroDeTurno) {
	std::string turno = "";
	StringHelper stringHelper;
	stringHelper.enteroAString(turno, numeroDeTurno);
	std::string nombreArchivo = nombreTableroRepresentado + GUION_BAJO + turno;
	archivoBmp.WriteToFile(nombreArchivo.c_str());

}
