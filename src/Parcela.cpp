/*
 * Parcela.cpp
 *
 *  Created on: Oct 17, 2018
 *      Author: brian
 */

#include "Parcela.h"

Parcela::Parcela() {
	this->coordenadaParcela = NULL;
	this->portal = NULL;
	this->celula = NULL;
	this->factorNacimiento = FACTOR_NACIMIENTO_DEFAULT;
	this->factorMuerte = FACTOR_MUERTE_DEFAULT;
	this->RGBParcela = RGBParcela;
}

void Parcela::setPortal(Portal * portal) {
	this->portal = portal;
}

CoordenadaParcela * Parcela::getCoordenadaParcela() {
	return this->coordenadaParcela;
}

Celula * Parcela::getCelula() {
	return this->celula;
}

Portal * Parcela::getPortal() {
	return this->portal;
}

void Parcela::setFactorNacimiento(float factorNacimiento) {
	if (factorNacimiento > 0) {
		this->factorNacimiento = factorNacimiento;
	} else {
		throw std::string("Factor de nacimiento invalido");
	}
}

void Parcela::setFactorMuerte(float factorMuerte) {
	if (factorMuerte > 0) {
		this->factorMuerte = factorMuerte;
	} else {
		throw std::string("Factor de muerte invalido");
	}
}

float Parcela::getfactorNacimiento() {
	return this->factorNacimiento;
}

float Parcela::getfactorMuerte() {
	return this->factorMuerte;
}

void Parcela::setCoordenadaParcela(CoordenadaParcela * coordenadaParcela) {
	this->coordenadaParcela = coordenadaParcela;
}

void Parcela::setRBGparcela(RGB RGBParcela) {
	this->RGBParcela = RGBParcela;
}

RGB Parcela::getRBGparcela() {
	return this->RGBParcela;
}


