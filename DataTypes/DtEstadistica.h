#ifndef DTESTADISTICA
#define DTESTADISTICA

#include <string>
#include <iostream>
using namespace std;

class DtEstadistica {
	private:
		int idEstadistica;
		string nombre;
		string descripcion;
		float valor;
	public:
		DtEstadistica();

        //getters
		int getIdEstadistica();
		string getNombre();
		string getDescripcion();
		float getValor();

        //setters
        int setIdEstadistica();
		string setNombre();
		string setDescripcion();
		float setValor();
        
};

#endif