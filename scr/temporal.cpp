#include "../temporal.h"
#include "../jugador.h"
#include "../Videojuego.h"
#include "../DataTypes/DtFechaHora.h"
#include <string>
#include <iostream>

using namespace std;

	// Constructor
Temporal::Temporal(string metpago, DtFechaHora *fechahoy, float val, Jugador* Player, Videojuego* Vj, string tipo)  {
	this->metodoDePago = metpago;
	this->valor = val;
	this->fecha = fechahoy;
	this->_jugador = Player;
	this->_videojuego = Vj;
	this->cancelada = false;
	
/*	Fabrica *fabrica = Fabrica::getInstancia();
	iControladorUsuarios *controlador = fabrica->getControladorUsuarios();
	
	DtFechaHora *fechahoy = controlador->getFechaHoraActual();*/
		
	if (tipo == "anual"){
		this->validez = new DtFechaHora(fechahoy->getAnio()+1, fechahoy->getMes(), fechahoy->getDia(), fechahoy->getHora(), fechahoy->getMinuto());
	}
	else if (tipo == "semestral") {
		if (fechahoy->getMes() <= 6) {
			validez = new DtFechaHora(fechahoy->getAnio(), fechahoy->getMes()+6, fechahoy->getDia(), fechahoy->getHora(), fechahoy->getMinuto());
		}
		else {
			this->validez = new DtFechaHora(fechahoy->getAnio()+1, fechahoy->getMes()-6, fechahoy->getDia(), fechahoy->getHora(), fechahoy->getMinuto());
		}
	}
	else if (tipo == "mensual") {
		if (fechahoy->getMes() == 12) {
			this->validez = new DtFechaHora(fechahoy->getAnio() + 1, 1, fechahoy->getDia(), fechahoy->getHora(), fechahoy->getMinuto());
		}
		else {
			this->validez = new DtFechaHora(fechahoy->getAnio(), fechahoy->getMes() +1, fechahoy->getDia(), fechahoy->getHora(), fechahoy->getMinuto());
		}
	}
}
	


	
	// Setters

	
	// Getters
DtFechaHora *Temporal::getValidez() {
	return this->validez;
}
bool Temporal::getCancelada() {
	return this->cancelada;
}
	// Funciones

bool Temporal::activa() {
	bool valida; //hoy < validez
	Fabrica *fabrica = Fabrica::getInstancia();
	iControladorUsuarios *controlador = fabrica->getControladorUsuarios(); 
	DtFechaHora *ahora = controlador->getFechaSistema(); // Esta funcion no est� creada OJOOOOO!!!
	if (validez->getAnio() > ahora->getAnio()) {
		valida= true;
	}
	else if ((validez->getAnio() == ahora->getAnio()) && (validez->getMes() > ahora->getMes())) {
		valida = true;
	}
	else if (((validez->getAnio() == ahora->getAnio()) && (validez->getMes() == ahora->getMes()) && validez->getDia() > ahora->getDia())) {
		valida = true;
	}
	else if ((((validez->getAnio() == ahora->getAnio()) && (validez->getMes() == ahora->getMes()) && validez->getDia() == ahora->getDia()))
				&& (validez->getHora() > ahora->getHora())) {
		valida = true;
	}
	else if (((((validez->getAnio() == ahora->getAnio()) && (validez->getMes() == ahora->getMes()) && validez->getDia() == ahora->getDia()))
			&& (validez->getHora() > ahora->getHora())) && (validez->getMinuto() >= ahora->getMinuto())) {
		valida = true;
	}
	else {
		valida = true;
	}
	return (!this->cancelada && valida);
}

string Temporal::TipoSuscripcion() {
	return "temporal";
}
void Temporal::cancelar() {
	this->cancelada = true;
}
