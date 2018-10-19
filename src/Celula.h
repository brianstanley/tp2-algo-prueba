/*
 * Celula.h
 *
 *  Created on: Oct 18, 2018
 *      Author: german
 */

#ifndef CELULA_H_
#define CELULA_H_

#include"color.h"

class Celula{
private:
	bool estadoCelula;
	int energiaCelula;
	Color colorCelula; //Para la implementacion de los colores de la celula y parcela
					   //propongo la clase Color
public:
	//post: se crea una celula muerta con color nulo y energia 0
	Celula();
	//post: se crea una celula viva con el color y su enerigia relativa al
	//factor de nacimiento de la parcela a la que pertenece
	Celula(float factorNacimiento, Color colorParcela);
	//post: se setea el estado de la celula a muerto y la energia a 0
	void morir();
	//post: se setea el estado de la celula a vivo ,la energia en funcion del factor de
	//nacimiento de la parcela y el color como fruto del promedio de los colores de las
	//tres celulas circundantes
	void nacer(float factorNacimiento, const Color& colorA, const Color& colorB, const Color& colorC);
	//post: se devuelve el color de la celula
	const Color& getColor();
	//post: se devuelve true si la celula esta viva y false en caso contrario
	bool getEstado();
};


#endif /* CELULA_H_ */
