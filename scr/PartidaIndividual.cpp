#include "partidaIndividual.h"
#include "DtPartidaIndividual.h"
#include "DtFechaHora.h"
#include "ControladorUsuarios.h"
#include <string>
#include <iostream>
using namespace std;

	// Constructor
PartidaIndividual::PartidaIndividual(int idPartida, Jugador* duenio, DtFechaHora* duracion, DtFechaHora fechaInicio,string juego, 
									,PartidaIndividual* cont) : Partida(idPartida,duenio,null,fechaInicio,juego)
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
			float dur=duracion->getAnio()*365*24 + duracion->getMes()*30*24 + duracion->getDia()*24 + duracion->getHora() + duracion->getMinuto()/60;
		}
		else { throw invalid_argument "Aun no ha terminado"; }
	}
	
	bool esContinuacion(){
		return (continuacion!=null;)
	}
	
	void terminarPartida(){
		DtFechaHora fechafin=getFechaSistema();
		duracion=duracionDt(fechaInicial,fechafin);
	}
	
	DtFechaHora duracionDt(DtFechaHora fechaInicial, DtFechaHora fechaFinal){
		DtFechaHora dur;
		int anio=fechaFinal.getAnio() - fechaInicial.getAnio();
		int mes=fechafin.getMes() - fechaInicio.getMes();
		int dia=fechafin.getDia() - fechaInicio.getDia();
		int hora=fechafin.getHora() - fechaInicio.getHora();
		int minuto=fechafin.getMinuto() - fechaInicio.getMinuto();
		if (minuto<0){
			hora=hora-1;
			minuto=60-abs(minuto);
		}
		if (hora<0){
			dia=dia-1;
			hora=24-abs(hora);
		})
		if (dia<0){
			mes=mes-1;
			dia=30-abs(dia);
		}
		if (mes<0){
			anio=anio-1;
			mes=12-abs(mes);
		}
		dur.setAnio(anio);
		dur.setMes(mes);
		dur.setDia(dia);
		dur.setHora(hora);
		dur.setMinuto(minuto);
		return dur;
	}
	
	DtPartida getDataPartida(){
		int k;
		if (continuacion==null) k=0;
		else k=continuacion->getPartida(); //retorna el id de la partida que se esta continuando
		DtPartida dtp=DtPartidaIndividual(duracion,fechaini,player,Videojuego,k);
		return dtp;
	}
