#include "../ControladorUsuarios.h"

ControladorUsuarios *ControladorUsuarios::instancia = NULL;

ControladorUsuarios *ControladorUsuarios::getInstancia() {
	if (instancia == NULL)
		instancia = new ControladorUsuarios();

	return instancia;	
}

ControladorUsuarios::ControladorUsuarios() {
	
}

string ControladorUsuarios::getUsuarioEnSesion() {
	return "hola";
}

set<string> ControladorUsuarios::getVideojuegoJugador(string email) {
	set<string> cosas;
	return cosas;
}

void ControladorUsuarios::registrarUsuario(string email, string contrasenia) {
	
}

void ControladorUsuarios::darEmpresa(string nombre) {
	
}

void ControladorUsuarios::darDatosJugador(string nick, string descripcion) {
	
}

void ControladorUsuarios::confirmarAltaUsuario() {
	
}

void ControladorUsuarios::obtenerVideojuegosJugador(string email) {
	
}

void ControladorUsuarios::desvincularSuscripciones(set<Jugador*> &js, Videojuego *v) {
	
}

void ControladorUsuarios::desvincularSuscripcion(string email, Videojuego *v) {
	
}

Suscripcion *ControladorUsuarios::buscarSuscripcion(Videojuego *v) {
	return NULL;
}

void ControladorUsuarios::agregarSusAJugador(Suscripcion *s) {
	
}
set<Jugador*> ControladorUsuarios::darJugadores(set<DtJugador*> &dtJugadores) {
	set<Jugador*> jugadores;
	return jugadores;
}

int ControladorUsuarios::cantidadJugadoresSuscriptosVideojuego(string videojuego) {
	return 1;
}

DtFechaHora *ControladorUsuarios::getFechaHoraActual() {
	return NULL;
}

set<DtJugador> ControladorUsuarios::listarJugadoresSuscriptosVideojuego(string videojuego){

}