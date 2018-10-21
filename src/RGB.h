/*
 * RGB.h
 *
 *  Created on: Oct 18, 2018
 *      Author: german
 */

#ifndef RGB_H_
#define RGB_H_

class RGB{
private:
	int red;
	int green;
	int blue;
public:
	/*pre: -
	 * post: se crea una instancia de la clase RGB con los valores rgbd
	seteados a 255 (blanco, seria como un estado "neutro")
	*/
	RGB();
	/*pre: -
	 * post: se crea una instancia de la clase RGB identica a la que se pasa por parametro
	 */
	RGB(const RGB& RGBAClonar);
	/*pre: -
	 * post: se devuelve un RGB que es el promedio de los tres RGBes pasados por paremetro
	 */
	void calcularPromedioRGBes(const RGB& RGBA, const RGB& RGBB, const RGB& RGBC);
};


#endif
