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
    			x = it->second;/*
				int anio 	= x->getAnio() - this->FechaInicio->getAnio();
				int mes 	= x->getMes() - this->FechaInicio->getMes();
				int dia 	= x->getDia() - this->FechaInicio->getDia();
				int hora 	= x->getHora() - this->FechaInicio->getHora();
				int minuto 	= x->getMinuto() - this->FechaInicio->getMinuto();
				if (minuto<0){
					hora=hora-1;
					minuto=60-abs(minuto);
				}
				if (hora<0){
					dia=dia-1;
					hora=24-abs(hora);
				}
				if (dia<0){
					mes=mes-1;
					dia=30-abs(dia);
				}
				if (mes<0){
					anio=anio-1;
					mes=12-abs(mes);
				}*/

				float horasDeJuego = this->diferencia(this->FechaInicio, x);

				d = d + horasDeJuego;
				//float f = Partida::diferencia(this->FechaInicio,x);
				//d = f;
				//cout << "para el juego "<< this->Videojuego <<" las horas ahora son: " << d << endl;
    			//d = d + x->getAnio()*365*24 + x->getMes()*30*24 + x->getDia()*24 + x->getHora() + x->getMinuto()/60;
			} //recorro el conjunto de jugadores y salidas para la suma de duraciones;
	}
	d = d + this->duracion;
	//cout << "partida multi: " << d << endl;
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
	for (auto it = this->conjuntoSalidas.begin(); it != this->conjuntoSalidas.end(); it++) {
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
	
	for (auto it = this->conjuntoSalidas.begin(); it != this->conjuntoSalidas.end(); ++it) {
		if((it)->first == jugador) {
			//it->second = new DtFechaHora(fechaSalida->getAnio(), fechaSalida->getMes(), fechaSalida->getDia(), fechaSalida->getHora(), fechaSalida->getMinuto());
			this->conjuntoSalidas[jugador]=fechaSalida;
			break;	
		}
	}
	
}




