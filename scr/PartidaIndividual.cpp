#include "../partidaIndividual.h"

PartidaIndividual::PartidaIndividual(int idPartida, DtFechaHora *FechaInicio, string juego, string jugador) {
	this->idPartida = idPartida;
	this->duenio = jugador;
	this->duracion = NULL;
	this->FechaInicio = FechaInicio;
	this->Videojuego = juego;
	this->continuacion = NULL;
}

float PartidaIndividual::darTotalDeHorasParticipantes() {
	
	int anios  = this->duracion->getAnio();
	int meses = this->duracion->getMes();
	int dias = this->duracion->getDia();
	int horas = this->duracion->getHora();
	int minutos = this->duracion->getMinuto();
	
	float horasDeJuego = (anios*12*30*24) + (meses*30*24) + (dias*24) + (horas) + minutos;
	
	return horasDeJuego;
}

PartidaIndividual *PartidaIndividual::getContinuacion() {
	return this->continuacion;
}

void PartidaIndividual::terminarPartida() {
	Fabrica *fabrica = Fabrica::getInstancia();
	iControladorUsuarios *controlador = fabrica->getControladorUsuarios();
	DtFechaHora *finalizacion = controlador->getFechaSistema();
	
	this->duracion = this->diferencia(this->FechaInicio, finalizacion);
	
	cout << "La partida se finalizo con exito.";
}

DtPartida *PartidaIndividual::getDataPartida() {
	int idContinuacion;
	if (this->continuacion != NULL) {
		idContinuacion = (this->continuacion)->getPartida();	
	}
	DtPartida *partida = new DtPartidaIndividual(this->idPartida, this->duracion, this->FechaInicio, this->duenio, this->Videojuego, idContinuacion); 
	return partida;
}


