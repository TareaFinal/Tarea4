#include "DtPartida.h"
#include "DtFechaHora.h"
#include <string>
using namespace std;

class PartidaIndividual : public Partida {
public:
	PartidaIndividual* = continua;
	//Constructor
	PartidaIndividual(int idPartida, int duracion, DtFechaHora FechaInicio, string juego, string emailjugador);
	//Destructor
	~PartidaIndividual();
	//operaciones
	float darTotaldeHorasParticipantes() :float;
	//bool esContinuacion();
	void terminarPartida();
	DtPartida getDataPartida();
	string getJugador();
	int Continua(); // si no continua a ninguna devuelve -1 y si no devuelve a la idPartida de la partida a la que continua.
};
