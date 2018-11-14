#include "../EjecucionTurno/TurnoTablero.h"

TurnoTablero::TurnoTablero(Tablero* tableroAsociado) {
	this->tableroAsociado = tableroAsociado;
}

void TurnoTablero::marcarCambiosARealizarParaSiguienteTurno() {
	for (unsigned int fila = 0; fila < this->tableroAsociado->getFilas();
			fila++) {
		for (unsigned int columna = 0;
				columna < this->tableroAsociado->getColumnas(); columna++) {
			RGB* coloresCelulasVivasCircundantes[3];
			unsigned int copiaColumna = columna;
			int celulasCircundantesVivas = chequearCelulasCircundantes(fila,
					columna, coloresCelulasVivasCircundantes);
			decidirVidaOMuerte(celulasCircundantesVivas,
					this->tableroAsociado->getParcela(fila, columna).getCoordenadaParcela(),
					coloresCelulasVivasCircundantes);
		}
	}
}

void TurnoTablero::guardarColorCelulasCircundantes(
		RGB* coloresCelulasVivasCircundantes[], int celulasCircundantesVivas,
		int fila, int columna) {
	if (celulasCircundantesVivas <= MAX_CANTIDAD_CELULAS_CIRCUNDANTES) {
		coloresCelulasVivasCircundantes[celulasCircundantesVivas - 1] =
				this->tableroAsociado->getParcela(fila, columna).getCelula()->getRGB();
	}
}

int TurnoTablero::chequearCelulasCircundantes(unsigned int fila,
		unsigned int columna, RGB* coloresCelulasVivasCircundantes[]) {
	int celulasCircundantesVivas = 0;
	int filaAchequear = (int) fila;
	int columnaAchequear = (int) columna;
	for (int i = filaAchequear - 1; i <= filaAchequear + 1; i++) {
		if (i >= 0 && i < (int) this->tableroAsociado->getFilas()) {
			for (int j = columnaAchequear - 1; j <= columnaAchequear + 1; j++) {
				if (j >= 0 && j < (int) this->tableroAsociado->getColumnas()) {
					bool mismaCelula = (i == (int) fila && j == (int) columna);
					if (!mismaCelula
							&& this->tableroAsociado->getParcela(i, j).getCelula()->getEstado()) {
						celulasCircundantesVivas++;
						guardarColorCelulasCircundantes(
								coloresCelulasVivasCircundantes,
								celulasCircundantesVivas, i, j);
					}
				}
			}
		}
	}
	return celulasCircundantesVivas;
}

RGB* TurnoTablero::promedioColoresCelulasCircundantes(
		RGB* coloresCelulasVivasCircundantes[]) {
	RGB* colorParaCelulaANacer = new RGB();
	colorParaCelulaANacer->calcularPromedioRGBes(
			coloresCelulasVivasCircundantes[0],
			coloresCelulasVivasCircundantes[1],
			coloresCelulasVivasCircundantes[2]);
	return colorParaCelulaANacer;
}

void TurnoTablero::decidirVidaOMuerte(int celulasVivasCircundantes,
		CoordenadaParcela* coordenadaEnCuestion,
		RGB* coloresCelulasVivasCircundantes[]) {
	unsigned int x = coordenadaEnCuestion->getCoordenadaX();
	unsigned int y = coordenadaEnCuestion->getCoordenadaY();
	bool estaViva =
			this->tableroAsociado->getParcela(x, y).getCelula()->getEstado();
	if (estaViva
			&& (celulasVivasCircundantes < 2 || celulasVivasCircundantes > 3)) {
		marcarCelulaMorir(coordenadaEnCuestion);
	} else {
		if (!estaViva && (celulasVivasCircundantes == 3)) {
			RGB* colorParaCelulaANacer = promedioColoresCelulasCircundantes(
					coloresCelulasVivasCircundantes);
			marcarCelulaNacer(coordenadaEnCuestion, colorParaCelulaANacer);
		}
	}
}

void TurnoTablero::marcarCelulaMorir(CoordenadaParcela* coordenadaEnCuestion) {
	ParcelaAfectada* celulaAMorir = new ParcelaAfectada(coordenadaEnCuestion);
	this->ParcelasAfectadas.acolar(celulaAMorir);
}

void TurnoTablero::marcarCelulaNacer(CoordenadaParcela* coordenadaEnCuestion,
		RGB* colorCelulaANacer) {
	ParcelaAfectada* CelulaANacer = new ParcelaAfectada(coordenadaEnCuestion,
			colorCelulaANacer);
	this->ParcelasAfectadas.acolar(CelulaANacer);
}

void TurnoTablero::concretarCambios() {
	this->tableroAsociado->getDatosTablero()->setCongeladoTurnoActual(true);
	while (!this->ParcelasAfectadas.estaVacia()) {
		ParcelaAfectada* CambioARealizar = this->ParcelasAfectadas.desacolar();
		if (CambioARealizar->naceLaCelula()) {
			float factorNacimientoParcela =
					CambioARealizar->getParcela().getfactorNacimiento();
			CambioARealizar->getParcela().getCelula()->nacer(
					factorNacimientoParcela,
					CambioARealizar->getColorPromedio());
			delete CambioARealizar->getColorPromedio();
			this->tableroAsociado->getDatosTablero()->sumarCelulaViva();
		} else {
			float factorMuerteParcelaAsociada =
					CambioARealizar->getParcela().getfactorMuerte();
			bool murio =
					CambioARealizar->getParcela().getCelula()->restarEnergia(
							factorMuerteParcelaAsociada);
			if (murio) {
				this->tableroAsociado->getDatosTablero()->sumarCelulaMuerta();
			}
		}
		if (CambioARealizar->hayPortal()) {
			cambiosPorPortal.agregar(CambioARealizar);
		}
		else{
			delete CambioARealizar;
		}

	}
	if (this->tableroAsociado->getDatosTablero()->getNacidasEnUltimoTurno() != 0
			|| this->tableroAsociado->getDatosTablero()->getMuertasEnUltimoTurno()
					!= 0) {
		this->tableroAsociado->getDatosTablero()->setCongeladoTurnoActual(
				false);
	}
	this->tableroAsociado->getDatosTablero()->setCantidadTurnosCongeladosTablero();
}

void TurnoTablero::plasmarCambiosEnArchivo() {
	this->tableroAsociado->generarBMP();
	this->tableroAsociado->guardarBMP(
			this->tableroAsociado->getDatosTablero()->getTurno());
}

void TurnoTablero::jugarTurnoTablero() {
	this->tableroAsociado->getDatosTablero()->avanzarUnTurno();
	this->marcarCambiosARealizarParaSiguienteTurno();
	this->concretarCambios();
}

void TurnoTablero::actualizarBMP() {
	this->plasmarCambiosEnArchivo();
}

ListaEnlazada<ParcelaAfectada*> & TurnoTablero::getCambiosPorPortal() {
	return this->cambiosPorPortal;
}
