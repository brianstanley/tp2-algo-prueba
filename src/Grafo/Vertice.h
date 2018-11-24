#include "../Listas/ListaEnlazada.h"
#include "Arista.h"

class Vertice{
private:
	ListaEnlazada<Arista*> AristasDelGrafo;
	Tablero* pesoVertice;
};
