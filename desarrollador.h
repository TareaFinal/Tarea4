#ifndef DESARROLLADOR
#define DESARROLLADOR

#include "usuario.h"
#include "Videojuego.h"
#include <set>
#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Videojuego;

class Desarrollador : public Usuario {
private:
	string empresa;
	set<Videojuego*> videojuegos;
	vector<int> IdsEstadisticas;
	
public:
	// Constructor
	Desarrollador(string email,string contrasenia, string emp);
	
	// Desarrollador
	~Desarrollador();

	// Setters

	void setEmpresa(string nombre);
	// Getters
	string getEmpresa(); // era DarEmpresa pero no encuentro diferencia
	string tipoUsuario();
	
	void agregarVideojuego(Videojuego *v);
	void eliminarVideojuego(Videojuego *v);
	
	void registrarStats(vector<int> stats);
	vector<int> getStats();
};

#endif
