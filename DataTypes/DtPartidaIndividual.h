#ifndef DTPARTIDAINDIVIDUAL
#define DTPARTIDAINDIVIDUAL

#include "DtPartida.h"
#include <string>
using namespace std;

class DtPartidaIndividual : public DtPartida {
	private: 
		int partidaContinuada;
	public:	
		DtPartidaIndividual(int idPartida, float duracion, DtFechaHora *fechaInicio, string nickname, string videojuego, int partidaContinuada);

        //getters
		int getPartidaContinuada();
		
		friend ostream &operator<< (ostream &os, DtPartidaIndividual* pi);
};

#endif
