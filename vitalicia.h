#ifndef VITALICIA
#define VITALICIA
#include "suscripcion.h"
#include "jugador.h"
#include "Videojuego.h"
#include <string>
#include <iostream>
using namespace std;
class Vitalicia : public Suscripcion {
private:
	
protected:

public:
	// Constructor
	Vitalicia(string metpago, DtFechaHora *fechahoy, float val, Jugador* player, Videojuego* vj);

	// Destructor
	~Vitalicia();

	// Funciones
	bool Activa(); // Devuelve True siempre;
	string TipoSuscripcion();
	
};
	

#endif
