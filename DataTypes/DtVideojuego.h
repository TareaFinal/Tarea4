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
		DtVideojuego();

        //getters
        string getNombre();
		string getDescripcion();
        float getPuntajePromedio();
        float getTotalDeHorasJugadas();
        string getEmpresa();

        //setters
        string setNombre();
		string setDescripcion();
        float setPuntajePromedio();
        float setTotalDeHorasJugadas();
        string setEmpresa();
        
};

#endif