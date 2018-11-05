/*
 * Celula.h
 *
 *  Created on: Oct 18, 2018
 *      Author: german
 */

#ifndef CELULA_H_
#define CELULA_H_

#include"RGB.h"

class Celula{
private:
	bool estadoCelula;
	float energiaCelula;
	RGB* RGBCelula;
public:
	/*pre: -
	 * post: se crea una celula muerta con RGB nulo y energia 0
	 */
	Celula();
	/*pre: -
	 * post: se setea el estado de la celula a vivo, la energia en funcion del
	 * factor de nacimiento de la parcela y con el RGB de la parcela
	 */
	void nacer(float factorNacimientoParcela, RGB* RGBParcela);

	/*pre: -
	* post: se le resta a la celula la energia correspondiente al factor de muerte de
	* su parcela asociada. si la celula muere se devuelve true, si no false
	*/
	bool restarEnergia(float factorMuerteParcela);

	/*pre: -
	 * post: se devuelve el RGB de la celula
	 */
	RGB* getRGB();
	/*pre: -
	 * post: se devuelve true si la celula esta viva y false en caso contrario
	 */
	bool getEstado();
};


#endif /* CELULA_H_ */
