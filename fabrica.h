#include "ControladorVideojuegos.h"
#include "ControladorUsuarios.h"
#include "ControladorPartidas.h"

class Fabrica {
	
	private:
		static Fabrica instancia;
	public:
		ControladorVideojuegos getControladorVideojuegos();
        ControladorUsuarios getControladorUsuarios();
        ControladorPartidas getControladorPartidas();
        static Fabrica getInstancia();

};