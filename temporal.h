#ifndef TEMPORAL
#define TEMPORAL
#include "suscripcion.h"
#include "jugador.h"
#include "videojuego.h"
#include "DataTypes/DTFecha.h"
#include <string>
#include <iostream>

using namespace std;

class Temporal : public Suscripcion {
private:
	DTFecha validez;
	bool cancelada;
protected:

public:
	// Constructor
	Temporal (string metpago, DTFecha fechahoy, float val, Jugador* Player, Videojuego* Vj, string tipo ); // validez se calcula sumandole a la fecha de hoy el el tiempo en tipo
	
	// Destructor
	~Vitalicia();
	
	// Setters

	void setCancelada(bool cancel);

	// Getters
	DTFecha getValidez();
	bool getCancelada();
	
	
	// Funciones
	bool activa(); // devuelve !cancelada && hoy<validez 
	void cancelar();
};

#endif