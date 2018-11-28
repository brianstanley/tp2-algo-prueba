#ifndef SRC_LECTURAARCHIVOCONFIGURACION_H_
#define SRC_LECTURAARCHIVOCONFIGURACION_H_
#include <string>
#include <fstream>

#include "../CreacionTablero/Lectura.h"
#include "../ProcesamientoDeStrings/StringHelper.h"
#include "../Tablero/Tablero.h"
#include "../Excepciones/ExcepcionesArchivo.h"
#include "../Listas/ListaEnlazada.h"
#include "../Grafo/Grafo.h"

std::string const PARCELA = "parcela";
std::string const PORTAL = "portal";
std::string const TABLERO = "tablero";
std::string const CELULA = "celula";

class LecturaArchivoConfiguracion {
private:
	ListaEnlazada<Tablero*>* tableros;
	void procesarTablero(std::string nombreTablero, std::ifstream&, Grafo* grafoAsociado);
	void procesarPortal(std::string nombreTablero, std::ifstream&, Grafo* grafoAsociado);
	void procesarParcela(std::string nombreTablero, std::ifstream&);
	void procesarCelula(std::string nombreTablero, std::ifstream&);
	void crearTablero(std::string, int ancho, int alto, Grafo* grafoAsociado);
	void crearCelula(std::string, int fila, int columna);
	Tablero * string2punteroTablero(std::string);
	void crearPortales(std::string tableroId, std::string tableroDestino,
			int filaOrigen, int columnaOrigen, int filaDestino,
			int columnaDestino, std::string tipoDePortal, Grafo* grafoAsociado);
public:
	/*
	 * pre: Ruta al archivo del cual se desea leer la configuración de
	 * inicio del juego. La ruta tiene que ser a un archivo que exista,
	 * tenga un formato valido como  específica la documentación y
	 * tiene que tener permisos de lectura.
	 * pos: Procesa el archivo de configuración creando los elementos
	 * que se encuentran indicadas en el archivo.
	 */
	void procesarArchivo(std::string, Grafo* grafoAsociado);

	/*
	 * pre: Lista inicializada
	 * pos: Lista de tableros creados a partir del archivo de texto
	 */
	ListaEnlazada<Tablero*>* obtenerListaTableros();
};

#endif /* SRC_LECTURAARCHIVOCONFIGURACION_H_ */
