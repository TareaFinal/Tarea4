#include "../partida.h"
#include <string>
#include <iostream>
using namespace std;

	// Constructor
Partida::Partida(int idpartida, DtFechaHora* duracion,DtFechaHora inicio, string videojuego, Jugador* player)
{
	idPartida=idpartida;
	duracion=null;
	FechaInicio=getFechaSistema();
	Videojuego=videojuego;
	player=player;
}
	// Destructor
Partida::~Partida(){
}
	
	// Setters
	void setIdPartida(int id){
		idPartida=id;
	}
	void setDuracion(DtFechaHora duracion){
		duracion=duracion;
	}
	void setFechaInicio(DtFechaHora fechainicio){
		FechaInicio=fechainicio;
	}
	void setVideoJuego(string juego){
		Videojuego=juego;
	}
	void setJugador(Jugador* jugador){
		player=jugador;
	}
	// Getters
	int getPartida{
		return idPartida;
	}
	DtFechaHora getDuracion(){
		return duracion;
	}
	DtFechaHora getFechaInicio(){
		return FechaInicio;
	}
	string getVideojuego(){
		return Videojuego;
	}
	Jugador* getJugador(){
		return player;
	}
	//no hay metodos
}
