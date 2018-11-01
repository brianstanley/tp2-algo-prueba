/*
 * turno.cpp
 *
 *  Created on: 27 oct. 2018
 *      Author: nazareno
 */

#include<turno.h>

const int MAX_CANTIDAD_CELULAS_CIRCUNDANTES = 3;

Turno::Turno(Tablero* tableroAsociado){
	this->celulasMuertasTurno = 0;
	this->celulasNacidasTurno = 0;
	this->numeroDeTurno = 1;
	this->tableroAsociado = tableroAsociado;
}

void Turno::marcarCambiosARealizarParaSiguienteTurno(){
	for(int fila=0; fila < this->tableroAsociado->getFilas(); fila++){
		for(int columna=0; columna < this->tableroAsociado->getColumnas(); columna++){
			RGB* coloresCelulasVivasCircundantes [3];
			int celulasCircundantesVivas = chequearCelulasCircundantes(fila, columna, coloresCelulasVivasCircundantes);
			decidirVidaOMuerte(celulasCircundantesVivas, this->tableroAsociado->getParcela(fila,columna).getCoordenadaParcela(), coloresCelulasVivasCircundantes);
		}
	}
}

void Turno::guardarColorCelulasCircundantes(RGB* coloresCeluasVivasCircundantes[], int celulasCircundantesVivas, int fila, int columna){
	if (celulasCircundantesVivas < MAX_CANTIDAD_CELULAS_CIRCUNDANTES){
		coloresCeluasVivasCircundantes[celulasCircundantesVivas-1] =
		this->tableroAsociado->getParcela(fila, columna).getCelula()->getRGB();
	}
}

int Turno::chequearCelulasCircundantes(int fila, int columna, RGB* coloresCelulasVivasCircundantes[]){
	int celulasCircundantesVivas = 0;
	for (int i=fila-1; i <=fila+1; i++){
		if (i > 0 && i <= this->tableroAsociado->getFilas()){
			for(int j=fila-1; j <=fila+1; j++){
				if (j > 0 && j <= this->tableroAsociado->getColumnas()){
					bool mismaCelula = (i == fila && j == columna);
					if(this->tableroAsociado->getParcela(i, j).getCelula()->getEstado() && !mismaCelula){
						guardarColorCelulasCircundantes(coloresCelulasVivasCircundantes, celulasCircundantesVivas, i, j);
						celulasCircundantesVivas ++;
					}
				}
			}
		}
	}
	return celulasCircundantesVivas;
}

RGB* Turno::promedioColoresCelulasCircundantes(RGB* coloresCelulasVivasCircundantes[]){
	RGB colorParaCelulaANacer;
	colorParaCelulaANacer.calcularPromedioRGBes(coloresCelulasVivasCircundantes[0],
	coloresCelulasVivasCircundantes[1], coloresCelulasVivasCircundantes[2]);
	return &colorParaCelulaANacer;
}

void Turno::decidirVidaOMuerte(int celulasVivasCircundantes, CoordenadaParcela* coordenadaEnCuestion, RGB* coloresCelulasVivasCircundantes[]){
	int x = coordenadaEnCuestion->getCoordenadaX();
	int y = coordenadaEnCuestion->getCoordenadaY();
	if (this->tableroAsociado->getParcela(x,y).getCelula()->getEstado()){ //en este caso la celula estaria viva
		if (celulasVivasCircundantes != 3){
			marcarCelulaMorir(coordenadaEnCuestion); // como no tiene 3 celulas vivas circundantes se marcaria como muerta
		}
	}
	else{ // en este caso la celula estaria muerta
		if (celulasVivasCircundantes == 3){
			RGB* colorParaCelulaANacer = promedioColoresCelulasCircundantes(coloresCelulasVivasCircundantes);
			marcarCelulaNacer(coordenadaEnCuestion, colorParaCelulaANacer);
		}
	}
}

void Turno::marcarCelulaMorir(CoordenadaParcela* coordenadaEnCuestion){
	ParcelaAfectada* celulaAMorir = new(ParcelaAfectada(coordenadaEnCuestion));
	this->ParcelasAfectadas.acolar(celulaAMorir);
}

void Turno::marcarCelulaNacer(CoordenadaParcela* coordenadaEnCuestion, RGB* colorCelulaANacer){
	ParcelaAfectada* celulaANacer = new(ParcelaAfectada(coordenadaEnCuestion, colorCelulaANacer));
	this->ParcelasAfectadas.acolar(celulaANacer);
}

void Turno::concretarCambios(){
	while (! this->ParcelasAfectadas.estaVacia()){
		ParcelaAfectada* CambioARealizar = this->ParcelasAfectadas.desacolar();
		if (CambioARealizar->naceLaCelula()){
			float factorNacimientoParcela = CambioARealizar->getParcela().getfactorNacimiento();
			CambioARealizar->getParcela().getCelula()->nacer(factorNacimientoParcela, CambioARealizar->getColorPromedio());
			this->celulasNacidasTurno ++;
			this->tableroAsociado->getDatosTablero()->sumarCelulaViva();
		}
		else{
			CambioARealizar->getParcela().getCelula()->morir();
			this->celulasMuertasTurno ++;
			this->tableroAsociado->getDatosTablero()->sumarCelulaMuerta();
		}
		if (CambioARealizar->hayPortal()){
			CambioARealizar->getParcela().getPortal()->accionarPortal(CambioARealizar->naceLaCelula(), CambioARealizar->getColorPromedio());
		}

	}
}

void Turno::plasmarCambiosEnArchivo(){
	this->tableroAsociado->generarBMP();
	this->tableroAsociado->guardarBMP(this->numeroDeTurno);
}

