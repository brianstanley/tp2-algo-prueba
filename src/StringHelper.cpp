/*
 * funciones_transformar_int_string.cpp
 *
 *  Created on: Oct 24, 2018
 *      Author: german
 */
#include "StringHelper.h"

std::string StringHelper::enteroIndividualAString (int entero){
	switch (entero){
		case 1:
 		return "1";

 		case 2: {
 		return "2";
 		}

 		case 3: {
 		return "3";
 		}

 		case 4: {
 		return "4";
 		}

 		case 5: {
 		return "5";
 		}

 		case 6: {
 		return "6";
 		}

 		case 7: {
 		return "7";
 		}

 		case 8: {
 		return "8";
 		}

 		case 9: {
 		return "9";
 		}

 		case 0: {
 		return "0";
 		}
	}
	return 0;
}

void StringHelper::enteroAString(std::string& enteroString, int entero){
	if ((entero/FACTOR) > 0){
		this->enteroAString(enteroString, (entero - (entero % FACTOR))/10);
	}
	enteroString = enteroString + this->enteroIndividualAString(entero % FACTOR);
}


std::string StringHelper::aMinuscula(std::string data) {
	std::transform(data.begin(), data.end(), data.begin(), ::tolower);
	return data;
}
