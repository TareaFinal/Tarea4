#ifndef PARTIDAINDIVIDUAL
#define PARTIDAINDIVIDUAL

#include "DataTypes/DtPartida.h"
#include "DataTypes/DtFechaHora.h"
#include "partida.h"

#include <string>
using namespace std;

class PartidaIndividual : public Partida {
	private:
		PartidaIndividual  *continuacion;	
	
	public:
		//Constructor
		PartidaIndividual(int idPartida, DtFechaHora *FechaInicio, string juego);
		//Destructor
		~PartidaIndividual();
		//operaciones
		float darTotalDeHorasParticipantes();
		PartidaIndividual *getContinuacion();
		void terminarPartida();
		DtPartida *getDataPartida();
};

#endif
