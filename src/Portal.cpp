/*
 * Portal.cpp
 *
 *  Created on: 21 oct. 2018
 *      Author: yorickvinesse
 */

#include "Portal.h"

Portal::Portal(bool esPortalDeOrigen, char tipoDelPortal,
		CoordenadaParcela parcelaPareja) {
	this->portalOrigen = esPortalDeOrigen;
	this->tipoDePortal = tipoDelPortal;
	this->parcelaAsociada = parcelaPareja;
}

char Portal::getTipoDePortal() {
	return this->tipoDePortal;
}

CoordenadaParcela Portal::getCoordenadaAsociada() {
	return this->parcelaAsociada;
}
