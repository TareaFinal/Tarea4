#include <string>
#include <iostream>
#include "../suscripcion.h"
using namespace std;


string Suscripcion::getMetodoDePago() {
	return this->metodoDePago;
}
float Suscripcion::getValor() {
	return this->valor;
}
DtFechaHora Suscripcion::getFecha() {
	return this->fecha;
}