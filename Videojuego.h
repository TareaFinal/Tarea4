#ifndef VIDEOJUEGO
#define VIDEOJUEGO

#include "DataTypes/DtVideojuego.h"
#include "DataTypes/DtJugador.h"
#include "jugador.h"
#include "Categoria.h"
#include "suscripcion.h"
#include "Estadistica.h"


#include <string>
#include <vector>

using namespace std;

class Categoria;
class Jugador;

class Videojuego {
	private: 
		string nombre;
		string descripcion;
		float *costos;
		Desarrollador *desarrollador;
		vector<Categoria*> categorias;
		vector<Estadistica*> estadisticas;
		vector<Suscripcion*> suscripciones;
		vector<int> puntajes;
		
	public:
		Videojuego(string n, string d, float* costos, Desarrollador *desarrollador);
		string getNombre();
		string getDescripcion();
		float *getCostos();
		vector<int> getPuntajes();
		int getCantidadJugadoresSuscriptos();
		vector<Categoria*> getCategorias();
		vector<Suscripcion*> getSuscripciones();
		DtJugador *getJugadoresSuscriptos();
		Jugador *getJugadores();
		DtVideojuego *getDataVideojuego();
		
		void setNombre(string nombre);
		void setDescripcion(string descripcion);
		void setCostos(float *costos);
		void agregarPuntaje(int puntaje);
		void agregarCategoria(Categoria *c);
		void agregarSuscripcion(Suscripcion *s);
		void agregarEstadistica(Estadistica *e);
		void eliminarCategoria(Categoria *c);
		void eliminarSuscripcion(Suscripcion *s);
		void eliminarEstadistica(Estadistica *e);
		
		float calcularEstadistica(int idEstadistica);
		float calcularPuntajePromedio();
};

#endif
