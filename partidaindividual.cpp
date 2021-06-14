#include "../partidaIndividual.h"
#include <string>
#include <iostream>
using namespace std;

	// Constructor
PartidaIndividual::PartidaIndividual(int idPartida,DtFechaHora duracion, DtFechaHora fechaInicio,string juego, 
									Jugador* player,PartidaIndividual* cont) : Partida(idPartida,duracion,fechaInicio,juego,player)
{
	continuacion=cont;
}

	// Destructor
PartidaIndividual::~PartidaIndividual(){
}
	
	// no hay Setters
	
	// no hay Getters

	//funciones
	float darTotalDeHorasParticipantes(){
		return this->
	}
	bool esContinuacion(){
		return (continuacion!=null)
	}
	void terminarPartida(){
	}
	DtPartida getDataPartida(){
	}
}
