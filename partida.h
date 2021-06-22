#ifndef PARTIDA
#define PARTIDA

#include "DataTypes/DtFechaHora.h"
#include "DataTypes/DtPartida.h"

#include <string>


class Partida {

	protected:
		int idPartida;
		string duenio;
		float duracion;
		DtFechaHora *FechaInicio;
		string Videojuego;
	public:
		//Constructor
	
		//Setters
		void setIdPartida(int id);
		void setDuracion(float dur);
		void setFechaInicio(DtFechaHora *fechainicio);
		void setVideoJuego(string juego);
		void setJugador(string jugador);
		//Getters
		int getPartida();
		DtFechaHora* getFechaInicio();
		string getVideojuego();
		float getDuracion();
		string getJugador();
		float diferencia(DtFechaHora *fechaInicial, DtFechaHora *fechafin);
		//operaciones
		virtual float darTotalDeHorasParticipantes() = 0;
		virtual void terminarPartida() = 0;
		virtual DtPartida *getDataPartida() = 0;
		
		//Destructor
		
};

#endif
