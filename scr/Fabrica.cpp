#include "../Fabrica.h"


iControladorVideojuegos *Fabrica::getControladorVideojuegos() {
	iControladorVideojuegos *controlador = ControladorVideojuegos::getInstancia();
	return controlador;
}

iControladorPartidas *Fabrica::getControladorPartidas() {
	iControladorPartidas *controlador = ControladorPartidas::getInstancia();
	return controlador;
}

iControladorUsuarios *Fabrica::getControladorUsuarios() {
	iControladorUsuarios *controlador = ControladorUsuarios::getInstancia();
	return controlador;
}



