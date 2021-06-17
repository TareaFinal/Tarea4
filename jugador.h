#ifndef JUGADOR
#define JUGADOR

#include "usuario.h"
#include "suscripcion.h"
#include "DataTypes/DtVideojuego.h" // ojo con las forward declarations
#include <vector>
#include <string>
#include <iostream>
#include <map>
using namespace std;

class Suscripcion;

class Jugador : public Usuario {
private:
	string nick, descripcion, contrasenia, email;
	std::map<string,Suscripcion*> dicSuscripciones; // para hacer find capaz es mejor tener un map, pero para eso necesitamos una clave que identifique a la suscripcion
	//std::set<DtVideojuego> colDTVideojuego;

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

	// Funciones
	void desvincularSub(string v);
	void agregarSuscripcion(Suscripcion* s);
	vector<DtVideojuego> videojuegosSuscripto();  // al implementar deberiamos vaciar la coleccion antes de mandar asi no se acumulan con las anteriores
	
		
};

#endif
