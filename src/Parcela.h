/*
 * Parcela.h
 *
 *  Created on: Oct 17, 2018
 *      Author: brian
 */

#ifndef SRC_PARCELA_H_
#define SRC_PARCELA_H_

#include "Celula.h"
#include "Portal.h"
#include "RGB.h"
#include "CoordenadaParcela.h"

class CoordenadaParcela;
class Portal;
int const FACTOR_NACIMIENTO_DEFAULT = 255;
int const FACTOR_MUERTE_DEFAULT = 255;

class Parcela {

private:
	CoordenadaParcela * coordenadaParcela;
	Celula * celula;
	Portal * portal;
	float factorNacimiento;
	float factorMuerte;
	RGB RGBParcela;
public:
	/*
	 * pre:-
	 * post: Inicializa todos los miembros de la clase
	 * apuntando los punteros a NULL
	 */
	Parcela();
	/*
	 * pre: Puntero a una objeto portal
	 * post: Se modifica el miembro puntero a portal.
	 */
	void setPortal(Portal * portal);
	/*
	 * pre: -
	 * post: retorna un puntero al objeto CoordenadaParcela
	 * asociado a la parcela.
	 */
	CoordenadaParcela * getCoordenadaParcela();
	/*
	 * pre: -
	 * post: retorna un puntero a la celula asociada a la parcela.
	 */
	Celula * getCelula();
	/*
	 * pre:  la parcela posee un portal
	 * post: retorna el portal asociado a la parcela.
	 */
	Portal * getPortal();

	/**
	 * pre: Numero mayor a cero
	 * pos: Modifica el atributo factor nacimiento
	 * de la parcela.
	 */
	void setFactorNacimiento(float);

	/**
	 * pre: Numero mayor a cero
	 * pos: Modifica el atributo factor muerte
	 * de la parcela.
	 */
	void setFactorMuerte(float);
	/*pre: -
	 * post: retorna el factor de nacimiento de la parcela.
	 */
	float getfactorNacimiento();
	/*pre: -
	 * post: retorna el factor de muerte de la parcela.
	 */
	float getfactorMuerte();
	/**
	 * pre: Puntero a un objeto CoordenadaParcela
	 * pos: Modifica el atributo coordenadaParcela
	 */
	void setCoordenadaParcela(CoordenadaParcela * coordenadaParcela);
	/**
	 * pre: objeto del tipo RGB
	 * pos: Modifica el atributo RGBParcela
	 */
	void setRBGparcela(RGB RGBParcela);

	/*
	 * pre: -
	 * post: retorna el RGB de la parcela.
	 */
	RGB getRBGparcela();

};
#endif /* SRC_PARCELA_H_ */

