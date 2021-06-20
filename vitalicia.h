#ifndef VITALICIA
#define VITALICIA

#include "suscripcion.h"
#include "jugador.h"
#include <string>
#include <iostream>
using namespace std;

class Jugador;

class Vitalicia : public Suscripcion {

public:
	// Constructor
	Vitalicia(string metpago, DtFechaHora *fechahoy, float val, Jugador* player, Videojuego* vj);

	// Destructor
	~Vitalicia();

	// Funciones
	bool activa(); // Devuelve True siempre;
	string TipoSuscripcion();
	
};
	

#endif
