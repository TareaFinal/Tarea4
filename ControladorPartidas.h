#ifndef CONTROLADORPARTIDAS
#define CONTROLADORPARTIDAS

#include "IControladorPartidas.h"
#include <string>
#include <set>
#include "partida.h"
//#include "partidaIndividual.h"
//#include "partidaMultijugador.h"
using namespace std;

class Partida;

class ControladorPartidas : public iControladorPartidas {
	
	private:
		static ControladorPartidas *instancia;
        set<Partida*> partidas;
        ControladorPartidas ();
	public:
                static ControladorPartidas *getInstancia();
		      
                float darHorasDePartida(string videojuego);
                set<DtVideojuego*> obtenerVideojuegosJugador();
                set<DtJugador*> obtenerJugadoresSuscriptos(int idPartida);
                set<DtJugador*> obtenerJugadoresMulti(int idPartida);
                bool ingreseIdPartida(int idPartida);
                void finalizarPartida(int idPartida);
                set<DtJugador*> jugadoresSuscriptosAVideojuego(string nombre);
};

#endif
