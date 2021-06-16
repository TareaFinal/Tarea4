#ifndef PARTIDA
#define PARTIDA

#include "DataTypes/DtFechaHora.h"
#include "DataTypes/DtPartida.h"
#include "jugador.h"

#include <string>


class Partida {

	protected:
		int idPartida;
		Jugador *duenio;
		DtFechaHora *duracion;
		DtFechaHora *FechaInicio;
		string Videojuego;
	public:
		//Constructor
	
		//Setters
		void setIdPartida(int id);
	//	void setDuracion(DtFechaHora *duracion);
		void setFechaInicio(DtFechaHora *fechainicio);
		void setVideoJuego(string juego);
		//Getters
		int getPartida();
		DtFechaHora *getDuracion();
		DtFechaHora *getFechaInicio();
		string getVideojuego();
		//operaciones
		virtual float darTotalDeHorasParticipantes() = 0;
		virtual void terminarPartida();
		virtual DtPartida *getDataPartida();
		
		//Destructor
		
};

#endif
