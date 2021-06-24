#include "../partidaMultijugador.h"

PartidaMultijugador::PartidaMultijugador(int idPartida, string duenio, DtFechaHora* fechaInicio, string juego, bool transmitida, vector<string> jugUnidos) {
	this->idPartida = idPartida;
	this->duenio = duenio;
	this->duracion = 0.0;
	this->FechaInicio = fechaInicio;
	this->Videojuego = juego;
	this->Transmitida = transmitida;
	for (auto j : jugUnidos) {
		this->conjuntoSalidas.insert(pair<string, DtFechaHora*> (j, NULL));	
	}
}

void PartidaMultijugador::setTransmitida(bool transmit) {
	this->Transmitida = transmit;
}

void PartidaMultijugador::setSalida(string jugador, DtFechaHora *fechaSalida) {

	//this->conjuntoSalidas.insert(pair<string, DtFechaHora*>(jugador, fechaSalida));
	this->conjuntoSalidas[jugador]=fechaSalida;
	
}

//Getters
bool PartidaMultijugador::getTransmitida() {
	return this->Transmitida;
}

//operaciones
float PartidaMultijugador::darTotalDeHorasParticipantes() {
	float d = 0;
	DtFechaHora *x;
	for (auto it = this->conjuntoSalidas.begin(); it != this->conjuntoSalidas.end(); ++it ) {
    		if (it->second != NULL) {
    			x = it->second;

				float horasDeJuego = this->diferencia(this->FechaInicio, x);

				d = d + horasDeJuego;

			} 
	}
	d = d + this->duracion;
	return d;
}

set<string> PartidaMultijugador::getNicknameJugadoresActivos() {
	set<string> jugadores;
	
	for (auto it = this->conjuntoSalidas.begin(); it != this->conjuntoSalidas.end(); ++it ) {	
		if (it->second == NULL)
			jugadores.insert(it->first);
	}
	return jugadores;
}

set<string> PartidaMultijugador::getDtJugadoresUnidos() {
	set<string> jugadores;
	
	for (auto it = this->conjuntoSalidas.begin(); it != this->conjuntoSalidas.end(); ++it) {
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
	for (auto it = this->conjuntoSalidas.begin(); it != this->conjuntoSalidas.end(); it++) {
		if((it)->second == NULL) 
			this->setSalida(it->first, fechafin);
	}
}

DtPartida *PartidaMultijugador::getDataPartida() {
	DtPartida *dataPartida = new DtPartidaMultijugador(this->idPartida, this->duracion, this->FechaInicio, this->duenio, this->Videojuego, this->Transmitida, this->colComentarios, this->getDtJugadoresUnidos());
	return dataPartida;
}

void PartidaMultijugador::abandonaPartidaJugador(string jugador) {
	Fabrica *fabrica = Fabrica::getInstancia();
	iControladorUsuarios* controlador=fabrica->getControladorUsuarios();
	DtFechaHora *fechaSalida=controlador->getFechaSistema();
	
	for (auto it = this->conjuntoSalidas.begin(); it != this->conjuntoSalidas.end(); ++it) {
		if((it)->first == jugador) {
			//it->second = new DtFechaHora(fechaSalida->getAnio(), fechaSalida->getMes(), fechaSalida->getDia(), fechaSalida->getHora(), fechaSalida->getMinuto());
			this->conjuntoSalidas[jugador]=fechaSalida;
			break;	
		}
	}
	
}




