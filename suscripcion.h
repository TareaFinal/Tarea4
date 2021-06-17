#ifndef SUSCRIPCION
#define SUSCRIPCION

#include <string>
#include <iostream>
#include "DataTypes/DtFechaHora.h"
#include "DataTypes/DtVideojuego.h"
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
		DtFechaHora fechahoy;
		Jugador* _jugador; // el jugador al que pertenece la suscripcion
		Videojuego* _videojuego; // es el videojuego al que se suscribe
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
		virtual DtFechaHora getFecha()=0;
		virtual DtVideojuego getDataVideojuego()=0;
	
		// Funciones
		virtual string TipoSuscripcion() =0;
		virtual bool activa()=0; // esta funcion determina si la suscripcion esta activa o no. Abstracta

};

#endif
