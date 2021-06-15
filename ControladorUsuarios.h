#include "DataTypes/DtEstadistica.h"
#include "DataTypes/DtVideojuego.h"
#include "DataTypes/DtCategoria.h"
#include "DataTypes/DtJugador.h"
#include "IControladorUsuarios.h"
#include <string>
#include <set>
#include "jugador.h"
#include "Videojuego.h"
#include "suscripcion.h"
#include "usuario.h"
using namespace std;

class ControladorUsuarios : public iControladorUsuarios {
	
	private:
                string mail = " ", contra = " ", nickname = " ", desc = " ", empresa = " ";
		static ControladorUsuarios instancia;
                set<Usuario> usuarios;
                string emailUsuarioEnSesion;
                DtFechaHora* systemTime;
	public:
                static ControladorUsuarios getInstancia();
                string getUsuarioEnSesion();
                set<string> getVideojuegoJugador(string email);
                void registrarUsuario(string email, string contrasenia);
                void darEmpresa(string nombre);
                void darDatosJugador(string nick, string descripcion);
                void confirmarAltaUsuario();
                set<DtVideojuego> obtenerVideojuegosJugador(string email);
                void desvincularSuscripciones(set<Jugador> js, Videojuego v);
                void desvincularSuscripcion(string email, Videojuego v);
                Suscripcion buscarSuscripcion(Videojuego v); 
                void agregarSusAJugador(string email, Suscripcion s);
                set<Jugador> darJugadores(set<DtJugador> dtJugadores);
                bool iniciarSesion(string email, string contrasenia);
                string getTipoUsuario();
                void setFechaSistema(DtFechaHora* fechaSist);
                DtFechaHora* getFechaSistema();
};