#ifndef PARTIDAMULTIJUGADOR
#define PARTIDAMULTIJUGADOR

#include "partida.h"

#include <string>
using namespace std;


class PartidaMultijugador : public Partida {
	private:
		bool Transmitida;
		//Jugador, DtFechaHora Salidas[*,*];
	public:
		//Constructor
		PartidaMultijugador(int idPartida, string juego, bool transmitida);

		//Setters
		void setTransmitida(bool transmit);
		void setSalidas(Jugador *jug,DtFechaHora *fecha);
		
		//Getters
		bool getTransmitida();
	//	Jugador,DtFechaHora *getSalidas();
		
		//operaciones
		float darTotalDeHorasParticipantes();
		set<DtJugador*> getDtJugadoresUnidos();
		void terminarPartida();
		DtPartida *getDataPartida();
		
		//Destructor
		~PartidaMultijugador();
};

#endif
