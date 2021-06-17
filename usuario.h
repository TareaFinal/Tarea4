#ifndef USUARIO
#define USUARIO
#include <string>
#include <iostream>
using namespace std;

class Usuario {  // abstracta
private:
	
protected:
	string email, contrasenia;
public:
	virtual void setEmail(string direccion);
	void setContrasenia(string pass);
	// Getters
	string getEmail();
	string getContrasenia();
	// funciones

};

#endif
