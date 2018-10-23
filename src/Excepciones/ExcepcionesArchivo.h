/*
 * ExcepcionesArchivo.h
 *
 *  Created on: Oct 22, 2018
 *      Author: brian
 */

#ifndef SRC_EXCEPCIONES_EXCEPCIONESARCHIVO_H_
#define SRC_EXCEPCIONES_EXCEPCIONESARCHIVO_H_

class ExcepcionesArchivo {
public:
	/**
	 * pre: -
	 * pos: Lanza una excepción del tipo "no se puede abrir archivo"
	 */
	void noSePuedeAbrir();
	/**
	 * pre: -
	 * pos: Lanza una excepción del tipo "operacion invalida"
	 */
	void operacionInvalida();
};

#endif /* SRC_EXCEPCIONES_EXCEPCIONESARCHIVO_H_ */
