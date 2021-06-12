#include "partida.h"
#include "DtFechaHora.h"
#include "DtJugador.h"
#include <string>
using namespace std;

class PartidaMultijugador : public Partida {
private:
	bool Transmitida;
	Jugador, DtFechaHora Salidas[*,*];
public:
	//Constructor
	PartidaMultijugador(int idPartida, DtFechaHora duracion, DtFechaHora FechaInicio, string juego, bool transmitida, Jugador,DtFechaHora Salidas[*,*]);
	//Destructor
	~PartidaMultijugador();
	//Setters
	void setTransmitida(bool transmit);
	void setSalidas(Jugador jug,DtFechaHora fecha);
	//Getters
	bool getTransmitida();
	Jugador,DtFechaHora getSalidas();
	//operaciones
	float darTotalDeHorasParticipantes();
	set<DtJugador> getDtJugadoresUnidos();
	void terminarPartida();
	DtPartida getDataPartida();
};
