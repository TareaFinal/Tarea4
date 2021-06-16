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
	return metodoDePago;
}
float Suscripcion::getValor() {
	return valor;
}
DtFechaHora Suscripcion::getFecha() {
	return fecha;
}
