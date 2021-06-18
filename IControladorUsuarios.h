#ifndef ICONTROLADORUSUARIOS
#define ICONTROLADORUSUARIOS

#include "DataTypes/DtJugador.h"
#include "Videojuego.h"
#include "jugador.h"
#include <vector>
#include <string>
#include <set>
//#include "jugador.h"
using namespace std;

class Jugador;

class iControladorUsuarios {
	
	public:
                virtual string getUsuarioEnSesion() = 0;
                virtual int cantidadJugadoresSuscriptosVideojuego(string videojuego) = 0;
                virtual set<string> getVideojuegoJugador(string email) = 0;
                virtual void registrarUsuario(string email, string contrasenia) = 0;
                virtual void darEmpresa(string nombre) = 0;
                virtual void darDatosJugador(string nick, string descripcion) = 0;
                virtual void confirmarAltaUsuario() = 0;
                virtual vector<DtVideojuego> obtenerVideojuegosJugador(string email) = 0;
                virtual void desvincularSuscripciones(set<Jugador*> &js, Videojuego *v) = 0;
                virtual void desvincularSuscripcion(string email, Videojuego *v) = 0;
                virtual Suscripcion *buscarSuscripcion(Videojuego *v) = 0;
                virtual void agregarSusAJugador(Suscripcion *s) = 0;
                virtual set<Jugador*> darJugadores(set<DtJugador*> &dtJugadores) = 0;
                virtual bool iniciarSesion(string email, string contrasenia) = 0;
                virtual string getTipoUsuario() = 0;
                virtual void setFechaSistema(DtFechaHora *fechaSist) = 0;
                virtual DtFechaHora *getFechaSistema() = 0;
                virtual vector<DtJugador> listarJugadoresSuscriptosVideojuego(string videojuego) = 0; 
};

#endif

