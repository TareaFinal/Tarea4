#ifndef DTPARTIDAINDIVIDUAL
#define DTPARTIDAINDIVIDUAL

#include "DtPartida.h"
#include <string>
using namespace std;

class DtPartidaIndividual : public DtPartida {
	private: 
		int partidaContinuada;
	public:	
		DtPartidaIndividual(int partidaContinuada);

        //getters
		int getPartidaContinuada();

};

#endif