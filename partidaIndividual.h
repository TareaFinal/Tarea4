#ifndef PARTIDAINDIVIDUAL
#define PARTIDAINDIVIDUAL

#include "DataTypes/DtPartida.h"
#include "DataTypes/DtFechaHora.h"
#include "partida.h"
#include <string>
using namespace std;

class PartidaIndividual : public Partida {
public:
	
	//Constructor
	PartidaIndividual(int idPartida, DtFechaHora* duracion, DtFechaHora FechaInicio, string juego, string emailjugador);
	//Destructor
	~PartidaIndividual();
	//operaciones
	PartidaIndividual* continua;
	float darTotaldeHorasParticipantes();
	void terminarPartida();
	DtPartidaIndividual getDataPartida();
	string getJugador();
	int Continua(); // si no continua a ninguna devuelve -1 y si no devuelve a la idPartida de la partida a la que continua.
};
#endif
