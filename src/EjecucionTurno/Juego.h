#ifndef JUEGO_H_
#define JUEGO_H_

#include "../CreacionTablero/LecturaArchivoConfiguracion.h"
#include "../EjecucionTurno/TurnoTablero.h"
#include "../Tablero/Tablero.h"
#include "../Listas/ListaEnlazada.h"
#include "../Grafo/Grafo.h"

const std::string EJECUTAR_TURNO = "e";
const std::string INICIAR_JUEGO = "r";
const std::string TERMINAR_JUEGO = "t";

/*
 * Clase conteniendo todos los datos del juego y que se instancia al principio de la partida.
 */

class Juego {
private:
	ListaEnlazada<Tablero*>* tablerosDelJuego;
	ListaEnlazada<DatosTablero*>* datosDelJuego;


	/*
	 * pre: recibe un turnoTablero* procesado que lleva los portales afectados.
	 * post: cambia los portales afectados una vez que todos los tableros son recorridos.
	 */
	void afectarCambiosPortalPorTablero(TurnoTablero * turnoTablero);

	/*
	 * pre: recibe un array nuevo de turnos
	 * post: ejecuta los turnos para cada tablero
	 */
	void jugarTurnosTableros(TurnoTablero ** turnos);

	/*
	 * pre: -
	 * post: muestra los datos por pantalla y resetea los contadores del ultimo turno.
	 */
	void procesarDatos();

public:

	Grafo* grafoAsociado;

	/*
	 * pre:
	 * post: Aplica la ejecucion de un turno para cada uno de los tableros cambiando las parcelas.
	 */
	void ejecutarTurno();

	/*
	 * pre: -
	 * post: devuelve por pantalla los tableros en formato BMP.
	 */
	void mostrarJuego();

	/*
	 * pre: este método pide al usuario de ingresar lo que quiere hacer al proximo turno.
	 * post: devuelve un caracter correspondiente a la proxima accion.
	 */
	std::string pedirProximoTurno();

	/*
	 * pre: pide al usuario la ruta del archivo de texto valido que contiene los datos para el juego
	 * post: inicia o reinicia el juego seteando los datos a sus valores originales y armando los tableros,
	 * parcelas, celulas.
	 */
	void iniciarJuego();

	/*
	 * pre: el juego ya esta inciciado
	 * post: termina el juego y cierra las representaciones BMP de los tableros.
	 */
	void terminarJuego();

};

#endif /* JUEGO_H_ */
