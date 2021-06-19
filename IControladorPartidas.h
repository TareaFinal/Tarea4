#ifndef ICONTROLADORPARTIDAS
#define ICONTROLADORPARTIDAS

#include "DataTypes/DtVideojuego.h"
#include "DataTypes/DtJugador.h"
#include "DataTypes/DtPartida.h"
#include <vector>
#include <set>

using namespace std;

class iControladorPartidas {
	
	public:
                virtual float darHorasDePartida(string videojuego) = 0; //esta en cp.h
                virtual vector<DtVideojuego> obtenerVideojuegosJugador() = 0;
                virtual vector<DtJugador> obtenerJugadoresSuscriptos() = 0;
                virtual set<string> obtenerJugadoresMulti(int idPartida) = 0;
                virtual bool ingreseIdPartida(int idPartida) = 0;
                virtual void finalizarPartida() = 0;
                virtual vector<DtPartida*> ListarPartidasNoFinalizadas()=0;
               // virtual vector<DtJugador> jugadoresSuscriptosAVideojuego(string nombre) = 0;
};

#endif
