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
		static ControladorPartidas* instancia;  // controladorpartidas es singleton
		vector<string> JugadoresApartidaMulti; // vector para guardar en memoria los Jugadores que se uniran a una partida multijugador
        map<int, Partida*> dicPartidas; // Colección de partidas
        ControladorPartidas();  // constructor del controlador
        // variables de memoria del sistema para los casos de uso con memoria
        string videojuegoseleccionado; // guarda el nombre del videojuego con el que se iniciaria partida
        int partidaIndividualAContinuar; // guarda la partida a continuar en caso de iniciar partida individual. 
        int partidaAfinalizar; // guarda la partida a finalizar
        string videoJuegoAContinuar; // guarda el videojuego que se continuara en partida individual
        string tipoPartida; // guarda el tipo de partida
        bool envivo; // guarda si la partida multijugador sera o no en vivo.
        PartidaIndividual* Continuacion=NULL;   //guarda la instancia de la partida que se va a continuar en iniciar partida
        
        // variable para asignacion automatica de identificador de partidas;
        
        int identificadorpartida = 1; // contador de partidas
        
	public:
        static ControladorPartidas* getInstancia();  //instancia del controlador de partidas.
        float darHorasDePartida(string videojuego);  // esto hay que implementarlo pero deberia reibir un id partida o un id jugador.
       	


        // Caso de uso iniciar partida
        vector<DtVideojuego*> obtenerVideojuegosJugador(); // funcion del sistema en iniciar partidamultijugador
        vector<DtPartida*> ObtenerAnteriores(); // se define la partida como INDIVIDUAL y es CONTINUACION y se devuelve todas las partidas anteriores para el usuario en sesion y el videojuego guardado
        vector<DtJugador> obtenerJugadoresSuscriptos();// devuelve los jugadores suscriptos al videojuego en memoria. PARTIDA MULTIJUGADOR
        
        set<string> obtenerJugadoresMulti(int idPartida); // dentro de finalizar partidamultijudador devuelve los jugadores que estan jugando.
        vector<DtPartida*> ListarPartidasNoFinalizadas(); // devuelve todas las partidas no finalizadas del jugador sin importar el videojuego ni si es multijugador o individual.

       
		void SeleccionarVideojuego(string Nombre); // se guarda el nombre en el controlador
		
        
        void seleccionarPartida(int idPartida); // da un id partida para continuar.

        void Transmitida(bool t);  // se define la partida como MULTIJUGADOR y se guarda ese dato para luego armar la partida.
         
        void seleccionarJugadores(vector<string> idJugadores); // guarda los jugadores en la memoria y controla que efectivamente esten suscriptos.
        void iniciarPartida(); // inicia la partida correspondiente con los datos guardados en memoria
        void setTipoPartida(string tipo);  // guarda en el sistema el tipo de partida que se piensa iniciar
        
        
        // Caso de uso abandonar partida multijugador
         void AbandonarPartidaActiva(int id);  // manda el id de la partida multijugador  
		 vector<DtPartida*> ObtenerPartidasActivas();   // devuelve las partidas multijugador donde el usuario en sesion participa. Abandonar partidaMultijugador 

        // Caso de uso finalizar partida
        
        bool ingreseIdPartida(int idPartida); // el sistema guarda esta info para finalizar la partida
        void finalizarPartida(); // finaliza la partida cuyo id está en memoria producto de ingresarIdPartida 
        

        //void finalizarPartidaMultijugador(); //finaliza una partida multijugador y saca a todos los jugadores
        
      
        ~ControladorPartidas();
        
        vector<string> darSinFinalizar(vector<string> videojuegos);
        bool hayActivas(); // devuelve si hay alguna partida activa
        
        
		void eliminarPartidasVideojuego(string nombre); // atiende el caso de uso Eliminar Videojuegos
};

#endif