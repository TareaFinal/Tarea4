#include "../jugador.h"
#include <string>
#include <iostream>
using namespace std;

	// Constructor
Jugador::Jugador(string email, string contrasenia, string nickname, string descrip) {
	this->email = email;
	this->contrasenia = contrasenia;
	this->nick = nickname;
	this->descripcion = descrip;
}

	// Destructor
Jugador::~Jugador() {
	
	for (auto it = this->colSuscripciones.begin(); it != this->colSuscripciones.end();)
	{
		Suscripcion *s = (it->second);
		this->colSuscripciones.erase(it++);
		delete s;
	}
	
}

	// Setters

void Jugador::setDescripcion(string descripcion) {
	this->descripcion = descripcion;
}
void Jugador::setNick(string nickname) {
	this->nick = nickname;
}

	// Getters

string Jugador::getDescripcion() { 
	return this->descripcion; 
}
string Jugador::getNick() { 
	return this->nick; 
}

Suscripcion *Jugador::getSuscripcion(string videojuego) {
	Suscripcion* sus = this->colSuscripciones[videojuego];
	return sus;
}


	// Funciones
void Jugador::desvincularSub(Videojuego* v) {
	string idVideojuego = v->getNombre();
	map<string, Suscripcion*>::iterator it = this->colSuscripciones.find(idVideojuego);
	
	if (it != this->colSuscripciones.end()) // si la encontro
		this->colSuscripciones.erase(idVideojuego);	
}

// borrar suscripcion al videojuego v. o hay que cancelarla y nada mas?
void Jugador::agregarSuscripcion(Suscripcion* s) {
	this->colSuscripciones.insert(pair<string, Suscripcion*> (s->getVideojuego()->getNombre(), s));
}

vector <DtVideojuego*> Jugador::videojuegosSuscripto() {
	
	vector <DtVideojuego*> colDtVideojuego;

	for (auto it = this->colSuscripciones.begin(); it != this->colSuscripciones.end();)
	{
		DtVideojuego* dataVideojuego = ((it->second)->getVideojuego())->getDataVideojuego();
		colDtVideojuego.push_back(dataVideojuego);
	}
	return colDtVideojuego;
}
