/*
 * Portal.cpp
 *
 *  Created on: 21 oct. 2018
 *      Author: yorickvinesse
 */

#include "Portal.h"

Portal::Portal(bool esPortalDeOrigen, char tipoDelPortal,
		CoordenadaParcela * parcelaPareja) {
	this->portalOrigen = esPortalDeOrigen;
	this->tipoDePortal = tipoDelPortal;
	this->parcelaAsociada = parcelaPareja;
}

char Portal::getTipoDePortal() {
	return this->tipoDePortal;
}

void Portal::accionarPortal(bool nace, RGB* color){
	if(this->tipoDePortal == ACTIVO) this->accionarPortalActivo(nace, color);
	else if(this->tipoDePortal == NORMAL) this->accionarPortalNormal(nace, color);
	else if(this->tipoDePortal == PASIVO) this->accionarPortalPasivo(nace, color);

}

void Portal::accionarPortalActivo(bool nace, RGB* color){
	if(this->portalOrigen){
		if(nace) this->nacioOrigenEntoncesNaceDestino(color);
		else this->murioOrigenEntoncesMuereDestino();
	}
	else if (!nace) this->murioDestinoEntoncesMuereOrigen();
}

void Portal::accionarPortalNormal(bool nace, RGB* color){
	if(this->portalOrigen){
		if(nace) this->nacioOrigenEntoncesNaceDestino(color);
		else this->murioOrigenEntoncesMuereDestino();
	}
}

void Portal::accionarPortalPasivo(bool nace, RGB* color){
	if(this->portalOrigen){
		if(nace) this->nacioOrigenEntoncesNaceDestino(color);
	}
}

void Portal::nacioOrigenEntoncesNaceDestino(RGB* color){
	int fila = this->parcelaAsociada->getCoordenadaX();
	int columna = this->parcelaAsociada->getCoordenadaY();
	float factorNacimiento = this->parcelaAsociada->getTablero()->getParcela(fila, columna).getfactorNacimiento();
	this->parcelaAsociada->getTablero()->getParcela(fila,columna).getCelula()->nacer(factorNacimiento,color);
	this->parcelaAsociada->getTablero()->getDatosTablero()->sumarCelulaViva();
}

void Portal::murioOrigenEntoncesMuereDestino(){
	int fila = this->parcelaAsociada->getCoordenadaX();
	int columna = this->parcelaAsociada->getCoordenadaY();
	this->parcelaAsociada->getTablero()->getParcela(fila,columna).getCelula()->morir();
	this->parcelaAsociada->getTablero()->getDatosTablero()->sumarCelulaMuerta();
}

void Portal::murioDestinoEntoncesMuereOrigen(){
	int fila = this->parcelaAsociada->getCoordenadaX();
	int columna = this->parcelaAsociada->getCoordenadaY();
	this->parcelaAsociada->getTablero()->getParcela(fila,columna).getCelula()->morir();
	this->parcelaAsociada->getTablero()->getDatosTablero()->sumarCelulaMuerta();
}
