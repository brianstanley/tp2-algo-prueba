/*
 * ParcelaAfectada.cpp
 *
 *  Created on: Oct 27, 2018
 *      Author: yorickvinesse
 */

#include "ParcelaAfectada.h"

ParcelaAfectada::ParcelaAfectada(CoordenadaParcela * coordenadaParcela) {
	coordenadaParcelaTocada = coordenadaParcela;
	parcelaTocada = coordenadaParcelaTocada.getTablero()->getParcela(coordenadaParcelaTocada.getCoordenadaX(), coordenadaParcelaTocada.getCoordenadaX());
	celulaNace = false;
	tipoDePortal = &(parcelaTocada.getPortal())->getTipoDePortal();

}

ParcelaAfectada::ParcelaAfectada(CoordenadaParcela * coordenadaParcela, RGB colorRecibido) {
	coordenadaParcelaTocada = coordenadaParcela;
	parcelaTocada = coordenadaParcelaTocada.getTablero()->getParcela(coordenadaParcelaTocada.getCoordenadaX(), coordenadaParcelaTocada.getCoordenadaX());
	celulaNace = true;
	tipoDePortal = &(parcelaTocada.getPortal())->getTipoDePortal();
	colorPromedioVecinos = colorRecibido;
}
