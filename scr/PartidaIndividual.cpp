#include "../partidaIndividual.h"

PartidaIndividual::PartidaIndividual(int idPartida, DtFechaHora *FechaInicio, string juego) {
	this->idPartida = idPartida;
	this->duracion = NULL;
	this->FechaInicio = FechaInicio;
	this->Videojuego = juego;
	this->continuacion = NULL;
}

float PartidaIndividual::darTotalDeHorasParticipantes() {
	return 0.0;
}

PartidaIndividual *PartidaIndividual::getContinuacion() {
	return NULL;
}

void PartidaIndividual::terminarPartida() {
	
}

DtPartida *PartidaIndividual::getDataPartida() {
	return NULL;
}
