/*
 * ParcelaAfectada.cpp
 *
 *  Created on: Oct 27, 2018
 *      Author: yorickvinesse
 */

#include "ParcelaAfectada.h"

ParcelaAfectada::ParcelaAfectada(CoordenadaParcela * coordenadaParcela) {
	coordenadaParcelaTocada = coordenadaParcela;
	Portal * portalAsociado = coordenadaParcela->getParcela().getPortal();
	celulaNace = false;
	tienePortal = false;
	if (portalAsociado) {
		tienePortal = true;
	}
}

ParcelaAfectada::ParcelaAfectada(CoordenadaParcela * coordenadaParcela, RGB colorRecibido) {
	coordenadaParcelaTocada = coordenadaParcela;
	Portal * portalAsociado = coordenadaParcela->getParcela().getPortal();
	celulaNace = true;
	tienePortal = false;
	if (portalAsociado) {
		tienePortal = true;
	}
	colorPromedioVecinos = colorRecibido;
}

Parcela & ParcelaAfectada::getParcela() {
	return this->coordenadaParcelaTocada->getParcela();
}

bool ParcelaAfectada::naceLaCelula() {
	return this->celulaNace;
}

bool ParcelaAfectada::hayPortal() {
	return this->tienePortal;
}

RGB ParcelaAfectada::getColorPromedio() {
	return this->colorPromedioVecinos;
}
