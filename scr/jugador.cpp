#include "../jugador.h"
#include <string>
#include <iostream>
using namespace std;
/*
class Jugador : public Usuario {
private:
	string nick, descripcion;
	std::set <Suscripcion*> colSuscripciones; // para hacer find capaz es mejor tener un map, pero para eso necesitamos una clave que identifique a la suscripcion
	std::set <DTVideojuego*> colDTVideojuego;

protected:

public:
*/
	// Constructor
Jugador::Jugador(string email, string contrasenia, string nickname, string descrip) :
	 Usuario(email, contrasenia), nick(nickname), descripcion(descrip) {}

	// Destructor
Jugador::~Jugador() {
}

	// Setters

void Jugador::setDescripcion(string descripcion) {
	this->descripcion = descripcion;
}
void Jugador::setNick(string nickname) {
	nick = nickname;
}

	// Getters

string Jugador::getDescripcion() { return descripcion }
string Jugador::getNick() { return nick }

	// Funciones
void Jugador::desvincularSub(Videojuego* v) {
	string idVideojuego = v->getNombre();
	map<string, Suscripcion*>::iterator it = dicSuscripciones.find(idVideojuego);
	
	if (it != dicSuscripciones.end()) // si la encontro
		dicSuscripciones.erase(idVideojuego);
}
// borrar suscripcion al videojuego v. o hay que cancelarla y nada mas?
void Jugador::agregarSuscripcion(Suscripcion* s) {
	dicSuscripciones[s->getDataVideojuego().getNombre()] = s;
}
std::set <DtVideojuego*> videojuegosSuscripto() {
	
	set <DtVideojuego*> colDtVideojuego;
	map <string, Suscripcion*>::iterator it; // it es un puntero a un elemento, pero como tengo elementos que son punteros:
										 //it es un puntero a un puntero que apunta a una suscripcion
	for (it = colSuscripciones.begin(); it != colSuscripciones.end(); ++it)
	{
		DtVideojuego* pDtVideojuego;
		pDtVideojuego = new((*(*it)).getDataVideojuego());
		colDtVideojuego.insert(pDtVideojuego);
	}
	return colDtVideojuego;
}// se manda una coleccion cada vez.   donde se borra??