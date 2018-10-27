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
	DatosPartida();
	/*
	 *pre:
	 *post:
	 */
	int getCantidadCelulasVivas();
	/*
	*pre:
	*post:
	*/
	void sumarCelulaViva();
	/*
	*pre:
	*post:
	*/
	void sumarCelulaMuerta();
	/*
	*pre:
	*post:
	*/
	int getNacidasTotal();
	/*
	*pre:
	*post:
	*/
	int getMuertasTotal();
	/*
	*pre:
	*post:
	*/
	float getPromedioNacidas();
	/*
	 *pre:
	*post:
	*/
	float getPromedioMuertas();
	/*
	*pre:
	*post:
	*/
	virtual ~DatosPartida();
};

#endif /* SRC_DATOSPARTIDA_H_ */
