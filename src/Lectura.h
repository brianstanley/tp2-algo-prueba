/*
 * Lectura.h
 *
 *  Created on: Oct 21, 2018
 *      Author: brianstanley
 */

#ifndef SRC_LECTURA_H_
#define SRC_LECTURA_H_
#include <iostream>

class Lectura {
public:
	Lectura();
	int leerConfig(std::string);
	virtual ~Lectura();
};

#endif /* SRC_LECTURA_H_ */
