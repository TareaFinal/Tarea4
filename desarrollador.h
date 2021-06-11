#ifndef DESARROLLADOR
#define DESARROLLADOR
#include "usuario.h"
#include <string>
#include <iostream>
using namespace std;

class Desarrollador : public Usuario {
private:
	string empresa;
protected:

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
};

#endif
