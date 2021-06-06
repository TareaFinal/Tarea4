using namespace std;

class controladorUsuarios : public iControladorUsuarios {
	
	private:
		static controladorUsuarios instancia;
        set<Usuario> usuarios:
        string emailUsuarioEnSesion;
	public:
        static controladorUsuarios getInstancia();
        string getUsuarioEnSesion();
        set<string> getVideojuegoJugador(string email);
        void registrarUsuario(string email, string contrasenia);
        void darEmpresa(string nombre);
        void darDatosJugador(string nick, string descripcion);
        void confirmarAltaUsuario();
        void obtenerVideojuegosJugador(string email);
        void desvincularSuscripciones(set<Jugador> js, Videojuego v);
        void desvincularSuscripcion(string email, Videojuego v);
        Suscripcion buscarSuscripcion(Videojuego v);
        void agregarSusAJugador(Suscripcion s);
        set<Jugador> darJugadores(set<DtJugador> dtJugadores);
};