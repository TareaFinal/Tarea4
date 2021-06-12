#include <string>
#include <iostream>
#include "../usuario.h"
using namespace std;

/*class Usuario {  // abstracta
private:
	
protected:
	string email, contrasenia;
public:
*/
	// Constructor
Usuario::Usuario(string email, string contrasenia) {
	if (email.find("@") == string::npos) {
		this->email = email;
		this->contrasenia = contrasenia;
	}
	else {
		throw invalid_argument("el email no tiene un formato valido\n");
	}
}
	// Destructor
Usuario::~Usuario() {
}
// Setters
void Usuario::setEmail(string direccion) {
	email = direccion;
}
void Usuario::setContrasenia(string pass) {
	contrasenia = pass;
}
	// Getters
string Usuario::getEmail() { return email; }
string Usuario::getContrasenia() { return contrasenia; }