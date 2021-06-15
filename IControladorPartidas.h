#include "DataTypes/DtVideojuego.h"
#include "DataTypes/DtJugador.h"
#include <set>
#include "partida.h"
using namespace std;

class iControladorPartidas {
	
	public:
                //virtual float darHorasDePartida(Partida partida) = 0;
                virtual set<DtVideojuego> obtenerVideojuegosJugador() = 0;
                virtual set<DtJugador> obtenerJugadoresSuscriptos() = 0;
                virtual set<DtJugador> obtenerJugadoresMulti(int idPartida) = 0;
                virtual bool ingreseIdPartida(int idPartida) = 0;
                virtual void finalizarPartida() = 0;
               // virtual set<DtJugador> jugadoresSuscriptosAVideojuego(string nombre) = 0;
                virtual void seleccionarJugadores(set<DtJugador> idJugadores);
};