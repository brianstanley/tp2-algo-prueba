#include "../Portal/ParcelaAfectada.h"

ParcelaAfectada::ParcelaAfectada(CoordenadaParcela * coordenadaParcela) {
	coordenadaParcelaTocada = coordenadaParcela;
	Portal * portalAsociado = coordenadaParcela->getParcela().getPortal();
	celulaNace = false;
	tienePortal = false;
	if (portalAsociado) {
		tienePortal = true;
	}
	colorPromedioVecinos = 0;
}

ParcelaAfectada::ParcelaAfectada(CoordenadaParcela * coordenadaParcela,
		RGB* colorRecibido) {
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

Tablero* ParcelaAfectada::getTablero(){
	return this->coordenadaParcelaTocada->getTablero();
}

bool ParcelaAfectada::naceLaCelula() {
	return this->celulaNace;
}

bool ParcelaAfectada::hayPortal() {
	return this->tienePortal;
}

RGB* ParcelaAfectada::getColorPromedio() {
	return this->colorPromedioVecinos;
}
