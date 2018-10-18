/*
 * Parcela.h
 *
 *  Created on: Oct 17, 2018
 *      Author: brian
 */

#ifndef PARCELA_H_
#define PARCELA_H_
#include <string>

class Parcela {
private:
	std::string color;
	void setColor();
	int numero;
public:
	Parcela();
	virtual ~Parcela();
};

#endif /* PARCELA_H_ */
