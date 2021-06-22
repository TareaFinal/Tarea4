#include "../DtPartida.h"

int DtPartida::getIdPartida(){
    return this->idPartida;
};
float DtPartida::getDuracion(){
    return this->duracion;
};
DtFechaHora *DtPartida::getFechaInicio(){
    return this->fechaInicio;
};
string DtPartida::getNicknameCreador(){
    return this->nicknameCreador;
};
string DtPartida::getVideojuego(){
    return this->videojuego;
};
