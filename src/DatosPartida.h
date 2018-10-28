/*
 * DatosPartida.h
 *
 *  Created on: 27 oct. 2018
 *      Author: nazareno
 */

#ifndef SRC_DATOSPARTIDA_H_
#define SRC_DATOSPARTIDA_H_

class DatosPartida {
private:
	int cantidadCelulasVivas;
	int nacidasTotal;
	int muertasTotal;
	float promedioNacidas;
	float promedioMuertas;

public:
	/*
	 * pre: -
	 * post:inicializa una instancia de DatosPartida con los valores en 0
	 */
	DatosPartida();
	/*
	 *pre: -
	 *post: devueleve el valor de la cantidadCelulasVivas
	 */
	int getCantidadCelulasVivas();
	/*
	*pre: -
	*post: contabiliza un nacimiento de celula
	*/
	void sumarCelulaViva();
	/*
	*pre: -
	*post: contabiliza una muerte de celula
	*/
	void sumarCelulaMuerta();
	/*
	*pre: -
	*post: devueleve el valor de nacidasTotal
	*/
	int getNacidasTotal();
	/*
	*pre: -
	*post: devueleve el valor de muertasTotal
	*/
	int getMuertasTotal();
	/*
	*pre: -
	*post: devueleve el valor de promedioNacidas
	*/
	float getPromedioNacidas();
	/*
	 *pre: -
	*post: devueleve el valor de promedioMuertas
	*/
	float getPromedioMuertas();
};

#endif /* SRC_DATOSPARTIDA_H_ */
