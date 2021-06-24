#ifndef DTVIDEOJUEGO
#define DTVIDEOJUEGO

#include "DtPartida.h"
#include <string>
#include <iostream>
#include <map>
#include <vector>
#include "../DataTypes/DtCategoria.h"
using namespace std;

class DtVideojuego {
	private:
        string nombre;
		string descripcion;
        float puntajePromedio;
        float totalDeHorasJugadas;
        string empresa;
        float costoMensual, costoTrimestral, costoAnual, costoVitalicio;
		vector<DtCategoria> datacategorias;
		vector<string> cats;
		
	public:
		DtVideojuego(string nombre, string descripcion, float puntajePromedio, float totalDeHorasJugadas, string empresa, map<int,float> costos, vector<string> cats);

        //getters
        
		float getCostoMensual();
		float getCostoTrimestral();
		float getCostoAnual();
		float getCostoVitalicio();
		vector<DtCategoria> getDtCategorias();
        string getNombre();
		string getDescripcion();
        float getPuntajePromedio();
        float getTotalDeHorasJugadas();
        string getEmpresa();
		vector<string> getStringCats();
		friend ostream &operator<< (ostream &os, DtVideojuego* vi);

};

#endif
