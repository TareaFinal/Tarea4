#ifndef TEMPORAL
#define TEMPORAL
#include "suscripcion.h"
#include "jugador.h"
#include "Videojuego.h"
#include "DataTypes/DtFechaHora.h"
#include <string>
#include <iostream>

using namespace std;
class Temporal : public Suscripcion {
private:
	DtFechaHora *validez;
	bool cancelada;
protected:

public:
	// Constructor
//	Temporal (string metpago, DtFechaHora fechahoy, float val, Jugador* Player, Videojuego* Vj, string tipo ); // validez se calcula sumandole a la fecha de hoy el el tiempo en tipo
	
	// Destructor
	~Temporal();
	
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
