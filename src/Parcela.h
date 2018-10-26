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

class Parcela {
private:
	CoordenadaParcela coordenadaParcela;
	Celula celula;
	Portal portal;
	float factorNacimiento;
	float factorMuerte;
	RGB RGBParcela;

public:
	/*pre: la coordenada ha sido generada
	 * post: se crea una parcela con su correspondiente coordenada,
	 * una celula muerta y sin portal.
	 */
	Parcela(CoordenadaParcela coordenadaParcela, float factorNacimiento,
			float factorMuerte, RGB RGBParcela);
	/*pre: -
	 *post: se crea un portal asociado a la parcela
	 */
	void setPortal(bool esPortalDeOrigen, char tipoDelPortal,
			CoordenadaParcela * parcelaPareja);
	/*pre: -
	 * post: retorna el objeto coordenada asociado a la parcela.
	 */
	CoordenadaParcela getCoordenadaParcela();
	/*pre: -
	 * post: retorna la celula asociada a la parcela.
	 */
	Celula getCelula();
	/*pre: la parcela posee un portal
	 * post: retorna el portal asociado a la parcela.
	 */
	Portal getPortal();
	/*pre: -
	 * post: retorna el factor de nacimiento de la parcela.
	 */
	float getfactorNacimiento();
	/*pre: -
	 * post: retorna el factor de muerte de la parcela.
	 */
	float getfactorMuerte();
	/*pre: -
	 * post: retorna el RGB de la parcela.
	 */
	RGB getRBGparcela();

}
#endif /* SRC_PARCELA_H_ */

