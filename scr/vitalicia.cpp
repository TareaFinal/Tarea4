#include "../vitalicia.h"
#include "../jugador.h"
#include "../Videojuego.h"
#include <string>
#include <iostream>
using namespace std;

Vitalicia::Vitalicia(string metpago, DtFechaHora *fechahoy, float val, Jugador* player, Videojuego* vj) {
	this->metodoDePago = metpago;
	this->valor = val;
	this->fecha = fechahoy;
	this->_jugador = player;
	this->_videojuego = vj;
}


bool Vitalicia::Activa() {
	return true;
}
string Vitalicia::TipoSuscripcion() { // esta es una funcion abstracta pero aca no se define con virtual porque estamos en la clase derivada
	return "vitalicia";
}
