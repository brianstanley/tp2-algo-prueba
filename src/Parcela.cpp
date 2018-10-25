/*
 * Parcela.cpp
 *
 *  Created on: Oct 17, 2018
 *      Author: brian
 */

#include "Parcela.h"

Parcela::Parcela(CoordenadaParcela coordenadaParcela, float factorNacimiento,
		float factorMuerte, RGB RGBParcela) {
	this->coordenadaParcela = coordenadaParcela;
	this->factorNacimiento = factorNacimiento;
	this->factorMuerte = factorMuerte;
	this->RGBParcela = RGBParcela;
	this->celula = Celula();
	this->portal = NULL; /* ¿ACA COMO CREEN QUE PODRIA TRATAR AL PORTAL? */
}

void Parcela::setPortal(bool esPortalDeOrigen, char tipoDelPortal,
		CoordenadaParcela * parcelaPareja) {
	this->portal = portal(esPortalDeOrigen, tipoDelPortal, *parcelaPareja);
}

CoordenadaParcela Parcela::getCoordenadaParcela(){
	return this->coordenadaParcela;
}

Celula Parcela::getCelula(){
	return this->celula;
}

Portal Parcela::getPortal(){
	return this->portal;
}

float Parcela::getfactorNacimiento(){
	return this->factorNacimiento;
}

float Parcela::getfactorMuerte(){
	return this->factorMuerte;
}

RGB Parcela::getRBGparcela(){
	return this->RGBParcela;
}
