/*
 * RGB.cpp
 *
 *  Created on: Oct 18, 2018
 *      Author: german
 */

#include"RGB.h"

RGB::RGB(){
	this->red = 255;
	this->green = 255;
	this->blue = 255;
}

RGB::RGB(const RGB& RGBAClonar){
	this->red = RGBAClonar.red;
	this->green = RGBAClonar.green;
	this->blue = RGBAClonar.blue;
}

void RGB::calcularPromedioRGBes(const RGB& RGBA, const RGB& RGBB, const RGB& RGBC){
	this->red = (RGBA.red + RGBB.red + RGBC.red) / 3;
	this->green= (RGBA.green + RGBB.green + RGBC.green) / 3;
	this->blue = (RGBA.blue + RGBB.blue + RGBC.blue) / 3;
}
