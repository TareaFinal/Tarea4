#include <string>
#include <iostream>
#include <stdexcept> 
#include "../usuario.h"
using namespace std;

/*class Usuario {  // abstracta
private:
	
protected:
	string email, contrasenia;
public:
*/

// Setters
void Usuario::setEmail(string direccion) {
	this->email = direccion;
}
void Usuario::setContrasenia(string pass) {
	this->contrasenia = pass;
}
	// Getters
string Usuario::getEmail() { return this->email; }
string Usuario::getContrasenia() { return this->contrasenia; }
