#ifndef LISTA_H_
#define LISTA_H_

#include"cursor.h"

template<class T> class Lista{

private:

	Nodo<T>* primero;

	//Setea el nodo anterior del que se quiere eliminar a su siguiente y libera los recursos
	//utilizados por el nodo a eliminar
	void baja(Nodo<T>* nodoAEliminar, Nodo<T>* nodoAnteriorAEliminar){
		nodoAnteriorAEliminar->setSiguiente(nodoAEliminar->getSiguiente());
		delete nodoAEliminar;
	}

	//Sobrecarga de "baja" que esta hecha para eliminar al primer elemento de una lista sin causar
	//complicaciones
	void baja(Nodo<T>* nodoAEliminar){
		primero = primero->getSiguiente();
		delete nodoAEliminar;
	}
public:

	//Constructor que inicializa una instancia de lista con el primer elemento apuntando al nulo
	Lista(){
		primero = 0;
	}

	//Añade un elemento al final de la lista (para retocar)
	void altaFinal(T dato){
		if (this->primero){
			Cursor<T> cursor (this->primero);
			while (cursor.avanzarEsValido()){
				cursor.avanzar();
			}
			Nodo<T>* nuevoNodo = new Nodo<T>(dato);
			Nodo<T>* nodoApuntadoCursor = cursor.getPosicionApuntada();
			nodoApuntadoCursor->setSiguiente(nuevoNodo);
		}
		else{
			Nodo<T>* nuevoNodo = new Nodo<T>(dato);
			this->primero = nuevoNodo;
		}
	}

	//Añade un elemento al principio de la lista (para retocar)
	void altaPrincipio(T dato){
		Nodo<T>* nuevoNodo = new Nodo<T>(dato, primero);
		primero = nuevoNodo;
	}

	//Elimina el elmento pasado por parametro en caso de que se encuentre en la lista
	void bajaElemento(T dato){
		if (primero->getDato() == dato){
			baja(primero);
		}
		else{
			Cursor<T> cursorActual = Cursor<T>(this->primero);
			cursorActual.avanzar();
			Cursor<T> cursorAnterior = Cursor<T>(this->primero);
			while (cursorActual.getPosicionApuntada()){
				if (cursorActual.getDatoApuntado() == dato){
					baja(cursorActual.getPosicionApuntada(), cursorAnterior.getPosicionApuntada());
				}
				cursorActual.avanzar();
				cursorAnterior.avanzar();
			}
		}
	}

	//Devuelve un valor de verdad positivo si el elemento pasado por parametro se encuentra en la lista
	//Si el elemento no se encuentra en la lista devuelve un valor de verdad negativo
	bool esta(T dato){
		Cursor<T> cursor = Cursor<T>(this->primero);
		while(cursor.getPosicionApuntada()){
			if (cursor.getDatoApuntado() == dato) return true;
			cursor.avanzar();
		}
		return false;
	}

	//Libera todos los recursos utilizados en la implementacion de la lista
	~Lista(){
		if (primero){
			Nodo<T>* auxiliar = primero;
			Nodo<T>* iterador = primero;
			while (auxiliar){
				iterador = iterador->getSiguiente();
				delete auxiliar;
				auxiliar = iterador;
			}
		}
	}

};

#endif
