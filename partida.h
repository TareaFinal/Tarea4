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
		Partida(int idpartida, Jugador* duenio, DtFechaHora* duracion, DtFechaHora FechaInicio,string videojuego);
		//Destructor
		~Partida();
		//Setters
		void setIdPartida(int id);
		void setDuenio(Jugador *duenio);
		void setDuracion(DtFechaHora *duracion);
		void setFechaInicio(DtFechaHora *fechainicio);
		void setVideoJuego(string juego);
		//Getters
		int getPartida();
		DtFechaHora *getFechaInicio();
		string getVideojuego();
		DtFechaHora* getDuracion();
		Jugador* getDuenio();
		//Destructor
		Partida::~Partida();
};

#endif
