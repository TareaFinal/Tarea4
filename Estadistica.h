#ifndef ESTADISTICA
#define ESTADISTICA

#include "DataTypes/DtEstadistica.h"

#include <string>

class Estadistica {
	private: 
		int idEstadistica;
		string nombre;
		string descripcion;
		//Estadistica EstrategiaEstadistica;

	public:
		virtual float calcular(string videojuego) = 0;
		virtual DtEstadistica getDataEstadistica();
};

#endif
