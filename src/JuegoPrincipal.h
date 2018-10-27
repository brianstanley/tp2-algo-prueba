/*
 * JuegoPrincipal.h
 *
 *  Created on: 27 oct. 2018
 *      Author: nazareno
 */

#ifndef SRC_JUEGOPRINCIPAL_H_
#define SRC_JUEGOPRINCIPAL_H_

#include<Tablero.h>

class JuegoPrincipal {
private:
	Lista<Tablero> tableros;
public:
	JuegoPrincipal();
	virtual ~JuegoPrincipal();
};

#endif /* SRC_JUEGOPRINCIPAL_H_ */
