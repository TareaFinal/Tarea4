#ifndef TEMPORAL
#define TEMPORAL

#include "suscripcion.h"
#include <string>
#include <iostream>

using namespace std;

class Jugador;
class Suscripcion;

class Temporal : public Suscripcion {
private:
	DtFechaHora *validez;
	bool cancelada;
public:
	// Constructor
	Temporal (string metpago, DtFechaHora *fechahoy, float val, Jugador* Player, Videojuego* Vj, int tipo); // validez se calcula sumandole a la fecha de hoy el el tiempo en tipo
	
	// Destructor
	
	// Setters

	// Getters
	DtFechaHora *getValidez();
	bool getCancelada();
	
	
	// Funciones
	bool activa(); // devuelve !cancelada && hoy<validez 
	string TipoSuscripcion();
	void cancelar();
};

#endif
