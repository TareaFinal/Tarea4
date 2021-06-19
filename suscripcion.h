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
		DtFechaHora *fecha;
		Jugador *_jugador; 
		Videojuego *_videojuego; 
	public:	
		
		string getMetodoDePago();
		float getValor();
		DtFechaHora *getFecha();
		Videojuego *getVideojuego();
		Jugador *getJugador();
	
	
		virtual string TipoSuscripcion() = 0;
		virtual bool activa() = 0; 

};

#endif
