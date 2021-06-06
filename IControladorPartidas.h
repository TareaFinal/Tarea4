#include "DataTypes/DtVideojuego.h"
#include "DataTypes/DtJugador.h"
using namespace std;

class iControladorPartidas {
	
	public:
                virtual float darHorasDePartida(Partida partida) = 0;
                virtual Set<DtVideojuego> obtenerVideojuegosJugador() = 0;
                virtual Set<DtJugador> obtenerJugadoresSuscriptos(int idPartida) = 0;
                virtual Set<DtJugador> obtenerJugadoresMulti(int idPartida) = 0;
                virtual bool ingreseIdPartida(int idPartida) = 0;
                virtual void finalizarPartida(int idPartida) = 0;
                virtual Set<DtJugador> jugadoresSuscriptosAVideojuego(string nombre) = 0;
};