#include "../DtPartidaMultijugador.h"

DtPartidaMultijugador::DtPartidaMultijugador(int idPartida, DtFechaHora* duracion, DtFechaHora* fechaInicio, string creador, string videojuego, bool transmitida, vector<DtComentario*> comentarios, const map_type&) {
    this->idPartida = idPartida;
	this->duracion = duracion;
    this->fechaInicio = fechaInicio;
    this->nicknameCreador = creador;
    this->videojuego = videojuego;
    this->transmitida = transmitida;
    this->conjuntoSalidas = map_type();
    this->comentarios = comentarios;
};
bool DtPartidaMultijugador::getTransmitida(){
    return this->transmitida;
};
set<string> DtPartidaMultijugador::getNicknameJugadoresUnidos(){
    set<string> jugadores;
	
	for (auto it = this->conjuntoSalidas.begin(); it != this->conjuntoSalidas.end(); ) {
		string nick = it->first;
		jugadores.insert(nick);
	}
	return jugadores;
};

set<string> DtPartidaMultijugador::getNicknameJugadoresActivos() {
	set<string> jugadores;
	
	for (auto it = this->conjuntoSalidas.begin(); it != this->conjuntoSalidas.end(); ) {
		if (it->second == NULL)
			jugadores.insert(it->first);
	}
	return jugadores;
}


vector<DtComentario*> DtPartidaMultijugador::getComentarios(){
    return this->comentarios;
};

ostream &operator<< (ostream &os, DtPartidaMultijugador* pm) { 
	os << "----------------------------------------\n"
	   << "---Partida Multijugador---" << endl
       << "Id: " << pm->getIdPartida() << "\n"
       << "Duracion: " <<  pm->getDuracion()->getDia() << "/" << pm->getDuracion()->getMes() << "/" << pm->getDuracion()->getAnio() << " Esto es un DtFechahora, ojo!!!\n" //aca devuelve algo de tipo fechahora, revisar!
       << "Fecha de inicio: " <<  pm->getFechaInicio()->getDia() << "/" << pm->getFechaInicio()->getMes() << "/" << pm->getFechaInicio()->getAnio() << " Esto es un DtFechahora, ojo!!!\n"
       << "Creador: " << pm->getNicknameCreador() << "\n"
       << "Videojuego: " << pm->getVideojuego() << "\n"
       << "Es transmitida en vivo: ";

    if (pm->getTransmitida())
   		os	<< "Si\n";
	else 
   		os	<< "No\n";

	os  << "Nickname Jugadores unidos: \n"
		<< "Falta recorrer este set"
		<< "\n"
		<< "\n"
		<< "De los cuales siguen activos: "
		<< "Falta recorrer este set"
		<< "\n"
		<< "\n"
		<< "Comentarios: "
		<< "Falta recorrer este vector"
		<< "\n"
		<< "\n";
	   
	return os;
};
