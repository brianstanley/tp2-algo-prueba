#include "../Celula/Celula.h"

Celula::Celula() {
	this->estadoCelula = MUERTA;
	this->energiaCelula = 0;
	this->RGBCelula = new RGB;
}

bool Celula::restarEnergia(float factorMuerteParcela) {
	bool murio = true;
	int energiaAPerder = ENERGIA_MAX * factorMuerteParcela;
	if (this->energiaCelula > energiaAPerder) {
		this->energiaCelula -= energiaAPerder;
		murio = false;
	} else {
		this->energiaCelula = 0;
		this->estadoCelula = MUERTA;
	}
	return murio;
}

void Celula::nacer(float factorNacimientoParcela, RGB* RGBParcela) {
	this->estadoCelula = VIVA;
	this->energiaCelula = ENERGIA_MAX * factorNacimientoParcela;
	this->RGBCelula->setRGB(RGBParcela->getRed(), RGBParcela->getGreen(), RGBParcela->getBlue());
}

RGB* Celula::getRGB() {
	return this->RGBCelula;
}

bool Celula::getEstado() {
	return this->estadoCelula;
}

Celula::~Celula(){
	if (this->RGBCelula){
		delete this->RGBCelula;
	}
}
