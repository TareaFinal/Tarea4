#include "DtPartida.h"
#include "DtFechaHora.h"
#include <string>
using namespace std;

class PartidaIndividual : public Partida {
public:
	//Constructor
	PartidaIndividual(int idPartida, DtFechaHora duracion, DtFechaHora FechaInicio, string juego, string emailjugador);
	//Destructor
	~PartidaIndividual();
	//operaciones
	float darTotaldeHorasParticipantes():float
	bool esContinuacion();
	void terminarPartida();
	DtPartida getDataPartida();
	string getJugador();
};
