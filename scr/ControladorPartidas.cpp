#include "../ControladorPartidas.h"

ControladorPartidas *ControladorPartidas::instancia = NULL;

ControladorPartidas *ControladorPartidas::getInstancia() {
	if (instancia == NULL)
		instancia = new ControladorPartidas();

	return instancia;	
}

ControladorPartidas::ControladorPartidas() {
	
}

float ControladorPartidas::darHorasDePartida(string videojuego) {
	return 0.0;
}

set<DtVideojuego*> ControladorPartidas::obtenerVideojuegosJugador() {
	set<DtVideojuego*> videojuegos;
	return videojuegos;
}

set<DtJugador*> ControladorPartidas::obtenerJugadoresSuscriptos(int idPartida) {
	set<DtJugador*> jugadores;
	return jugadores;
}

set<DtJugador*> ControladorPartidas::obtenerJugadoresMulti(int idPartida) {
	set<DtJugador*> jugadores;
	return jugadores;
}

bool ControladorPartidas::ingreseIdPartida(int idPartida) {
	return true;
}

void ControladorPartidas::finalizarPartida(int idPartida) {
	
}

set<DtJugador*> ControladorPartidas::jugadoresSuscriptosAVideojuego(string nombre) {
	set<DtJugador*> jugadores;
	return jugadores;
}
