#include "DataTypes/DtEstadistica.h"
#include "DataTypes/DtVideojuego.h"
#include "DataTypes/DtCategoria.h"
#include "DataTypes/DtJugador.h"
#include <string>
using namespace std;

class ControladorUsuarios : public iControladorUsuarios {
	
	private:
		static ControladorUsuarios instancia;
                set<Usuario> usuarios:
                string emailUsuarioEnSesion;
	public:
                static ControladorUsuarios getInstancia();
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