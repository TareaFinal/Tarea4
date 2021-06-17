#include "../DtComentario.h"

DtComentario::DtComentario(int idComentario, DtFechaHora fecha, string nicknameJugador, string texto){
    this->idComentario = idComentario;
    this->fecha = fecha;
    this->nicknameJugador;
    this->texto = texto;
};
int DtComentario::getIdComentario(){
    return this->idComentario;
};
DtFechaHora DtComentario::getFecha(){
    return this->fecha;
};
string DtComentario::getNicknameJugador(){
    return this->nicknameJugador;
};
string DtComentario::getTexto(){
    return this->texto;
};