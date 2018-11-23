#ifndef LISTA_H_
#define LISTA_H_

#include "Nodo.h"


template<class T> class ListaEnlazada {

    private:

        Nodo<T>* primero;

        unsigned int tamanio;

        Nodo<T>* cursor;

    public:

        /*
         * post: Lista vacía.
         */
        ListaEnlazada();

        /*
         * post: Lista que tiene los mismos elementos que otraLista.
         *       La instancia resulta en una copia de otraLista.
         */
        ListaEnlazada(ListaEnlazada<T>& otraLista);

        /*
         * post: indica si la Lista tiene algún elemento.
         */
        bool estaVacia();

        /*
         * post: devuelve la cantidad de elementos que tiene la Lista.
         */
        unsigned int contarElementos();

        /*
         * post: agrega el elemento al final de la Lista, en la posición:
         *       contarElementos() + 1.
         */
        void agregar(T elemento);

        /*
         * pre : posición pertenece al intervalo: [1, contarElementos() + 1]
         * post: agrega el elemento en la posición indicada.
         *
         */
        void agregar(T elemento, unsigned int posicion);

        /*
         * post: agrega todos los elementos de otraLista
         *       a partir de la posición contarElementos() + 1.
         */
        void agregar(ListaEnlazada<T> &otraLista);

        /*
         * pre : posición pertenece al intervalo: [1, contarElementos()]
         * post: devuelve el elemento en la posición indicada.
         */
        T obtener(unsigned int posicion);

        /*
         * pre : posicioó pertenece al intervalo: [1, contarElementos()]
         * post: cambia el elemento en la posición indicada por el
         *       elemento dado.
         */
        void asignar(T elemento, unsigned int posicion);

        /*
         * pre:
         * post: se devuelve la posicion del elemento en la lista, si el elemento
         * pasado no esta en la lista se devuelve 0
         */
        unsigned int obtenerPosicion(T elemento);

        /*
         * pre : posición pertenece al intervalo: [1, contarElementos()]
         * post: remueve de la Lista el elemento en la posición indicada.
         */
        void remover(unsigned int posicion);

        /*
         * post: deja el cursor de la Lista preparado para hacer un nuevo
         *       recorrido sobre sus elementos.
         */
        void iniciarCursor();

        /*
         * pre : se ha iniciado un recorrido (invocando el método
         *       iniciarCursor()) y desde entonces no se han agregado o
         *       removido elementos de la Lista.
         * post: mueve el cursor y lo posiciona en el siguiente elemento
         *       del recorrido.
         *       El valor de retorno indica si el cursor quedó posicionado
         *       sobre un elemento o no (en caso de que la Lista esté vacía o
         *       no existan más elementos por recorrer.)
         */
        bool avanzarCursor();

        /*
         * pre : el cursor está posicionado sobre un elemento de la Lista,
         *       (fue invocado el método avanzarCursor() y devolvió true)
         * post: devuelve el elemento en la posición del cursor.
         *
         */
        T obtenerCursor();

        /*
         * post: libera los recursos asociados a la Lista.
         */
        ~ListaEnlazada();

        /*
         * pre: -
         * post: si el elemento pasado por parametro esta en la lista se devuelve true, en caso contrario se devuelve false
         */
        bool esta(T elemento);

    private:

        /*
         * pre : posición pertenece al intervalo: [1, contarElementos()]
         * post: devuelve el nodo en la posición indicada.
         */
        Nodo<T>* obtenerNodo(unsigned int posicion); // NOTA: primitiva PRIVADA
};

template<class T> ListaEnlazada<T>::ListaEnlazada() {
    this->primero = NULL;
    this->tamanio = 0;
    this->cursor = NULL;
}

template<class T> ListaEnlazada<T>::ListaEnlazada(ListaEnlazada<T>& otraLista) {

    this->primero = NULL;
    this->tamanio = 0;
    this->cursor = NULL;

    /* copia los elementos de otraLista */
    this->agregar(otraLista);
}

template<class T> bool ListaEnlazada<T>::estaVacia() {

    return (this->tamanio == 0);
}

template<class T> unsigned int ListaEnlazada<T>::contarElementos() {

    return this->tamanio;
}

template<class T> void ListaEnlazada<T>::agregar(T elemento) {

    this->agregar(elemento, this->tamanio + 1);

}

template<class T> void ListaEnlazada<T>::agregar(T elemento, unsigned int posicion) {

    if ((posicion > 0) && (posicion <= this->tamanio + 1)) {

        Nodo<T>* nuevo = new Nodo<T>(elemento);

        if (posicion == 1) {

            nuevo->cambiarSiguiente(this->primero);
            this->primero = nuevo;

        } else {

            Nodo<T>* anterior = this->obtenerNodo(posicion - 1);
            nuevo->cambiarSiguiente(anterior->obtenerSiguiente());
            anterior->cambiarSiguiente(nuevo);
        }

        this->tamanio++;

        /* cualquier recorrido actual queda invalidado */
        this->iniciarCursor();
    }

}

template<class T> void ListaEnlazada<T>::agregar(ListaEnlazada<T> &otraLista) {

    otraLista.iniciarCursor();
    while (otraLista.avanzarCursor()) {
        this->agregar(otraLista.obtenerCursor());
    }
}

template<class T> T ListaEnlazada<T>::obtener(unsigned int posicion) {

    T elemento;

    if ((posicion > 0) && (posicion <= this->tamanio)) {

        elemento = this->obtenerNodo(posicion)->obtenerDato();
    }

    return elemento;
}

template<class T> unsigned int ListaEnlazada<T>::obtenerPosicion(T elemento){

	Nodo<T>* nodoIterador = this->primero;
	int posicionDelElemento = 0;
	int posicionIterador = 1;
	do{
		if(elemento == nodoIterador->obtenerDato()){
			posicionDelElemento = posicionIterador;
		}
		nodoIterador = nodoIterador->obtenerSiguiente();
		posicionIterador ++;
	}while(nodoIterador && posicionDelElemento == 0);

	return posicionDelElemento;
}

template<class T> void ListaEnlazada<T>::asignar(T elemento, unsigned int posicion) {

    if ((posicion > 0) && (posicion <= this->tamanio)) {

        this->obtenerNodo(posicion)->cambiarDato(elemento);
    }
}

template<class T> void ListaEnlazada<T>::remover(unsigned int posicion) {

    if ((posicion > 0) && (posicion <= this->tamanio)) {

        Nodo<T>* removido;

        if (posicion == 1) {

            removido = this->primero;
            this->primero = removido->obtenerSiguiente();

        } else {

            Nodo<T>* anterior = this->obtenerNodo(posicion - 1);
            removido = anterior->obtenerSiguiente();
            anterior->cambiarSiguiente(removido->obtenerSiguiente());
        }

        delete removido;
        this->tamanio--;

        /* cualquier recorrido actual queda invalidado */
        this->iniciarCursor();
    }
}

template<class T> void ListaEnlazada<T>::iniciarCursor() {

    this->cursor = NULL;
}

template<class T> bool ListaEnlazada<T>::avanzarCursor() {

    if (this->cursor == NULL) {

        this->cursor = this->primero;

    } else {

        this->cursor = this->cursor->obtenerSiguiente();
    }

    /* pudo avanzar si el cursor ahora apunta a un nodo */
    return (this->cursor != NULL);
}

template<class T> T ListaEnlazada<T>::obtenerCursor() {

    T elemento;

    if (this->cursor != NULL) {

        elemento = this->cursor->obtenerDato();
    }

    return elemento;
}

template<class T> ListaEnlazada<T>::~ListaEnlazada() {

    while (this->primero != NULL) {

        Nodo<T>* aBorrar = this->primero;
        this->primero = this->primero->obtenerSiguiente();

        delete aBorrar;
    }
}

template<class T> Nodo<T>* ListaEnlazada<T>::obtenerNodo(unsigned int posicion) {

    Nodo<T>* actual = this->primero;
    for (unsigned int i = 1; i < posicion; i++) {

        actual = actual->obtenerSiguiente();
    }

    return actual;
}

template<class T> bool ListaEnlazada<T>::esta(T elemento){
	Nodo<T>* nodoIterador = this->primero;
	bool elementoEsta = false;
	while(nodoIterador && !elementoEsta){
		if (nodoIterador->obtenerDato() == elemento){
			elementoEsta = true;
		}
		nodoIterador = nodoIterador->obtenerSiguiente();
	}
	return elementoEsta;
}

#endif /* LISTA_H_ */
