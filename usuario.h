#ifndef USUARIO
#define USUARIO
#include <string>
#include <iostream>
using namespace std;

class Usuario {  // abstracta
	
protected:
	string email, contrasenia;
public:
	void setEmail(string direccion);
	void setContrasenia(string pass);
	// Getters
	string getEmail();
	string getContrasenia();
	// funciones
	
	virtual ~Usuario() = default;

};

#endif
