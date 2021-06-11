#include "../vitalicia.h"
#include "../jugador.h"
#include "../Videojuego.h"
#include <string>
#include <iostream>
using namespace std;

// Constructor
Vitalicia::Vitalicia(string metpago, DtFechaHora fechahoy, float val, Jugador* player, Videojuego* vj): 
		Suscripcion(string metpago, DtFechaHora fechahoy, float val, Jugador* player, Videojuego* vj) // construyo una suscripcion con los mismos parametros
	{}
	// Destructor
~Vitalicia() {
	std::cout << "acaba de ejecutarse el destructor de Vitalicia" << std::endl;  // borrar este mensaje
}
// Funciones
bool Activa() {
	return true;
}
string TipoSuscripcion() { // esta es una funcion abstracta pero aca no se define con virtual porque estamos en la clase derivada
	return "vitalicia";
}
