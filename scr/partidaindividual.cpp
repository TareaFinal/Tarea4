#include "partidaIndividual.h"
#include "DtPartidaIndividual.h"
#include "DtFechaHora.h"
#include <string>
#include <iostream>
using namespace std;

	// Constructor
PartidaIndividual::PartidaIndividual(int idPartida,DtFechaHora* duracion, DtFechaHora fechaInicio,string juego, 
									Jugador* player,PartidaIndividual* cont) : Partida(idPartida,null,fechaInicio,juego,player)
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
		if (duracion!=null){
			float dur=duracion->getAnio()*365*24 + duracion->getMes()*30*24 + duracion->getDia()*24 + duracion->getHora() + duracion->getMinuto()/24;
		}
		else { throw invalid_argument "Aun no ha terminado"; }
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
