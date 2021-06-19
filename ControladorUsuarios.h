#ifndef CONTROLADORUSUARIOS
#define CONTROLADORUSUARIOS

#include "IControladorUsuarios.h"
#include "usuario.h"
#include "desarrollador.h"
#include "jugador.h"
#include <string>
#include <vector>
#include <set>

using namespace std;

class ControladorUsuarios : public iControladorUsuarios {
	
	private:
				string mail = " ", contra = " ", nickname = " ", desc = " ", empresa = " ";
				static ControladorUsuarios *instancia;
                set<Usuario*> usuarios;
                string emailUsuarioEnSesion;
                DtFechaHora *systemTime;
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
                vector<DtVideojuego> obtenerVideojuegosJugador(string email);
                void desvincularSuscripciones(set<Jugador*> &js, Videojuego *v);
                void desvincularSuscripcion(string email, Videojuego *v);
                Suscripcion *buscarSuscripcion(Videojuego *v);
                void agregarSusAJugador(Suscripcion *s);
                set<Jugador*> darJugadores(set<DtJugador*> &dtJugadores);
                bool iniciarSesion(string email, string contrasenia);
                string getTipoUsuario();
                void setFechaSistema(DtFechaHora *fechaSist);
                DtFechaHora *getFechaSistema();
                vector<DtJugador> listarJugadoresSuscriptosVideojuego(string videojuego);
                bool altaSuscripcion(string nomJugador, string nomVideo, Suscripcion *sus, bool isVitalicia);
                bool esTemporal(Suscripcion *s);
};

#endif

