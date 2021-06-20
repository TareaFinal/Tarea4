#include "../comentario.h"

Comentario::Comentario(int idComent, Jugador *jugador,string texto, PartidaMultijugador *partida) {
	this->idComentario = idComent;
	this->jugador = jugador;
	this->Fecha = NULL;
	this->texto = texto;
	this->partida = partida;
}

void Comentario::setIdComentario(int idComent) {
	this->idComentario = idComent;
}

void Comentario::setFecha(DtFechaHora *date) {
	this->Fecha = date;
}

void Comentario::setTexto(string texto) {
	this->texto = texto;
}

int Comentario::getIdComentario() {
	return this->idComentario;
}

DtFechaHora *Comentario::getFechaHora() {
	return this->Fecha;
}

string Comentario::getTexto() {
	return this->texto;
}
