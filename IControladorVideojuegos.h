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
#include <vector>

using namespace std;

class Suscripcion;

class iControladorVideojuegos {

	public:
                virtual float calcularEstadistica(int estadistica, string nomVideojuego) = 0;
                virtual float calcularHorasJugadas(string videojuego) = 0;
                virtual vector<DtJugador> jugadoresSuscriptosAVideojuego(string nombre) = 0;
                virtual void eliminarVideojuego(string nombre) = 0;
                virtual vector<DtVideojuego> obtenerVideojuegos() = 0;
                virtual void confirmarEliminacion() = 0;
                virtual bool ingreseNombreVideojuego(string nombreVideojuego) = 0;
                virtual vector<DtEstadistica> listarEstadisticas(string nombreVideojuego) = 0;
                virtual bool esTemporal(Suscripcion *s) = 0;
                virtual Suscripcion *ingresarNombre(string nombre) = 0;
                virtual void ingresarCategoria(DtCategoria *cat, Desarrollador *des) = 0;
                
                virtual bool existeVideojuego(string nombre) = 0;
                virtual bool existeCategoria(string nombre) = 0;
                virtual bool existeEstadistica(int id) = 0;
                virtual bool altaSuscripcion(string nomJugador, string video, Suscripcion sus, bool isVitalicia) = 0;
                virtual bool asignarPuntajeAVideojuego(string nomVideojuego, int puntaje) = 0;
};

#endif