#include "../Estadistica2.h"
#include "../fabrica.h"

#include <string>


Estadistica2::Estadistica2(int id, string nombre, string desc) {
	this->idEstadistica = id;
	this->nombre = nombre;
	this->descripcion = desc;
}


float Estadistica2::calcular(string videojuego) {
	Fabrica *fabrica = Fabrica::getInstancia();
	iControladorUsuarios *controlador = fabrica->getControladorUsuarios(); 
	int resultado = controlador->cantidadJugadoresSuscriptosVideojuego(videojuego);    // Le pide a ControladorVideojuegos que devuelva la cantidad de jugadores que tienen suscripciones a videojuego.
	return resultado;
}

DtEstadistica *Estadistica2::getDataEstadistica(float valor) {
	DtEstadistica *dataEstadistica = new DtEstadistica(this->idEstadistica, this->nombre, this->descripcion,	valor);  /// ¿Qué le paso al Dt?
	return dataEstadistica;	
}
