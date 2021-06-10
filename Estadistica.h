#ifndef ESTADISTICA
#define ESTADISTICA

#import "../DtEstadistica.h"

#include <string>

class Estadistica {
	private: 
		int idEstadistica
		string nombre
		string descripcion
		Estadistica EstrategiaEstadistica;

	public:
		virtual float calcular() = 0;
		DtEstadistica getDataEstadistica();
};

#endif
