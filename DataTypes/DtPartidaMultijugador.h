#ifndef DTPARTIDAMULTIJUGADOR
#define DTPARTIDAMULTIJUGADOR

#include "DtPartida.h"
#include "DtComentario.h"
#include <string>
#include <set>
using namespace std;

class DtPartidaMultijugador : public DtPartida {
	private: 
		bool transmitida;
		set<string> nicknameJugadoresUnidos;
		set<DtComentario> comentarios;
	public:	
		DtPartidaMultijugador(DtFechaHora duracion, DtFechaHora fechaInicio, string nicknameCreador, string videojuego, bool transmitida, set<string> nicknameJugadoresUnidos, set<DtComentario> comentarios);

        //getters
		bool getTransmitida();
		set<string> getNicknameJugadoresUnidos();
		set<DtComentario> getComentarios();

};

#endif