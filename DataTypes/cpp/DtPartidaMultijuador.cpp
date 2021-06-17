#include "../DtPartidaMultijugador.h"

DtPartidaMultijugador::DtPartidaMultijugador(bool transmitida, string *nicknameJugadoresUnidos, DtComentario *comentarios){
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