#ifndef ESTADISTICA2
#define ESTADISTICA2

#include "Estadistica.h"
#include <string>

class Estadistica2 : public Estadistica {
	public:
		Estadistica2(int id, string nombre, string desc);
		float calcular(string videojuego);
		DtEstadistica *getDataEstadistica(float valor);
};

#endif
