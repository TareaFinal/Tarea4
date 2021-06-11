#include "DataTypes/DtEstadistica.h"
#include "DataTypes/DtVideojuego.h"
#include "DataTypes/DtCategoria.h"
#include "DataTypes/DtJugador.h"
#include "IControladorPartidas.h"
#include <string>
#include <set>
//#include "partida.h"
//#include "partidaIndividual.h"
//#include "partidaMultijugador.h"
using namespace std;

class ControladorPartidas : public iControladorPartidas {
	
	private:
		static ControladorPartidas instancia;
                set<Partida> partidas;
	public:
                static ControladorPartidas getInstancia();
                float darHorasDePartida(Partida partida);
                set<DtVideojuego> obtenerVideojuegosJugador();
                set<DtJugador> obtenerJugadoresSuscriptos(int idPartida);
                set<DtJugador> obtenerJugadoresMulti(int idPartida);
                bool ingreseIdPartida(int idPartida);
                void finalizarPartida(int idPartida);
                set<DtJugador> jugadoresSuscriptosAVideojuego(string nombre);
};