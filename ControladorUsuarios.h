#ifndef CONTROLADORUSUARIOS
#define CONTROLADORUSUARIOS

#include "IControladorUsuarios.h"
#include "usuario.h"
#include <string>
#include <set>

using namespace std;

class ControladorUsuarios : public iControladorUsuarios {
	
	private:
		static ControladorUsuarios *instancia;
                set<Usuario*> usuarios;
                string emailUsuarioEnSesion;
        ControladorUsuarios();
	public:
                static ControladorUsuarios *getInstancia();
		        
                string getUsuarioEnSesion();
                int cantidadJugadoresSuscriptosVideojuego(string videojuego);
                set<string> getVideojuegoJugador(string email);
                void registrarUsuario(string email, string contrasenia);
                void darEmpresa(string nombre);
                void darDatosJugador(string nick, string descripcion);
                void confirmarAltaUsuario();
                void obtenerVideojuegosJugador(string email);
                void desvincularSuscripciones(set<Jugador*> &js, Videojuego *v);
                void desvincularSuscripcion(string email, Videojuego *v);
                Suscripcion *buscarSuscripcion(Videojuego *v);
                void agregarSusAJugador(Suscripcion *s);
                set<Jugador*> darJugadores(set<DtJugador*> &dtJugadores);
                DtFechaHora *getFechaHoraActual();
                set<DtJugador> listarJugadoresSuscriptosVideojuego(string videojuego);
};

#endif

