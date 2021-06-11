#include "../temporal.h"
#include "jugador.h"
#include "Videojuego.h"
#include "DataTypes/DtFechaHora.h"
#include <string>
#include <iostream>

using namespace std;

	// Constructor
Temporal::Temporal(string metpago, DtFechaHora fechahoy, float val, Jugador* Player, Videojuego* Vj, string tipo)
	:Suscripcion(metpago,fechahoy,val, Player,Vj), cancelada(false)
		// validez se calcula sumandole a la fecha de hoy el tiempo en tipo
{
	if (tipo == "anual"){
		validez = DtFechaHora(fechahoy.get(anio)+1, fechahoy.get(mes), fechahoy.get(dia), fechahoy.get(hora), fechahoy.get(minuto));
	}
	else if (tipo == "semestral") {
		if (fechahoy.get(mes) <= 6) {
			validez = DtFechaHora(fechahoy.get(anio), fechahoy.get(mes)+6, fechahoy.get(dia), fechahoy.get(hora), fechahoy.get(minuto));
		}
		else {
			validez = DtFechaHora(fechahoy.get(anio)+1, fechahoy.get(mes)-6, fechahoy.get(dia), fechahoy.get(hora), fechahoy.get(minuto));
		}
	}
	else if (tipo == "mensual") {
		if (fecha.hoy.get(mes) == 12) {
			validez = DtFechaHora(fechahoy.get(anio) + 1, 1, fechahoy.get(dia), fechahoy.get(hora), fechahoy.get(minuto));
		}
		else {
			validez = DtFechaHora(fechahoy.get(anio), fechahoy.get(mes) +1, fechahoy.get(dia), fechahoy.get(hora), fechahoy.get(minuto));
		}
	}
	else {
		throw invalid_argument("el tipo de suscripcion no es válido\n");
	}
}
	
	// Destructor
Temporal::~Temporal () {
	}
	
	// Setters

	
	// Getters
DtFechaHora Temporal::getValidez() {
	return validez;
}
bool Temporal::getCancelada() {
	return cancelada;
}
	// Funciones
bool Temporal::activa() {
	bool valida; //hoy < validez
	DtFechaHora ahora = contusuarios.getFechaHoraActual(); // Esta funcion no está creada OJOOOOO!!!
	if (validez.get(anio) > ahora.get(anio)) {
		valida= true;
	}
	else if ((validez.get(anio) == ahora.get(anio)) && (validez.get(mes) > ahora.get(mes))) {
		valida = true;
	}
	else if (((validez.get(anio) == ahora.get(anio)) && (validez.get(mes) == ahora.get(mes)) && validez.get(dia) > ahora.get(dia))) {
		valida = true;
	}
	else if ((((validez.get(anio) == ahora.get(anio)) && (validez.get(mes) == ahora.get(mes)) && validez.get(dia) == ahora.get(dia)))
				&& (validez.get(hora) > ahora.get(hora))) {
		valida = true;
	}
	else if (((((validez.get(anio) == ahora.get(anio)) && (validez.get(mes) == ahora.get(mes)) && validez.get(dia) == ahora.get(dia)))
			&& (validez.get(hora) > ahora.get(hora))) && (validez.get(minuto) >= ahora.get(minuto))) {
		valida = true;
	}
	else {
		valida = true;
	}
	return !cancelada && valida;
} 
string Temporal::TipoSuscripcion() {
	return "temporal";
}
void Temporal::cancelar() {
	cancelada = true;
}


#endif