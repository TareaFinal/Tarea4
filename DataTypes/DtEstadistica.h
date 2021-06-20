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
		DtEstadistica(int idEstadistica, string nombre,	string descripcion,	float valor);

        //getters
		int getIdEstadistica();
		string getNombre();
		string getDescripcion();
		float getValor();
  
   		friend ostream &operator<< (ostream &os, DtEstadistica* est);     
};

#endif
