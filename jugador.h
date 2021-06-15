#ifndef JUGADOR
#define JUGADOR
#include "usuario.h"
#include "suscripcion.h"
#include "Videojuego.h"
#include "DataTypes/DtVideojuego.h" // ojo con las forward declarations

#include <string>
#include <iostream>
#include <set>
#include <map>
using namespace std;

class Jugador : public Usuario {
private:
	string nick, descripcion;
	std::map<string, Suscripcion*> dicSuscripciones; // un diccionario donde la clave es el nombre del videojuego.
	std::set<DtVideojuego*> colDTVideojuego;
protected:

public:
	// Constructor
	Jugador(string email, string contrasenia,string nickname,string descrip);
	// Destructor
	~Jugador();

	// Setters

	void setDescripcion(string descripcion);
	void setNick(string nickname);

	// Getters

	string getDescripcion();
	string getNick();
	set<Suscripcion*> getSuscripciones()

	// Funciones
	void desvincularSub(Videojuego* vj);
	void agregarSuscripcion(Suscripcion* s);
	std::set <DtVideojuego*> videojuegosSuscripto();  // al implementar deberiamos vaciar la coleccion antes de mandar asi no se acumulan con las anteriores
	
		
};

#endif
