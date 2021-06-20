#include "../suscripcion.h"


string Suscripcion::getMetodoDePago() {
	return this->metodoDePago;
}
float Suscripcion::getValor() {
	return this->valor;
}
DtFechaHora *Suscripcion::getFecha() {
	return this->fecha;
}

Videojuego *Suscripcion::getVideojuego() {
	return this->_videojuego;
}

Jugador *Suscripcion::getJugador() {
	return this->_jugador;
}
