/*
 * ParcelaAfectada.h
 *
 *  Created on: Oct 27, 2018
 *      Author: yorickvinesse
 */

#ifndef SRC_PARCELAAFECTADA_H_
#define SRC_PARCELAAFECTADA_H_


#include "RGB.h"
#include "CoordenadaParcela.h"
#include "Parcela.h"

/*
 * La clase ParcelaAfectada crea instancias de las parcelas que son afectadas por el cambio del proximo turno.
 * Contiene la parcela y almacena los datos necesarios a la actualizacion:
 * nace o muere? qué tipo de portal es? el color de los vecinos.
 * El objetivo es armar una lista de esas parcelas de origen. Las parcelas asociadas con portal seran cambiadas
 * justo después las células de origen con las mismas caracteristicas, por eso no es necesario almacenarlas todas.
 */

class ParcelaAfectada {

private:
	CoordenadaParcela * coordenadaParcelaTocada;
	bool celulaNace; //permite saber si hacemos un promedio de los colores vecinos o no.
	bool tienePortal;
	RGB colorPromedioVecinos;


public:
	/*
	 * Caso cuando muere, no ponemos los colores de los vecinos en argumento.
	 * Este constructor se fija si hay un portal asociado. En el caso de que haya, asigna el char correspondiente
	 * a tipoDePortal. Si no, el tipoDeportal esta inicializado a NOPORTAL.
	 */
	ParcelaAfectada(CoordenadaParcela * coordenadaParcela);

	/*
	 * Sobrecarga de la ParcelaAfectada cuando la célula nace, ingresamos los colores de los vecinos.
	 */
	ParcelaAfectada(CoordenadaParcela * coordenadaParcela, RGB colorRecibido);

	Parcela & getParcela();

	bool naceLaCelula();

	bool hayPortal();

	RGB getColorPromedio();
};


#endif /* SRC_PARCELAAFECTADA_H_ */
