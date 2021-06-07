#ifndef JUGADOR
#define JUGADOR
#include "usuario.h"
#include "suscripcion.h"
#include "DataTypes/DTVideojuego.h" // ojo con las forward declarations
#include <string>
#include <iostream>
using namespace std;

class Jugador : public Usuario {
private:
	string nick, descripcion;
	std::set <Suscripcion*> colSuscripciones; // para hacer find capaz es mejor tener un map, pero para eso necesitamos una clave que identifique a la suscripcion
	std::set <DTVideojuego*> colDTVideojuego;

protected:

public:
	// Constructor
	Jugador(email: string, contrasenia: string, nickname : string, descrip : string);

	// Destructor
	~Jugador();

	// Setters

	void setDescripcion(string descripcion);
	void setNick(string nickname);

	// Getters

	string getDescripcion();
	string getNick();

	// Funciones
	void desvincularSub(Suscripcion s);
	void agregarSuscripcion(Suscripcion s);
	colDTVideojuego* videojuegosSuscripto();  // al implementar deberiamos vaciar la coleccion antes de mandar asi no se acumulan con las anteriores
	
		
};

#endif
