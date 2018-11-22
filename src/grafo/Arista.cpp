#include "Arista.h"

Arista::Arista(){
	this->estadoArista = DESACTIVADA;
	this->pesoArista = PESO_ARISTA_NULA;
}

void Arista::Activar(){
	this->estadoArista = ACTIVADA;
}

void Arista::Desctivar(){
	this->estadoArista = DESACTIVADA;
}

void Arista::SumarPeso(int pesoASumar){
	this->pesoArista += pesoASumar;
}
