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
		DtCategoria();

        //getters
		string getNombre();
		string getTipo();
		string getDescripcion();

        //setters
		string setNombre();
		string setTipo();
		string setDescripcion();
        
};

#endif