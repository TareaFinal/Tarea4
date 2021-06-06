using namespace std;

class controladorPartidas : public iControladorPartidas {
	
	private:
		static controladorPartidas instancia;
        set<Partida> partidas;
	public:
        static ControladorPartidas getInstancia();
        float darHorasDePartida(Partida partida);
        Set<DtVideojuego> obtenerVideojuegosJugador();
        Set<DtJugador> obtenerJugadoresSuscriptos(int idPartida);
        Set<DtJugador> obtenerJugadoresMulti(int idPartida);
        bool ingreseIdPartida(int idPartida);
        void finalizarPartida(int idPartida);
        Set<DtJugador> jugadoresSuscriptosAVideojuego(string nombre);
};