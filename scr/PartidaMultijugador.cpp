#include "../partidaMultijugador.h"

PartidaMultijugador::PartidaMultijugador(int idPartida, string juego, bool transmitida) {
	this->idPartida = idPartida;
	this->duracion = NULL;
	this->FechaInicio = NULL;
	this->Videojuego = juego;
	this->Transmitida = transmitida;
}

void PartidaMultijugador::setTransmitida(bool transmit) {
	
}

void PartidaMultijugador::setSalidas(Jugador *jug,DtFechaHora *fecha) {
	
}

//Getters
bool PartidaMultijugador::getTransmitida() {
	return true;
}
//	Jugador,DtFechaHora *getSalidas();

//operaciones
float PartidaMultijugador::darTotalDeHorasParticipantes() {
	return 0.0;	
}

set<DtJugador*> PartidaMultijugador::getDtJugadoresUnidos() {
	set<DtJugador*> jugadores;
	return jugadores;
}

void PartidaMultijugador::terminarPartida() {
	
}

DtPartida *PartidaMultijugador::getDataPartida() {
	return NULL;
}
