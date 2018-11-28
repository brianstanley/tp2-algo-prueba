#ifndef SRC_GRAFO_RECORRIDOTABLERO_H_
#define SRC_GRAFO_RECORRIDOTABLERO_H_

#include "Arista.h"
#include <string>

class RecorridoTablero {
private:
	int peso;
	bool recorridoPosible;
	Vertice * verticeOrigen;
	Vertice * verticeDestino;
	std::string recorrido;

public:

	/*
	 * pre: -
	 * post: inicializa el recorrido como imposible y setea los valores de origen y de destino.
	 * Pone el primer tablero del recorrido como string en recorrido
	 */
	RecorridoTablero(Vertice * verticeDeOrigen, Vertice* verticeDeDestino);

	/*
	 * pre: Se puede llamar solo si el recorrido esta posible
	 * pos: devuelve el recorrido entre origen y destino.
	 */
	std::string getRecorrido();

	/*
	 * pre: Se puede llamar solo si el recorrido esta posible
	 * pos: devuelve el peso del recorrido entre origen y destino.
	 */
	int getPesoRecorrido();

	/*
	 * pre:
	 * post: setea recorridoPosible a true si el verticeDeTransito es lo de destino.
	 */
	void agregarVerticeAlRecorrido(Vertice * verticeDeTransito);

	/*
	 * pre: -
	 * post: actualiza el peso del recorrido. Siempre va bajandose o manteniendose.
	 */
	void actualizarPeso(int pesoActualizado);

	/*
	 * pre: -
	 * post: devuelve true si el recorrido es posible, false si no.
	 */
	bool esPosibleElRecorrido();

	/*
	 * pre: se llama cuando se encuentra un vertice de transito que es igual al vertice de destino
	 * post: set el recorrido a posible.
	 */
	void setPosibleElRecorrido();

};

#endif /* SRC_GRAFO_RECORRIDOTABLERO_H_ */
