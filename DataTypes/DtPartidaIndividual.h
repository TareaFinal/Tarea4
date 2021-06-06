#ifndef DTPARTIDAINDIVIDUAL
#define DTPARTIDAINDIVIDUAL

#include "DtPartida.h"
#include <string>
using namespace std;

class DtPartidaIndividual : public DtPartida {
	private: 
		int partidaContinuada;
	public:	
		DtPartidaIndividual();

        //getters
		int getPartidaContinuada();

        //setters
		int setPartidaContinuada();
};

#endif