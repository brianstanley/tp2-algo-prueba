#ifndef NODO_H_
#define NODO_H_

//La clase nodo esta declarada como un template, por ese motivo es que su implementacion tambien esta declarada
//en este header.

template<class T> class Nodo{
private:

	T dato;
	Nodo* siguiente;
public:

	//Inicializa una instancia de la clase nodo con los el dato y el valor de siguiente indicados
	Nodo(T dato, Nodo *siguiente){
		this->dato = dato;
		this->siguiente = siguiente;
	}

	//Inicializa una instancia de la clase nodo con el dato pasado por parametro
	Nodo(T dato){
		this->dato = dato;
		this->siguiente = 0;
	}

	//Devuelve el dato almacenado en el nodo
	T getDato(){
		return dato;
	}

	//Devuelve el siguiente del nodo
	Nodo<T>* getSiguiente(){
		return siguiente;
	}

	//Reemplaza el dato del nodo por el dato pasado por parametro
	void setDato(T dato){
		this->dato = dato;
	}

	//Reemplaza el siguiente del nodo por el siguiente pasado por parametro
	void setSiguiente(Nodo *siguiente){
		this->siguiente = siguiente;
	}
};


#endif
