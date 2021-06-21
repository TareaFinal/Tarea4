#ifndef ICONTROLADORVIDEOJUEGOS
#define ICONTROLADORVIDEOJUEGOS


#include "DataTypes/DtEstadistica.h"
#include "DataTypes/DtVideojuego.h"
#include "DataTypes/DtCategoria.h"
#include "DataTypes/DtJugador.h"
#include "Videojuego.h"
#include "suscripcion.h"
#include "desarrollador.h"

#include <string>
#include <set>
#include <vector>

using namespace std;

class Desarrollador;
class Suscripcion;

class iControladorVideojuegos {


	public:
                virtual float calcularEstadistica(int estadistica, string nomVideojuego) = 0;
                virtual float calcularHorasJugadas(string videojuego) = 0;
                virtual vector<DtJugador> jugadoresSuscriptosAVideojuego(string nombre) = 0;
                virtual void eliminarVideojuego(string nombre) = 0;
                virtual vector<DtVideojuego> solicitarVideojuegos() = 0;
                virtual vector<DtVideojuego> obtenerVideojuegosDes() = 0;
                virtual vector<string> obtenerVideojuegosDesFinalizados() = 0;
                virtual void confirmarEliminacion() = 0;
                virtual bool ingreseNombreVideojuego(string nombreVideojuego) = 0;
                virtual bool esTemporal(Suscripcion *s) = 0;
                virtual Suscripcion *ingresarNombre(string nombre) = 0;
                virtual void ingresarCategoria(string nombre, string tipo, string descripcion) = 0;
                
                virtual bool existeVideojuego(string nombre) = 0;
                virtual bool existeCategoria(string nombre) = 0;
                virtual bool existeEstadistica(int id) = 0;
                
            	virtual bool altaSuscripcion(string videojuego, string tipo, string metodoPago, int validez) = 0;
                virtual bool asignarPuntajeAVideojuego(string nomVideojuego, int puntaje) = 0;
                
                virtual vector<string> consultarEstadisticas(string nombreVideojuego) = 0;
                virtual vector<DtEstadistica> listarEstadisticas() = 0;
                
                virtual void publicarVideojuego() = 0;
                virtual void setearDatosVideojuego(string nombre, string descripcion, float precioMes, float precioTri, float precioAnio, float precioVit) = 0;
                virtual void asignarGenero(DtCategoria* gen) = 0;
                virtual void asignarPlataforma(DtCategoria* plat) = 0;
                virtual void asignarCategorias(vector<DtCategoria*> cats) = 0;
                virtual vector<DtCategoria*> solicitarCategorias() = 0;
                
                virtual void generarStats() = 0;
                virtual void seleccionarEstadisticas(vector<DtEstadistica> stats) = 0;
                
                
                
};

#endif

