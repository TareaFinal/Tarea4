#include "../partidaMultijugador.h"
#include <string>
#include <iostream>
using namespace std;

	// Constructor
PartidaMultijugador::PartidaMultijugador(int idPartida, DtFechaHora* duracion, DtFechaHora fechaInicio,string juego, Jugador* player, bool transmitida, 
										Jugador sal1,DtFechaHora sal2) : Partida(idPartida,null,fechaInicio,juego,player)
{
	Transmitida=transmitida;
	salida1=sal1
	salida2=sal2;
	
}
	// Destructor
PartidaMultijugador::~PartidaMultijugador(){
}
	
	// Setters
	void PartidaMultijugador::setTransmitida(bool transmit){
		Transmitida=transmit;
	}
	void PartidaMultijugador::setsalida1(Jugador salid1){
		salida1=salid1;
	}
	void setsalida2(DtFechaHora salid2){
		salida2=salid2;
	}
	
	// Getters
	bool PartidaMultijugador::getTransmitida(){
		return Transmitida;
	}
	Jugador PartidaMultijugador::getsalida1(){
		return salida1;
	}
	DtFechaHora PartidaMultijugador::getsalida2(){
		return salida2;
	}

	//funciones
	float darTotalDeHorasParticipantes(){
		
	}
	set<DtJugador> getDtJugadoresUnidos(){
		set<DtJugador> conj;
		set<DtJugador>::iterator it;
		for (it = Conjunto.begin(); it != Conjunto.end(); ++it) {
    		conj.insert(*it.jug);
		}
		return conj;
	}
	void terminarPartida(){
		
	}
	DtPartida getDataPartida(){
		DtPartidaMultijugador dtpm=DtPartidaMultijugador(duracion,FechaInicio,player.getNick(),Videojuego, 
								Transmitida, string *nicknameJugadoresUnidos, colComentarios);

	}
}
