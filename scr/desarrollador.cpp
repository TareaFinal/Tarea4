#include "../desarrollador.h"
#include <string>
#include <iostream>
using namespace std;
	// Constructor
Desarrollador::Desarrollador(string email,string contrasenia, string emp) {
	this->email = email;
	this->contrasenia = contrasenia;
	this->empresa = emp;
}
	// Destructor
Desarrollador::~Desarrollador() {
}
	// Setters
void Desarrollador::setEmpresa(string nombre) {
	this->empresa = nombre;
}
	// Getters
string Desarrollador::getEmpresa() { 
	return this->empresa;
}
	// Funciones
string Desarrollador::tipoUsuario() { 
	return "desarrollador";
}

void Desarrollador::agregarVideojuego(Videojuego *v) {
	set<Videojuego*>::iterator it = this->videojuegos.find(v);
	
	if (it != this->videojuegos.end()) {
		this->videojuegos.insert(v);
		cout << "Videojuego agregado correctamente al desarrollador.";
	} else {
		cout << "El videojuego ya esta ingresado.";
	}
}

void Desarrollador::eliminarVideojuego(Videojuego *v) {
	for (auto it = this->videojuegos.begin(); it != this->videojuegos.end();) {
		if (*it == v) {
			this->videojuegos.erase(it++);
			cout << "Videojuego removido correctamente.";
			break;
		}		
	}
}
