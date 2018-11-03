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
	if(this->tipoDePortal == ACTIVO){
		if(this->portalOrigen){
			if(nace){
				this->nacer(color);
			}
			else{
				this->morir();
			}
		}
		else if (!nace){
			this->morir();
		}
	}
	else if(this->tipoDePortal == NORMAL){
		if(this->portalOrigen){
			if(nace){
				this->nacer(color);
			}
			else{
				this->morir();
			}
		}
	}
	else{ //Pasivo
		if(this->portalOrigen){
			if(nace){
				this->nacer(color);
			}
		}
	}
}

void Portal::nacer(RGB* color){
	int fila = this->parcelaAsociada->getCoordenadaX();
	int columna = this->parcelaAsociada->getCoordenadaY();
	float factorNacimiento = this->parcelaAsociada->getTablero()->getParcela(fila, columna).getfactorNacimiento();
	Tablero * tableroAsociado = this->parcelaAsociada->getTablero();
	tableroAsociado->getParcela(fila,columna).getCelula()->nacer(factorNacimiento,color);
	tableroAsociado->getDatosTablero()->sumarCelulaViva();
	if(tableroAsociado->getDatosTablero()->estaCongelado()){
		tableroAsociado->getDatosTablero()->setCongeladoTurnoActual(false);
	}
}

void Portal::morir(){
	int fila = this->parcelaAsociada->getCoordenadaX();
	int columna = this->parcelaAsociada->getCoordenadaY();
	Tablero * tableroAsociado = this->parcelaAsociada->getTablero();
	tableroAsociado->getParcela(fila,columna).getCelula()->morir();
	tableroAsociado->getDatosTablero()->sumarCelulaMuerta();
	if(tableroAsociado->getDatosTablero()->estaCongelado()){
		tableroAsociado->getDatosTablero()->setCongeladoTurnoActual(false);
	}
}
