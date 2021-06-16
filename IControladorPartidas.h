#ifndef ICONTROLADORPARTIDAS
#define ICONTROLADORPARTIDAS

#include "DataTypes/DtVideojuego.h"
#include "DataTypes/DtJugador.h"
#include <set>
#include "partida.h"

using namespace std;

class iControladorPartidas {
	
	public:
                virtual float darHorasDePartida(string videojuego) = 0;
                virtual set<DtVideojuego*> obtenerVideojuegosJugador() = 0;
                virtual set<DtJugador*> obtenerJugadoresSuscriptos(int idPartida) = 0;
                virtual set<DtJugador*> obtenerJugadoresMulti(int idPartida) = 0;
                virtual bool ingreseIdPartida(int idPartida) = 0;
                virtual void finalizarPartida(int idPartida) = 0;
                virtual set<DtJugador*> jugadoresSuscriptosAVideojuego(string nombre) = 0;
};

#endif
