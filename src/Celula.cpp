/*
 * Celula.cpp
 *
 *  Created on: Oct 18, 2018
 *      Author: german
 */
#define ENERGIA_MAX 100

#include"Celula.h"

Celula::Celula(){
	this->estadoCelula = false;
	this->energiaCelula = 0;
	this->colorCelula = 0;
}

Celula::Celula(float factorNacimiento, Color colorParcela){
	this->estadoCelula = true;
	this->energiaCelula = ENERGIA_MAX * factorNacimiento;
	this->colorCelula = Color(colorParcela);
}

void Celula::morir(){
	this->estadoCelula = false;
	this->energiaCelula = 0;
}

void Celula::nacer(float factorNacimiento, const Color& colorA, const Color& colorB, const Color& colorC){
	this->estadoCelula = true;
	this->energiaCelula = ENERGIA_MAX * factorNacimiento;
	this->colorCelula = colorCelula.calcularPromedioColores(colorA, colorB, colorC);
}

const Color& Celula:: getColor(){
	return this->colorCelula;
}

bool Celula::getEstado(){
	return this->estadoCelula;
}
