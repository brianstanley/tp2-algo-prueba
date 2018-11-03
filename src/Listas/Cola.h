#ifndef COLA_H_
#define COLA_H_

#include <string>
#include "Nodo.h"

template<class T> class Cola {

private:

	Nodo<T>* frente;

	Nodo<T>* fondo;

public:

	/*
	 * post: instancia de Cola vacía y lista para ser usada.
	 */
	Cola();

	/*
	 * post: devuelve si la Cola no tiene ningún elemento.
	 */
	bool estaVacia();

	/*
	 * post: agrega 'elemento' en el fondo de la Cola.
	 */
	void acolar(T elemento);

	/*
	 * pre : la Cola no está vacía.
	 * post: remueve el frente de la Cola y lo devuelve.
	 */
	T desacolar();

	/*
	 * pre : la Cola no está vacía.
	 * post: devuelve el frente de la Cola.
	 */
	T obtenerFrente();

	/*
	 * post: remueve todos los elementos y libera
	 *       los recursos tomados por la estructura de datos.
	 */
	~Cola();
};

template<class T>
Cola<T>::Cola() {

	this->frente = NULL;
	this->fondo = NULL;
}

template<class T>
bool Cola<T>::estaVacia() {

	return (this->frente == NULL);
}

template<class T>
void Cola<T>::acolar(T elemento) {

	Nodo<T>* nuevoFondo = new Nodo<T>(elemento);

	if (this->estaVacia()) {
		this->frente = nuevoFondo;

	} else {
		this->fondo->setSiguiente(nuevoFondo);
	}

	this->fondo = nuevoFondo;
}

template<class T>
T Cola<T>::desacolar() {

	if (this->estaVacia()) {
		throw std::string("No se puede desacolar, la cola está vacía.");
	}

	/* remueve el frente de la estructura */
	Nodo<T>* frenteAnterior = this->frente;
	this->frente = frenteAnterior->getSiguiente();

	if (this->frente == NULL) {
		this->fondo = NULL;
	}

	/* devuelve el elemento y libera los recursos asociados */
	T elemento = frenteAnterior->getDato();
	delete frenteAnterior;

	return elemento;
}

template<class T>
T Cola<T>::obtenerFrente() {

	if (this->estaVacia()) {
		throw std::string("No se puede obtener el frente, la cola está vacía.");
	}

	T elemento = this->frente->obtenerDato();

	return elemento;
}

template<class T>
Cola<T>::~Cola() {

	while (! this->estaVacia()) {

		this->desacolar();
	}
}



#endif /* COLA_H_ */
