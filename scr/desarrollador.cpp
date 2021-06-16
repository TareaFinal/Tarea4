#include "../desarrollador.h"
#include <string>
#include <iostream>
using namespace std;
	// Constructor
Desarrollador::Desarrollador(string email,string contrasenia, string emp): 
Usuario(email, contrasenia), empresa(emp){
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
