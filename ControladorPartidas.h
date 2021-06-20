#ifndef CONTROLADORPARTIDAS
#define CONTROLADORPARTIDAS

#include "IControladorPartidas.h"
#include "partida.h"
#include "partidaIndividual.h"
#include "partidaMultijugador.h"
#include "fabrica.h"
#include <string>
#include <set>
#include <map>

using namespace std;

class Partida;
class PartidaIndividual;

class ControladorPartidas : public iControladorPartidas {
	
	private:
		static ControladorPartidas* instancia;// es static porque es operacion de clase?
		vector<string> JugadoresApartidaMulti;
        map<int, Partida*> dicPartidas;
        ControladorPartidas();
        // variables de memoria del sistema para los casos de uso con memoria
        string videojuegoseleccionado;
        int partidaIndividualAContinuar;
        int partidaAfinalizar;
        string videoJuegoAContinuar;
        string tipoPartida;
        bool envivo;
        PartidaIndividual* Continuacion=NULL;
        
        // variable para asignacion automatica de identificador de partidas;
        
        int identificadorpartida = 1;
        
	public:
        static ControladorPartidas* getInstancia();
        float darHorasDePartida(string videojuego);  // esto hay que implementarlo pero deberia reibir un id partida o un id jugador.
       	


        // Caso de uso iniciar partida
        vector<DtVideojuego*> obtenerVideojuegosJugador();
        vector<DtPartida*> ObtenerAnteriores(); // se define la partida como INDIVIDUAL y es CONTINUACION y se devuelve todas las partidas anteriores para el usuario en sesion y el videojuego guardado
        vector<DtJugador> obtenerJugadoresSuscriptos();// devuelve los jugadores suscriptos a el videojuego en memoria. PARTIDA MULTIJUGADOR
        vector<DtPartida*> ObtenerPartidasActivas();   
        set<string> obtenerJugadoresMulti(int idPartida); // dentro de finalizar partidamultijudador devuelve los jugadores que estan jugando.
        vector<DtPartida*> ListarPartidasNoFinalizadas(); // devuelve todas las partidas no finalizadas del jugador sin importar el videojuego ni si es multijugador o individual.

       
		void SeleccionarVideojuego(string Nombre); // se guarda el nombre en el controlador

        
        void seleccionarPartida(int idPartida); // da un id partida hay que controlar que corresponda a uno de los dados anteriormente.

        void Transmitida(bool t);  // se define la partida como MULTIJUGADOR y se guarda ese dato para luego armar la partida.
         
        void seleccionarJugadores(vector<string> idJugadores); // guarda los jugadores en la memoria y controla que efectivamente esten suscriptos.
        void iniciarPartida();
        
        
        // Caso de uso abandonar partida multijugador
         void AbandonarPartidaActiva(int id);  // manda el id de la partida multijugador  


        // Caso de uso finalizar partida
        
        bool ingreseIdPartida(int idPartida); // el sistema guarda esta info para finalizar la partida
        void finalizarPartida(); // finaliza la partida cuyo id está en memoria producto de ingresarIdPartida 
        

        //void finalizarPartidaMultijugador(); //finaliza una partida multijugador y saca a todos los jugadores
        
        // De eliminar videojuego
        void eliminarPartidasVideojuego(string nombre);
        ~ControladorPartidas();
};

#endif
