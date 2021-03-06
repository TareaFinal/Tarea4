#ifndef DTJUGADOR
#define DTJUGADOR

#include <string>
#include <iostream>
using namespace std;

class DtJugador {
	private:
        string email;
        string contrasenia;
        string nickname;
        string descripcion;

	public:    
        DtJugador(string email, string contrasenia, string nickname, string descripcion);
        //getters
        string getEmail();
        string getContrasenia();
        string getNickname();
        string getDescripcion();
        
        friend ostream &operator<< (ostream &os, DtJugador* est);
};

#endif
