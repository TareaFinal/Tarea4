#ifndef ESTADISTICA
#define ESTADISTICA

#include "DataTypes/DtEstadistica.h"

#include <string>

class Estadistica {
	protected: 
		int idEstadistica;
		string nombre;
		string descripcion;
		//Estadistica EstrategiaEstadistica;

	public:
		int getID();
		string getNombre();
		string getDescripcion();
		virtual float calcular(string videojuego) = 0;
		virtual DtEstadistica *getDataEstadistica(float valor) = 0;
};

#endif
