#include "DataTypes/DtVideojuego.h"
#include "DataTypes/DtJugador.h"
#include <vector>
#include "partida.h"
using namespace std;

class iControladorPartidas {
	
	public:
                //virtual float darHorasDePartida(Partida partida) = 0;
                virtual vector<DtVideojuego> obtenerVideojuegosJugador() = 0;
                virtual vector<DtJugador> obtenerJugadoresSuscriptos() = 0;
                virtual vector<DtJugador> obtenerJugadoresMulti(int idPartida) = 0;
                virtual bool ingreseIdPartida(int idPartida) = 0;
                virtual void finalizarPartida() = 0;
               // virtual vector<DtJugador> jugadoresSuscriptosAVideojuego(string nombre) = 0;
                
                virtual void seleccionarJugadores(vector<DtJugador> idJugadores);
};