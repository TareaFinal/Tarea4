#include "../DtPartidaMultijugador.h"

DtPartidaMultijugador::DtPartidaMultijugador(DtFechaHora duracion, DtFechaHora fechaInicio, string nicknameCreador, string videojuego, bool transmitida, string *nicknameJugadoresUnidos, DtComentario *comentarios){
    this->duracion = duracion;
    this->fechaInicio = fechaInicio;
    this->nicknameCreador = nicknameCreador;
    this->videojuego = videojuego;
    this->transmitida = transmitida;
    this->nicknameJugadoresUnidos = nicknameJugadoresUnidos;
    this->comentarios = comentarios;
};
bool DtPartidaMultijugador::getTransmitida(){
    return this->transmitida;
};
string* DtPartidaMultijugador::getNicknameJugadoresUnidos(){
    return this->nicknameJugadoresUnidos;
};
DtComentario* DtPartidaMultijugador::getComentarios(){
    return this->comentarios;
};