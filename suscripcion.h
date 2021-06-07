#ifndef SUSCRIPCION
#define SUSCRIPCION
#include <string>
#include <iostream>
#include "DataTypes/DTFecha.h"
#include "Jugador.h"
#include "Videojuego.h"
using namespace std;

class Suscripcion {
private:
	string metodoDePago;
	float valor;
	DTFecha fecha;
	Jugador* _jugador; // el jugador al que pertenece la suscripcion
	Videojuego* _videojuego // es el videojuego al que se suscribe
protected:

public:
	//Constructor
	Suscripcion (string metpago, DTFecha fechahoy,float val, Jugador* player, VideoJuego* vj);
	
	// Destructor

	~Suscripcion();
	// Seters

	void setMetodoDePago(string descripcion); // se setan estas cosas?
	void setValor(float val);
	void setFecha(DTFecha fechahora);

	//Getters
	
	string getMetodoDePago();
	float getValor();
	DTFecha getFecha();

	// Funciones
	bool Activa(); // esta funcion determina si la suscripcion está activa o no. Abstracta

};

#endif