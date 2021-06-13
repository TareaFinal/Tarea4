#ifndef JUGADOR
#define JUGADOR
#include "usuario.h"
#include "suscripcion.h"
#include "DataTypes/DtVideojuego.h" // ojo con las forward declarations
#include <set>
#include <string>
#include <iostream>
using namespace std;

class Jugador : public Usuario {
private:
	string nick, descripcion;
	std::set<Suscripcion*> colSuscripciones; // para hacer find capaz es mejor tener un map, pero para eso necesitamos una clave que identifique a la suscripcion
	std::set<DtVideojuego*> colDTVideojuego;

protected:

public:
	// Constructor
	Jugador(string email, string contrasenia, string nickname, string descripcion);

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
	void desvincularSub(Suscripcion s);
	void agregarSuscripcion(Suscripcion s);
	colDTVideojuego* videojuegosSuscripto();  // al implementar deberiamos vaciar la coleccion antes de mandar asi no se acumulan con las anteriores
	
		
};

#endif
