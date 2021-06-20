#include "../partidaMultijugador.h"

PartidaMultijugador::PartidaMultijugador(int idPartida, string duenio, DtFechaHora* fechaInicio, string juego, bool transmitida, const map_type&) {
	this->idPartida = idPartida;
	this->duenio = duenio;
	this->duracion = NULL;
	this->FechaInicio = fechaInicio;
	this->Videojuego = juego;
	this->Transmitida = transmitida;
	this->conjuntoSalidas = map_type();
}

void PartidaMultijugador::setTransmitida(bool transmit) {
	this->Transmitida = transmit;
}

void PartidaMultijugador::setSalida(string jugador, DtFechaHora *fechaSalida) {

	this->conjuntoSalidas.insert(pair<string, DtFechaHora*>(jugador, fechaSalida));
	
}

//Getters
bool PartidaMultijugador::getTransmitida() {
	return this->Transmitida;
}

//operaciones
float PartidaMultijugador::darTotalDeHorasParticipantes() {
	float d = 0;
	DtFechaHora *x;
	for (auto it = this->conjuntoSalidas.begin(); it != this->conjuntoSalidas.end(); ) {
    		if (it->second != NULL) {
    			x = it->second;
    			d = d + x->getAnio()*365*24 + x->getMes()*30*24 + x->getDia()*24 + x->getHora() + x->getMinuto()/60;
			} //recorro el conjunto de jugadores y salidas para la suma de duraciones;
	}
	return d;
}

set<string> PartidaMultijugador::getNicknameJugadoresActivos() {
	set<string> jugadores;
	
	for (auto it = this->conjuntoSalidas.begin(); it != this->conjuntoSalidas.end(); ) {
		if (it->second == NULL)
			jugadores.insert(it->first);
	}
	return jugadores;
}

set<string> PartidaMultijugador::getDtJugadoresUnidos() {
	set<string> jugadores;
	
	for (auto it = this->conjuntoSalidas.begin(); it != this->conjuntoSalidas.end(); ) {
		string nick = it->first;
		jugadores.insert(nick);
	}
	return jugadores;
}

void PartidaMultijugador::terminarPartida() {
	Fabrica *fabrica = Fabrica::getInstancia();
	iControladorUsuarios* controlador=fabrica->getControladorUsuarios();
	DtFechaHora *fechafin=controlador->getFechaSistema();
	this->duracion=diferencia(this->FechaInicio, fechafin); //llamo a la funcion auxiliar
	//recorro el conjunto de Jugadores y si aun no ha terminado su partida la termino
	for (auto it = this->conjuntoSalidas.begin(); it != this->conjuntoSalidas.end(); ) {
		if((it)->second == NULL) 
			this->setSalida(it->first, fechafin);
	}
}

DtPartida *PartidaMultijugador::getDataPartida() {
	DtPartida *dataPartida = new DtPartidaMultijugador(this->idPartida, this->duracion, this->FechaInicio, this->duenio, this->Videojuego, this->Transmitida, this->colComentarios, this->conjuntoSalidas);
	return dataPartida;
}

void PartidaMultijugador::abandonaPartidaJugador(string jugador) {
	Fabrica *fabrica = Fabrica::getInstancia();
	iControladorUsuarios* controlador=fabrica->getControladorUsuarios();
	DtFechaHora *fechaSalida=controlador->getFechaSistema();
	
	for (auto it = this->conjuntoSalidas.begin(); it != this->conjuntoSalidas.end(); ) {
		if((it)->first == jugador) {
			it->second = new DtFechaHora(fechaSalida->getAnio(), fechaSalida->getMes(), fechaSalida->getDia(), fechaSalida->getHora(), fechaSalida->getMinuto());
			break;	
		}
	}
	
}




