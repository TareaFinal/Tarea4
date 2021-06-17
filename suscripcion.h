#ifndef SUSCRIPCION
#define SUSCRIPCION

#include <string>
#include <iostream>
#include "DataTypes/DtFechaHora.h"
#include "jugador.h"
#include "Videojuego.h"

#include <string>
using namespace std;

class Jugador;
class Videojuego;

class Suscripcion {
	protected:
		string metodoDePago;
		float valor;
		DtFechaHora fecha;
		Jugador *_jugador; // el jugador al que pertenece la suscripcion
		Videojuego *_videojuego; // es el videojuego al que se suscribe
	public:	//Constructor
		
		// Destructor
	
		~Suscripcion();
		// Seters no tenemos seters por el momento
		/*
		void setMetodoDePago(string descripcion); // se setan estas cosas?
		void setValor(float val);
		void setFecha(DTFecha fechahora);
		*/
		//Getters
		
		string getMetodoDePago();
		float getValor();
		DtFechaHora getFecha();
	
		// Funciones
	//	virtual string TipoSuscripcion();
	//	virtual bool activa(); // esta funcion determina si la suscripcion est� activa o no. Abstracta

};

#endif
