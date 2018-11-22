#include "../Listas/ListaEnlazada.h"
#include "Arista.h"
#include "../Tablero/Tablero.h"

class Grafo{
private:
	int cantidadVertices;
	Arista* MatrizDegrafo;
	ListaEnlazada<Tablero*>* listaDeVertices;

public:

	/*
	 * pre: la cantidad de vertices pasada por parametro debe ser mayor a 0
	 * post: se crea una iteracion de la clase grafo con todo en 0
	 */
	Grafo();

	/*
	 * pre: se tienen todos los vertices que queremos usar en el grafo
	 * post: se crea una matriz que contabiliza las aristas entre los vertices del grafo
	 */
	void crearMatrizGrafo();

	/*
	 * pre: -
	 * post: se agrega un vertice a la lista de vertices
	 */
	void agregarVertice(Tablero* tableroAsociado);

	//void eliminarVertice


};
