#ifndef PARTIDAMULTIJUGADOR
#define PARTIDAMULTIJUGADOR

#include "partida.h"
#include "DataTypes/DtFechaHora.h"
#include "DataTypes/DtJugador.h"
#include <string>
#include <map>
using namespace std;
class Partida;
class PartidaMultijugador : public Partida {
private:
	bool Transmitida;
	//Jugador j; DtFechaHora Salidas[*, *];
	set<Comentario> colComentarios;
	struct {
		DtJugador jug;
		DtFechaHora fecha;
	} str;
	set<str> Conjunto;
public:
	//Constructor
	PartidaMultijugador(int idPartida, DtFechaHora duracion, DtFechaHora FechaInicio, string juego, bool transmitida, string jugador,map<string,DtFechaHora> Salidas);
	//Destructor
	~PartidaMultijugador();
	//Setters
	void setTransmitida(bool transmit);
	//void setSalidas(Jugador jug,DtFechaHora fecha);
	//Getters
	bool getTransmitida();
	map<string,DtFechaHora> getSalidas();
	//operaciones
	float darTotalDeHorasParticipantes();
	set<DtJugador> getDtJugadoresUnidos(); //los jugadores que se unieron en algun momento
	set<DtJugador> getDtJugadoresActivos(); //los jugadores que estan jugando
	void terminarPartida();
	DtPartidaMultijugador getDataPartida();
};
#endif
