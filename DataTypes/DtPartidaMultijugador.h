#ifndef DTPARTIDAMULTIJUGADOR
#define DTPARTIDAMULTIJUGADOR

#include "DtPartida.h"
#include "DtComentario.h"
#include <string>
using namespace std;

class DtPartidaMultijugador : public DtPartida {
	private: 
		bool transmitida;
		string *nicknameJugadoresUnidos;
		DtComentario *comentarios;
	public:	
		DtPartidaMultijugador(bool transmitida, string *nicknameJugadoresUnidos, DtComentario *comentarios);

        //getters
		bool getTransmitida();
		string *getNicknameJugadoresUnidos();
		DtComentario *getComentarios();

};

#endif