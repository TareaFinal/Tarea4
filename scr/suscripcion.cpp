#include <string>
#include <iostream>
#include "../suscripcion.h"
using namespace std;

	//Constructor
Suscripcion::Suscripcion(string metpago, DtFechaHora fechahoy, float val, Jugador* player, Videojuego* vj) : metodoDePago(metpago), valor(val), fecha(fechahoy)
		_jugador(player), _videojuego(vj);
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

DtVideojuego Suscripcion::getDataVideojuego()
{
	if (this->activa()) { // ni puta idea de si esto funciona pero suscripcion no tiene metodo para activa pero sus derivadas si.
		return _videojuego->getDataVideojuego(); // le digo a mi videojuego que me de su data
	}
	else {
		throw invalid_argument "La suscripcion está inactiva";
	}
}
