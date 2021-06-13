#include "DataTypes/DtEstadistica.h"
#include "DataTypes/DtVideojuego.h"
#include "DataTypes/DtCategoria.h"
#include "DataTypes/DtJugador.h"
#include "IControladorPartidas.h"
#include "ControladorVideojuegos.h"
#include "ControladorUsuarios.h"

#include <string>
#include <map>
#include "partida.h"  // como es lo del forward declaration??
#include "partidaIndividual.h"
#include "partidaMultijugador.h"
///#include "partidaIndividual.h"
//#include "partidaMultijugador.h"
using namespace std;
class Jugador;  // Forward declaration
//class Partida;
class ControladorPartidas : public iControladorPartidas {
	
	private:
		static ControladorPartidas* instancia=NULL; // es static porque es operacion de clase?
        map<int, Partida*> dicPartidas;
        ControladorPartidas();
        string videojuegoseleccionado;
        int partidaIndividualAContinuar;
        string tipoPartida;
        set<DtPartida*> copiaAnterioresEnControlador;
        bool envivo;
	public:
        static ControladorPartidas* getInstancia();
        float darHorasDePartida(Partida partida);
        set<DtVideojuego> obtenerVideojuegosJugador();
        void SeleccionarVideojuego(string Nombre); // se guarda el nombre en el controlador

        set<DtJugador> obtenerJugadoresSuscriptos();// devuelve los jugadores suscriptos a el videojuego en memoria. PARTIDA MULTIJUGADOR
        //set<DtJugador> obtenerJugadoresMulti(int idPartida); // ESTO NO SE QUE ES
        bool ingreseIdPartida(int idPartida); // el sistema guarda esta info para continuar partida INDIVIDUAL no finalizada.
        void finalizarPartida(int idPartida);
        //set<DtJugador> jugadoresSuscriptosAVideojuego(string nombre);
        void eliminarPartidasVideojuego(string nombre);
        void seleccionarPartida(int idPartida); // da un id partida hay que controlar que corresponda a uno de los dados anteriormente.
        set<DtPartida> ObtenerAnteriores(); // se define la partida como INDIVIDUAL y se devuelve todas las partidas anteriores para el usuario en sesion y el videojuego guardado
        void Transmitida(bool t);  // se define la partida como MULTIJUGADOR y se guarda ese dato para luego armar la partida.
        set<DtPartida> ListarPartidasNoFinalizadas(); // devuelve todas las partidas no finalizadas del jugador sin importar el videojuego
        void seleccionarJugadores(set<string> idJugadores); // guarda los jugadores en la memoria y controla que efectivamente esten suscriptos.
        void iniciarPartida(); // crea una instancia de partida con los datos del sistema tiene que armar una partida individual o multi segun corresponda
};