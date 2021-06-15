#include "../DtPartidaIndividual.h"

DtPartidaIndividual::DtPartidaIndividual(DtFechaHora duracion, DtFechaHora fechaInicio, string nicknameCreador, string videojuego, int partidaContinuada){
    this->duracion = duracion;
    this->fechaInicio = fechaInicio;
    this->nicknameCreador = nicknameCreador;
    this->videojuego = videojuego;
    this->partidaContinuada = partidaContinuada;
};

int DtPartidaIndividual::getPartidaContinuada(){
    return this->partidaContinuada;
};