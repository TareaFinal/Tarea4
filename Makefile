laboratorio:	DtCategoria.o DtComentario.o DtEstadistica.o DtFechaHora.o DtJugador.o DtPartida.o DtPartidaIndividual.o DtPartidaMultijugador.o DtVideojuego.o 
	g++ DtCategoria.o DtComentario.o DtEstadistica.o DtFechaHora.o DtJugador.o DtPartida.o DtPartidaIndividual.o DtPartidaMultijugador.o DtVideojuego.o CotroladorPartidas.o -o laboratorio

ControladorPartidas.o: ControladorPartidas.cpp
	g++ -c scr/ControladorPartidas.cpp

DtCategoria.o: DtCategoria.cpp
	g++ -c DataTypes/cpp/DtCategoria.cpp

DtComentario.o: DtComentario.cpp
	g++ -c DataTypes/cpp/DtComentario.cpp

DtEstadistica.o: DtEstadistica.cpp
	g++ -c DataTypes/cpp/DtEstadistica.cpp

DtFechaHora.o: DtFechaHora.cpp
	g++ -c DataTypes/cpp/DtFechaHora.cpp

DtJugador.o: DtJugador.cpp
	g++ -c DataTypes/cpp/DtJugador.cpp

DtPartida.o: DtPartida.cpp
	g++ -c DataTypes/cpp/DtPartida.cpp

DtPartidaIndividual.o: DtPartidaIndividual.cpp
	g++ -c DataTypes/cpp/DtPartidaIndividual.cpp

DtPartidaMultijugador.o: DtPartidaMultijugador.cpp
	g++ -c DataTypes/cpp/DtPartidaMultijugador.cpp

DtVideojuego.o: DtVideojuego.cpp
	g++ -c DataTypes/cpp/DtVideojuego.cpp

clean:
	rm *.o laboratorio