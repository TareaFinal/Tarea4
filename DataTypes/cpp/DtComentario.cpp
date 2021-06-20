#include "../DtComentario.h"

DtComentario::DtComentario(int idComentario, DtFechaHora *fecha, string nicknameJugador, string texto){
    this->idComentario = idComentario;
    this->fecha = fecha;
    this->nicknameJugador = nicknameJugador;
    this->texto = texto;
};
int DtComentario::getIdComentario(){
    return this->idComentario;
};
DtFechaHora *DtComentario::getFecha(){
    return this->fecha;
};
string DtComentario::getNicknameJugador(){
    return this->nicknameJugador;
};
string DtComentario::getTexto(){
    return this->texto;
};

ostream &operator<< (ostream &os, DtComentario* com) {
	os << "----------------------------------------\n"
	   << "---Comentario---" << endl
       << "Id: " << com->getIdComentario() << "\n"
	   << "Fecha: " <<  com->getFecha()->getDia() << "/" << com->getFecha()->getMes() << "/" << com->getFecha()->getAnio() << " Esto es un DtFechahora, ojo!!!\n" 
       << "Nickname del Jugador: " << com->getNicknameJugador() << "\n"
       << "Texto: " << com->getTexto() << "\n";
	   
	return os;
};
