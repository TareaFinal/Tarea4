#ifndef DTVIDEOJUEGO
#define DTVIDEOJUEGO

#include "DtPartida.h"
#include <string>
#include <iostream>
using namespace std;

class DtVideojuego {
	private:
        string nombre;
		string descripcion;
        float puntajePromedio;
        float totalDeHorasJugadas;
        string empresa;

	public:
		DtVideojuego(string nombre, string descripcion, float puntajePromedio, float totalDeHorasJugadas, string empresa);

        //getters
        string getNombre();
		string getDescripcion();
        float getPuntajePromedio();
        float getTotalDeHorasJugadas();
        string getEmpresa();

		friend ostream &operator<< (ostream &os, DtVideojuego* vi);

};

#endif
