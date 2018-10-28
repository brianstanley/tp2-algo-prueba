/*
 * Celula.cpp
 *
 *  Created on: Oct 18, 2018
 *      Author: german
 */
const int ENERGIA_MAX = 100;
const bool MUERTA = false;
const bool VIVA = true;

#include "Celula.h"

Celula::Celula() {
	this->estadoCelula = MUERTA;
	this->energiaCelula = 0;
}

void Celula::morir() {
	this->estadoCelula = MUERTA;
	this->energiaCelula = 0;
}

void Celula::nacer(float factorNacimientoParcela, const RGB& RGBParcela){
	this->estadoCelula = VIVA;
	this->energiaCelula = ENERGIA_MAX * factorNacimientoParcela;
	this->RGBCelula = RGBParcela;
}

void Celula::nacer(float factorNacimientoParcela, RGB* RGBvecino1, RGB* RGBvecino2, RGB* RGBvecino3) {
	this->estadoCelula = VIVA;
	this->energiaCelula = ENERGIA_MAX * factorNacimientoParcela;
	RGBCelula.calcularPromedioRGBes(RGBvecino1, RGBvecino2, RGBvecino3);
}

const RGB& Celula::getRGB() {
	return this->RGBCelula;
}

bool Celula::getEstado() {
	return this->estadoCelula;
}
