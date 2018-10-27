/*
 * Parcela.cpp
 *
 *  Created on: Oct 17, 2018
 *      Author: brian
 */

#include "Parcela.h"

Parcela::Parcela(CoordenadaParcela * coordenadaParcela, float factorNacimiento, float factorMuerte, RGB RGBParcela) {
	this->coordenadaParcela = coordenadaParcela;
	this->factorNacimiento = factorNacimiento;
	this->factorMuerte = factorMuerte;
	this->RGBParcela = RGBParcela;
	this->portal = 0;
	//this->celula = Celula(); SE CONSTRUYE EN LA DECLARACION
	//this->portal = NULL; portalNulo
}

//void Parcela::setPortal(bool esPortalDeOrigen, char tipoDelPortal,
//		CoordenadaParcela * parcelaPareja) {
void Parcela::setPortal(Portal * portal) {
	this->portal = portal;
}

CoordenadaParcela * Parcela::getCoordenadaParcela() {
	return this->coordenadaParcela;
}

Celula Parcela::getCelula() {
	return this->celula;
}

Portal * Parcela::getPortal() {
	return this->portal;
}

float Parcela::getfactorNacimiento() {
	return this->factorNacimiento;
}

float Parcela::getfactorMuerte() {
	return this->factorMuerte;
}

RGB Parcela::getRBGparcela() {
	return this->RGBParcela;
}

