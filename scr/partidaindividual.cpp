#include "partidaIndividual.h"
#include "DtPartidaIndividual.h"
#include "DtFechaHora.h"
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
		float diasAhoras=duracion.getDia()/24;
	}
	bool esContinuacion(){
		return (continuacion!=null);
	}
	void terminarPartida(){
		
	}
	DtPartida getDataPartida(){
		int k;
		if (continuacion==null) k=0;
		else k=continuacion.getPartida(); //retorna el id de la partida que se esta continuando
		DtPartida dtp=DtPartidaIndividual(duracion,fechaini,player,Videojuego,k);
		return dtp;
	}
}
