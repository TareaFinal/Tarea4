#ifndef CONTROLADORVIDEOJUEGOS
#define CONTROLADORVIDEOJUEGOS


#include "IControladorVideojuegos.h"
#include "suscripcion.h"
#include "Categoria.h"
//#include "Videojuego.h"
#include "Estadistica.h"
#include "desarrollador.h"

#include <string>
#include <set>
#include <vector>

using namespace std;

class Categoria;
class Videojuego;
class Estadistica;

class ControladorVideojuegos : public iControladorVideojuegos {
	
	private: 
	        static ControladorVideojuegos *instancia;
            set<Categoria*> categorias;
            set<Videojuego*> videojuegos;
            set<Estadistica*> estadisticas;
            ControladorVideojuegos();
                
            
			string nombreVideojuego;
			string descripcionVideojuego;
			float costoMensual, costoTrimestral, costoAnual, costoVitalicio;
			DtCategoria* plataforma;
			DtCategoria* genero;
			vector<DtCategoria*> categoriasVideojuego;
                
	public:
                static ControladorVideojuegos *getInstancia();
                
                float calcularEstadistica(int estadistica, string nomVideojuego); //no deberia de ser de la misma clase que el identificador de estadisticas que viene a ser un int? ---- Ag: Si, lo deje porque asi estaba
                float calcularHorasJugadas(string videojuego);
                vector<DtJugador> jugadoresSuscriptosAVideojuego(string nombre);
                void eliminarVideojuego(string nombre);
                vector<DtVideojuego> obtenerVideojuegos();
                void confirmarEliminacion();
                bool ingreseNombreVideojuego(string nombreVideojuego);
                bool esTemporal(Suscripcion *s);
                Suscripcion *ingresarNombre(string nombre);
                void ingresarCategoria(string nombre, string tipo, string descripcion);
                
                bool existeVideojuego(string nombre);
                bool existeCategoria(string nombre);
                bool existeEstadistica(int id);
              	
              	bool altaSuscripcion(string videojuego, string tipo, string metodoPago, int validez);
                bool asignarPuntajeAVideojuego(string nomVideojuego, int puntaje);
                
                vector<string> consultarEstadisticas(string nombreVideojuego);
                vector<DtEstadistica> listarEstadisticas();
                
                void publicarVideojuego();
                void setearDatosVideojuego(string nombre, string descripcion, float precioMes, float precioTri, float precioAnio, float precioVit);
                void asignarGenero(DtCategoria* gen);
                void asignarPlataforma(DtCategoria* plat);
                void asignarCategorias(vector<DtCategoria*> cats);
                
                vector<DtCategoria*> solicitarCategorias();
};



#endif
