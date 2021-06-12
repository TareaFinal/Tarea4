#ifndef SUSCRIPCION
#define SUSCRIPCION
#include <string>
#include <iostream>
#include "../DataTypes/DtFechaHora.h"
#include "jugador.h"
#include "Videojuego.h"
using namespace std;

class Suscripcion {
private:
	
protected:
	string metodoDePago;
	float valor;
	DtFechaHora fecha;
	Jugador* _jugador; // el jugador al que pertenece la suscripcion
	Videojuego* _videojuego; // es el videojuego al que se suscribe
public:
	//Constructor
	Suscripcion(string metpago, DtFechaHora fechahoy,float val, Jugador* player, Videojuego* vj);
	
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
	DtVideojuego getDataVideojuego();

	// Funciones
	virtual string TipoSuscripcion();
	virtual bool activa(); // esta funcion determina si la suscripcion está activa o no. Abstracta

};

#endif