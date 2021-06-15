#ifndef VIDEOJUEGO
#define VIDEOJUEGO

#include "DataTypes/DtVideojuego.h"
#include "DataTypes/DtJugador.h"
#include "jugador.h"
#include "Categoria.h"
#include "suscripcion.h"
#include "Estadistica.h"

#include <string>

class Videojuego {
	private: 
		string nombre;
		string descripcion;
		float *costos;
		int *puntajes;
		Desarrollador desarrollador;
		Categoria **categorias ;
		Suscripcion **suscripciones;
		Estadistica **estadisticas;
		
	public:
		Videojuego::Videojuego(string n, string d, float* costos, Desarrollador desarrollador, Categoria** categorias, Estadistica** estadisticas)
		string getNombre();
		string getDescripcion();
		float *getCostos();
		int *getPuntajes();
		int getCantidadJugadoresSuscriptos();
		Categoria **getCategorias();
		Suscripcion **getSuscripciones();
		DtJugador *getJugadoresSuscriptos();
		Jugador *getJugadores();
		DtVideojuego getDataVideojuego();
		
		void setNombre(string nombre);
		void setDescripcion(string descripcion);
		void setCostos(float *costos);
		void agregarPuntaje(int puntaje);
		void agregarCategoria(Categoria c);
		void agregarSuscripcion(Suscripcion s);
		void agregarEstadistica(Estadistica e);
		void eliminarCategoria(Categoria c);
		void eliminarSuscripcion(Suscripcion s);
		void eliminarEstadistica(Estadistica e);
		
		float calcularEstadistica(int idEstadistica);
		int calcularPuntajePromedio();
};

#endif
