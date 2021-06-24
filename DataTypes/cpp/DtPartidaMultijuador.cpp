#include "../DtPartidaMultijugador.h"

DtPartidaMultijugador::DtPartidaMultijugador(int idPartida, float duracion, DtFechaHora* fechaInicio, string creador, string videojuego, bool transmitida, vector<DtComentario*> comentarios, set<string> conjuntoSalidas) {
    this->idPartida = idPartida;
	this->duracion = duracion;
    this->fechaInicio = fechaInicio;
    this->nicknameCreador = creador;
    this->videojuego = videojuego;
    this->transmitida = transmitida;
    this->conjuntoSalidas = conjuntoSalidas;
    this->comentarios = comentarios;
};
bool DtPartidaMultijugador::getTransmitida(){
    return this->transmitida;
};
set<string> DtPartidaMultijugador::getNicknameJugadoresUnidos(){
    set<string> jugadores;
	
	for (auto it = this->conjuntoSalidas.begin(); it != this->conjuntoSalidas.end(); it++) {
		string nick = *it;
		jugadores.insert(nick);
	}
	return jugadores;
};


vector<DtComentario*> DtPartidaMultijugador::getComentarios(){
    return this->comentarios;
};

ostream &operator<< (ostream &os, DtPartidaMultijugador* pm) { 
	os << "----------------------------------------\n"
	   << "---Partida Multijugador---" << endl
       << "Id: " << pm->getIdPartida() << "\n";
	if (pm->getDuracion() != 0.0) {
		os << "Duracion: " <<  pm->getDuracion() << " horas\n";
	}
	os << "Fecha de inicio: " <<  pm->getFechaInicio()->getDia() << "/" << pm->getFechaInicio()->getMes() << "/" << pm->getFechaInicio()->getAnio() << endl
	<< "Creador: " << pm->getNicknameCreador() << "\n"
	<< "Videojuego: " << pm->getVideojuego() << "\n"
	<< "Es transmitida en vivo: ";

    if (pm->getTransmitida())
   		os	<< "Si\n";
	else 
   		os	<< "No\n";

	set<string> unidos = pm->getNicknameJugadoresUnidos();

	os  << "Nickname Jugadores unidos: " ;
	for(auto it : unidos){
		os  << it << ", ";
	};
	os  << endl;
	return os;
	   
	//return os;
};
