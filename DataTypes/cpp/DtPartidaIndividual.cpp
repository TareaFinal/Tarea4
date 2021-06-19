#include "../DtPartidaIndividual.h"

DtPartidaIndividual::DtPartidaIndividual(int idPartida, DtFechaHora *duracion, DtFechaHora *fechaInicio, string nickname, string videojuego, int partidaContinuada) { 
	this->idPartida = idPartida; ;
	this->duracion = duracion; //no deberia de ser de tipo float?
    this->fechaInicio = fechaInicio;
    this->nicknameCreador = nickname;
    this->videojuego = videojuego;
    this->partidaContinuada = partidaContinuada;
};

int DtPartidaIndividual::getPartidaContinuada(){
    return this->partidaContinuada;
};
