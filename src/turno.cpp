/*
 * turno.cpp
 *
 *  Created on: 27 oct. 2018
 *      Author: nazareno
 */

#include<turno.h>

Turno::Turno(Tablero* tableroAsociado){
	this->celulasMuertasTurno = 0;
	this->celulasNacidasTurno = 0;
	this->numeroDeTurno = 0; //capaz que lo ponemos en 1
	this->tableroAsociado = tableroAsociado;
}

void Turno::marcarCambiosARealizarParaSiguienteTurno(){
	for(int fila=0; fila < this->tableroAsociado->getFilas(); fila++){
		for(int columna=0; columna < this->tableroAsociado->getColumnas(); columna++){
			RGB* coloresCelulasVivasCircundantes[3];
			int celulasCircundantesVivas = chequearCelulasCircundantes(fila, columna, &coloresCelulasVivasCircundantes);
			decidirVidaOMuerte(celulasCircundantesVivas, this->tableroAsociado->getParcela().getCoordenada, coloresCelulasVivasCircundantes);
		//parcela deberia tener un metodo que devuelva sus coordenadas			}
		}
	}
}

int Turno::chequearCelulasCircundantes(int fila, int columna, RGB* coloresCelulasVivasCircundantes){
	int celulasCircundantesVivas;
	if(this->tableroAsociado->getParcela(fila, columna).getCelula().getEstado()){
		celulasCircundantesVivas --;
	}
	for (int i=fila-1; i <=fila+1; i++){
		if (i > 0){
			for(int j=fila-1; j <=fila+1; j++){
				if (j > 0){
					if(this->tableroAsociado->getParcela(i, j).getCelula().getEstado()){ // A MIRAR
						celulasCircundantesVivas ++;
						if (celulasCircundantesVivas < 4){
							coloresCelulasVivasCircundantes[celulasCircundantesVivas-1] = &(this->tableroAsociado->getParcela(i, j).getCelula()
							.getRGB());
						}
					}
				}
			}
		}
	}
	return celulasCircundantesVivas;
}

void Turno::decidirVidaOMuerte(int celulasVivasCircundanes, CoordenadaParcela coordenadaEnCuestion){
	int x = coordenadaEnCuestion.getCoordenadaX();
	int y = coordenadaEnCuestion.getCoordenadaY();
	if (this->tableroAsociado->getParcela(x,y).getCelula().getEstado()){ //en este caso la celula estaria viva
		if (celulasVivasCircundanes != 3){
			marcarCelulaMorir(coordenadaEnCuestion);
		}
	}
	else{ //esta muerta
		if (celulasVivasCircundanes == 3){
			marcarCelulaNacer(coordenadaEnCuestion);
		}
	}
}
