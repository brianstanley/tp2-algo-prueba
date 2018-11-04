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

void Portal::accionarPortal(bool nace, RGB* color, float factorNacimientoOrigen, float factorMuerteOrigen){
	if(this->tipoDePortal == ACTIVO){
		if(this->portalOrigen){
			if(nace){
				this->nacer(color, factorNacimientoOrigen);
			}
			else{
				this->morir(factorMuerteOrigen);
			}
		}
		else if (!nace){
			this->morir(factorMuerteOrigen);
		}
	}
	else if(this->tipoDePortal == NORMAL){
		if(this->portalOrigen){
			if(nace){
				this->nacer(color, factorNacimientoOrigen);
			}
			else{
				this->morir(factorMuerteOrigen);
			}
		}
	} else if(this->portalOrigen  && nace) { //Pasivo
		this->nacer(color, factorNacimientoOrigen);
	}
}

void Portal::nacer(RGB* color, bool factorNacimientoOrigen){
	int fila = this->parcelaAsociada->getCoordenadaX();
	int columna = this->parcelaAsociada->getCoordenadaY();
	Tablero * tableroAsociado = this->parcelaAsociada->getTablero();
	tableroAsociado->getParcela(fila,columna).getCelula()->nacer(factorNacimientoOrigen,color);
	tableroAsociado->getDatosTablero()->sumarCelulaViva();
	if(tableroAsociado->getDatosTablero()->estaCongelado()){
		tableroAsociado->getDatosTablero()->setCongeladoTurnoActual(false);
	}
}

void Portal::morir(bool factorMuerteOrigen){
	int fila = this->parcelaAsociada->getCoordenadaX();
	int columna = this->parcelaAsociada->getCoordenadaY();
	Tablero * tableroAsociado = this->parcelaAsociada->getTablero();
	bool murio = tableroAsociado->getParcela(fila,columna).getCelula()->restarEnergia(factorMuerteOrigen);
	if (murio){
		tableroAsociado->getDatosTablero()->sumarCelulaMuerta();
	}
	if(tableroAsociado->getDatosTablero()->estaCongelado()){
		tableroAsociado->getDatosTablero()->setCongeladoTurnoActual(false);
	}
}
