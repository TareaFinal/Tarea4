#ifndef ESTADISTICA2
#define ESTADISTICA2

#include "Estadistica.h"
#include <string>

class Estadistica2 : public Estadistica {
	public:
		float calcular(string videojuego);
		DtEstadistica getDataEstadistica();
};

#endif
