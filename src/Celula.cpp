/*
 * Celula.cpp
 *
 *  Created on: Oct 18, 2018
 *      Author: german
 */
const int ENERGIA_MAX = 100;
const bool MUERTA = false;
const bool VIVA = true;

#include"Celula.h"


Celula::Celula(){
	this->estadoCelula = MUERTA;
	this->energiaCelula = 0;
	this->RGBCelula = RGB();
}

Celula::Celula(float factorNacimientoParecla, RGB RGBParcela){
	this->estadoCelula = VIVA;
	this->energiaCelula = ENERGIA_MAX * factorNacimientoParecla;
	this->RGBCelula = RGB(RGBParcela);
}

void Celula::morir(){
	this->estadoCelula = MUERTA;
	this->energiaCelula = 0;
}

void Celula::nacer(float factorNacimientoParecla, const RGB& RGBA, const RGB& RGBB, const RGB& RGBC){
	this->estadoCelula = VIVA;
	this->energiaCelula = ENERGIA_MAX * factorNacimientoParecla;
	RGBCelula.calcularPromedioRGBes(RGBA, RGBB, RGBC);
}

const RGB& Celula:: getRGB(){
	return this->RGBCelula;
}

bool Celula::getEstado(){
	return this->estadoCelula;
}
