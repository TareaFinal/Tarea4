#ifndef PARTIDAMULTIJUGADOR
#define PARTIDAMULTIJUGADOR

#include "partida.h"
#include "fabrica.h"
#include "DataTypes/DtPartida.h"
#include "DataTypes/DtComentario.h"
#include "DataTypes/DtPartidaMultijugador.h"
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;


class PartidaMultijugador : public Partida {
	private:
		bool Transmitida;
		
	map<string, DtFechaHora*> conjuntoSalidas;
	vector<DtComentario*> colComentarios;	
	
	public:
		typedef map<string, DtFechaHora*> map_type;
		//Constructor
		PartidaMultijugador(int idPartida, string duenio, DtFechaHora* fechaInicio, string juego, bool transmitida, vector<string> jugUnidos);

		//Setters
		void setTransmitida(bool transmit);
		void setSalida(string jugador,DtFechaHora *fechaSalida);

		
		//Getters
		bool getTransmitida();
		set<string> getNicknameJugadoresActivos();
	//	Jugador,DtFechaHora *getSalidas();
		
		//operaciones
		float darTotalDeHorasParticipantes();
		set<string> getDtJugadoresUnidos();
		void terminarPartida();
		DtPartida *getDataPartida();
		
		
		void abandonaPartidaJugador(string jugador);
		
		//Destructor
		~PartidaMultijugador() {
		};
};

#endif
