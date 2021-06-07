#ifndef VITALICIA
#define VITALICIA
#include "suscripcion.h"
#include "jugador.h"
#include "videojuego.h"
#include <string>
#include <iostream>
using namespace std;

class Vitalicia : public Suscripcion {
private:
	
protected:

public:
	// Constructor
	Vitalicia(string metpago, DTFecha fechahoy, float val, Jugador* player, VideoJuego* vj);

	// Destructor
	~Vitalicia();

	// Funciones
	bool Activa(); // Devuelve True siempre;
};
	

#endif