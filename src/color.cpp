/*
 * color.cpp
 *
 *  Created on: Oct 18, 2018
 *      Author: german
 */

#include"color.h"

Color::Color(){
	this->red = 255;
	this->green = 255;
	this->blue = 255;

}

Color::Color(const Color& ColorAClonar){
	this->red = ColorAClonar.red;
	this->green = ColorAClonar.green;
	this->blue = ColorAClonar.blue;
}

Color Color::calcularPromedioColores(const Color& colorA,const Color& colorB,const Color& colorC){
	Color colorARetornar = Color();
	colorARetornar.red = (colorA.red + colorB.red + colorC.red) / 3;
	colorARetornar.green = (colorA.green + colorB.green + colorC.green) / 3;
	colorARetornar.blue = (colorA.blue + colorB.blue + colorC.blue) / 3;
	return colorARetornar;
}
