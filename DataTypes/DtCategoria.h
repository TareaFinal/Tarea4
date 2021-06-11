#ifndef DTCATEGORIA
#define DTCATEGORIA

#include <string>
#include <iostream>
using namespace std;

class DtCategoria {
	private:
		string nombre;
		string tipo;
		string descripcion;
	public:
		DtCategoria(string nombre, string tipo, string descripcion);

        //getters
		string getNombre();
		string getTipo();
		string getDescripcion();
        
};

#endif