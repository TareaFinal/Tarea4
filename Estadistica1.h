#ifndef ESTADISTICA1
#define ESTADISTICA1

#include "Estadistica.h"
#include <string>

class Estadistica1 : public Estadistica {
	public:
		Estadistica1(int id, string nombre, string desc);
		float calcular(string videojuego);
		DtEstadistica *getDataEstadistica(float valor);
};

#endif
