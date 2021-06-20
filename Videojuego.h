#ifndef VIDEOJUEGO
#define VIDEOJUEGO

#include "DataTypes/DtVideojuego.h"
#include "DataTypes/DtJugador.h"
#include "jugador.h"
#include "Categoria.h"
#include "suscripcion.h"
#include "Estadistica.h"
#include "desarrollador.h"


#include <string>
#include <vector>
#include <map>

using namespace std;

class Categoria;
class Jugador;
class Desarrollador;
class Suscripcion;

class Videojuego {
	private: 
		string nombre;
		string descripcion;
		map<int,float> costos;
		Desarrollador *desarrollador;
		vector<Categoria*> categorias;
		vector<Estadistica*> estadisticas;
		vector<Suscripcion*> suscripciones;
		vector<int> puntajes;
		
	public:
		typedef map<int, float> map_type;
		
		Videojuego(string n, string d, Desarrollador *desarrollador, vector<Categoria*> categorias, const map_type = map_type());
		
		string getNombre();
		string getDescripcion();
		map<int,float> getCostos();
		vector<int> getPuntajes();
		int getCantidadJugadoresSuscriptos();
		vector<Categoria*> getCategorias();
		vector<Suscripcion*> getSuscripciones();
		DtJugador *getJugadoresSuscriptos();
		Jugador *getJugadores();
		DtVideojuego *getDataVideojuego();
		Desarrollador* getDesarrollador();
		
		void setNombre(string nombre);
		void setDescripcion(string descripcion);
		void setCostos(map<int,float> costos);
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
