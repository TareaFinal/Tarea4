#ifndef FABRICA
#define FABRICA

#include "ControladorVideojuegos.h"
#include "ControladorUsuarios.h"
#include "ControladorPartidas.h"
#include "IControladorVideojuegos.h"
#include "IControladorUsuarios.h"
#include "IControladorPartidas.h"

class iControladorVideojuegos;
class iControladorUsuarios;
class iControladorPartidas;

class Fabrica {
	
	private:
		static Fabrica *instancia;
	public:
		iControladorVideojuegos *getControladorVideojuegos();
        iControladorUsuarios *getControladorUsuarios();
        iControladorPartidas *getControladorPartidas();
        static Fabrica *getInstancia();

};

#endif
