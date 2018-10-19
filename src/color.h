/*
 * color.h
 *
 *  Created on: Oct 18, 2018
 *      Author: german
 */

#ifndef COLOR_H_
#define COLOR_H_

class Color{
private:
	int red;
	int green;
	int blue;
public:
	//post: se crea una instancia de la clase color con los valores rgbd
	//seteados a 255 (blanco, seria como un estado "neutro")
	Color();
	//post: se crea una instancia de la clase color identica a la que se pasa por parametro
	Color(const Color& colorAClonar);
	//post: se devuelve un color que es el promedio de los tres colores pasados por paremetro
	Color calcularPromedioColores(const Color& colorA,const Color& colorB,const Color& colorC);
};


#endif /* COLOR_H_ */
