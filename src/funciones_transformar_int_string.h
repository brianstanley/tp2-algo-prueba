/*
 * funciones_transformar_int_string.h
 *
 *  Created on: Oct 24, 2018
 *      Author: german
 */

#ifndef FUNCIONES_TRANSFORMAR_INT_STRING_H_
#define FUNCIONES_TRANSFORMAR_INT_STRING_H_

#include<iostream>
#include<string>

const int factor = 10;

/*
 * post: la funcion debe recibir un entero entre 0 y 9 inclusive
 * pre: la funcion devuelve el string que representa el entero que recibio por parametro
 */
std::string enteroIndividualAString(int num);

/*
 * pre: la funcion debe recibir un string vacio (lease string = "")
 * post: la funcion devuelve el string que representa el entero que recibio por parametro
 */
void enteroAString(std::string& enteroString, int entero);


#endif /* FUNCIONES_TRANSFORMAR_INT_STRING_H_ */
