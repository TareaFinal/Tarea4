#include "../ControladorVideojuegos.h"

ControladorVideojuegos *ControladorVideojuegos::instancia = NULL;

ControladorVideojuegos *ControladorVideojuegos::getInstancia() {
	if (instancia == NULL)
		instancia = new ControladorVideojuegos();

	return instancia;	
}

ControladorVideojuegos::ControladorVideojuegos() {
	
}

float ControladorVideojuegos::calcularEstadistica(int estadistica) {
	
	return 0.0;
}


float ControladorVideojuegos::calcularHorasJugadas(string videojuego) {
	return 0.0;
	
}

set<DtJugador*> ControladorVideojuegos::jugadoresSuscriptosAVideojuego(string nombre) {
	set<DtJugador*> jugadores;
	return jugadores;
}

void ControladorVideojuegos::eliminarVideojuego(string nombre) {
	
}

set<DtVideojuego*> ControladorVideojuegos::obtenerVideojuegos() {
	set<DtVideojuego*> videojuegos;
	return videojuegos;
	
}

void ControladorVideojuegos::confirmarEliminacion() {
	
}

bool ControladorVideojuegos::ingreseNombreVideojuego(string nombreVideojuego) {
	return true;
}

set<DtEstadistica*> ControladorVideojuegos::listarEstadisticas(string nombreVideojuego) {
	set<DtEstadistica*> estadisticas;
	return estadisticas;
	
}

bool ControladorVideojuegos::esTemporal(Suscripcion *s) {
	return true;
}

Suscripcion *ControladorVideojuegos::ingresarNombre(string nombre) {
	Suscripcion *s = NULL;
	return s;
}

void ControladorVideojuegos::ingresarCategoria(DtCategoria *cat) {
	
}

bool ControladorVideojuegos::existeVideojuego(string nombre) {
	return true;
}

bool ControladorVideojuegos::existeCategoria(string nombre) {
	return true;
}

bool ControladorVideojuegos::existeEstadistica(int id) {
	return true;
}
