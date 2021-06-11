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
		DtComentario(int idComentario, DtFechaHora fecha, string nicknameJugador, string texto);

        //getters
		int getIdComentario();
		DtFechaHora getFecha();
		string getNicknameJugador();
        string getTexto();
        
};

#endif