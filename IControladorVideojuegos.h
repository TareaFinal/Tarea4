#ifndef ICONTROLADORVIDEOJUEGOS
#define ICONTROLADORVIDEOJUEGOS

#include "DataTypes/DtEstadistica.h"
#include "DataTypes/DtVideojuego.h"
#include "DataTypes/DtCategoria.h"
#include "DataTypes/DtJugador.h"
#include "Videojuego.h"
#include "suscripcion.h"

#include <string>
#include <set>

using namespace std;

class Suscripcion;

class iControladorVideojuegos {

	public:
                virtual float calcularEstadistica(int estadistica) = 0;
                virtual float calcularHorasJugadas(string videojuego) = 0;
                virtual set<DtJugador*> jugadoresSuscriptosAVideojuego(string nombre) = 0;
                virtual void eliminarVideojuego(string nombre) = 0;
                virtual set<DtVideojuego*> obtenerVideojuegos() = 0;
                virtual void confirmarEliminacion() = 0;
                virtual bool ingreseNombreVideojuego(string nombreVideojuego) = 0;
                virtual set<DtEstadistica*> listarEstadisticas(string nombreVideojuego) = 0;
                virtual bool esTemporal(Suscripcion *s) = 0;
                virtual Suscripcion *ingresarNombre(string nombre) = 0;
                virtual void ingresarCategoria(DtCategoria *cat) = 0;
                
                virtual bool existeVideojuego(string nombre) = 0;
                virtual bool existeCategoria(string nombre) = 0;
                virtual bool existeEstadistica(int id) = 0;
};

#endif

