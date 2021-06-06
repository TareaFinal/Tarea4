laboratorio:	DtFechaHora.o DtPartida.o DtPartidaIndividual.o DtPartidaMultijugador.o DtVideojuego.o 
	g++ DtFechaHora.o DtJugador.o DtPartida.o DtPartidaIndividual.o DtPartidaMultijugador.o DtVideojuego.o -o laboratorio

DtFechaHora.o: DtFechaHora.cpp
	g++ -c DtFechaHora.cpp

DtPartida.o: DtPartida.cpp
	g++ -c DtPartida.cpp

DtPartidaIndividual.o: DtPartidaIndividual.cpp
	g++ -c DtPartidaIndividual.cpp

DtPartidaMultijugador.o: DtPartidaMultijugador.cpp
	g++ -c DtPartidaMultijugador.cpp

DtVideojuego.o: DtVideojuego.cpp
	g++ -c DtVideojuego.cpp

clean:
	rm *.o laboratorio