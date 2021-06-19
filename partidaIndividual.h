#ifndef PARTIDAINDIVIDUAL
#define PARTIDAINDIVIDUAL

#include "partida.h"
#include "fabrica.h"
#include "DataTypes/DtPartida.h"
#include "DataTypes/DtFechaHora.h"
#include "DataTypes/DtPartidaIndividual.h"


#include <string>
using namespace std;

class PartidaIndividual : public Partida {
	private:
		PartidaIndividual  *continuacion;	
	
	public:
		PartidaIndividual(int idPartida, DtFechaHora *FechaInicio, string juego, string jugador);
		~PartidaIndividual();
		PartidaIndividual *getContinuacion();
		
		
		float darTotalDeHorasParticipantes();
		void terminarPartida();
		DtPartida *getDataPartida();		
};

#endif
