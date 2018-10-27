#ifndef CURSOR_H_
#define CURSOR_H_

#include"nodo.h"

template<class T> class Cursor{
private:
	Nodo<T>* posicionApuntada;
public:

	//Inicializa una instancia de la clase cursor apuntando al primer elemento de la lista pasada
	//por parametro
	Cursor(Nodo<T>* primerElementoLista){
		posicionApuntada = primerElementoLista;
	}

	//se pasa el cursor de al siguiente elemento de la lista
	void avanzar(){
		posicionApuntada = posicionApuntada->getSiguiente();
	}

	//devuelve un valor de verdad verdadero si el siguiente elemento al apuntado de la lista
	//no es nulo
	bool avanzarEsValido(){
		if (posicionApuntada->getSiguiente()) return true;
		else return false;
	}

	//devuelve la posicion a la que esta apuntando el cursor
	Nodo<T>* getPosicionApuntada(){
		return posicionApuntada;
	}

	//devuelve el dato guardado en la posicion apuntada
	T getDatoApuntado(){
		return posicionApuntada->getDato();
	}

};


#endif
