/*
 * Portal.h
 *
 *  Created on: 21 oct. 2018
 *      Author: yorickvinesse
 */

#ifndef PORTAL_H_
#define PORTAL_H_
#include "CoordenadaParcela.h"

const char ACTIVO = 'A';
const char NORMAL = 'N';
const char PASIVO = 'P';
const char NOPORTAL = '-';

class CoordenadaParcela;
/*
 * La clase Portal esta siempre asociada con una parcela, por lo tanto no lleva las coordenadas de la parcela.
 *
 */

class Portal {

private:

	/*
	 * Cada portal esta asociado con una parcela, entonces no es necesario definir las coordenadas del mismo.
	 * Sin embargo, necesitamos definir les coordenadas de la parcela asociada.
	 * Por eso usamos la clase CoordenadaParcela. Con el booleano portalOrigen definimos si el portal origino en
	 * la dicha parcela (true) o en la parcela asociada (false).
	 */

	/*
	 * En el futuro necesitamos usar un puntero para apuntar al portal asociado.
	 */
	bool portalOrigen;
	char tipoDePortal;
	CoordenadaParcela * parcelaAsociada;

	void nacer(RGB* color, bool factorNacimientoOrigen);

	void morir(bool factorMuerteOrigen);
public:
	/*
	 * pre: -
	 * post: se crea una instancia de portal
	 */
	Portal(bool esPortalDeOrigen, char tipoDelPortal, CoordenadaParcela * parcelaPareja);

	/*
	 * pre: -
	 * post: se devuelve el tipo de portal
	 */
	char getTipoDePortal();

	/*
	 * pre: -
	 * post: se acciona el portal correspondiente
	 */
	void accionarPortal(bool nace, RGB* color, float factorNacimientoOrigen, float factorMuerteOrigen);
};

#endif /* PORTAL_H_ */
