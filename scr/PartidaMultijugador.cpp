#include "../partidaMultijugador.h"
#include <string>
#include <iostream>
#include <time.h>
using namespace std;

	// Constructor
PartidaMultijugador::PartidaMultijugador(int idPartida, DtFechaHora* duracion, DtFechaHora fechaInicio,string juego, Jugador* player, bool transmitida, 
										Jugador sal1,DtFechaHora sal2) : Partida(idPartida,null,fechaInicio,juego,player)
{
	Transmitida=transmitida;
	colComentarios=null;
}
	// Destructor
PartidaMultijugador::~PartidaMultijugador(){
}
	
	// Setters
	void PartidaMultijugador::setTransmitida(bool transmit){
		Transmitida=transmit;
	}
	
	/*void PartidaMultijugador::setsalida1(Jugador salid1){
		salida1=salid1;
	}
	void setsalida2(DtFechaHora salid2){
		salida2=salid2;
	}*/
	
	
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
		float d=0;
		DtFechaHora x;
		set<DtJugador>::iterator it;
		for (it = Conjunto.begin(); it != Conjunto.end(); ++it) {
    		if (it->fecha!=null) {
    			x=duracionDt(fechaInicial,fecha);
    			d= d + x.getAnio()*365*24 + x.getMes()*30*24 + x.getDia()*24
    			+ x.getHora() + x.getMinuto()/60;
			} //recorro el conjunto de jugadores y salidas para la suma de duraciones;
		}
		return d;
	}
	set<DtJugador> getDtJugadoresUnidos(){
		set<DtJugador>::iterator it;
		for (it = Conjunto.begin(); it != Conjunto.end(); ++it) {
    		conj.insert(*it.jug); //recorro el conjunto de jugadores y salidas para agregar al nuevo conjunto creado que devolveré
		}
		return conj;
	}
	void terminarPartida(){
		DtFechaHora fechafin=getFechaSistema();
		duracion=duracionDt(fechaInicial,fechafin); //llamo a la funcion auxiliar
		set<DtJugador>::iterator it;
		for (it = Conjunto.begin(); it != Conjunto.end(); ++it) {
    		if(it.fecha==null) it.fecha=fechafin; //recorro el conjunto de Jugadores y si aun no ha terminado su partida la termino
		}
	}
	DtPartida getDataPartida(){
		DtPartidaMultijugador dtpm=DtPartidaMultijugador(duracion,FechaInicio,player.getNick(),Videojuego, 
								Transmitida, string *nicknameJugadoresUnidos, colComentarios);

	}
}
