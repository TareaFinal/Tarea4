#include "DataTypes/DtEstadistica.h"
#include "DataTypes/DtVideojuego.h"
#include "DataTypes/DtCategoria.h"
#include "DataTypes/DtJugador.h"
#include "IControladorVideojuegos.h"
#include "Videojuego.h"
#include "suscripcion.h"
#include "Categoria.h"
//#include <string>
//#include <set>
using namespace std;

class ControladorVideojuegos : public iControladorVideojuegos {
	
	private:
	        static ControladorVideojuegos* instancia;
                set<Categoria> categorias;
                set<Videojuego> videojuegos;
	public:
                static ControladorVideojuegos* getInstancia();
                float calcularEstadistica(int estadistica); //no deberia de ser de la misma clase que el identificador de estadisticas que viene a ser un int? ---- Ag: Si, lo deje porque asi estaba
                float calcularHorasJugadas(Videojuego videojuego);
                set<DtJugador> jugadoresSuscriptosAVideojuego(string nombre);
                void eliminarVideojuego(string nombre);
                set<DtVideojuego> obtenerVideojuegos();
                void confirmarEliminacion();
                bool ingreseNombreVideojuego(string nombreVideojuego);
                set<DtEstadistica> listarEstadisticas(string nombreVideojuego);
                bool esTemporal(Suscripcion s);
                Suscripcion ingresarNombre(string nombre);
                void ingresarCategoria(DtCategoria cat);
};