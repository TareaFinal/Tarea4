#include "../DtPartidaMultijugador.h"

DtPartidaMultijugador::DtPartidaMultijugador(int idPartida, float duracion, DtFechaHora* fechaInicio, string creador, string videojuego, bool transmitida, vector<DtComentario*> comentarios, map<string, DtFechaHora*> conjuntoSalidas) {
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
	for(auto it : unidos){
		cout  << it << endl;
	};
	os << "pase los unidos" << endl;
	set<string> activos = pm->getNicknameJugadoresActivos();

	os  << "Nickname Jugadores unidos:" << endl;
	for(auto it : unidos){
		os  << it << endl;
	};
	os	<< "De los cuales siguen activos: " << endl;
	for(auto it : activos){
		os  << it << endl;
	};
	os	<< "Comentarios: " << endl
		<< "Falta recorrer este vector"
		<< "\n"
		<< "\n";
	   
	return os;
	   
	//return os;
};
