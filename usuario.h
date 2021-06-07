#ifndef USUARIO
#define USUARIO
#include <string>
#include <iostream>
using namespace std;

class Usuario {
private:
	string email, contrasenia;
protected:
	
public:
	// Constructor
	Usuario(string email, string contrasenia);
	// Destructor
	~Usuario();
	// Setters
	void setEmail(string direccion);
	void setContrasenia(string pass);
	// Getters
	string getEmail();
	string getContrasenia();
	
};

#endif
