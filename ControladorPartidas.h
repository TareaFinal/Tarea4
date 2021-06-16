#ifndef CONTROLADORPARTIDAS
#define CONTROLADORPARTIDAS
#include "ControladorVideojuegos.h"
#include "ControladorUsuarios.h"
#include "DataTypes/DtEstadistica.h"
#include "DataTypes/DtVideojuego.h"
#include "DataTypes/DtCategoria.h"
#include "DataTypes/DtPartidaMultijugador.h"
#include "DataTypes/DtJugador.h"
#include "DataTypes/DtPartidaIndividual.h"
#include "IControladorPartidas.h"
#include "partidaIndividual.h"
#include "partida.h"  // como es lo del forward declaration??
//#include "partidaIndividual.h"
#include "partidaMultijugador.h"
#include <vector>
#include <string>
#include <map>

using namespace std;
class Jugador;   // Forward declaration

                //class Partida;
class ControladorPartidas : public iControladorPartidas {
	
	private:
        static ControladorPartidas* instancia;// es static porque es operacion de clase?
        map<int, Partida*> dicPartidas;
        ControladorPartidas();
        // variables de memoria del sistema para los casos de uso con memoria
        string videojuegoseleccionado;
        int partidaIndividualAContinuar;
        int partidaAfinalizar;
        string videoJuegoAContinuar;
        string tipoPartida;
        bool envivo;
        bool continuacion=false;
        /*
        vector<DtPartida> copiaAnterioresEnControlador;
        vector<DtVideojuego> copiaVideojuegosJugador;
        vector<DtJugador> copiaSetJugadores;
        */
        vector<DtJugador> JugadoresApartidaMulti;
        // variable para asignacion automatica de identificador de partidas;
        
        int identificadorpartida = 1;
	public:
        static ControladorPartidas* getInstancia();
        //float darHorasDePartida(Partida partida);
        


        // Caso de uso iniciar partida
        vector<DtVideojuego> obtenerVideojuegosJugador();
        void SeleccionarVideojuego(string Nombre); // se guarda el nombre en el controlador

        vector<DtPartidaIndividual> ObtenerAnteriores(); // se define la partida como INDIVIDUAL y es CONTINUACION y se devuelve todas las partidas anteriores para el usuario en sesion y el videojuego guardado
        void seleccionarPartida(int idPartida); // da un id partida hay que controlar que corresponda a uno de los dados anteriormente.

        void Transmitida(bool t);  // se define la partida como MULTIJUGADOR y se guarda ese dato para luego armar la partida.
        vector<DtJugador> obtenerJugadoresSuscriptos();// devuelve los jugadores suscriptos a el videojuego en memoria. PARTIDA MULTIJUGADOR
        
        void seleccionarJugadores(vector<DtJugador> idJugadores); // guarda los jugadores en la memoria y controla que efectivamente esten suscriptos.
        void iniciarPartida();
        
        
        // Caso de uso abandonar partida multijugador
        vector<DtPartidaMultijugador> ObtenerPartidasActivas();   
        void AbandonarPartidaActiva(int id);  // manda el id de la partida multijugador  


        // Caso de uso finalizar partida
        vector<DtPartida> ListarPartidasNoFinalizadas(); // devuelve todas las partidas no finalizadas del jugador sin importar el videojuego ni si es multijugador o individual.

        bool ingreseIdPartida(int idPartida); // el sistema guarda esta info para finalizar la partida
        void finalizarPartida(); // finaliza la partida cuyo id está en memoria producto de ingresarIdPartida 
        

        vector<DtJugador> obtenerJugadoresMulti(int idPartida); // dentro de finalizar partidamultijudador devuelve los jugadores que estan jugando.
        //void finalizarPartidaMultijugador(); //finaliza una partida multijugador y saca a todos los jugadores
        
        // De eliminar videojuego
        void eliminarPartidasVideojuego(string nombre);
        ~ControladorPartidas();
};
#endif