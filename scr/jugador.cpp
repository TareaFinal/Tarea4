#include "../jugador.h"
#include <string>
#include <iostream>
#include <map>
using namespace std;

	// Constructor
Jugador::Jugador(string email, string contrasenia, string nickname, string descrip) {
	this->nick = nickname; this->descripcion = descrip; this->contrasenia = contrasenia; this->email = email;
}
	// Destructor
Jugador::~Jugador() {
	map <string, Suscripcion*>::iterator it; // it es un puntero a un elemento, pero como es un map hay que ir al first la clave o seconde el elemento, 
										//pero como tengo elementos que son punteros:
										 //it es un puntero que apunta a un objeto con dos metodos el segundo es un puntero que apunta a una suscripcion
	for (it = dicSuscripciones.begin(); it != dicSuscripciones.end(); ++it)
	{
		delete it->second;
	}
	dicSuscripciones.clear();
}

	// Setters

void Jugador::setDescripcion(string descripcion) {
	this->descripcion = descripcion;
}
void Jugador::setNick(string nickname) {
	nick = nickname;
}

	// Getters

string Jugador::getDescripcion() { return descripcion; }
string Jugador::getNick() { return nick; }

	// Funciones
void Jugador::desvincularSub(string v) {
	
	
	std::map<string, Suscripcion*>::iterator it = dicSuscripciones.find(v);
	
	if (it != dicSuscripciones.end()) // si la encontro
		dicSuscripciones.erase(v);

}
// borrar suscripcion al videojuego v. o hay que cancelarla y nada mas?
void Jugador::agregarSuscripcion(Suscripcion* s) {
	dicSuscripciones[s->getDataVideojuego().getNombre()]= s;
}

std::vector <DtVideojuego> Jugador::videojuegosSuscripto() {
	
	vector <DtVideojuego> colDtVideojuego;
	map <string, Suscripcion*>::iterator it; // it es un puntero a un elemento, pero como es un map hay que ir al first la clave o seconde el elemento, 
										//pero como tengo elementos que son punteros:
										 //it es un puntero que apunta a un objeto con dos metodos el segundo es un puntero que apunta a una suscripcion
	for (it = dicSuscripciones.begin(); it != dicSuscripciones.end(); ++it){

		colDtVideojuego.push_back(it->second->getDataVideojuego());
	}
	return colDtVideojuego;
}