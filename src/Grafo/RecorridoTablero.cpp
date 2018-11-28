#include "RecorridoTablero.h"

RecorridoTablero::RecorridoTablero(Vertice* verticeDeOrigen,
		Vertice* verticeDeDestino) {
	this->peso = NULL;
	this->recorridoPosible = false;
	this->verticeOrigen = verticeDeOrigen;
	this->verticeDestino = verticeDeDestino;
	this->recorrido = verticeDeOrigen->getTableroAsociado()->getNombre();

}

std::string RecorridoTablero::getRecorrido() {
	return this->recorrido;
}

int RecorridoTablero::getPesoRecorrido() {
	return this->peso;
}

void RecorridoTablero::agregarVerticeAlRecorrido(Vertice* verticeDeTransito) {
	this->recorrido.append(" ");
	this->recorrido.append(verticeDeTransito->getTableroAsociado()->getNombre());
	if ((verticeDeTransito == this->verticeDestino) && !esPosibleElRecorrido()) {
		setPosibleElRecorrido();
	}
}

void RecorridoTablero::actualizarPeso(int pesoActualizado) {
	this->peso = pesoActualizado;
}

bool RecorridoTablero::esPosibleElRecorrido() {
	return this->recorridoPosible;
}

void RecorridoTablero::setPosibleElRecorrido() {
	this->recorridoPosible = true;
}
