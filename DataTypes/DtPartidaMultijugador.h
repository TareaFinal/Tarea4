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
		map<string, DtFechaHora*> conjuntoSalidas;
		vector<DtComentario*> comentarios;
	public:	
		typedef map<string, DtFechaHora*> map_type;
		DtPartidaMultijugador(int idPartida, float duracion, DtFechaHora* fechaInicio, string creador, string videojuego, bool transmitida, vector<DtComentario*> comentarios, const map_type& = map_type());

        //getters
		bool getTransmitida();
		set<string> getNicknameJugadoresUnidos();
		set<string> getNicknameJugadoresActivos();
		vector<DtComentario*> getComentarios();
		
		friend ostream &operator<< (ostream &os, DtPartidaMultijugador* pm);

};

#endif
