#include <string>
#include <iostream>
#include "../suscripcion.h"
#include "../jugador.h"
#include "../Videojuego.h"
using namespace std;

	//Constructor
Suscripcion::Suscripcion(string metpago, DtFechaHora fechahoy, float val, Jugador* player, Videojuego* vj) : metodoDePago(metpago), valor(val), fecha(fechahoy),
		_jugador(player), _videojuego(vj)
{
		std::cout << "acaba de ejecutarse el constructor de Suscripcion" << std::endl;  // borrar este mensaje
}

	// Destructor 
Suscripcion::~Suscripcion() 
{
	std::cout << "acaba de ejecutarse el destructor de Suscripcion" << std::endl;
}
	// Seters
	// no tenemos setters
	//Getters

string Suscripcion::getMetodoDePago() {
	return this->metodoDePago;
}
float Suscripcion::getValor() {
	return this->valor;
}
DtFechaHora Suscripcion::getFecha() {
	return this->fecha;
}
