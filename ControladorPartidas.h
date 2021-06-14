#ifndef CONTROLADORPARTIDAS
#define CONTROLADORPARTIDAS

#include "DataTypes/DtEstadistica.h"
#include "DataTypes/DtVideojuego.h"
#include "DataTypes/DtCategoria.h"
#include "DataTypes/DtPartidaMultijugador.h"
#include "DataTypes/DtJugador.h"
#include "IControladorPartidas.h"
#include "ControladorVideojuegos.h"
#include "ControladorUsuarios.h"
//#include "partida.h"  // como es lo del forward declaration??
#include "partidaIndividual.h"
#include "partidaMultijugador.h"
#include <set>
#include <string>
#include <map>

using namespace std;
class Jugador;   // Forward declaration

                //class Partida;
class ControladorPartidas : public iControladorPartidas {
	
	private:
		static ControladorPartidas* instancia = NULL; // es static porque es operacion de clase?
        map<int, Partida*> dicPartidas;
        ControladorPartidas();
        // variables de memoria del sistema para los casos de uso con memoria
        string videojuegoseleccionado;
        int partidaIndividualAContinuar;
        string tipoPartida;
        bool envivo;
        bool continuacion=false;
        set<DtPartida> copiaAnterioresEnControlador;
        set<DtVideojuego> copiaVideojuegosJugador;
        set<DtJugador> copiaSetJugadores;
        set<DtJugador> JugadoresApartidaMulti;
        // variable para asignacion automatica de identificador de partidas;
        int identificadorpartida = 0;
	public:
        static ControladorPartidas* getInstancia();
        //float darHorasDePartida(Partida partida);
        


        // Caso de uso iniciar partida
        set<DtVideojuego> obtenerVideojuegosJugador();
        void SeleccionarVideojuego(string Nombre); // se guarda el nombre en el controlador

        set<DtPartida> ObtenerAnteriores(); // se define la partida como INDIVIDUAL y es CONTINUACION y se devuelve todas las partidas anteriores para el usuario en sesion y el videojuego guardado
        void seleccionarPartida(int idPartida); // da un id partida hay que controlar que corresponda a uno de los dados anteriormente.

        void Transmitida(bool t);  // se define la partida como MULTIJUGADOR y se guarda ese dato para luego armar la partida.
        set<DtJugador> obtenerJugadoresSuscriptos();// devuelve los jugadores suscriptos a el videojuego en memoria. PARTIDA MULTIJUGADOR
        void seleccionarJugadores(set<string> idJugadores); // guarda los jugadores en la memoria y controla que efectivamente esten suscriptos.
        void iniciarPartida();
        
        
        // Caso de uso abandonar partida multijugador
        set<DtPartidaMultijugador> ObtenerPartidasActivas();   
        AbandonarPartidaActiva(int id);  // manda el id de la partida multijugador  


        // Caso de uso finalizar partida
        set<DtPartida> ListarPartidasNoFinalizadas(); // devuelve todas las partidas no finalizadas del jugador sin importar el videojuego
        bool ingreseIdPartida(int idPartida); // el sistema guarda esta info para finalizar la partida
        void finalizarPartidaIndividual(); // finaliza la partida cuyo id está en memoria producto de ingresarIdPartida 
        

        set<DtJugador> obtenerJugadoresMulti(int idPartida); // dentro de finalizar partidamultijudador devuelve los jugadores que estan jugando.
        void finalizarPartidaMultijugador(); //finaliza una partida multijugador y saca a todos los jugadores
        
        // De eliminar videojuego
        void eliminarPartidasVideojuego(string nombre);
        ~ControladorPartidas();
};
#endif