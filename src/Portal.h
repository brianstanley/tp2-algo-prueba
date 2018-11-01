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

	/*
	 *
	 *
	 */
	void accionarPortalActivo(bool nace, RGB* color);

	/*
	 *
	 *
	 */
	void accionarPortalNormal(bool nace, RGB* color);

	/*
	 *
	 *
	 */
	void accionarPortalPasivo(bool nace, RGB* color);

	/*
	 *
	 */
	void nacioOrigenEntoncesNaceDestino(RGB* color);

	/*
	 *
	 */
	void murioOrigenEntoncesMuereDestino();

	/*
	 *
	 */
	void murioDestinoEntoncesMuereOrigen();
public:
	Portal(bool esPortalDeOrigen, char tipoDelPortal,
			CoordenadaParcela * parcelaPareja);

	char getTipoDePortal();

	CoordenadaParcela * getCoordenadaAsociada();

	/*
	 * pre: -
	 * post: de acuerdo con el tipo de portal, hace cambios en el tablero de origen y destino
	 */

	/*
	 * pre:-
	 * post:
	 */
	void accionarPortal(bool nace, RGB* color);



};

#endif /* PORTAL_H_ */
