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
                virtual vector<DtVideojuego*> obtenerVideojuegosJugador() = 0;
                virtual vector<DtJugador> obtenerJugadoresSuscriptos() = 0;
                virtual set<string> obtenerJugadoresMulti(int idPartida) = 0;
                virtual bool ingreseIdPartida(int idPartida) = 0;
                virtual void finalizarPartida() = 0;
                virtual vector<DtPartida*> ListarPartidasNoFinalizadas()=0;
               // virtual vector<DtJugador> jugadoresSuscriptosAVideojuego(string nombre) = 0;
               	virtual vector<DtPartida*> ObtenerAnteriores() = 0;
               	virtual void SeleccionarVideojuego(string Nombre) = 0;
               	virtual void seleccionarPartida(int idPartida) = 0;
               
               	virtual void Transmitida(bool t) = 0;  // se define la partida como MULTIJUGADOR y se guarda ese dato para luego armar la partida.
               	virtual void setTipoPartida(string tipo) = 0;
         
        		virtual void seleccionarJugadores(vector<string> idJugadores) = 0; // guarda los jugadores en la memoria y controla que efectivamente esten suscriptos.
        		virtual void iniciarPartida() = 0;
        		
        		virtual void AbandonarPartidaActiva(int id) = 0;
        		virtual vector<DtPartida*> ObtenerPartidasActivas() = 0;
};

#endif
