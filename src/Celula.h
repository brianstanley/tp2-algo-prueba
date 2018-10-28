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
	int energiaCelula;
	RGB RGBCelula;
public:
	/*pre: -
	 * post: se crea una celula muerta con RGB nulo y energia 0
	 */
	Celula();
	/*pre: -
	 * post: se crea una celula viva con el RGB y su enerigia relativa al
	factor de nacimiento de la parcela a la que pertenece
	*/
	Celula(float factorNacimiento, RGB RGBParcela);
	/*pre: -
	 * post: se setea el estado de la celula a muerto y la energia a 0
	 */
	void morir();
	/*pre: -
	 * post: se setea el estado de la celula a vivo ,la energia en funcion del factor de
	nacimiento de la parcela y el RGB como fruto del promedio de los RGBes de las
	tres celulas circundantes
	*/
	void nacer(float factorNacimiento, RGB* RGBA, RGB* RGBB, RGB* RGBC);
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
