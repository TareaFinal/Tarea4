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
	empresa = nombre;
}
	// Getters
string Desarrollador::getEmpresa() { 
	return empresa;
}
	// Funciones
string Desarrollador::tipoUsuario() { 
	return "desarrollador";
}
