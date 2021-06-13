#ifndef JUGADOR
#define JUGADOR
#include "usuario.h"
#include "suscripcion.h"
<<<<<<< HEAD
#include "Videojuego.h"
#include "DataTypes/DtVideojuego.h" // ojo con las forward declarations
=======
#include "DataTypes/DtVideojuego.h" // ojo con las forward declarations
#include <set>
>>>>>>> ecef6d937beb97a226cd2577e55da449f5483e8c
#include <string>
#include <iostream>
#include <set>
#include <map>
using namespace std;

class Jugador : public Usuario {
private:
	string nick, descripcion;
<<<<<<< HEAD
	//std::map<int, Funcion*> dicFunciones;
	std::map<string, Suscripcion*> dicSuscripciones; // un diccionario donde la clave es el nombre del videojuego.
=======
	std::set<Suscripcion*> colSuscripciones; // para hacer find capaz es mejor tener un map, pero para eso necesitamos una clave que identifique a la suscripcion
	std::set<DtVideojuego*> colDTVideojuego;

>>>>>>> ecef6d937beb97a226cd2577e55da449f5483e8c
protected:

public:
	// Constructor
<<<<<<< HEAD
	Jugador(string email, string contrasenia,string nickname,string descrip);
=======
	Jugador(string email, string contrasenia, string nickname, string descripcion);
>>>>>>> ecef6d937beb97a226cd2577e55da449f5483e8c

	// Destructor
	~Jugador();

	// Setters

	void setDescripcion(string descripcion);
	void setNick(string nickname);

	// Getters

	string getDescripcion();
	string getNick();

	// Funciones
	void desvincularSub(Videojuego* vj);
	void agregarSuscripcion(Suscripcion* s);
	std::set <DtVideojuego*> videojuegosSuscripto();  // al implementar deberiamos vaciar la coleccion antes de mandar asi no se acumulan con las anteriores
	
		
};

#endif
