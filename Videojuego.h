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
		string getNombre();
		string getDescripcion();
		float *getCostos();
		int *getPuntajes();
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
		
		float calcularEstadistica(int idEstadistica);
		int calcularPuntajePromedio();
};

#endif
