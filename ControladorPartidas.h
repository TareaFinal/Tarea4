#include "DataTypes/DtEstadistica.h"
#include "DataTypes/DtVideojuego.h"
#include "DataTypes/DtCategoria.h"
#include "DataTypes/DtJugador.h"
#include <string>
using namespace std;

class ControladorPartidas : public iControladorPartidas {
	
	private:
		static ControladorPartidas instancia;
                set<Partida> partidas;
	public:
                static ControladorPartidas getInstancia();
                float darHorasDePartida(Partida partida);
                Set<DtVideojuego> obtenerVideojuegosJugador();
                Set<DtJugador> obtenerJugadoresSuscriptos(int idPartida);
                Set<DtJugador> obtenerJugadoresMulti(int idPartida);
                bool ingreseIdPartida(int idPartida);
                void finalizarPartida(int idPartida);
                Set<DtJugador> jugadoresSuscriptosAVideojuego(string nombre);
};