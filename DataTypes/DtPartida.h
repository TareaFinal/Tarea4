#ifndef DTPARTIDA
#define DTPARTIDA

#include "DtFechaHora.h"
#include <string>
#include <iostream>
using namespace std;

class DtPartida {
	protected:
        int idPartida;
		float duracion; //no deberia de ser de tipo float?
        DtFechaHora *fechaInicio;
        string nicknameCreador;
        string videojuego;

	public: //esto deberia de ponerlo en las clases hijo
    
        //getters
        int getIdPartida();
		float getDuracion();
        DtFechaHora *getFechaInicio();
        string getNicknameCreador();
        string getVideojuego();

        virtual ~DtPartida() {
		}
        
};

#endif
