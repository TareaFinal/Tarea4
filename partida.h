#ifndef PARTIDA
#define PARTIDA
#include "DataTypes/DtFechaHora.h"
#include "DataTypes/DtPartida.h"
//#include "comentario.h"
using namespace std;
#include <string>


class Partida {

protected:
	int idParida;
	DtFechaHora* duracion;
	DtFechaHora FechaInicio;
	string Videojuego;
	Jugador* player; //Jugador que inició la partida
public:
	//Constructor
	Partida(int idpartida, DtFechaHora* duracion, DtFechaHora FechaInicio,string videojuego,Jugador* player);
	//Destructor
	~Partida();
	//Setters
	void setIdPartida(int id);
	void setDuracion(DtFechaHora duracion);
	void setFechaInicio(DtFechaHora fechainicio);
	void setVideoJuego(string juego);
	//Getters
	int getPartida();
	DtFechaHora getDuracion();
	DtFechaHora getFechaInicio();
	string getVideojuego();
	virtual string getJugador(); //devuelve el jugador o el que la inicio si es multi
	//operaciones
	float darTotalDeHorasParticipantes();
	virtual void terminarPartida();
	DtPartida getDataPartida(); // ojo con esto capaz que no tiene que haber y solo tiene que haber una getdtpartidaindividual y otra multi
	virtual string tipo(); // devuelve "individual" o "multijugador" segun coresponda

};
#endif
