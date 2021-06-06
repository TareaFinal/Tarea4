#ifndef DTCOMENTARIO
#define DTCOMENTARIO

#include "DtFechaHora.h"
#include <string>
#include <iostream>
using namespace std;

class DtComentario {
	private:
		int idComentario;
		DtFechaHora fecha;
		string nicknameJugador;
        string texto;
	public:
		DtComentario();

        //getters
		int getIdComentario();
		DtFechaHora getFecha();
		string getNicknameJugador();
        string getTexto();

        //setters
		int setIdComentario();
		DtFechaHora setFecha();
		string setNicknameJugador();
        string setTexto();
        
};

#endif