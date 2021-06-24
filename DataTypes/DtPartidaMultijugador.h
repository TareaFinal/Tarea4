#ifndef DTPARTIDAMULTIJUGADOR
#define DTPARTIDAMULTIJUGADOR

#include "DtPartida.h"
#include "DtComentario.h"
#include "DtFechaHora.h"
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;


class DtPartidaMultijugador : public DtPartida {
	private: 
		bool transmitida;
		set<string> conjuntoSalidas;
		vector<DtComentario*> comentarios;
	public:	
		typedef map<string, DtFechaHora*> map_type;
		DtPartidaMultijugador(int idPartida, float duracion, DtFechaHora* fechaInicio, string creador, string videojuego, bool transmitida, vector<DtComentario*> comentarios, set<string> conjuntoSalidas);

        //getters
		bool getTransmitida();
		set<string> getNicknameJugadoresUnidos();
		vector<DtComentario*> getComentarios();
		
		friend ostream &operator<< (ostream &os, DtPartidaMultijugador* pm);

};

#endif
