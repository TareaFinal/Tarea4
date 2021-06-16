#include "../Estadistica1.h"
#include "../Fabrica.h"

float Estadistica1::calcular(string videojuego) {
	Fabrica *fabrica = Fabrica::getInstancia();
	iControladorPartidas *controlador = fabrica->getControladorPartidas(); 
	float horasJugadas = controlador->darHorasDePartida(videojuego);
	return horasJugadas;
}

DtEstadistica *Estadistica1::getDataEstadistica(float valor) {
	DtEstadistica *dataEstadistica = new DtEstadistica(this->idEstadistica, this->nombre, this->descripcion,	valor);  /// ¿Qué le paso al Dt?
	return dataEstadistica;
}
